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

//
// Created by asassoye on 28/07/21.
//

#ifndef COCKROACH_POKER_SRC_MODEL_GAME_PLAYER_HPP_
#define COCKROACH_POKER_SRC_MODEL_GAME_PLAYER_HPP_

#include <map>
#include <vector>

#include "model/cards/card.hpp"
#include "model/cards/cardcollection.hpp"

namespace cpoker::model::game {
/**
 * The player class managed the player's hand and table cards
 */
class Player {
 protected:
  /**
   * @brief minimum age required to play the game
   */
  constexpr static unsigned MIN_AGE = 8;

  /**
   * @brief name of the player
   */
  std::string name_;

  /**
   * @brief age of the player
   */
  unsigned age_;

  /**
   * @brief cards in hand
   */
  cards::CardCollection hand_;

  /**
   * @brief cards in the public table
   */
  cards::CardCollection table_;

 public:
  /**
   * @brief Player constructor
   *
   * @param name Name of the player
   * @param age Age of the player
   */
  Player(std::string_view name, unsigned age) noexcept(false);

  /**
   * @brief get the name of the player
   *
   * @return the name of the player
   */
  [[nodiscard]] std::string_view name() const noexcept;

  /**
   * @brief set the name of the player
   *
   * @param new_name The new name of the player
   */
  void name(std::string_view &&new_name) noexcept;

  /**
   * @brief get the age of the player
   *
   * @return The age
   */
  [[nodiscard]] unsigned age() const noexcept;

  /**
   * @brief Set the age of the player
   *
   * @param new_age The new age to set in the player
   */
  void age(unsigned new_age) noexcept;

  /**
   * @brief add a card in the player's hand
   *
   * @param card Card to add to the hand
   */
  void addHand(const cards::Card &card);

  /**
   * @brief Verify if a player has cards left in his hand
   *
   * @return true is the player has cards left
   * @return false if not
   */
  bool hasCardsLeft() noexcept;

  /**
   * @brief Add a card to the table
   *
   * @param card Card to add
   */
  void addTable(const cards::Card &card);

  /**
   * @brief Count how many cards are present in hand with given CardType
   *
   * @param type Type of card to count
   * @return The result of the count
   */
  [[nodiscard]] unsigned countTable(cards::CardType type) const;

  /**
   * @brief Count how many cards are present on the table with given CardType
   *
   * @param type Type of the cards to add in the count
   * @return The number of cards with given CardType
   */
  [[nodiscard]] unsigned countHand(cards::CardType type) const;

  /**
   * @brief Remove a card in the hand with given type
   * @param type Type of the first card to remove
   */
  void remove(cards::CardType type);

  /**
   * @brief Get a map of the number of cards present on the table per CardType
   * @return the result map
   */
  [[nodiscard]] std::map<cards::CardType, unsigned> table() const;

  /**
   * @brief Get a map of the number of cards present in the hand per CardType
   * @return the result map
   */
  [[nodiscard]] std::map<cards::CardType, unsigned> hand() const;

  /**
   * @brief Withdraw a card in the hand
   *
   * @param index of the card
   * @return the withdrew card
   */
  [[maybe_unused]] cards::Card withdraw(unsigned index);
};
}  // namespace cpoker::model::game

#endif  // COCKROACH_POKER_SRC_MODEL_GAME_PLAYER_HPP_
