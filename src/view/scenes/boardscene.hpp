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

#ifndef COCKROACH_POKER_SRC_VIEW_SCENES_BOARDSCENE_HPP_
#define COCKROACH_POKER_SRC_VIEW_SCENES_BOARDSCENE_HPP_

#include <QGraphicsScene>
#include <QMap>
#include <QString>
#include <QVector>

#include "view/components/cardtable.hpp"

namespace cpoker::view::scenes {
/**
 * @brief The BoardScene manage the table of the players
 */
class BoardScene : public QGraphicsScene {
  Q_OBJECT
 protected:
  /**
   * @brief Map of players
   */
  QMap<QString, components::CardTable *> players_;

 public:
  /**
   * @brief default constructor
   * @param players name of the players
   */
  explicit BoardScene(const QVector<QString> &players);

  /**
   * @brief Update the number of cards of a player
   *
   * @param playerName The name of the player that need an update
   * @param update the update map of number of cards by CardType
   */
  void update(const QString &playerName,
              const QMap<components::CardType, unsigned> &update);
};
}  // namespace cpoker::view::scenes
#endif  // COCKROACH_POKER_SRC_VIEW_SCENES_BOARDSCENE_HPP_
