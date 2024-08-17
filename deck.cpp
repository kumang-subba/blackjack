#include "Deck.h"
#include "Card.h"
#include "Random.h"
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iterator>

Deck::Deck() {
  std::size_t index{0};
  for (auto suit : Card::allSuits) {
    for (auto rank : Card::allRanks) {
      m_deck[index] = Card{rank, suit};
      index++;
    }
  }
  assert(std::size(m_deck) == 52);
}

void Deck::shuffle() {
  std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
  m_nextCardIndex = 0;
}

const Card &Deck::dealCard() {
  assert(m_nextCardIndex != 52 && "Deck::dealCard ran out of cards");
  return m_deck[m_nextCardIndex++];
}
