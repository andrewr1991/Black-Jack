#include "dealer.h"

using namespace std;

void Dealer::createDeck() {
  for (int i = 0; i < 4; i++) {
    for (int k = 0; k < 13; k++) {
      Card card(k, Card::Suits(i));
      deck.push_back(card);
    }
  }
}

Card Dealer::deal() {

}

Card Dealer::hit() {
  srand(time(NULL));
  return deck[rand() % deck.size()];
}
