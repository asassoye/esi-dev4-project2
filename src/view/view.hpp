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

#ifndef COCKROACH_POKER_SRC_VIEW_VIEW_HPP_
#define COCKROACH_POKER_SRC_VIEW_VIEW_HPP_

#include <QWidget>
#include <map>
#include <string>

#include "model/game/gamestatus.hpp"
#include "utils/observer.hpp"
#include "view/components/card.hpp"
#include "view/windows/boardwindow.hpp"
#include "view/windows/playerpickerwindow.hpp"
#include "view/windows/startwindow.hpp"

namespace cpoker::view {
class View : public QWidget, public utils::Observer {
  Q_OBJECT
 protected:
  model::game::GameStatus status_;
  windows::StartWindow *startWindow_;
  windows::BoardWindow *boardWindow_;
  windows::PlayerPickerWindow *player_picker_window_;
  std::function<void(std::map<std::string, unsigned> &)> *startAction_;
  [[maybe_unused]] void status(model::game::GameStatus status);

 public:
  View();
  void update(const std::string_view &propertyName,
              const utils::Observable *observable) override;
  void showBoard(const QVector<QString> &players);
  void connectStartAction(
      std::function<void(std::map<std::string, unsigned> &)> *startAction);
};
}  // namespace cpoker::view
#endif  // COCKROACH_POKER_SRC_VIEW_VIEW_HPP_
