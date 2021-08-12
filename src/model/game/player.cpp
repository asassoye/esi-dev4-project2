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

#include "player.hpp"

#include <stdexcept>

namespace cpoker::model::game {

Player::Player(std::string_view name, unsigned int age) noexcept(false)
    : name_(name), age_(age) {
  if (age < MIN_AGE) {
    throw std::invalid_argument("You are too young..");
  }
}

std::string_view Player::name() const noexcept { return name_; }

void Player::name(std::string_view &&new_name) noexcept { name_ = new_name; }

unsigned Player::age() const noexcept { return age_; }

void Player::age(unsigned int new_age) noexcept { age_ = new_age; }

void Player::addHand(const cards::Card &card) { hand_.add(card); }

bool Player::hasCardsLeft() noexcept { return !hand_.empty(); }

void Player::addTable(const cards::Card &card) { table_.add(card); }

unsigned Player::countTable(cards::CardType type) { return table_.count(type); }

cards::Card Player::withdraw(unsigned int index) {
  return hand_.withdraw(index);
}
}  // namespace cpoker::model::game