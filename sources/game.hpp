#ifndef GAME_HPP

#define GAME_HPP
#include "player.hpp"
using namespace std;
class Game{
    public:
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
     Game(Player,Player);
};





#endif