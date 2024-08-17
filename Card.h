#ifndef CARD_H
#define CARD_H

#include <array>
#include <ostream>
#include <string_view>

struct Card {
  enum Rank {
    rank_ace,
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,

    max_ranks
  };
  enum Suit { suit_spade, suit_diamond, suit_heart, suit_club, max_suits };
  static constexpr std::array<Rank, max_ranks> allRanks{
      rank_ace, rank_2, rank_3,  rank_4,    rank_5,     rank_6,   rank_7,
      rank_8,   rank_9, rank_10, rank_jack, rank_queen, rank_king};
  static constexpr std::array<Suit, max_suits> allSuits{
      suit_spade, suit_diamond, suit_heart, suit_club};
  Rank rank;
  Suit suit;
  static constexpr std::array<std::string_view, max_ranks> s_rankString{
      "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
  static constexpr std::array<std::string_view, max_suits> s_suitString{
      "♠", "♦", "♥", "♣"};
  static constexpr std::array rankValues{11, 2, 3,  4,  5,  6, 7,
                                         8,  9, 10, 10, 10, 10};
  std::string_view getRank() const { return s_rankString[this->rank]; }
  std::string_view getSuit() const { return s_suitString[this->suit]; }
  std::string_view getRank(Rank rank) { return s_rankString[rank]; }
  friend std::ostream &operator<<(std::ostream &out, const Card &card);

  int value() const { return rankValues[rank]; }
};

#endif // !CARD_H
