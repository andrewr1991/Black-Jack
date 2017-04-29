//Player class to create object that represents the

#ifndef PLAYER_H
#define PLAYER_H 2017
#include "card.h"
#include <vector>

using namespace std;

class Player {
  private:
    vector<Card> playerHand;

  public:
    void hit(Card card);
    int getScore();
};
#endif
