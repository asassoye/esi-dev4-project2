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
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "playerinput.hpp"

namespace cpoker::view::widgets {
PlayerInput::PlayerInput(QWidget *parent) : PlayerInput(0, parent) {}

PlayerInput::PlayerInput(unsigned int id, QWidget *parent) : QWidget(parent) {
  layout_ = new QHBoxLayout{this};
  this->setLayout(layout_);

  name_ = new QLineEdit{this};
  name_->setText(QString{"Player%1"}.arg(id));
  name_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  layout_->addWidget(name_);

  age_ = new QSpinBox{this};
  age_->setSuffix(" ans");
  age_->setRange(8, 99);
  age_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  layout_->addWidget(age_);
}

std::string PlayerInput::name() const { return name_->text().toStdString(); }

unsigned PlayerInput::age() const { return age_->value(); }
}  // namespace cpoker::view::widgets
