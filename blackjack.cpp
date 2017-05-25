#include <iostream>
#include <string>
#include "dealer.h"
#include "player.h"
#include "controller.h"
#include "view.h"

int main() {
	View view;
	int selection, hitOrStay_selection;
	cout << view.menu_toString();
	cin >> selection;

	if (selection == 1) {
		Controller controller;
		controller.createDealer();
		controller.createPlayer();
		controller.deal();
		while (true) {
			cout << controller.playerDeck_toString();
			cout << view.hitOrStay_toString();
			cin >> hitOrStay_selection;
			
			if (hitOrStay_selection == 1) {
				controller.hitPlayer();
			}
			else {
				break;
			}
		}
	}
	else {
	return 0;
	}
}
