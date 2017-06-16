#include "player.h"

void Player::initializeHand(Card card) {
		playerHand.push_back(card);
}

void Player::hit(Card card) {
  playerHand.push_back(card);
}

void Player::hitSplitHands(int vector, Card card) {
	if (vector == 1) {
		playerHandSplit1.push_back(card);
	}
	else if (vector == 2) {
		playerHandSplit2.push_back(card);
	}
}

int Player::getScore(int vector) {
  int score = 0;
  
  if (vector == 0) {
	  for (int i = 0; i < playerHand.size(); i++) {
		score += playerHand[i].getRank();
	  }
	  return score;
  }
  else if (vector == 1) {
	  for (int i = 0; i < playerHandSplit1.size(); i++) {
		score += playerHandSplit1[i].getRank();
	  }
	  return score;
  }
  else if (vector == 2) {
	  for (int i = 0; i < playerHandSplit2.size(); i++) {
		score += playerHandSplit2[i].getRank();
	  }
	  return score;
  }
  else {
	  cout << "Enter a valid input" << endl;
  }
}

string Player::playerDeck(int vector) {
	
	if (vector == 0) {
		string playerCards = "Player hand\n";
		for (int i = 0; i < playerHand.size(); i++) {
			playerCards += to_string(playerHand[i].getRank()) + " ";
		}
		playerCards += "\n\n";
		return playerCards;
	}
	else if (vector == 1) {
		string playerCardsSplit1 = "Player hand deck 1: ";
		for (int i = 0; i < playerHandSplit1.size(); i++) {
			playerCardsSplit1 += to_string(playerHandSplit1[i].getRank()) + " ";
		}
		playerCardsSplit1 += " ";
		return playerCardsSplit1;
	}
	else if (vector == 2) {
		string playerCardsSplit2 = "Player hand deck 2: ";
		for (int i = 0; i < playerHandSplit2.size(); i++) {
			playerCardsSplit2 += to_string(playerHandSplit2[i].getRank()) + " ";
	}
		playerCardsSplit2 += "\n";
		return playerCardsSplit2;
	}
}

Card& Player::getCard(int index) {
	return playerHand[index];
}

void Player::splitCards() {
	playerHandSplit1.push_back(playerHand[0]);
	playerHandSplit2.push_back(playerHand[1]);
}
