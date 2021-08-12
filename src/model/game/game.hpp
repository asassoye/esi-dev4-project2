// MIT License
//
// Copyright (c) 2021 Andrew SASSOYE
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef COCKROACH_POKER_SRC_MODEL_GAME_GAME_HPP_
#define COCKROACH_POKER_SRC_MODEL_GAME_GAME_HPP_

#include <vector>

#include "model/cards/deck.hpp"
#include "model/game/gamestatus.hpp"
#include "model/game/player.hpp"
#include "model/game/round.hpp"
#include "utils/observable.hpp"

namespace cpoker::model::game {
class Game : public utils::Observable {
 protected:
  GameStatus status_;

  std::vector<Player> players_;

  Round round_;

  Player &youngestPlayer() noexcept(false);

 public:
  static constexpr unsigned MIN_PLAYERS = 2;
  static constexpr unsigned MAX_PLAYERS = 6;
  static const std::map<cards::CardType, unsigned int> basicDeckMap;
  Game();

  void addPlayer(const std::string_view &name, unsigned age);

  void addPlayers(const std::map<std::string, unsigned> &players);

  void removePlayer(unsigned index) noexcept(false);

  void distributeCards() noexcept(false);

  void start() noexcept(false);

  [[nodiscard]] GameStatus status() const;

  void status(GameStatus status);
};
}  // namespace cpoker::model::game
#endif  // COCKROACH_POKER_SRC_MODEL_GAME_GAME_HPP_
