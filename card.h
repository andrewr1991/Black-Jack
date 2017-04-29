//Card class used to create each of the 52 card objects for the deck

#ifndef CARD_H
#define CARD_H 2017
#include <string>

using namespace std;

class Card {
  private:
    int rank;
    string suit;
    //Suits suit;
  public:
    Card (int _rank, string _suit) : rank{_rank}, suit{_suit} {}
    //enum Suits {diamond, heart, club, spade};
    //string suitToString(suits s);
    int getRank();
    //string[] suit_to_string = {"Spade"}; suit_to_string[s]
};
#endif
