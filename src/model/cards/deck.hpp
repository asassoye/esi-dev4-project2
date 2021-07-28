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

//
// Created by Andrew Sassoye on 14/07/2021.
//

#ifndef COCKROACH_POKER_SRC_MODEL_CARDS_DECK_HPP_
#define COCKROACH_POKER_SRC_MODEL_CARDS_DECK_HPP_

#include <vector>
#include <array>
#include <map>
#include <random>
#include "model/cards/card.hpp"

namespace cpoker::model::cards {
/**
 * @brief Deck class
 */
class Deck {
 protected:
  std::vector<Card> cards_;

  std::default_random_engine re_;

 public:
  Deck() noexcept(false);

  Deck(std::map<CardType, unsigned int> &) noexcept(false);

  bool empty() noexcept;

  bool has(CardType) noexcept;

  unsigned count(CardType) noexcept;

  Card pop() noexcept(false);

  void shuffel() noexcept;

  void add(CardType) noexcept(false);

  void add(const std::map<CardType, unsigned int> &) noexcept(false);

  void clear() noexcept;
};
}
#endif //COCKROACH_POKER_SRC_MODEL_CARDS_DECK_HPP_
