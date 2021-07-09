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

#ifndef COCKROACH_POKER_SRC_MODEL_CARDS_CARD_HPP_
#define COCKROACH_POKER_SRC_MODEL_CARDS_CARD_HPP_

#include "cardtype.hpp"

namespace cpoker::model::cards {
class Card {
 protected:
  const CardType type_;

 public:
  constexpr explicit inline Card(CardType) noexcept;

  constexpr explicit inline Card(Card &&) noexcept;

  constexpr explicit inline Card(const Card &) noexcept;

  constexpr inline CardType type() noexcept;

  constexpr inline std::string_view name() noexcept;

  friend bool operator==(const Card &, const Card &);
};

// ***********************************************************************
// --- FORWARD DECLARATIONS
// ***********************************************************************
inline bool operator==(const Card &, const Card &);

inline bool operator!=(const Card &, const Card &);

// ***********************************************************************
// --- INLINE DEFINITION
// **********************************************************************

}

#endif //COCKROACH_POKER_SRC_MODEL_CARDS_CARD_HPP_
