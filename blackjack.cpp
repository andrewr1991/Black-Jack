#include <iostream>
#include <string>
#include "dealer.h"
#include "player.h"
#include "view.h"

int main() {
	View view;
	int selection;
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
			dealer.playerPlay();
			dealer.checkFinalScore();
			
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
