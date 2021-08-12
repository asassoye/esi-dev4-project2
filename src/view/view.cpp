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

#include <memory>
#include <stdexcept>
#include <iostream>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include "view.hpp"
#include "model/model.hpp"

namespace cpoker::view {

View::View() : status_{model::game::NOT_STARTED} {
  setWindowTitle("Cockroach Poker");

  startWindow_ = new windows::StartWindow{};
  startWindow_->show();

}

void View::update(const std::string_view &propertyName, const utils::Observable *observable) {
  std::cout << propertyName << std::endl;

  auto model = dynamic_cast<const model::Model *>(observable);

  if (propertyName == "STATUS_UPDATED") {
    status_ = model->status();
  }
}

void View::showBoard() {
  QGraphicsView gview = QGraphicsView{this};
  //gview.setScene(&scene);

  gview.setFrameStyle(QFrame::NoFrame);
  gview.setAlignment(Qt::AlignLeft | Qt::AlignTop);
  gview.setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
  gview.show();
}

void View::askPlayers() {

}

void View::connectStartAction(std::function<void(std::map<std::string, unsigned> &)> *startAction) {
  startAction_ = startAction;
  connect(startWindow_, &windows::StartWindow::confirmed, this, [this, startAction]() {
    auto players = startWindow_->players();
    (*startAction)(players);
    startWindow_->hide();
  });
}

}
