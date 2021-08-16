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

#ifndef COCKROACH_POKER_SRC_MODEL_MODEL_HPP_
#define COCKROACH_POKER_SRC_MODEL_MODEL_HPP_

#include <map>
#include <string>
#include <vector>

#include "model/game/game.hpp"

namespace cpoker::model {
/**
 * @brief Type of a map of CardType and count
 */
typedef std::map<cards::CardType, unsigned> CardMap;

/**
 * @brief The model class managed the model of the application
 */
class Model : public game::Game {
 public:
  /**
   * @brief Returns a vector of player names
   *
   * @return Players
   */
  [[nodiscard]] std::vector<std::string_view> players() const;

  /**
   * @brief Returns the playing player name
   *
   * @return Playing player
   */
  [[nodiscard]] std::string playingPlayer() const;

  /**
   * @brief Choose a card in the round
   *
   * @param card_type The type of the card
   */
  void chooseCard(model::cards::CardType card_type);

  /**
   * @brief Choose a value to announce in the round
   *
   * @param card_type The type to announce
   */
  void chooseValue(model::cards::CardType card_type);

  /**
   * @brief Choose a receiver in the round
   *
   * @param name The name of the receiver player
   */
  void chooseReceiver(std::string &name);

  /**
   * @brief Accept the card that is send in the round
   *
   * @param guess Guess if the announced value is the truth or a lie
   */
  void accept(bool guess);

  /**
   * @brief Transfer the card
   */
  void transfer();

  /**
   * @brief Returns the actual RoundStatus
   *
   * @return the actual status
   */
  [[nodiscard]] game::RoundStatus roundStatus() const;

  /**
   * @brief Returns the announced value
   *
   * @return the announced value type
   */
  [[nodiscard]] model::cards::CardType announcedCard() const;

  /**
   * @brief Returns the actual board
   *
   * @return A mess with all the information of the actual board
   */
  [[nodiscard]] std::vector<
      std::pair<std::string, std::map<cards::CardType, unsigned>>>
  board() const;

  /**
   * @brief Returns the name of the looser
   * @return the looser
   */
  [[nodiscard]] std::string looser() const;

  /**
   * @brief Returns a specific player's hand cards
   *
   * @param name The name of the player
   * @return A map with the representation of the player's hand
   */
  std::map<cards::CardType, unsigned> hand(std::string &name) const;
};
}  // namespace cpoker::model

#endif
