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

#include <QVBoxLayout>
#include <QPushButton>
#include <map>
#include <utility>
#include <string_view>
#include "startwindow.hpp"

namespace cpoker::view::windows {

StartWindow::StartWindow(QWidget *parent) : QWidget(parent) {
  layout_ = new QVBoxLayout{this};
  this->setLayout(layout_);

  auto *plus_min_layout = new QHBoxLayout{};
  layout_->addLayout(plus_min_layout);

  plus_ = new QPushButton("+", this);
  min_ = new QPushButton("-", this);
  plus_min_layout->addWidget(plus_);
  plus_min_layout->addWidget(min_);

  confirm_ = new QPushButton{"Nouvelle Partie", this};
  connect(confirm_, &QPushButton::pressed, this, [this]() {
    emit confirmed();
  });
  layout_->addWidget(confirm_);

  addPlayer();
  addPlayer();

  connect(plus_, &QPushButton::clicked, this, &StartWindow::addPlayer);
  connect(min_, &QPushButton::clicked, this, &StartWindow::removePlayer);
  setAttribute(Qt::WA_DeleteOnClose);
}

void StartWindow::addPlayer() {
  if (players_.size() == 6) {
    return;
  }
  auto *player = new widgets::PlayerInput{static_cast<unsigned>(players_.size() + 1), this};
  players_.push_back(player);
  layout_->removeWidget(confirm_);
  layout_->addWidget(player);
  layout_->addWidget(confirm_);
}

void StartWindow::removePlayer() {
  if (players_.size() <= 2) {
    return;
  }
  auto *player = players_.last();
  layout_->removeWidget(player);
  players_.pop_back();
  delete player;
}
std::map<std::string, unsigned> StartWindow::players() const {
  std::map<std::string, unsigned> result{};
  for (auto *player : players_) {
    result.insert(std::pair<std::string, unsigned>{
        player->name(),
        player->age()});
  }
  return result;
}
}