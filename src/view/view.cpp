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

#include "view.hpp"

#include <QApplication>
#include <QDebug>
#include <memory>
#include <string>

#include "model/model.hpp"

namespace cpoker::view {

View::View()
    : status_{model::game::NOT_STARTED},
      boardWindow_{nullptr},
      player_picker_window_{new windows::PlayerPickerWindow{}},
      startAction_{nullptr} {
  setWindowTitle("Cockroach Poker");

  startWindow_ = new windows::StartWindow{};
  startWindow_->show();
  connect(startWindow_, &QWidget::destroyed, this, &QWidget::close);
}

void View::update(const std::string_view &propertyName,
                  const utils::Observable *observable) {
  auto model = dynamic_cast<const model::Model *>(observable);

  if (propertyName == "STATUS_UPDATED") {
    status_ = model->status();

    if (status_ == model::game::STARTED) {
      QVector<QString> players{};
      for (auto &player : model->players()) {
        players.push_back(QString::fromStdString(std::string{player}));
      }

      showBoard(players);

      player_picker_window_->players(players);
      player_picker_window_->player(
          QString::fromStdString(model->playingPlayer()));
      player_picker_window_->show();
    }
  }
}

void View::showBoard(const QVector<QString> &players) {
  boardWindow_ = new windows::BoardWindow{players};
  boardWindow_->show();
}

void View::connectStartAction(
    std::function<void(std::map<std::string, unsigned> &)> *startAction) {
  startAction_ = startAction;
  connect(startWindow_, &windows::StartWindow::confirmed, this, [this]() {
    auto players = startWindow_->players();
    (*startAction_)(players);
    startWindow_->hide();
  });
}

[[maybe_unused]] void View::status(model::game::GameStatus status) {
  status_ = status;
}

}  // namespace cpoker::view
