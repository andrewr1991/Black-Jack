#include "controller.h"

void Controller::deal() {
  dealer.createDeck();
  dealer.shuffleDeck();

  for (int i = 0; i < 2; i++) {
    dealer.hitDealer();
    player.hit(dealer.hitPlayer());
  }
}

void Controller::createDealer() {
	Dealer _dealer = dealer;
}

void Controller::createPlayer() {
	Player _player = player;
}

string Controller::playerDeck_toString() {
	return player.playerDeck();
}
	
