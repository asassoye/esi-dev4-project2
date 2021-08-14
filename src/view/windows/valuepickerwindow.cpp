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

#include "valuepickerwindow.hpp"

namespace cpoker::view::windows {

ValuePickerWindow::ValuePickerWindow(QWidget *parent)
    : QWidget{parent},
      layout_{new QVBoxLayout{this}},
      player_{},
      text_{new QLabel{this}} {
  setLayout(layout_);
  setAttribute(Qt::WA_DeleteOnClose);
  layout_->addWidget(text_);
  initCards();
}
void ValuePickerWindow::initCards() {
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
void ValuePickerWindow::player(const QString &player) {
  player_ = player;
  text_->setText(
      QString{"%1, quelle carte voulez vous annoncer?"}.arg(player_));
}
}  // namespace cpoker::view::windows