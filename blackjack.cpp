#include <iostream>
#include <string>
#include "dealer.h"
#include "player.h"
#include "view.h"

int main() {
	View view;
	int selection, hitOrStay_selection;
	cout << view.menu_toString();
	cin >> selection;

	if (selection == 1) {
		Dealer dealer;
		dealer.createPlayer();
		dealer.createDeck();
		dealer.shuffleDeck();
		dealer.deal();
		while (true) {
			cout << dealer.playerDeck_toString() << dealer.playerScore();
			
			cout << view.hitOrStay_toString();
			cin >> hitOrStay_selection;

			if (hitOrStay_selection == 1) {
				dealer.hitPlayer();
			}
			else if (hitOrStay_selection == 2) {
				cout << dealer.dealerDeck_toString() << dealer.dealerScore();
				dealer.dealerPlay();
				cout << dealer.dealerDeck_toString() << dealer.dealerScore();
				break;
			}
		}
	}
	else {
	return 0;
	}
}
