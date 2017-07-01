/*
 * Change playerscore_toString() to show split scores as well
 * Add end game socre testing to determine winner
 */

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
	hitPlayer(0);
    hitDealer();
  }
  
  // Loop through the initial 2-card deck to look for aces and prompt the user for what they want to do with them
  for (int i = 0; i < 2; i++) {
	  if (player.getCard(i).getRank() == 1) {
		  int oneOrEleven;
		  cout << "Would you like the ace to be a 1 or an 11? "; 
		  cin >> oneOrEleven;
		  
		  if (oneOrEleven == 11) {
			  player.getCard(i).changeRank(11);
			  cout << "The ace will have a value of 11" << endl;
		  }
		  else {
			  cout << "The ace will have a value of 1" << endl;
		  }
	  }
  }

  if (player.getCard(0).getRank() == player.getCard(1).getRank()) {
	  string splitSelection;
	  cout << "Would you like to split? (yes or no) ";
	  cin >> splitSelection;
	  
	  if (splitSelection == "yes") {
		  player.splitCards();
		  split = true;
	  }
  }
	// Show player decks
	if (!split) {
		cout << playerDeck_toString(0);
		cout << playerScore_toString();
	}
	else if (split) {
		cout << playerDeck_toString(1);
		cout << playerScore(1) << endl;
			
		cout << playerDeck_toString(2);
		cout << playerScore(2) << endl;
	}
}

// Pushes a card from the back of the shuffled deck into the player's hand then deletes that same card from the main deck 
void Dealer::hitPlayer(int vector) {

	if (split == false) {
		Card temp = deck.back();
		deck.pop_back();
		player.hit(temp);
	}
	else if (split == true && vector == 1) {
		Card temp = deck.back();
		deck.pop_back();
		player.hitSplitHands(vector, temp);
	}
	else if (split == true && vector == 2) {
		Card temp = deck.back();
		deck.pop_back();
		player.hitSplitHands(vector, temp);
	}
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

void Dealer::createView() {
	View _view = view;
}

// Returns the player's hand as a string
string Dealer::playerDeck_toString(int vector) {
  return "\n" + player.playerDeck(vector);
}

// Returns the player's total score
int Dealer::playerScore(int vector) {
	return player.getScore(vector);
}

string Dealer::playerScore_toString() {
	string playerScoreString;
	if (playerScore(0) > 21) {
		return playerScoreString = "Bust!\n";
	}
	else if (playerScore(0) == 21) {
		return playerScoreString = "Blackjack! You win!";
	}
	else {
		return playerScoreString = "Score: " + to_string(playerScore(0)) + "\n";
	}
}

string Dealer::dealerDeck_toString() {
	string dealerCards = "\nDealer hand\n";
		for (int i = 0; i < dealerHand.size(); i++) {
			dealerCards += to_string(dealerHand[i].getRank()) + " ";
		}
	dealerCards += "\n\n";
	return dealerCards;
}

int Dealer::dealerScore() {
  int dealerScore = 0;
  for (int i = 0; i < dealerHand.size(); i++) {
    dealerScore += dealerHand[i].getRank();
  }
  return dealerScore;
}

string Dealer::dealerScore_toString() {
	string dealerScoreString;
	if (dealerScore() > 21) {
		return dealerScoreString = "Dealer busts!\n";
	}
	return dealerScoreString = "Dealer score: " + to_string(dealerScore()) + "\n";
}

// Checks if the dealer's score is less than 17, if so hit, if not stay 
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

void Dealer::playerPlay() {
	while (playerScore(0) < 22 && playerScore(0) != 21 && !split) {
		int hitOrStay_selection;
		cout << view.hitOrStay_toString();
		cin >> hitOrStay_selection;

		if (hitOrStay_selection == 1) {
			hitPlayer(0);
		}
		else if (hitOrStay_selection == 2) {
			break;
		}
		cout << playerDeck_toString(0);
		cout << playerScore_toString();
	}
	
	while (split) {
		if (playerScore(1) > 21) {
			cout << "***** Bust *****" << endl;
			break;
		}
		
		int hitOrStay_selection;
		cout << "\n1st hand:\n1. Hit\n2. Stay\n";
		
		cin >> hitOrStay_selection;
		
		if (hitOrStay_selection == 1 && playerScore(1) < 22) {
			hitPlayer(1);
		}
		else if (hitOrStay_selection == 2) {
			break;
		}
		else {
			break;
		}
		cout << playerDeck_toString(1) << endl;
		dealerScore_toString();
	}
		
	while (split) {
		if (playerScore(2) > 21) {
			cout << "***** Bust *****" << endl;
			break;
		}
		
		int hitOrStay_selection;
		cout << "\n2st hand:\n1. Hit\n2. Stay\n";
		cin >> hitOrStay_selection;
		
		if (hitOrStay_selection == 1 && playerScore(2) < 22) {
			hitPlayer(2);
		}
		else if (hitOrStay_selection == 2) {
			break;
		}
		else {
			break;
		}
		cout << playerDeck_toString(2) << endl;
		cout << playerScore(2) << endl;
	}
	
	// Dealer's turn
	if (playerScore(0) != 21 || playerScore(1) != 21 || playerScore(2) != 21) {
		dealerPlay();
		cout << dealerDeck_toString() << dealerScore_toString();
	}
}
	
	
	
