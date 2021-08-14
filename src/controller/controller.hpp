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

#ifndef COCKROACH_POKER_SRC_CONTROLLER_CONTROLLER_HPP_
#define COCKROACH_POKER_SRC_CONTROLLER_CONTROLLER_HPP_

#include <functional>
#include <map>

#include "model/model.hpp"
#include "view//view.hpp"

namespace cpoker::controller {
class Controller {
 protected:
  model::Model *model_;
  view::View *view_;

 public:
  std::function<void(std::map<std::string, unsigned> &)> startAction_;
  std::function<void(model::cards::CardType)> chooseCardAction_;
  std::function<void(model::cards::CardType)> chooseValueAction_;
  std::function<void(std::string)> chooseReceiverAction_;
  std::function<void(bool)> acceptAction_;
  std::function<void()> transferAction_;
  Controller(model::Model *model, view::View *view);
};
}  // namespace cpoker::controller

#endif  // COCKROACH_POKER_SRC_CONTROLLER_CONTROLLER_HPP_
