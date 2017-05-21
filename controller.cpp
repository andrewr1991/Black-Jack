#include "controller.h"

void Controller::deal() {
  dealer.createDeck();
  dealer.shuffleDeck();

  for (int i = 0; i < 2; i++) {
    dealer.hitDealer();
    player.hit(dealer.hitPlayer());
  }
}
