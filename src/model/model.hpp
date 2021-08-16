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

#ifndef COCKROACH_POKER_SRC_MODEL_MODEL_HPP_
#define COCKROACH_POKER_SRC_MODEL_MODEL_HPP_

#include <map>
#include <string>
#include <vector>

#include "model/game/game.hpp"

namespace cpoker::model {
typedef std::map<cards::CardType, unsigned> CardMap;

class Model : public game::Game {
 public:
  [[nodiscard]] std::vector<std::string_view> players() const;
  [[nodiscard]] std::string playingPlayer() const;
  void chooseCard(model::cards::CardType card_type);
  void chooseValue(model::cards::CardType card_type);
  void chooseReceiver(std::string &name);
  void accept(bool guess);
  void transfer();
  [[nodiscard]] game::RoundStatus roundStatus() const;
  [[nodiscard]] model::cards::CardType announcedCard() const;
  [[nodiscard]] std::vector<
      std::pair<std::string, std::map<cards::CardType, unsigned>>>
  board() const;

  std::map<cards::CardType, unsigned> hand(std::string &name) const;
};
}  // namespace cpoker::model

#endif
