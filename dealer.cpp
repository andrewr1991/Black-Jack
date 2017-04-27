#include "dealer.h"

using namespace std;

void Dealer::createDeck() {
  int counter = 0;
  vector<string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
  for (int i = 0; i < 4; i++) {
    for (int k = 0; k < 52; k++) {
      Card card(k, suits[i]);
      deck[counter] = card;
      counter++;
    }
  }
}

void Dealer::shuffle() {
  srand(time(NULL));

  for (int i = 0; i < 1000; i++) {
    int a = rand() % 52 + 1;
    int b = rand() % 52 + 1;

    iter_swap(shuffledDeck.begin() + a, shuffledDeck.begin() + b);
  }
}
