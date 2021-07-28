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


/**
 * @file deck.cpp
 */
#include <stdexcept>
#include <random>
#include <algorithm>
#include <chrono>
#include "deck.hpp"

namespace cpoker::model::cards {

Deck::Deck() noexcept(false):
    cards_{},
    re_{static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count())} {}

Deck::Deck(std::map<CardType, unsigned int> &cards) noexcept(false): Deck() {
  add(cards);
}

bool Deck::empty() noexcept {
  return cards_.empty();
}

bool Deck::has(CardType type) noexcept {
  for (auto &card : cards_) {
    if (card.type() == type)
      return true;
  }

  return false;
}

unsigned Deck::count(CardType type) noexcept {
  unsigned count = 0;

  for (auto &card: cards_) {
    if (card.type() == type)
      ++count;
  }
  return count;
}

Card Deck::pop() noexcept(false) {
  if (empty()) {
    throw std::out_of_range("Deck is empty. Impossible to pop a Card.");
  }

  auto card = cards_.back();
  cards_.pop_back();

  return card;
}

void Deck::shuffel() noexcept {
  std::shuffle(cards_.begin(), cards_.end(), re_);
}

void Deck::add(CardType type) noexcept(false) {
  cards_.emplace_back(Card{type});
}

void Deck::add(const std::map<CardType, unsigned int> &cards) noexcept(false) {
  for (auto &card : cards) {
    for (unsigned i = 0; i < card.second; ++i) {
      add(card.first);
    }
  }
}

void Deck::clear() noexcept {
  cards_.clear();
}
}
