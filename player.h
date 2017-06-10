//Player class to create object that represents a human player

#ifndef PLAYER_H
#define PLAYER_H 2017
#include <vector>
#include "card.h"

using namespace std;

class Player {
  private:
    vector<Card> playerHand;
    vector<Card> playerHandSplit1;
    vector<Card> playerHandSplit2;

  public:
    void initializeHand(Card card);
    void hit(Card card);
    int getScore(int vector);
    string playerDeck();
    string playerSplitDeck();
    Card& getCard(int index);
    void splitCards();
    void hitSplitHands(Card card1, Card card2);
};
#endif
