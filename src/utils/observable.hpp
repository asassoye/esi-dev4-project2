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

#ifndef COCKROACH_POKER_SRC_UTILS_OBSERVABLE_HPP_
#define COCKROACH_POKER_SRC_UTILS_OBSERVABLE_HPP_

#include <set>

#include "utils/observer.hpp"

namespace cpoker::utils {

class Observable {
 protected:
  std::set<Observer *> observers_;

 public:
  // virtual ~Observable() = default;

  virtual void addObserver(Observer *observer) final {
    observers_.insert(observer);
  }

  virtual void removeObserver(Observer *observer) final {
    observers_.erase(observer);
  }

  virtual void notify(const std::string_view &propertyName) const final {
    for (auto const &observer : observers_) {
      observer->update(propertyName, this);
    }
  }
};
}  // namespace cpoker::utils
#endif  // COCKROACH_POKER_SRC_UTILS_OBSERVABLE_HPP_
