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

#include "view/windows/cardpickerwindow.hpp"

#include <QMapIterator>

namespace cpoker::view::windows {
CardPickerWindow::CardPickerWindow(QWidget *parent)
    : QWidget{parent},
      player_{""},
      layout_{new QVBoxLayout{}},
      text_{new QLabel{this}} {
  setLayout(layout_);
  layout_->addWidget(text_);
  setAttribute(Qt::WA_DeleteOnClose);
  initCards();
}

void CardPickerWindow::cards(
    const QMap<components::CardType, unsigned> &cards) {
  QMapIterator<components::CardType, unsigned> i(cards);
  while (i.hasNext()) {
    i.next();
    QPushButton *card = cards_.value(i.key());
    if (i.value() == 0) {
      card->setDisabled(true);
    } else {
      card->setDisabled(false);
    }
    card->setToolTip(
        QString{"Vous avez %1 cartes \"%2\""}.arg(i.value()).arg(card->text()));
  }
}

void CardPickerWindow::initCards() {
  for (auto &type : components::CardTypes) {
    auto *card =
        new QPushButton{QString::fromStdString(components::name(type)), this};
    cards_.insert(type, card);
    layout_->addWidget(card);
    connect(card, &QPushButton::pressed, this, [this, type]() {
      emit choosed(type);
      hide();
    });
  }
}
void CardPickerWindow::player(const QString &player) {
  player_ = player;
  text_->setText(
      QString{"%1, c'est à vous de jouer.  Les autres, fermez les yeux.. \n "
              "Quelle carte voulez-vous choisir?"}
          .arg(player_));
}
}  // namespace cpoker::view::windows