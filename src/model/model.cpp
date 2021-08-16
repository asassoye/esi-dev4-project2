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

#include "model.hpp"
namespace cpoker::model {
std::vector<std::string_view> Model::players() const {
  auto result = std::vector<std::string_view>{};
  for (auto &player : players_) {
    result.push_back(player.name());
  }
  return result;
}

std::string Model::playingPlayer() const {
  return std::string{round_.playing().name()};
}
void Model::chooseCard(model::cards::CardType card_type) {
  round_.chooseCard(card_type);
  notify("ROUND_UPDATED");
}
game::RoundStatus Model::roundStatus() const { return round_.status(); }
void Model::chooseValue(model::cards::CardType card_type) {
  round_.chooseValue(card_type);
  notify("ROUND_UPDATED");
}
void Model::chooseReceiver(std::string &name) {
  round_.chooseReceiver(getPlayer(name));
  notify("ROUND_UPDATED");
}
model::cards::CardType Model::announcedCard() const {
  return round_.announced();
}
void Model::accept(bool guess) {
  round_.accept(guess);
  notify("ROUND_UPDATED");
}
void Model::transfer() {
  round_.transfer();
  notify("ROUND_UPDATED");
}

std::vector<std::pair<std::string, std::map<cards::CardType, unsigned>>>
Model::board() const {
  auto players = std::vector<std::pair<std::string, CardMap>>{};

  for (auto &player : players_) {
    std::pair<std::string, CardMap> pair{player.name(), player.table()};
    players.push_back(pair);
  }

  return players;
}

std::map<cards::CardType, unsigned> Model::hand(std::string &name) const {
  for (auto &player : players_) {
    if (player.name() == name) {
      return player.hand();
    }
  }

  return {};
}

std::string Model::looser() const {
  auto &player = round_.looser();
  return std::string{player.name()};
}
}  // namespace cpoker::model