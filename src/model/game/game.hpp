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
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
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
/**
 * @brief The Game class is a class to generate a Game of the Cockroach Poker
 */
class Game : public utils::Observable {
 protected:
  /**
   * @brief The status of the game
   */
  GameStatus status_;

  /**
   * @brief The players of the game
   */
  std::vector<Player> players_;

  /**
   * @brief The actual round
   */
  Round round_;

  /**
   * @brief Find the youngest player in the players
   *
   * @return the youngest player
   */
  Player &youngestPlayer() noexcept(false);

 public:
  /**
   * @brief The min allowed players
   */
  static constexpr unsigned MIN_PLAYERS = 2;

  /**
   * @brief The max allowed players
   */
  static constexpr unsigned MAX_PLAYERS = 6;

  /**
   * @brief The basic deck map (8 cards each CardType)
   */
  static const std::map<cards::CardType, unsigned int> basicDeckMap;

  /**
   * @brief The default constructor of a game
   */
  Game();

  /**
   * @brief add a Player to the game (only possible when the game is not already
   * started)
   *
   * @param name Name of the new player
   * @param age Age of the new player
   */
  void addPlayer(const std::string_view &name, unsigned age);

  /**
   * @brief Get a player by name
   *
   * @param name name of the player to search
   * @return the player with the given name
   */
  [[nodiscard]] Player &getPlayer(const std::string &name) const;

  /**
   * @brief Add multiple players in the game
   *
   * @param players is a map with for each element a player name and a age
   */
  void addPlayers(const std::map<std::string, unsigned> &players);

  /**
   * @brief remove a player by index
   *
   * @param index of the player
   */
  [[maybe_unused]] void removePlayer(unsigned index) noexcept(false);

  /**
   * @brief Distribute a full deck randomly to the players hands
   */
  void distributeCards() noexcept(false);

  /**
   * @brief Start the game
   */
  void start() noexcept(false);

  /**
   * @brief gives the actual game status
   *
   * @return the game status
   */
  [[nodiscard]] GameStatus status() const;

  /**
   * @brief modify the actual game status
   *
   * @param status next status
   */
  void status(GameStatus status);
};
}  // namespace cpoker::model::game
#endif  // COCKROACH_POKER_SRC_MODEL_GAME_GAME_HPP_
