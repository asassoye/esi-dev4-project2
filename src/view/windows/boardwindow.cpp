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

#include "boardwindow.hpp"

namespace cpoker::view::windows {

[[maybe_unused]] BoardWindow::BoardWindow(const QVector<QString> &players,
                                          QWidget *parent)
    : QGraphicsView(parent), boardScene_{new scenes::BoardScene{players}} {
  setScene(boardScene_);
  setFrameStyle(QFrame::NoFrame);
  setAlignment(Qt::AlignLeft | Qt::AlignTop);
  setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
  setAttribute(Qt::WA_DeleteOnClose);
}
void BoardWindow::update(
    const QString &playerName,
    const QMap<components::CardType, unsigned int> &update) {
  boardScene_->update(playerName, update);
}
}  // namespace cpoker::view::windows