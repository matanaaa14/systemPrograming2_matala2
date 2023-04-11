#include <iostream>
#include "card.hpp"
#include "player.hpp"
#include "game.hpp"
using namespace std;
int main2() {
    Player p1("matan1");
    Player p2("matan2");
    Game game(p1,p2);
    cout << p1.stacksize() <<endl ;
  return 0;
}
