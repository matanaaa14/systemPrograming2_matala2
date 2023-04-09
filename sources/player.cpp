#include "player.hpp"
#include <iostream>
#include <sstream>
using namespace std;


int Player::stacksize(){
    return myCards.size();
 }
int Player::cardesTaken(){
    return this->takenCards.size();
}
Player::Player(std::string newName){
    this->name = newName;
    this->playing = false;
}