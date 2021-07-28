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
#include "model/cards/deck.hpp"

using namespace cpoker::model::cards;

TEST_CASE("class Deck") {
  std::map<CardType, unsigned int> basicDeck = {{BAT, 8},
                                                {FLY, 8},
                                                {COCKROACH, 8},
                                                {TOAD, 8},
                                                {RAT, 8},
                                                {SCORPION, 8},
                                                {SPIDER, 8},
                                                {STINKBUG, 8}};

  SECTION("constructor") {
    SECTION("Deck()") {
      auto deck = Deck();
      CHECK(deck.empty() == true);
    }

    SECTION("Deck(std::map<CardType, unsigned int> &)") {
      auto deck = Deck(basicDeck);

      for (auto &e: basicDeck) {
        CHECK(deck.count(e.first) == e.second);
      }
    }
  }

  SECTION("void Deck::add(CardType type)") {
    auto deck = Deck();
    for (auto &e: basicDeck) {
      SECTION("CardType: " + std::to_string(e.first)) {
        deck.add(e.first);

        //CHECK(card.has);
      }
    }
  }

  SECTION("Card Deck::pop()") {
    auto deck = Deck();
    for (auto &e: basicDeck) {
      SECTION("CardType: " + std::to_string(e.first)) {
        deck.add(e.first);

        auto card = deck.pop();
        CHECK(card.type() == e.first);
        CHECK(deck.empty());
      }
    }
  }


}

