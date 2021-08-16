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
/**
 * @brief Class to manage a Game Round
 */
class Round {
 protected:
  /**
   * @brief status of the round
   */
  RoundStatus status_;

  /**
   * @brief sender of the card
   */
  Player *sender_;

  /**
   * @brief receiver of the card
   */
  Player *receiver_;

  /**
   * @brief Card that is sent
   */
  std::optional<cards::Card> card_;

  /**
   * @brief Value of card that is announced to receiver
   */
  std::optional<cards::Card> value_;

  /**
   * @brief Migrate to the next round
   *
   * @param nextSender The next sender of the round
   * @param card if transfer, the card that is transferred
   */
  void next(Player &nextSender,
            const std::optional<cards::Card> &card =
                std::optional<cards::Card>()) noexcept(false);

 public:
  /**
   * @brief default Round constructor
   */
  Round();

  /**
   * @brief Start the round
   *
   * @param firstPlayer the first player
   */
  void start(Player &firstPlayer) noexcept(false);

  /**
   * @brief Reset the round
   */
  [[maybe_unused]] void reset() noexcept;

  /**
   * @brief Choose a card to send
   *
   * @param sender The sender of the card
   * @param card The card to send
   */
  void chooseCard(Player &sender, const cards::Card &card);

  /**
   * @brief Choose a card to send (without verification)
   * @param card_type type of the card to choose
   */
  void chooseCard(cards::CardType card_type);

  /**
   * @brief Choose a value to announce to the receiver
   *
   * @param sender The sender of the card
   * @param card The value that have to be announced
   */
  void chooseValue(Player &sender, const cards::Card &card);

  /**
   * @brief Choose a value to announce to the receiver
   * @param card_type Type that is announced
   */
  void chooseValue(cards::CardType card_type);

  /**
   * @brief Choose a receiver of the card
   *
   * @param sender The sender of the card
   * @param receiver The receiver of the card
   */
  void chooseReceiver(Player &sender, Player &receiver) noexcept(false);

  /**
   * @brief Choose a receiver of the card
   *
   * @param receiver The receiver of the card
   */
  void chooseReceiver(Player &receiver);

  /**
   * @brief Accept the card
   *
   * @param receiver The receiver of the card
   * @param guess The guess of the receiver. True if he thinks the announced
   * value is the real card, False if he thinks the sender is a liar.
   */
  void accept(Player &receiver, bool guess);

  /**
   * @brief Accept the card
   * @param guess The guess of the receiver. True if he thinks the announced
   * value is the real card, False if he thinks the sender is a liar.
   */
  void accept(bool guess);

  /**
   * @brief Transfer the received card
   * @param receiver The receiver of the card that he wants to transfer
   */
  void transfer(Player &receiver);

  /**
   * @brief Transfer the received card
   */
  void transfer();

  /**
   * @brief Returns the player who loosed (if the game is over)
   * @return the looser
   */
  [[nodiscard]] Player &looser() const noexcept(false);

  /**
   * @brief Returns the actual player that needs to make a choose
   * @return the playing player
   */
  [[nodiscard]] Player &playing() const;

  /**
   * @brief Returns the round status
   *
   * @return The round status
   */
  [[nodiscard]] RoundStatus status() const;

  /**
   * @brief returns the value that is announced by the sender
   * @return value_
   */
  [[nodiscard]] cards::CardType announced() const;
};
}  // namespace cpoker::model::game

#endif  // COCKROACH_POKER_SRC_MODEL_GAME_ROUND_HPP_
