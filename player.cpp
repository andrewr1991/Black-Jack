#include "player.h"

void Player::initializeHand(Card card) {
		playerHand.push_back(card);
}

void Player::hit(Card card) {
  playerHand.push_back(card);
}

int Player::getScore() {
  int score = 0;
  for (int i = 0; i < playerHand.size(); i++) {
    score += playerHand[i].getRank();
  }
  return score;
}

string Player::playerDeck() {
	string playerCards = "Player hand\n";
	for (int i = 0; i < playerHand.size(); i++) {
		playerCards += to_string(playerHand[i].getRank()) + " ";
	}
	playerCards += "\n\n";
	return playerCards;
}

Card& Player::getCard(int index) {
	return playerHand[index];
}

void moveSplitCards() {
	playerHandSplit1[0] = playerHand[0];
	playerHandSplit2[0] = playerHand[1];
}
