#include <iostream>
#include <string>
#include "card.h"
#include "dealer.h"
#include "player.h"

int main() {
  Dealer dealer;
  dealer.createDeck();
  dealer.shuffleDeck();
  return 0;
}
