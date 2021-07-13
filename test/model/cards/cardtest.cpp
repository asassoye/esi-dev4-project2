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

#include <map>
#include "catch2/catch.hpp"
#include "model/cards/card.hpp"

using namespace cpoker::model::cards;

TEST_CASE("class Card") {
  std::map<CardType, std::string> types = {
      {BAT, "BAT"},
      {FLY, "FLY"},
      {COCKROACH, "COCKROACH"},
      {TOAD, "TOAD"},
      {RAT, "RAT"},
      {SCORPION, "SCORPION"},
      {SPIDER, "SPIDER"},
      {STINKBUG, "STINKBUG"},
  };

  SECTION("constructors") {
    SECTION("Card::Card(CardType card_type)") {
      for (auto &type : types) {
        SECTION(type.second) {
          auto card = Card{type.first};

          REQUIRE(card.type() == type.first);
        }
      }
    }

    SECTION("Card::Card(Card && card)") {
      for (auto &type : types) {
        SECTION(type.second) {
          auto card = Card{Card{type.first}};

          REQUIRE(card.type() == type.first);
        }
      }
    }

    SECTION("Card::Card(const Card & card)") {
      for (auto &type : types) {
        SECTION(type.second) {
          const Card a = Card{Card{type.first}};
          auto card = Card{a};

          REQUIRE(card.type() == type.first);
        }
      }
    }

  }

  SECTION("methods") {
    SECTION("std::string_view Card::name()") {
      for (auto &type : types) {
        SECTION(type.second) {
          auto card = Card{type.first};

          REQUIRE(card.name() == type.second);
        }
      }
    }
  }

  SECTION("operators") {
    SECTION("operator=(const Card &card)") {
      auto card = Card(COCKROACH);

      for (auto &type : types) {
        SECTION(type.second) {
          card = Card{type.first};

          REQUIRE(card.type() == type.first);
        }
      }
    }

    SECTION("operator==(const Card &a, const Card &b)") {
      for (auto &type : types) {
        SECTION(type.second + " == " + type.second) {
          auto card1 = Card{type.first};
          auto card2 = Card{type.first};

          REQUIRE(card1 == card2);
        }
      }
    }

    SECTION("operator!=(const Card &a, const Card &b)") {
      for (auto &type1 : types) {
        for (auto &type2 : types) {
          if (type1 != type2) {
            SECTION(type1.second + " != " + type2.second) {
              auto card1 = Card{type1.first};
              auto card2 = Card{type2.first};

              REQUIRE(card1 != card2);
            }
          }
        }
      }
    }
  }
}


