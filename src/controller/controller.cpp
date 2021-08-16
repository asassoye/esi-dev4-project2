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
#include "controller.hpp"

#include <stdexcept>

namespace cpoker::controller {
Controller::Controller(model::Model *model, view::View *view)
    : model_{model}, view_{view} {
  if (model == nullptr) {
    throw std::invalid_argument("Model cannot be null");
  }

  if (view == nullptr) {
    throw std::invalid_argument("View cannot be null");
  }

  model->addObserver(view);

  startAction_ = [this](std::map<std::string, unsigned> &players) {
    model_->addPlayers(players);
    model_->start();
  };

  chooseCardAction_ = [this](model::cards::CardType card_type) {
    model_->chooseCard(card_type);
  };

  chooseValueAction_ = [this](model::cards::CardType card_type) {
    model_->chooseValue(card_type);
  };

  chooseReceiverAction_ = [this](std::string name) {
    model_->chooseReceiver(name);
  };

  acceptAction_ = [this](bool guess) { model_->accept(guess); };

  transferAction_ = [this]() { model_->transfer(); };

  view_->connectStartAction(&startAction_);
  view_->connectChooseCardAction(&chooseCardAction_);
  view_->connectChooseValueAction(&chooseValueAction_);
  view_->connectReceiverAction(&chooseReceiverAction_);
  view_->connectAcceptActon(&acceptAction_);
  view_->connectTransferAction(&transferAction_);
}
}  // namespace cpoker::controller