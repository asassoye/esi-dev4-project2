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

#ifndef COCKROACH_POKER_SRC_VIEW_WIDGETS_PLAYERINPUT_HPP_
#define COCKROACH_POKER_SRC_VIEW_WIDGETS_PLAYERINPUT_HPP_

#include <QHBoxLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QWidget>
#include <string_view>

namespace cpoker::view::widgets {
/**
 * @brief PlayerInput class is a input of a name and an age of a player
 */
class PlayerInput : public QWidget {
  Q_OBJECT
 protected:
  /**
   * @brief Layout of the Widget
   */
  QHBoxLayout *layout_;

  /**
   * @brief The name input of the player
   */
  QLineEdit *name_;

  /**
   * @brief The age input of the player
   */
  QSpinBox *age_;

 public:
  /**
   * @brief Default constructor
   * @param parent parent widget
   */
  explicit PlayerInput(QWidget *parent = nullptr);

  /**
   * @brief Constructor with player id
   *
   * @param id ID of the player (for auto naming)
   * @param parent parent widget
   */
  explicit PlayerInput(unsigned id, QWidget *parent = nullptr);

  /**
   * @brief Get the name of the player input
   * @return The player's name
   */
  [[nodiscard]] std::string name() const;

  /**
   * @brief The age of the player
   *
   * @return The age of the input
   */
  [[nodiscard]] unsigned age() const;
};
}  // namespace cpoker::view::widgets

#endif  // COCKROACH_POKER_SRC_VIEW_WIDGETS_PLAYERINPUT_HPP_
