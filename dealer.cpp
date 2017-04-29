#include "dealer.h"

using namespace std;

void Dealer::createDeck() {
  int counter = 0;
  vector<string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
  for (int i = 0; i < 4; i++) {
    for (int k = 0; k < 13; k++) {
      Card card(k, suits[i]);
      deck.push_back(card);
    }
  }
}

Card Dealer::hit() {
  srand(time(NULL));
  return deck[rand() % deck.size()];
}
