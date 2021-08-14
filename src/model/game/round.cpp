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

#include "round.hpp"

#include <stdexcept>

namespace cpoker::model::game {

Round::Round()
    : status_{INIT}, sender_{nullptr}, receiver_{nullptr}, card_{}, value_{} {}

void Round::start(Player &firstPlayer) noexcept(false) {
  if (status_ != INIT) {
    throw std::logic_error("Round is already started");
  }

  sender_ = &firstPlayer;
  status_ = CHOOSING_CARD;
}

void Round::reset() noexcept {
  card_.reset();
  value_.reset();
  receiver_ = nullptr;
  sender_ = nullptr;
  status_ = INIT;
}

void Round::next(Player &nextSender,
                 const std::optional<cards::Card> &card) noexcept(false) {
  if (card.has_value()) {
    card_ = card.value_or(cards::Card{cards::COCKROACH});
    status_ = CHOOSING_VALUE;
  } else {
    card_.reset();
    status_ = CHOOSING_CARD;
  }

  sender_ = &nextSender;
  receiver_ = nullptr;
  value_.reset();
}

void Round::chooseCard(Player &sender, const cards::Card &card) {
  if (status_ != CHOOSING_CARD) {
    throw std::logic_error("It's not the moment to choose a card.");
  }

  if (&sender != sender_) {
    throw std::logic_error("It's not your turn");
  }

  if (!sender_->hasCardsLeft()) {
    status_ = LOOSED;
    return;
  }

  card_ = card;
  status_ = CHOOSING_VALUE;
}

void Round::chooseCard(cards::CardType card_type) {
  chooseCard(*sender_, cards::Card{card_type});
}

void Round::chooseValue(Player &sender, const cards::Card &card) {
  if (status_ != CHOOSING_VALUE) {
    throw std::logic_error("It's not the moment to choose a value");
  }

  if (&sender != sender_) {
    throw std::logic_error("It's not your turn");
  }

  value_ = card;
  status_ = CHOOSING_RECEIVER;
}

void Round::chooseValue(cards::CardType card_type) {
  chooseValue(*sender_, cards::Card{card_type});
}

void Round::chooseReceiver(Player &sender, Player &receiver) noexcept(false) {
  if (status_ != CHOOSING_RECEIVER) {
    throw std::logic_error("it's not the moment to choose a receiver");
  }

  if (&sender != sender_) {
    throw std::logic_error("It's not your turn");
  }

  if (&receiver == sender_) {
    throw std::logic_error("You cannot choose yourself");
  }

  receiver_ = &receiver;
  status_ = SEND;
}

void Round::chooseReceiver(Player &receiver) {
  chooseReceiver(*sender_, receiver);
}

void Round::accept(Player &receiver, bool guess) {
  if (status_ != SEND) {
    throw std::logic_error("it's not the moment to guess");
  }

  if (&receiver != receiver_) {
    throw std::logic_error("It's not your turn");
  }

  bool truth = card_ == value_;
  Player *roundLooser = truth == guess ? sender_ : receiver_;
  roundLooser->addTable(card_.value());

  // Verify if looser has 4 identical cards on table
  if (roundLooser->countTable(card_.value().type()) == 4) {
    sender_ = roundLooser;
    status_ = LOOSED;
    return;
  }

  next(*roundLooser);
}

void Round::accept(bool guess) { accept(*receiver_, guess); }

void Round::transfer(Player &receiver) {
  if (status_ != SEND) {
    throw std::logic_error("it's not the moment to transfer a card");
  }

  if (&receiver != receiver_) {
    throw std::logic_error("It's not your turn");
  }

  next(*receiver_, card_);
}

void Round::transfer() { transfer(*receiver_); }
Player &Round::looser() noexcept(false) {
  if (status_ != LOOSED) {
    throw std::logic_error("Game is not finished");
  }

  return *sender_;
}
Player &Round::playing() const {
  if (status_ == INIT || status_ == LOOSED) {
    throw std::logic_error("not started");
  }

  switch (status_) {
    default:
    case CHOOSING_CARD:
    case CHOOSING_VALUE:
    case CHOOSING_RECEIVER:
      return *sender_;
    case SEND:
      return *receiver_;
  }
}

RoundStatus Round::status() const { return status_; }
cards::CardType Round::announced() const { return value_->type(); }

}  // namespace cpoker::model::game