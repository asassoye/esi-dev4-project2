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

#ifndef COCKROACH_POKER_SRC_VIEW_WIDGETS_PLAYERINPUT_HPP_
#define COCKROACH_POKER_SRC_VIEW_WIDGETS_PLAYERINPUT_HPP_

#include <QHBoxLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QWidget>
#include <string_view>

namespace cpoker::view::widgets {
class PlayerInput : public QWidget {
  Q_OBJECT
 protected:
  QHBoxLayout *layout_;
  QLineEdit *name_;
  QSpinBox *age_;

 public:
  explicit PlayerInput(QWidget *parent = nullptr);
  explicit PlayerInput(unsigned id, QWidget *parent = nullptr);
  [[nodiscard]] std::string name() const;
  [[nodiscard]] unsigned age() const;
};
}  // namespace cpoker::view::widgets

#endif  // COCKROACH_POKER_SRC_VIEW_WIDGETS_PLAYERINPUT_HPP_