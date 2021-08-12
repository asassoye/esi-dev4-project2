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

#ifndef COCKROACH_POKER_SRC_VIEW_WINDOWS_STARTWINDOW_HPP_
#define COCKROACH_POKER_SRC_VIEW_WINDOWS_STARTWINDOW_HPP_

#include <QWidget>
#include <QVector>
#include <QMap>
#include <string>
#include <string_view>
#include <map>
#include <QVBoxLayout>
#include <QPushButton>
#include "view/widgets/playerinput.hpp"

namespace cpoker::view::windows {
class StartWindow : public QWidget {
 Q_OBJECT
 protected:
  QVBoxLayout *layout_;
  QVector<widgets::PlayerInput *> players_;
  QPushButton *confirm_;

 signals:
  void confirmed();

 protected slots:
  void addPlayer();
  void removePlayer();
 public:
  explicit StartWindow(QWidget *parent = nullptr);
  std::map<std::string, unsigned> players() const;
};
}

#endif //COCKROACH_POKER_SRC_VIEW_WINDOWS_STARTWINDOW_HPP_
