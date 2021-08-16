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

#include "cardtable.hpp"

#include <QGraphicsRectItem>
#include <iostream>

namespace cpoker::view::components {

CardTable::CardTable(const QMap<CardType, unsigned int> &table,
                     QGraphicsItem *parent)
    : QGraphicsItemGroup{parent}, piles_{} {
  auto *bg = new QGraphicsRectItem{
      QRectF{0.0, 0.0, 167.0 * 8 + (167.0 / 4) * 8, 387.0}};
  bg->setBrush(QBrush{Qt::gray, Qt::Dense2Pattern});
  addToGroup(bg);

  for (auto type : CardTypes) {
    auto *card_pile = new CardPile{type, 0, this};
    double aX = static_cast<unsigned>(type) * (167 + 167.0 / 4);
    double aY = 0;
    card_pile->setPos(aX, aY);
    addToGroup(card_pile);
    this->piles_.insert(type, card_pile);
  }
}

CardTable::CardTable(QGraphicsItem *parent)
    : CardTable(QMap<CardType, unsigned>{}, parent) {}

void CardTable::add(CardType type) {
  CardPile *card_pile = piles_.value(type);
  card_pile->addCard();
}

void CardTable::update(const QMap<CardType, unsigned int> &table) {
  for (auto &pile : piles_) {
    pile->update(table.value(pile->cardType(), 0));
  }
}

QRectF CardTable::boundingRect() const {
  return QRectF{0.0, 0.0, 167.0 * 8 + (167.0 / 4) * 8, 387.0};
}
}  // namespace cpoker::view::components
