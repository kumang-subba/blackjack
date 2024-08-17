#include "Player.h"
#include <iostream>
#include <string_view>

int Player::getTotal() const {
  int score{0};
  for (auto card : m_owned_cards) {
    score += card.value();
  }
  return score;
}

Card Player::getFirstCard() const {
  assert(std::size(m_owned_cards) != 0 && "Deal card first");
  return m_owned_cards[0];
}

void Player::addCard(const Card &card) { m_owned_cards.push_back(card); }

Player::Player(std::string_view name) : m_name{name}, m_owned_cards{} {}

void Player::printCards() {
  for (Card card : m_owned_cards) {
    std::cout << ' ' << card;
  }
}
