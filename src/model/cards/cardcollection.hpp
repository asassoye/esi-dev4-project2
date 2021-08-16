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

#ifndef COCKROACH_POKER_SRC_MODEL_CARDS_CARDCOLLECTION_HPP_
#define COCKROACH_POKER_SRC_MODEL_CARDS_CARDCOLLECTION_HPP_

#include <array>
#include <map>
#include <random>
#include <vector>

#include "model/cards/card.hpp"

namespace cpoker::model::cards {
/**
 * @brief The CardCollection card is a class to manage multiple cards that are
 * grouped (in a deck for example or in a hand of a player, ....)
 */
class CardCollection {
 protected:
  /**
   * @brief Vector of cards
   */
  std::vector<Card> cards_;

 public:
  /**
   * @brief Constructor empty
   */
  CardCollection() noexcept(false);

  /**
   * @brief Constructor with a set of cards
   *
   * @param map Map with number of cards to add by type
   */
  explicit CardCollection(const std::map<CardType, unsigned int> &map) noexcept(
      false);

  /**
   * @brief check if the collection is empty
   *
   * @return
   */
  bool empty() noexcept;

  /**
   * @brief Check if the collection contains a certain type of card
   *
   * @return true if the card is present
   * @return false if the card is absent
   */
  [[nodiscard]] bool has(CardType) const noexcept;

  /**
   * @brief Check if a certain card is present
   *
   * @return true if the card is present
   * @return false if the card is not present
   */
  [[nodiscard]] bool has(const Card &) const noexcept;

  /**
   * @brief Count the number of cards with the given type is present in
   * collection
   *
   * @param type CardType to count
   * @return the number of cards with the given type
   */
  [[nodiscard]] unsigned count(CardType type) const noexcept;

  /**
   *
   * @return
   */
  Card pop() noexcept(false);

  /**
   * @brief Withdraw a card with a given index in the collection
   *
   * @param index index of the card to withdraw
   * @return the withdrew card
   */
  Card withdraw(unsigned index);

  /**
   * @brief Add a card of a certain type
   *
   * @param type the type of the card to add
   */
  void add(CardType type) noexcept(false);

  /**
   * @brief Add a card to the collection
   *
   * @param card the card to add
   */
  void add(const Card &card) noexcept(false);

  /**
   * @brief Add multiple cards to the collection
   *
   * @param map The map of how many cards per type it is needed to add to the
   * collection
   */
  void add(const std::map<CardType, unsigned int> &map) noexcept(false);

  /**
   * @brief Remove a card of a certain type
   *
   * @param type The type of one card that you want to delete
   */
  void remove(CardType type);

  /**
   * @brief empty the collection
   */
  [[maybe_unused]] void clear() noexcept;
};
}  // namespace cpoker::model::cards
#endif  // COCKROACH_POKER_SRC_MODEL_CARDS_CARDCOLLECTION_HPP_
