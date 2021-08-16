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

#ifndef COCKROACH_POKER_SRC_MODEL_GAME_ROUNDSTATUS_HPP_
#define COCKROACH_POKER_SRC_MODEL_GAME_ROUNDSTATUS_HPP_

namespace cpoker::model::game {
enum RoundStatus {
  /**
   * @brief The round is initialised
   */
  INIT,
  /**
   * The sender has to choose a card
   */
  CHOOSING_CARD,
  /**
   * The sender has to choose a value to announce
   */
  CHOOSING_VALUE,
  /**
   * The sender has to choose a receiver
   */
  CHOOSING_RECEIVER,
  /**
   * The card is send to the receiver. He needs to accept or transfer
   */
  SEND,
  /**
   * The sender loosed the game
   */
  LOOSED
};
}

#endif  // COCKROACH_POKER_SRC_MODEL_GAME_ROUNDSTATUS_HPP_
