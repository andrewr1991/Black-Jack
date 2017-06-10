#include "player.h"

void Player::initializeHand(Card card) {
		playerHand.push_back(card);
}

void Player::hit(Card card) {
  playerHand.push_back(card);
}

void Player::hitSplitHands(Card card1, Card card2) {
	playerHandSplit1.push_back(card1);
	playerHandSplit2.push_back(card2);
}

int Player::getScore(int vector) {
  int score = 0;
  
  if (vector = 0) {
	  for (int i = 0; i < playerHand.size(); i++) {
		score += playerHand[i].getRank();
	  }
	  return score;
  }
  else if (vector = 1) {
	  for (int i = 0; i < playerHandSplit1.size(); i++) {
		score += playerHandSplit1[i].getRank();
	  }
	  return score;
  }
  else if (vector = 2) {
	  for (int i = 0; i < playerHandSplit2.size(); i++) {
		score += playerHandSplit2[i].getRank();
	  }
	  return score;
  }
  else {
	  cout << "Enter a valid input" << endl;
  }
}

string Player::playerDeck() {
	string playerCards = "Player hand\n";
	for (int i = 0; i < playerHand.size(); i++) {
		playerCards += to_string(playerHand[i].getRank()) + " ";
	}
	playerCards += "\n\n";
	return playerCards;
}

string Player::playerSplitDeck() {
	string playerCardsSplit1 = "Player hand deck 1: "; string playerCardsSplit2 = "Player hand deck 2: ";
	
	for (int i = 0; i < playerHandSplit1.size(); i++) {
		playerCardsSplit1 += to_string(playerHandSplit1[i].getRank()) + " ";
	}
	
	for (int i = 0; i < playerHandSplit2.size(); i++) {
		playerCardsSplit2 += to_string(playerHandSplit2[i].getRank()) + " ";
	}
	
	playerCardsSplit1 += " ";
	
	return playerCardsSplit1 + playerCardsSplit1;
}
	

Card& Player::getCard(int index) {
	return playerHand[index];
}

void Player::splitCards() {
	playerHandSplit1[0] = playerHand[0];
	playerHandSplit2[0] = playerHand[1];
}
