#ifndef PLAYER_HPP

#define PLAYER_HPP
#include <iostream>
#include <sstream>
#include "player.hpp"
using namespace std;
class Player{
    public:
    int stacksize();
    int cardesTaken();
    Player(){};
    Player(std::string);
};





#endif