#include <iostream>
#include <string>
#include "dealer.h"
#include "player.h"
#include "controller.h"
#include "view.h"

int main() {
	View view;
	int selection;
	cout << view.menu_toString();
	cin >> selection;

	if (selection == 1) {
		Controller controller(Dealer dealer, Player player);
		while (true) {

		}
	}
	else {
	return 0;
	}
}
