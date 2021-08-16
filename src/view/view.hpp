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
#include <QHBoxLayout>

#include "model/cards/cardtype.hpp"
#include "model/game/gamestatus.hpp"
#include "model/game/roundstatus.hpp"
#include "utils/observer.hpp"
#include "view/components/card.hpp"
#include "view/windows/boardwindow.hpp"
#include "view/windows/cardpickerwindow.hpp"
#include "view/windows/playerpickerwindow.hpp"
#include "view/windows/receiverwindow.hpp"
#include "view/windows/startwindow.hpp"
#include "view/windows/valuepickerwindow.hpp"

namespace cpoker::view {
/**
 * @brief THE VIEW class :)
 */
class View : public QWidget, public utils::Observer {
  Q_OBJECT
 protected:
  /**
   * @brief The layout of the widget
   */
  QHBoxLayout *layout_;
  /**
   * @brief The status of the game
   */
  model::game::GameStatus status_;

  /**
   * @brief the status of the round
   */
  model::game::RoundStatus round_status_;

  /**
   * @brief The start window
   */
  windows::StartWindow *startWindow_;

  /**
   * @brief The boardWindow
   */
  windows::BoardWindow *boardWindow_;

  /**
   * @brief the player chooser window
   */
  windows::PlayerPickerWindow *player_picker_window_;

  /**
   * @brief The card picker window
   */
  windows::CardPickerWindow *card_picker_window_;

  /**
   * @brief The value picker window
   */
  windows::ValuePickerWindow *value_picker_window_;

  /**
   * @brief The Receiver Window
   */
  windows::ReceiverWindow *receiver_window_;

  /**
   * @brief The lambda start action
   */
  std::function<void(std::map<std::string, unsigned> &)> *startAction_;

  /**
   * @brief The lambda choose card action
   */
  std::function<void(model::cards::CardType)> *chooseCardAction_;

  /**
   * @brief The lambda choose value action
   */
  std::function<void(model::cards::CardType)> *chooseValueAction_;

  /**
   * @brief The lambda choose receiver action
   */
  std::function<void(std::string)> *chooseReceiverAction_;

  /**
   * @brief The lambda accept action
   */
  std::function<void(bool)> *acceptAction_;

  /**
   * @brief The lambda transfer action
   */
  std::function<void()> *transferAction_;

  /**
   * @brief change the status of the game
   */
  [[maybe_unused]] void status(model::game::GameStatus status);

 public:
  /**
   * @brief The default View constructor
   */
  View();

  /**
   * @inherit
   */
  void update(const std::string_view &propertyName,
              const utils::Observable *observable) override;

  /**
   * @brief Show the board
   *
   * @param players Name of the players
   */
  void showBoard(const QVector<QString> &players);

  /**
   * @brief Update the board information
   * @param players players information mess
   */
  void updateBoard(
      const std::vector<
          std::pair<std::string, std::map<model::cards::CardType, unsigned>>>
          &players);

  /**
   * @brief connector for the startAction
   * @param startAction the lambda
   */
  void connectStartAction(
      std::function<void(std::map<std::string, unsigned> &)> *startAction);

  /**
   * @brief connector for the chooseCardAction
   * @param chooseCardAction the lambda
   */
  void connectChooseCardAction(
      std::function<void(model::cards::CardType)> *chooseCardAction);

  /**
   * @brief The connector for the ChooseValueAction
   * @param chooseCardAction the lambda
   */
  void connectChooseValueAction(
      std::function<void(model::cards::CardType)> *chooseCardAction);

  /**
   * @brief Connector for the receiverAction
   * @param chooseReceiverAction the lambda
   */
  void connectReceiverAction(
      std::function<void(std::string)> *chooseReceiverAction);

  /**
   * @brief Connector for the acceptAction
   * @param acceptAction the lambda
   */
  void connectAcceptActon(std::function<void(bool)> *acceptAction);

  /**
   * @brief Connector for the transferAction
   *
   * @param transferAction the lambda
   */
  void connectTransferAction(std::function<void()> *transferAction);
};
}  // namespace cpoker::view
#endif  // COCKROACH_POKER_SRC_VIEW_VIEW_HPP_
