#include <iostream>
#include <string>
#include "dealer.h"
#include "player.h"
#include "view.h"

int main() {
	View view;
	int selection, hitOrStay_selection;
	string playAgain;
	cout << view.menu_toString();
	cin >> selection;

	if (selection == 1) {
			while(true) {
			Dealer dealer;
			dealer.createPlayer();
			dealer.createDeck();
			dealer.shuffleDeck();
			dealer.deal();
			while (true) {
				if (dealer.playerScore() < 21) {
					cout << view.hitOrStay_toString();
					cin >> hitOrStay_selection;

					if (hitOrStay_selection == 1) {
						dealer.hitPlayer();
					}
					else if (hitOrStay_selection == 2) {
						dealer.dealerPlay();
						cout << dealer.dealerDeck_toString() << dealer.dealerScore_toString();
						break;
					}
				}
				else {
					break;
				}
				// Print the users deck
				cout << dealer.playerDeck_toString() << dealer.playerScore_toString();				
			}
			cout << "Play again? (yes or no) ";
			cin >> playAgain;
			if (playAgain == "no") {
				break;
			}
			cout << endl << "***** New Game *****" << endl;
		}
	}
	else {
	return 0;
	}
}
