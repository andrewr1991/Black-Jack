#include "dealer.h"

using namespace std;

// Creates the deck of cards using the Card class constructor
void Dealer::createDeck() {
  for (int i = 0; i < 4; i++) {
    for (int k = 0; k < 13; k++) {
      Card card(k, Card::Suits(i));
      deck.push_back(card);
    }
  }
}

// Shuffles the deck by swapping two randomly-selected values in the vector 1000 times
void Dealer::shuffleDeck() {
  srand(time(NULL));
  for (int i = 0; i < 1000; i++) {
    int r = rand() % deck.size();
    int s = rand() % deck.size();
    swap(deck[r], deck[s]);
  }
}

// Simply returns one of the shuffled cards
Card Dealer::hitPlayer() {
  Card temp = deck.back();
  deck.erase(deck.end());
  return temp;
}

void Dealer::hitDealer() {

}
