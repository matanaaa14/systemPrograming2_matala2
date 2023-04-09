#ifndef PLAYER_HPP

#define PLAYER_HPP
#include <iostream>
#include <sstream>
#include "player.hpp"
#include "card.hpp"
#include <stack>

using namespace std;
class Player{
    public:
    stack<Card> myCards;
    stack<Card> takenCards;
    bool playing;
    string name;
    int stacksize();
    int cardesTaken();
    Player(){};
    Player(std::string);
};





#endif