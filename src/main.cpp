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

#include <QApplication>
#include <QLabel>
#include <QGraphicsPixmapItem>
#include <QRectF>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <cmath>
#include <iostream>
#include "model/model.hpp"
#include "view/view.hpp"
#include "view/components/card.hpp"
#include "view/components/cardpile.hpp"
#include "view/components/cardtable.hpp"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

//  cpoker::model::Model model{};
//  cpoker::view::View view{};
//  view.show();

  QGraphicsScene scene = QGraphicsScene{QRectF{-5, -5, 800, 800}};
  scene.setBackgroundBrush(QBrush{Qt::gray, Qt::Dense2Pattern});

  QMap<cpoker::view::components::CardType, unsigned> mapping{
      {cpoker::view::components::FLY, 1},
      {cpoker::view::components::STINKBUG, 1},
      {cpoker::view::components::COCKROACH, 3},
      {cpoker::view::components::SPIDER, 2},
      {cpoker::view::components::TOAD, 3},
      {cpoker::view::components::SCORPION, 1},
      {cpoker::view::components::RAT, 3},
      {cpoker::view::components::BAT, 2},

  };

  double degrees{0.0};
  double radius{250.0};
  int n{6};

  for (int i = 0; i < n; ++i) {
    degrees = i * (360.0 / n);
    double radian = (degrees * (M_PI / 180));

    auto *pixmap_item = new cpoker::view::components::CardTable{mapping};
    pixmap_item->setScale(0.15);
    double width = pixmap_item->boundingRect().width() * pixmap_item->scale();
    double height = pixmap_item->boundingRect().height() * pixmap_item->scale();
    pixmap_item->setPos(radius * std::cos(radian) + 375 - width / 2, radius * std::sin(radian) + 375);

    QTransform transform;
    transform.translate(width / 2, height / 2);
    transform.rotate(degrees - 90);
    transform.translate(-(width / 2), -(height / 2));

    pixmap_item->setTransform(transform);
    scene.addItem(pixmap_item);
  }

  QGraphicsView gview = QGraphicsView{};
  gview.setScene(&scene);

  gview.setFrameStyle(QFrame::NoFrame);
  gview.setAlignment(Qt::AlignLeft | Qt::AlignTop);
  gview.setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
  gview.show();

  return QApplication::exec();
}
