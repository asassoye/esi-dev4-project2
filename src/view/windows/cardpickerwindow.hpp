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

#ifndef COCKROACH_POKER_SRC_VIEW_WINDOWS_CARDPICKERWINDOW_HPP_
#define COCKROACH_POKER_SRC_VIEW_WINDOWS_CARDPICKERWINDOW_HPP_

#include <QLabel>
#include <QMap>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "view/components/cardtype.hpp"

namespace cpoker::view::windows {
/**
 * @brief CardPickerWindow class
 */
class CardPickerWindow : public QWidget {
  Q_OBJECT
 private:
  /**
   * @brief Cards buttons
   */
  QMap<components::CardType, QPushButton *> cards_;

  /**
   * @brief Actual player name
   */
  QString player_;

  /**
   * @brief widget Layout
   */
  QVBoxLayout *layout_;

  /**
   * @brief Text to display with info about the action to take
   */
  QLabel *text_;

  /**
   * @brief init all the cards of the widget
   */
  void initCards();

 signals:
  /**
   * @brief chosen signal when the player chooses a card
   */
  void choosed(components::CardType);

 public:
  /**
   * @brief Default constructor
   *
   * @param parent parent widget
   */
  explicit CardPickerWindow(QWidget *parent = nullptr);

  /**
   * @brief update the cards available in hand
   *
   * @param cards Cards in the hand of actual player
   */
  void cards(const QMap<components::CardType, unsigned> &cards);

  /**
   * @brief update the actual playing player name
   * @param player the name of the playing person
   */
  void player(const QString &player);
};
}  // namespace cpoker::view::windows
#endif  // COCKROACH_POKER_SRC_VIEW_WINDOWS_CARDPICKERWINDOW_HPP_
