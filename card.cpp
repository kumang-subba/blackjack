#include "Card.h"

std::ostream &operator<<(std::ostream &out, const Card &card) {
  out << card.getRank() << card.getSuit();
  return out;
}
