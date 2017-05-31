//Card class used to create each of the 52 card objects for the deck

#ifndef CARD_H
#define CARD_H 2017
#include <string>
#include <iostream>

using namespace std;

class Card {
  public:
    enum Suits {diamond, heart, club, spade};
    Card (int _rank, Suits _suit) : rank{_rank}, suit{_suit} {}
    string suitToString();
    int getRank();
    void changeRank(int change);

  private:
    int rank;
    Suits suit;
};
#endif
