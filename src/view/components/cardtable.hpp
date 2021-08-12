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


#ifndef COCKROACH_POKER_SRC_VIEW_COMPONENTS_CARDTABLE_HPP_
#define COCKROACH_POKER_SRC_VIEW_COMPONENTS_CARDTABLE_HPP_

#include <QGraphicsItemGroup>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QVector>
#include <QMap>
#include "view/components/cardtype.hpp"
#include "view/components/card.hpp"
#include "view/components/cardpile.hpp"

namespace cpoker::view::components {
class CardTable : public QGraphicsItemGroup {
 protected:
  QMap<CardType, CardPile *> piles_;
 public:
  explicit CardTable(const QMap<CardType, unsigned int> &table, QGraphicsItem *parent = nullptr);
  explicit CardTable(QGraphicsItem *parent = nullptr);
  void add(CardType type);
  void update(QMap<CardType, unsigned> table);
  QRectF boundingRect() const override;
};
}
#endif //COCKROACH_POKER_SRC_VIEW_COMPONENTS_CARDTABLE_HPP_
