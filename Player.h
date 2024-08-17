#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Deck.h"
#include <cassert>
#include <string_view>
#include <vector>

class Player {
private:
  const std::string_view m_name;
  std::vector<Card> m_owned_cards;
  int getTotal() const;
  void addCard(const Card &card);
  Card getCard(std::size_t index) { return m_owned_cards[index]; }

public:
  Player(std::string_view name);
  Card getFirstCard() const;
  void printCards();
  friend class Blackjack;
};

#endif // !PLAYER_H
