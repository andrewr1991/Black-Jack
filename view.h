#ifndef VIEW_H
#define VIEW_H 2017
#include <iostream>
#include <string>

using namespace std;

class View {
  private:
    string menu = "Blackjack 1.0\n1. Start new game\n0. exit";

  public:
    string menu_toString();
};
#endif
