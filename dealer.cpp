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

// Deal each the dealer and player two cards
void Dealer::deal() {
  for (int i = 0; i < 2; i++) {
    hitDealer();
	hitPlayer();
  }
}

// Pushes a card from the back of the shuffled deck into the player's hand then deletes that same card from the main deck 
void Dealer::hitPlayer() {
  Card temp = deck.back();
  deck.pop_back();
  player.hit(temp);
}

// Pushes a card from the back of the shuffled deck into the dealer's hand then deletes that same card from the main deck
void Dealer::hitDealer() {
  dealerHand.push_back(deck.back());
  deck.pop_back();
}

// Creates a Player object
void Dealer::createPlayer() {
  Player _player = player;
}

// Returns the player's deck of cards as a string
string Dealer::playerDeck_toString() {
  return "\n" + player.playerDeck();
}

// Returns the player's total score
string Dealer::playerScore() {
	string playerScore_toString;
	int playerScore = player.getScore();
	return playerScore_toString = "Total score: " + to_string(playerScore) + "\n";
}

string Dealer::dealerDeck_toString() {
	string dealerCards = "\nDealer hand\n";
		for (int i = 0; i < dealerHand.size(); i++) {
			dealerCards += to_string(dealerHand[i].getRank()) + " ";
		}
	dealerCards += "\n\n";
	return dealerCards;
}

// 
int Dealer::dealerScore() {
  int dealerScore = 0;
  for (int i = 0; i < dealerHand.size(); i++) {
    dealerScore += dealerHand[i].getRank();
  }
  return dealerScore;
}

string Dealer::dealerScore_toString() {
	string dealerScoreString;
	return dealerScoreString = 

// Checks if the dealer's score is less than 17, 
int Dealer::dealerPlay() {
	
	while (true) {
		if (dealerScore() < 17) {
			hitDealer();
		}
		else {
			break;
		}
	}
}
	
	
	
