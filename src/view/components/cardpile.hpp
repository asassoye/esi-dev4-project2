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

#ifndef COCKROACH_POKER_SRC_VIEW_COMPONENTS_CARDPILE_HPP_
#define COCKROACH_POKER_SRC_VIEW_COMPONENTS_CARDPILE_HPP_

#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QPainter>
#include <QRectF>
#include <QStyleOptionGraphicsItem>
#include <QVector>
#include <QWidget>

#include "view/components/card.hpp"
#include "view/components/cardtype.hpp"

namespace cpoker::view::components {
/**
 * @brief View class to represent a stack of cards
 */
class CardPile : public QGraphicsItemGroup {
 protected:
  /**
   * @brief type of the cards
   */
  CardType type_;

  /**
   * @brief number of cards in the stack
   */
  unsigned nb_;

  /**
   * @brief Vector of Graphic Card Items
   */
  [[maybe_unused]] QVector<Card *> cards_;

 public:
  /**
   * Default constructor for a CardStack
   *
   * @param type Type of cards
   * @param nb Number of cards
   * @param parent Parent GraphicsItem
   */
  CardPile(CardType type, unsigned nb, QGraphicsItem *parent = nullptr);

  /**
   * The Rectangle of the item for the view
   * @return The QRectF
   */
  [[nodiscard]] QRectF boundingRect() const override;

  /**
   * @brief paint the component (QT shit)
   *
   * @param painter QPainter
   * @param option Options
   * @param widget Widget
   */
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;

  /**
   * @brief add a card
   */
  void addCard();

  /**
   * @brief update the card numbers
   *
   * @param nb updated number of cards
   */
  void update(unsigned nb);

  /**
   * @brief Returns the number of cards
   * @return the number of cards
   */
  [[maybe_unused]] [[nodiscard]] unsigned nb() const;

  /**
   * @brief Returns the type of the cards in the stack
   * @return The CardType of the cards
   */
  CardType cardType();
};
}  // namespace cpoker::view::components
#endif  // COCKROACH_POKER_SRC_VIEW_COMPONENTS_CARDPILE_HPP_
