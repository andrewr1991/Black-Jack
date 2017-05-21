#ifndef CONTROLLER_H
#define CONTROLLER_H 2017
#include "card.h"
#include "dealer.h"
#include "player.h"

using namespace std;

class Controller {
	public:
		void createDealer();
		void createPlayer();
		void deal();
		void showPlayerDeck();
		void showDealerDeck();
		string playerDeck_toString();
		
	private:
		Dealer dealer;
		Player player;
};

#endif
