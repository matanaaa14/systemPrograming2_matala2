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
    int numOfWins;
    int stacksize();
    int cardesTaken();
    Player() : playing(false), numOfWins(0){};
    Player(std::string);

};





#endif