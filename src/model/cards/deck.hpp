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

#ifndef COCKROACH_POKER_SRC_MODEL_CARDS_DECK_HPP_
#define COCKROACH_POKER_SRC_MODEL_CARDS_DECK_HPP_

#include <chrono>
#include <model/cards/cardcollection.hpp>

namespace cpoker::model::cards {
/**
 * @brief The Deck class is an extension of CardCollection to permit to shuffle
 * the cards
 */
class Deck : public CardCollection {
 protected:
  /**
   * @brief Random engine to shuffle the cards
   */
  std::default_random_engine re_{static_cast<unsigned>(
      std::chrono::system_clock::now().time_since_epoch().count())};

 public:
  /**
   * @brief default constructor of a deck
   */
  Deck() noexcept(false);

  /**
   * @brief Constructor to immediately add the required cards
   *
   * @param map the map that gives the number of cards to add by CardType
   */
  explicit Deck(const std::map<CardType, unsigned int> &map) noexcept(false);

  /**
   * @brief Shuffle the deck
   */
  void shuffle() noexcept;
};
}  // namespace cpoker::model::cards

#endif  // COCKROACH_POKER_SRC_MODEL_CARDS_DECK_HPP_
