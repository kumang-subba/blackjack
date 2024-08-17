#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Deck.h"
#include "Player.h"

class Blackjack {
public:
  enum GAME_STATUS { win, loss, draw };

private:
  Deck m_deck;
  static constexpr int s_dealerStopsAt{18};

public:
  Blackjack();
  bool dealCardTo(Player &player);
  void printPlayerScore(Player &player);
  bool playerTurn(Player &player);
  bool dealerTurn(Player &dealer);
  bool isBlackJack(Player &player);
  GAME_STATUS getGameStatus(Player &player, Player &dealer);
};

#endif // !BLACKJACK_H
