#ifndef CONTROLLER_H
#define CONTROLLER_H 2017
#include "card.h"
#include "dealer.h"
#include "player.h"

using namespace std;

class Controller {
public:
  void deal();

private:
  Dealer dealer;
  Player player;
};

#endif
