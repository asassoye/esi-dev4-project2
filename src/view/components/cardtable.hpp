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

#ifndef COCKROACH_POKER_SRC_VIEW_COMPONENTS_CARDTABLE_HPP_
#define COCKROACH_POKER_SRC_VIEW_COMPONENTS_CARDTABLE_HPP_

#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QMap>
#include <QPainter>
#include <QRectF>
#include <QStyleOptionGraphicsItem>
#include <QVector>
#include <QWidget>

#include "view/components/card.hpp"
#include "view/components/cardpile.hpp"
#include "view/components/cardtype.hpp"

namespace cpoker::view::components {
/**
 * @brief CardTable View class
 */
class CardTable : public QGraphicsItemGroup {
 protected:
  /**
   * @brief The card stacks
   */
  QMap<CardType, CardPile *> piles_;

 public:
  /**
   * @brief Constructor with already cards inside
   * @param table a map with each number of cards by type
   * @param parent parent item
   */
  explicit CardTable(const QMap<CardType, unsigned int> &table,
                     QGraphicsItem *parent = nullptr);

  /**
   * @brief Constructor with a empty table
   * @param parent parent item
   */
  explicit CardTable(QGraphicsItem *parent = nullptr);

  /**
   * @brief Add a card of a certain type
   *
   * @param type Type of the card to add to the table
   */
  void add(CardType type);

  /**
   * @brief Update the actual cards on the table
   *
   * @param table The map with number of cards by type
   */
  void update(const QMap<CardType, unsigned> &table);

  /**
   * @brief Getter of the bounding rectangle
   * @return QRectF (qt shit)
   */
  [[nodiscard]] QRectF boundingRect() const override;
};
}  // namespace cpoker::view::components
#endif  // COCKROACH_POKER_SRC_VIEW_COMPONENTS_CARDTABLE_HPP_
