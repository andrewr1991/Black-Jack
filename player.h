//Player class to create object that represents a human player

#ifndef PLAYER_H
#define PLAYER_H 2017
#include "card.h"
#include <vector>

using namespace std;

class Player {
  private:
    vector<Card> playerHand;

  public:
    void initializeHand(Card card);
    void hit(Card card);
    int getScore();
};
#endif
