#ifndef CONTROLLER_H
#define CONTROLLER_H 2017
#include "card.h"
#include "dealer.h"

using namespace std;

class Controller {
public:
  Card deal();

private:
  Dealer dealer;
};

#endif
