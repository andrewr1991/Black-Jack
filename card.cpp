#include "card.h"

int Card::getRank() {
  return rank;
}

string Card::suitToString() {
  switch(suit) {
    case 0:
      return "Diamond";
    case 1:
      return "Heart";
    case 2:
      return "Club";
    case 3:
      return "Spade";
  }
}

void Card::changeRank(int change) {
	rank = change;
}
