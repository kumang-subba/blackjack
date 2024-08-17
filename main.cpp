#include "Blackjack.h"
#include "Player.h"
#include <iostream>
#include <limits>

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool playerWantsHit() {
  while (true) {
    std::cout << "(h) to hit, or (s) to stand: ";
    char ch{};
    std::cin >> ch;
    if (!std::cin || (ch != 'h' && ch != 's')) {
      if (std::cin.eof()) {
        exit(0);
      }
      std::cin.clear();
      ignoreLine();
      std::cout << "Invalid input\n";
      continue;
    }
    switch (ch) {
    case 'h':
      return true;
    case 's':
      return false;
    }
  }
}

Blackjack::GAME_STATUS playBlackJack() {
  Player player{"Player"};
  Player dealer{"Dealer"};
  Blackjack game{};
  game.dealCardTo(dealer);
  game.dealCardTo(dealer);
  game.dealCardTo(player);
  game.dealCardTo(player);

  std::cout << "The dealer is showing: " << dealer.getFirstCard() << " 🂠 ";
  game.printPlayerScore(dealer);
  std::cout << "Your cards:";
  player.printCards();
  game.printPlayerScore(player);
  std::cout << '\n';
  while (playerWantsHit()) {
    if (game.playerTurn(player)) {
      std::cout << "You busted\n";
      return Blackjack::loss;
    }
    if (game.isBlackJack(player))
      break;
    std::cout << '\n';
  }
  std::cout << '\n';
  std::cout << "The dealer shows his cards.\n";
  std::cout << "The dealer's cards";
  dealer.printCards();
  game.printPlayerScore(dealer);
  if (game.dealerTurn(dealer)) {
    return Blackjack::win;
  }
  return game.getGameStatus(player, dealer);
}

int main() {
  switch (playBlackJack()) {
  case Blackjack::win:
    std::cout << "You win\n";
    break;
  case Blackjack::loss:
    std::cout << "You lose\n";
    break;
  case Blackjack::draw:
    std::cout << "Draw\n";
    break;
  }
  return 0;
}
