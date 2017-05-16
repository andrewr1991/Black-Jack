#ifndef DEALER_H
#define DEALER_H 2017
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "card.h"

using namespace std;

class Dealer {
  private:
    vector<Card> deck;
    vector<Card> dealerHand;

  public:
    void createDeck();
    void shuffleDeck();
    Card deal();
    Card hit();
};
#endif
