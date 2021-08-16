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

#ifndef COCKROACH_POKER_SRC_MODEL_GAME_ROUND_HPP_
#define COCKROACH_POKER_SRC_MODEL_GAME_ROUND_HPP_

#include <optional>

#include "model/cards//card.hpp"
#include "model/game/player.hpp"
#include "model/game/roundstatus.hpp"

namespace cpoker::model::game {
class Round {
 protected:
  RoundStatus status_;

  Player *sender_;

  Player *receiver_;

  std::optional<cards::Card> card_;

  std::optional<cards::Card> value_;

  void next(Player &nextSender,
            const std::optional<cards::Card> &card =
                std::optional<cards::Card>()) noexcept(false);

 public:
  Round();

  void start(Player &firstPlayer) noexcept(false);

  void reset() noexcept;

  void chooseCard(Player &sender, const cards::Card &card);

  void chooseCard(cards::CardType card_type);

  void chooseValue(Player &sender, const cards::Card &card);

  void chooseValue(cards::CardType card_type);

  void chooseReceiver(Player &sender, Player &receiver) noexcept(false);

  void chooseReceiver(Player &receiver);

  void accept(Player &receiver, bool guess);

  void accept(bool guess);

  void transfer(Player &receiver);

  void transfer();

  Player &looser() const noexcept(false);

  Player &playing() const;

  RoundStatus status() const;

  cards::CardType announced() const;
};
}  // namespace cpoker::model::game

#endif  // COCKROACH_POKER_SRC_MODEL_GAME_ROUND_HPP_
