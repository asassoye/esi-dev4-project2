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

#ifndef COCKROACH_POKER_SRC_VIEW_WINDOWS_PLAYERPICKERWINDOW_HPP_
#define COCKROACH_POKER_SRC_VIEW_WINDOWS_PLAYERPICKERWINDOW_HPP_

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

namespace cpoker::view::windows {
/**
 * @brief Player Picker Window to choose a receiver in the actual round
 */
class PlayerPickerWindow : public QWidget {
  Q_OBJECT
 private:
  /**
   * @brief Available players
   */
  QVector<QPushButton *> players_;

  /**
   * @brief Actual player name
   */
  QString player_;

  /**
   * @brief Widget Layout
   */
  QVBoxLayout *layout_;

  /**
   * @brief Text with info about the action
   */
  QLabel *text_;

  /**
   * @brief Disable the playing player (to not permit to choose himself)
   * @param name Name of the actual player
   */
  void disablePlayer(const QString &name);

 signals:
  /**
   * @brief Chosen signal when a player is clicked
   * @param name Name of the chosen player
   */
  void choosed(const QString &name);

 public:
  /**
   * @brief Default constructor
   *
   * @param parent parent widget
   */
  explicit PlayerPickerWindow(QWidget *parent = nullptr);

  /**
   * @brief Update the available players
   *
   * @param players Vector of player names
   */
  void players(const QVector<QString> &players);

  /**
   * @brief Update the actual playing player
   * @param player name of the player
   */
  void player(const QString &player);
};
}  // namespace cpoker::view::windows
#endif  // COCKROACH_POKER_SRC_VIEW_WINDOWS_PLAYERPICKERWINDOW_HPP_
