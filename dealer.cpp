#include "dealer.h"

using namespace std;

// Creates the deck of cards using the Card class constructor
void Dealer::createDeck() {
  for (int i = 0; i < 4; i++) {
    for (int k = 0; k < 13; k++) {
		if (k > 10) {
			Card card(10, Card::Suits(i));
		}
		else if (k == 0) {
			Card card(1, Card::Suits(i));
		}
		else {
		  Card card(k, Card::Suits(i));
		  deck.push_back(card);
	  }
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

void Dealer::deal() {
  for (int i = 0; i < 2; i++) {
    // Hit dealer
    dealerHand.push_back(deck.back());
    deck.pop_back();

    // Hit player
    Card temp = deck.back();
    deck.pop_back();
    player.hit(temp);
  }
}

// Simply returns one of the shuffled cards
void Dealer::hitPlayer() {
  Card temp = deck.back();
  deck.pop_back();
  player.hit(temp);
}

void Dealer::hitDealer() {
  dealerHand.push_back(deck.back());
  deck.pop_back();
}

void Dealer::createPlayer() {
  Player _player = player;
}

string Dealer::playerDeck_toString() {
  return player.playerDeck();
}
