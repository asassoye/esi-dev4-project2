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

#include "game.hpp"

#include <stdexcept>

namespace cpoker::model::game {
const std::map<cards::CardType, unsigned int> Game::basicDeckMap = {
    {cards::BAT, 8},    {cards::FLY, 8},     {cards::COCKROACH, 8},
    {cards::TOAD, 8},   {cards::RAT, 8},     {cards::SCORPION, 8},
    {cards::SPIDER, 8}, {cards::STINKBUG, 8}};

Game::Game() : status_{NOT_STARTED} {}

void Game::addPlayer(const std::string_view &name, unsigned int age) {
  if (status_ != NOT_STARTED) {
    throw std::domain_error(
        "You cannot addHand players when the game is started..");
  }

  if (players_.size() > MAX_PLAYERS) {
    throw std::out_of_range("You reached the maximum of players.");
  }

  players_.emplace_back(name, age);

  notify("PLAYER_ADDED");
}

void Game::removePlayer(unsigned int index) noexcept(false) {
  if (index > players_.size() - 1) {
    throw std::out_of_range("The player you try to remove doesn't exist..");
  }

  players_.erase(players_.begin() + index);
  notify("PLAYER_REMOVED");
}

void Game::distributeCards() {
  if (status_ != NOT_STARTED) {
    throw std::logic_error("It's not the moment to distribute cards");
  }

  if (players_.size() < MIN_PLAYERS) {
    throw std::domain_error("The minimal required players is 3");
  }

  cards::Deck deck{basicDeckMap};
  deck.shuffle();

  unsigned count = 0;
  while (!deck.empty()) {
    auto card = deck.pop();
    players_[count++ % players_.size()].addHand(card);
  }

  status(CARDS_DISTRIBUTED);
}

void Game::start() noexcept(false) {
  if (status_ == NOT_STARTED) {
    distributeCards();
    status(CARDS_DISTRIBUTED);
  }

  if (status_ != CARDS_DISTRIBUTED) {
    throw std::logic_error("The game is already started");
  }
  status(STARTED);
  round_.start(youngestPlayer());
  notify("ROUND_UPDATED");
}

Player &Game::youngestPlayer() noexcept(false) {
  Player *youngest = &players_.at(0);
  for (auto &player : players_) {
    if (player.age() < youngest->age()) {
      youngest = &player;
    }
  }

  return *youngest;
}

GameStatus Game::status() const { return status_; }

void Game::status(GameStatus status) {
  status_ = status;

  notify("STATUS_UPDATED");
}

void Game::addPlayers(const std::map<std::string, unsigned> &players) {
  for (auto &player : players) {
    addPlayer(player.first, player.second);
  }
}

Player &Game::getPlayer(const std::string &name) const {
  for (const auto &i : players_) {
    auto &player = const_cast<Player &>(i);
    if (player.name() == name) {
      return player;
    }
  }
  throw std::logic_error("no player with this name");
}

}  // namespace cpoker::model::game