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

//
// Created by asassoye on 1/08/21.
//

#include "cardpile.hpp"
namespace cpoker::view::components {

QRectF CardPile::boundingRect() const {
  return QGraphicsItemGroup::boundingRect();
}

void CardPile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget) {
  QGraphicsItemGroup::paint(painter, option, widget);
}

CardPile::CardPile(CardType type, unsigned int nb, QGraphicsItem *parent)
    : QGraphicsItemGroup{parent}, type_{type}, nb_{0} {
  for (auto i = 0; i < nb; ++i) {
    addCard();
  }
}

void CardPile::addCard() {
  Card *card = new Card{this->type_, this};
  card->setPos(0, this->nb_ * card->boundingRect().height() / 4);
  ++(this->nb_);
  addToGroup(card);
}

void CardPile::update(unsigned nb) {
  for (unsigned i = this->nb_; i < nb; ++i) {
    addCard();
  }
}
unsigned CardPile::nb() const { return nb_; }

CardType CardPile::cardType() { return type_; }
}  // namespace cpoker::view::components
