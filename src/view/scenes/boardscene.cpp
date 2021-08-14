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

#include "boardscene.hpp"

#include <QDebug>
#include <QGraphicsTextItem>
#include <stdexcept>

#include "view/components/cardtable.hpp"

namespace cpoker::view::scenes {

BoardScene::BoardScene(const QVector<QString> &players)
    : QGraphicsScene(-5, -5, 800, 800) {
  this->setBackgroundBrush(QBrush{Qt::gray, Qt::Dense2Pattern});

  double degrees, radius{250.0};
  unsigned n{static_cast<unsigned>(players.size())}, i{0};

  if (n > 6) {
    throw std::logic_error("There is max 6 players allowed");
  }

  for (auto &playerName : players) {
    degrees = i * (360.0 / n);
    double radian = (degrees * (M_PI / 180));

    auto *player = new cpoker::view::components::CardTable{};
    auto *name = new QGraphicsTextItem{playerName};
    player->setScale(0.15);
    double width = player->boundingRect().width() * player->scale();
    double height = player->boundingRect().height() * player->scale();
    player->setPos(radius * std::cos(radian) + 375 - width / 2,
                   radius * std::sin(radian) + 375);
    name->setPos((radius - 100) * std::cos(radian) + 475 - width / 2,
                 (radius - 100) * std::sin(radian) + 375);
    QTransform transform;
    transform.translate(width / 2, height / 2);
    transform.rotate(degrees - 90);
    transform.translate(-(width / 2), -(height / 2));

    player->setTransform(transform);
    players_.insert(playerName, player);
    this->addItem(player);
    this->addItem(name);
    i++;
  }
}

void BoardScene::update(
    const QString &playerName,
    const QMap<components::CardType, unsigned int> &update) {
  components::CardTable *player = players_.value(playerName);

  if (player == nullptr) {
    throw std::invalid_argument("Player does not exist");
  }

  player->update(update);
}
}  // namespace cpoker::view::scenes