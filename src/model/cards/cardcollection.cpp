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

/**
 * @file deck.cpp
 */
#include "cardcollection.hpp"

#include <algorithm>
#include <chrono>
#include <random>
#include <stdexcept>

namespace cpoker::model::cards {

CardCollection::CardCollection() noexcept(false) : cards_{} {}

CardCollection::CardCollection(
    const std::map<CardType, unsigned int> &cards) noexcept(false)
    : CardCollection() {
  add(cards);
}

bool CardCollection::empty() noexcept { return cards_.empty(); }

bool CardCollection::has(CardType type) const noexcept {
  return has(Card{type});
}

bool CardCollection::has(const Card &c) const noexcept {
  for (auto &card : cards_) {
    if (card == c) return true;
  }

  return false;
}

unsigned CardCollection::count(CardType type) const noexcept {
  unsigned count = 0;

  for (auto &card : cards_) {
    if (card.type() == type) ++count;
  }
  return count;
}

Card CardCollection::pop() noexcept(false) {
  if (empty()) {
    throw std::out_of_range(
        "CardCollection is empty. Impossible to pop a Card.");
  }

  auto card = cards_.back();
  cards_.pop_back();

  return card;
}

Card CardCollection::withdraw(unsigned int index) {
  if (index > cards_.size() - 1) {
    throw std::out_of_range("index of card to withdraw is out of range.");
  }

  cards::Card card = cards_[index];
  cards_.erase(cards_.begin() + index);

  return card;
}

void CardCollection::add(CardType type) noexcept(false) { add(Card{type}); }

void CardCollection::add(const Card &card) noexcept(false) {
  cards_.emplace_back(card);
}

void CardCollection::add(
    const std::map<CardType, unsigned int> &cards) noexcept(false) {
  for (auto &card : cards) {
    for (unsigned i = 0; i < card.second; ++i) {
      add(card.first);
    }
  }
}

void CardCollection::clear() noexcept { cards_.clear(); }

void CardCollection::remove(CardType type) {
  if (empty()) {
    throw std::out_of_range(
        "CardCollection is empty. Impossible to pop a Card.");
  }

  for (int i = 0; i < cards_.size(); ++i) {
    if (cards_[i].type() == type) {
      cards_.erase(cards_.begin() + i);
      return;
    }
  }
}

}  // namespace cpoker::model::cards
