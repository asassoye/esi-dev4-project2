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

#ifndef COCKROACH_POKER_SRC_VIEW_WINDOWS_RECEIVERWINDOW_HPP_
#define COCKROACH_POKER_SRC_VIEW_WINDOWS_RECEIVERWINDOW_HPP_
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

namespace cpoker::view::windows {
/**
 * @brief Receiver window is the window where the receiver must choose between
 * accept the card or transfer it
 */
class ReceiverWindow : public QWidget {
  Q_OBJECT
 private:
  /**
   * @brief The layout of the widget
   */
  QVBoxLayout *layout_;

  /**
   * @brief The player name
   */
  [[maybe_unused]] QString player_;

  /**
   * @brief The name of the card that is received
   */
  [[maybe_unused]] QString card_;

  /**
   * @brief The Text label for infos about the action
   */
  QLabel *text_;

  /**
   * @brief Button to declare that the card is the truth
   */
  QPushButton *truth_;

  /**
   * @brief Button to declare that the card is a lie
   */
  QPushButton *lie_;

  /**
   * @brief The button to tranfer the card
   */
  QPushButton *transfer_;

 signals:
  /**
   * @brief Signal to accept the card
   *
   * @param guess The guess of the truth
   */
  void accept(bool guess);

  /**
   * @brief The signal to transfer the card
   */
  void transfer();

 public:
  /**
   * @brief The Receiver Window default constructor
   *
   * @param parent the parent widget
   */
  explicit ReceiverWindow(QWidget *parent = nullptr);

  /**
   * @brief Update the actual player and received card
   *
   * @param player The actual playing player
   * @param card The received card
   */
  void update(const QString &player, const QString &card);
};
}  // namespace cpoker::view::windows
#endif  // COCKROACH_POKER_SRC_VIEW_WINDOWS_RECEIVERWINDOW_HPP_
