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
      round_status_{model::game::INIT},
      boardWindow_{nullptr},
      player_picker_window_{new windows::PlayerPickerWindow{}},
      card_picker_window_{new windows::CardPickerWindow{}},
      value_picker_window_{new windows::ValuePickerWindow{}},
      receiver_window_{new windows::ReceiverWindow{}},
      startAction_{nullptr},
      chooseCardAction_{nullptr},
      chooseValueAction_{nullptr},
      chooseReceiverAction_{nullptr},
      acceptAction_{nullptr},
      transferAction_{nullptr} {
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
    }
  }

  if (propertyName == "ROUND_UPDATED") {
    round_status_ = model->roundStatus();
    auto board = model->board();
    updateBoard(board);

    if (round_status_ == model::game::CHOOSING_RECEIVER) {
      player_picker_window_->player(
          QString::fromStdString(model->playingPlayer()));
      player_picker_window_->show();
    }

    if (round_status_ == model::game::CHOOSING_CARD) {
      card_picker_window_->player(
          QString::fromStdString(model->playingPlayer()));
      card_picker_window_->show();
    }

    if (round_status_ == model::game::CHOOSING_VALUE) {
      value_picker_window_->player(
          QString::fromStdString(model->playingPlayer()));
      value_picker_window_->show();
    }

    if (round_status_ == model::game::SEND) {
      receiver_window_->update(
          QString::fromStdString(model->playingPlayer()),
          QString::fromStdString(components::name(
              static_cast<components::CardType>(model->announcedCard()))));
      receiver_window_->show();
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

void View::connectChooseCardAction(
    std::function<void(model::cards::CardType)> *chooseCardAction) {
  chooseCardAction_ = chooseCardAction;
  connect(
      card_picker_window_, &windows::CardPickerWindow::choosed, this,
      [this](components::CardType card_type) {
        (*chooseCardAction_)(static_cast<model::cards::CardType>(card_type));
      });
}

void View::connectChooseValueAction(
    std::function<void(model::cards::CardType)> *chooseCardAction) {
  chooseValueAction_ = chooseCardAction;
  connect(
      value_picker_window_, &windows::ValuePickerWindow::choosed, this,
      [this](components::CardType card_type) {
        (*chooseValueAction_)(static_cast<model::cards::CardType>(card_type));
      });
}
void View::connectReceiverAction(
    std::function<void(std::string)> *chooseReceiverAction) {
  chooseReceiverAction_ = chooseReceiverAction;
  connect(player_picker_window_, &windows::PlayerPickerWindow::choosed, this,
          [this](const QString &name) {
            (*chooseReceiverAction_)(name.toStdString());
          });
}
void View::connectAcceptActon(std::function<void(bool)> *acceptAction) {
  acceptAction_ = acceptAction;
  connect(receiver_window_, &windows::ReceiverWindow::accept, this,
          [this](bool guess) { (*acceptAction_)(guess); });
}

void View::connectTransferAction(std::function<void()> *transferAction) {
  transferAction_ = transferAction;
  connect(receiver_window_, &windows::ReceiverWindow::transfer, this,
          [this]() { (*transferAction_)(); });
}
void View::updateBoard(
    const std::vector<
        std::pair<std::string, std::map<model::cards::CardType, unsigned int>>>
        &players) {
  for (auto &player : players) {
    QString name = QString::fromStdString(player.first);
    QMap<components::CardType, unsigned> map{};
    for (auto item : player.second) {
      map.insert(static_cast<components::CardType>(item.first), item.second);
    }

    boardWindow_->update(name, map);
  }
}

}  // namespace cpoker::view
