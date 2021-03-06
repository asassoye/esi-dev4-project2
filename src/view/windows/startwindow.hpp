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

#ifndef COCKROACH_POKER_SRC_VIEW_WINDOWS_STARTWINDOW_HPP_
#define COCKROACH_POKER_SRC_VIEW_WINDOWS_STARTWINDOW_HPP_

#include <QMap>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVector>
#include <QWidget>
#include <map>
#include <string>
#include <string_view>

#include "view/widgets/playerinput.hpp"

namespace cpoker::view::windows {
/**
 * @brief The start window where is asked for player names and ages
 */
class StartWindow : public QWidget {
  Q_OBJECT
 protected:
  /**
   * @brief The layout of the widget
   */
  QVBoxLayout *layout_;

  /**
   * @brief The players inputs (2 to 6)
   */
  QVector<widgets::PlayerInput *> players_;

  /**
   * @brief add a new player button
   */
  QPushButton *plus_;

  /**
   * @brief Removes a player button
   */
  QPushButton *min_;

  /**
   * @brief confirm and begin the game button
   */
  QPushButton *confirm_;

 signals:
  /**
   * @brief the confirmed signal
   */
  void confirmed();

 protected slots:
  /**
   * @brief slot to add a player in the list
   */
  void addPlayer();

  /**
   * @brief slot to remove the last player in the list
   */
  void removePlayer();

 public:
  /**
   * @brief default constructor
   *
   * @param parent parent widget
   */
  explicit StartWindow(QWidget *parent = nullptr);

  /**
   * @brief get all players names and ages
   *
   * @return player names and ages in a map
   */
  [[nodiscard]] std::map<std::string, unsigned> players() const;
};
}  // namespace cpoker::view::windows

#endif  // COCKROACH_POKER_SRC_VIEW_WINDOWS_STARTWINDOW_HPP_
