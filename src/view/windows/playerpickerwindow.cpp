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

#include "playerpickerwindow.hpp"

#include <stdexcept>

namespace cpoker::view::windows {
PlayerPickerWindow::PlayerPickerWindow(QWidget *parent)
    : QWidget(parent),
      players_{},
      layout_{new QVBoxLayout{}},
      text_{new QLabel{this}} {
  setLayout(layout_);
  layout_->addWidget(text_);
  setAttribute(Qt::WA_DeleteOnClose);
}

void PlayerPickerWindow::players(const QVector<QString> &players) {
  if (!players_.empty()) {
    throw std::logic_error("Players are already set");
  }

  for (auto &player : players) {
    auto *playerButton = new QPushButton{player, this};
    playerButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    players_.push_back(playerButton);
    layout_->addWidget(playerButton);

    connect(playerButton, &QPushButton::pressed, this, [this, player]() {
      emit choosed(player);
      hide();
    });
  }
}

void PlayerPickerWindow::player(const QString &player) {
  player_ = player;
  text_->setText(
      QString{"%1, a qui voulez-vous envoyer la carte?"}.arg(player_));
  disablePlayer(player);
}

void PlayerPickerWindow::disablePlayer(const QString &name) {
  for (auto player : players_) {
    if (player->text() == name) {
      player->hide();
    } else {
      player->show();
    }
  }
}
}  // namespace cpoker::view::windows