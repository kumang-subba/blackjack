#include "Blackjack.h"
#include "Card.h"
#include <iostream>

Blackjack::Blackjack() : m_deck{} { m_deck.shuffle(); }

bool Blackjack::dealCardTo(Player &player) {
  player.m_owned_cards.push_back(m_deck.dealCard());
  if (player.getTotal() > 21) {
    return true;
  }
  return false;
}

void Blackjack::printPlayerScore(Player &player) {
  std::cout << " | Score: " << player.getTotal() << '\n';
}

bool Blackjack::playerTurn(Player &player) {
  Card newCard{m_deck.dealCard()};
  player.addCard(newCard);
  std::cout << "You were dealt " << newCard << "\n";
  std::cout << "You cards are now:";
  player.printCards();
  printPlayerScore(player);
  if (player.getTotal() > 21) {
    return true;
  }
  return false;
}

bool Blackjack::dealerTurn(Player &dealer) {
  while (dealer.getTotal() < s_dealerStopsAt) {
    Card card{m_deck.dealCard()};
    dealer.addCard(card);
    std::cout << "Dealer flipped card: " << card << '\n';
    std::cout << "Dealer cards now: ";
    dealer.printCards();
    printPlayerScore(dealer);
  }
  if (dealer.getTotal() > 21) {
    std::cout << "Dealer went bust\n";
    return true;
  }
  return false;
}

bool Blackjack::isBlackJack(Player &player) {
  return (player.getTotal() == 21);
}

Blackjack::GAME_STATUS Blackjack::getGameStatus(Player &player,
                                                Player &dealer) {
  if (player.getTotal() > dealer.getTotal()) {
    return Blackjack::win;
  } else if (player.getTotal() < dealer.getTotal()) {
    return Blackjack::loss;
  } else {
    return Blackjack::draw;
  }
}
