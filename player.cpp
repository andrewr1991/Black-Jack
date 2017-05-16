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
