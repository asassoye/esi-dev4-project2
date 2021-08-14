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
 * @file card.hpp
 */
#ifndef COCKROACH_POKER_SRC_MODEL_CARDS_CARD_HPP_
#define COCKROACH_POKER_SRC_MODEL_CARDS_CARD_HPP_

#include <string_view>

#include "cardtype.hpp"

namespace cpoker::model::cards {
/**
 * @brief Card class
 */
class Card {
 protected:
  /**
   * @brief Type of the card
   */
  CardType type_;

 public:
  /**
   * @brief Card constructor by CardType
   *
   * @param card_type Type of the card
   */
  constexpr explicit inline Card(CardType) noexcept;

  /**
   * @brief Card constructor by lvalue reference
   *
   * @param card Initial card
   */
  constexpr inline Card(Card &&) noexcept;

  /**
   * @brief Card constructor by copy
   */
  constexpr inline Card(const Card &) noexcept;

  /**
   * @brief type_ getter
   *
   * @return Type of the card
   */
  [[nodiscard]] constexpr inline CardType type() const noexcept;

  /**
   * @brief name of the card cardType
   *
   * @return Name of the Card
   */
  [[nodiscard]] constexpr inline std::string_view name() const noexcept;

  /**
   * @brief re-affectation operator
   *
   * @return new reference
   */
  Card &operator=(const Card &) = default;

  friend bool operator==(const Card &, const Card &);
};

// ***********************************************************************
// --- FORWARD DECLARATIONS
// ***********************************************************************
/**
 * @brief Compares two cards
 *
 * @return true if cards are identical
 * @return false if cards are different
 */
inline bool operator==(const Card &, const Card &);

/**
 * @brief Compares two cards
 *
 * @return false if cards are identical
 * @return true if cards are different
 */
inline bool operator!=(const Card &, const Card &);

// ***********************************************************************
// --- INLINE DEFINITION
// **********************************************************************

constexpr Card::Card(CardType card_type) noexcept : type_{card_type} {}

constexpr Card::Card(Card &&card) noexcept : type_{card.type_} {}

constexpr Card::Card(const Card &card) noexcept = default;

constexpr CardType Card::type() const noexcept { return type_; }

constexpr std::string_view Card::name() const noexcept {
  switch (type_) {
    case BAT:
      return "BAT";
    case FLY:
      return "FLY";
    case TOAD:
      return "TOAD";
    case RAT:
      return "RAT";
    case SCORPION:
      return "SCORPION";
    case SPIDER:
      return "SPIDER";
    case STINKBUG:
      return "STINKBUG";
    case COCKROACH:
    default:
      return "COCKROACH";
  }
}

bool operator==(const Card &a, const Card &b) { return a.type_ == b.type_; }

bool operator!=(const Card &a, const Card &b) { return !(a == b); }
}  // namespace cpoker::model::cards

#endif  // COCKROACH_POKER_SRC_MODEL_CARDS_CARD_HPP_
