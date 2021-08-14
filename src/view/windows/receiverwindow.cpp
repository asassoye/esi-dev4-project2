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

#include "receiverwindow.hpp"

namespace cpoker::view::windows {

ReceiverWindow::ReceiverWindow(QWidget *parent)
    : QWidget{parent},
      layout_{new QVBoxLayout{}},
      player_{},
      card_{},
      text_{new QLabel{this}},
      truth_{new QPushButton{this}},
      lie_{new QPushButton{this}},
      transfer_{new QPushButton{this}} {
  setLayout(layout_);
  setAttribute(Qt::WA_DeleteOnClose);

  layout_->addWidget(text_);
  layout_->addWidget(truth_);
  layout_->addWidget(lie_);
  layout_->addWidget(transfer_);

  transfer_->setText("Je transfère la carte");

  connect(truth_, &QPushButton::pressed, this, [this]() {
    emit accept(true);
    hide();
  });
  connect(lie_, &QPushButton::pressed, this, [this]() {
    emit accept(false);
    hide();
  });
  connect(transfer_, &QPushButton::pressed, this, [this]() {
    emit transfer();
    hide();
  });
}

void ReceiverWindow::update(const QString &player, const QString &card) {
  text_->setText(
      QString{"%1, le joueur annonce \"%2!\".\n "
              "Que décidez vous de faire?"}
          .arg(player, card));

  truth_->setText(QString{"%1? C'est vrai!"}.arg(card));
  lie_->setText(QString{"%2...? C'est un mensonge!"}.arg(card));
}
}  // namespace cpoker::view::windows