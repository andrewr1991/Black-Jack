#ifndef DEALER_H
#define DEALER_H 2017
#include <string>
#include <vector>
#include <cstdlib>
#include "card.h"

using namespace std;

class Dealer {
  private:
    vector<Card> deck;
    vector<Card> shuffledDeck;

  public:
    void createDeck();
    void shuffle();
};
#endif
