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
// Created by asassoye on 28/07/21.
//

#ifndef COCKROACH_POKER_SRC_MODEL_GAME_PLAYER_HPP_
#define COCKROACH_POKER_SRC_MODEL_GAME_PLAYER_HPP_

#include <vector>
#include "model/cards/card.hpp"
#include "model/cards/cardcollection.hpp"

namespace cpoker::model::game {
class Player {
 protected:
  constexpr static unsigned MIN_AGE = 8;

  std::string_view name_;

  unsigned age_;

  cards::CardCollection hand_;

  cards::CardCollection table_;

 public:
  Player(std::string_view name, unsigned age) noexcept(false);

  std::string_view &name() noexcept;

  void name(std::string_view &&new_name) noexcept;

  unsigned age() const noexcept;

  void age(unsigned new_age) noexcept;

  void add(const cards::Card &card);

  cards::Card withdraw(unsigned index);

};
}

#endif //COCKROACH_POKER_SRC_MODEL_GAME_PLAYER_HPP_
