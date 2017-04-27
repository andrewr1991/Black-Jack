//Card class used to create each of the 52 card objects for the deck

#ifndef CARD_H
#define CARD_H 2017
#include <string>

class Card {
  private:
    int rank;
    std::string suit;

  public:
    Card (int _rank, std::string _suit) : rank{_rank}, suit{_suit} {}
    int getRank();
};
#endif
