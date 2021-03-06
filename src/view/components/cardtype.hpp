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
 * @file cardtype.hpp
 */
#ifndef COCKROACH_POKER_SRC_VIEW_CARDTYPE_HPP_
#define COCKROACH_POKER_SRC_VIEW_CARDTYPE_HPP_

#include <array>
#include <string>

namespace cpoker::view::components {
/**
 * @brief CardType enum
 */
enum CardType {
  /**
   * @brief Chauve-souris
   */
  BAT,
  /**
   * @brief Mouche
   */
  FLY,
  /**
   * @brief Cafard
   */
  COCKROACH,
  /**
   * @brief Crapaud
   */
  TOAD,
  /**
   * @brief Rat
   */
  RAT,
  /**
   * @brief Scorpion
   */
  SCORPION,
  /**
   * @brief Araignée
   */
  SPIDER,
  /**
   * @brief Punaise
   */
  STINKBUG
};

/**
 * @brief Static function that returns all the possible types of CardType
 */
[[maybe_unused]] static constexpr std::array<CardType, 8> CardTypes = {
    BAT, FLY, COCKROACH, TOAD, RAT, SCORPION, SPIDER, STINKBUG};

/**
 * @brief static function that return a string for a CardType in French
 * @param card_type The type to get the name
 * @return The name of the card in french
 */
[[maybe_unused]] static std::string name(CardType card_type) {
  switch (card_type) {
    case BAT:
      return "Chauve-souris";
    case FLY:
      return "Mouche";
    case COCKROACH:
      return "Cafard";
    case TOAD:
      return "Crapaud";
    case RAT:
      return "Rat";
    case SCORPION:
      return "Scorpion";
    case SPIDER:
      return "Araignée";
    case STINKBUG:
    default:
      return "Punaise";
  }
}

}  // namespace cpoker::view::components

#endif  // COCKROACH_POKER_SRC_VIEW_CARDTYPE_HPP_
