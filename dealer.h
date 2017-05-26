#ifndef DEALER_H
#define DEALER_H 2017
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "card.h"
#include "player.h"

using namespace std;

class Dealer {
  public:
    void createDeck();
    void shuffleDeck();
    void hitPlayer();
    void hitDealer();
    void createPlayer();
    void deal();
    string playerDeck_toString();

  private:
    Player player;
    vector<Card> deck;
    vector<Card> dealerHand;
};
#endif
