#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <array>
#include <cstddef>
#include <vector>
class Deck {
public:
  void shuffle();
  const Card &dealCard();

private:
  std::array<Card, 52> m_deck{};
  std::size_t m_nextCardIndex{0};

public:
  Deck();

  friend class Player;
};

#endif // !DECK_H
