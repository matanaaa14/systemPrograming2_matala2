#ifndef GAME_HPP

#define GAME_HPP
#include "player.hpp"
#include "card.hpp"
#include <stack>
using namespace std;
class Game{
    public:
    stack<Card> gameCards;
    stack<Card> cardsOnTable1;//the cards player put on the table
    stack<Card> cardsOnTable2;//the cards player 2 put on the table
    string lastTurn;
    stack<string> allTurns;
    Player& player1;
    Player& player2;
    int numOfRounds;
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
    Game(Player&,Player&);
    string cardType(int num);
    };





#endif