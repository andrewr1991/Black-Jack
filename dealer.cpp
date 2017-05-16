#include "dealer.h"
#include <algorithm>

using namespace std;

void Dealer::createDeck() {
  for (int i = 0; i < 4; i++) {
    for (int k = 0; k < 13; k++) {
      Card card(k, Card::Suits(i));
      deck.push_back(card);
    }
  }
}

void Dealer::shuffleDeck() {
  cout << "Before: " << endl;
  for (int i = 0; i < 52; i++) {
    cout << deck[i].getRank() << " " << deck[i].suitToString() << endl;
  }
  cout << endl;
  srand(time(NULL));
  for (int i = 0; i < 1000; i++) {
    int r = rand() % deck.size();
    int s = rand() % deck.size();
    swap(deck[r], deck[s]);
  }
  cout << "After: " << endl;
  for (int i = 0; i < 52; i++) {
    cout << deck[i].getRank() << " " << deck[i].suitToString() << endl;
  }
}

Card Dealer::deal() {
  for (int i = 0; i < 2; i++) {

  }
}

Card Dealer::hit() {
  
}
