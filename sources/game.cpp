#include "game.hpp"
#include "card.hpp"
using namespace std;
#include <vector>
#include <algorithm> // for shuffle
#include <iostream>
#include <random>
using namespace std;
    void Game::playTurn(){
        if(this->player1.myCards.size() == 0 || this->player2.myCards.size() == 0 ){
            cout << "on of the players already finish all his cards " << endl;
            return;
        }
        
        Card c1=this->player1.myCards.top();
        Card c2=this->player2.myCards.top();
        cout << "the card is: "<< c1.toString() <<endl;
        cout << "the second card is: "<< c2.toString() <<endl;
        player1.myCards.pop();
        player2.myCards.pop();
        if(c1.value == c2.value){
            this->lastTurn= player1.name + " played " +c1.strValue +" of "+ c1.type + " " + player2.name + " played " +c2.strValue +" of "+ c2.type ;

            while(c1.value == c2.value && player1.myCards.size() > 2 && player2.myCards.size() > 2 ){
                cardsOnTable1.push(c1);
                cardsOnTable2.push(c2);
                cardsOnTable1.push(player1.myCards.top());
                cardsOnTable2.push(player2.myCards.top());
                player1.myCards.pop();
                player2.myCards.pop();
                Card c1=this->player1.myCards.top();
                Card c2=this->player2.myCards.top();
                player1.myCards.pop();
                player2.myCards.pop();
                this->lastTurn+= ", " + player1.name + " played " +c1.strValue +" of "+ c1.type + " " + player2.name + " played " +c2.strValue +" of "+ c2.type ;

            }
        
        if(c1.value == c2.value){//which means that the cards end during the tie break
            while(!cardsOnTable1.empty()){
                this->player1.takenCards.push(cardsOnTable1.top());
                cardsOnTable1.pop();
            }
            while(!cardsOnTable2.empty()){
                this->player2.takenCards.push(cardsOnTable2.top());
                cardsOnTable2.pop();
            }
            return;
        }
        if(c1.value > c2.value){
            while(!cardsOnTable1.empty()){
                this->player1.takenCards.push(cardsOnTable1.top());
                cardsOnTable1.pop();
            }
            while(!cardsOnTable2.empty()){
                this->player1.takenCards.push(cardsOnTable2.top());
                cardsOnTable2.pop();
            }
            return;
        }
        if(c1.value < c2.value){
            while(!cardsOnTable1.empty()){
                this->player2.takenCards.push(cardsOnTable1.top());
                cardsOnTable1.pop();
            }
            while(!cardsOnTable2.empty()){
                this->player2.takenCards.push(cardsOnTable2.top());
                cardsOnTable2.pop();
            }
            return;
        }
        }
        if(c1.value > c2.value){
            player1.takenCards.push(c1);
            player1.takenCards.push(c2);
            this->lastTurn= player1.name + " played " +c1.strValue +" of "+ c1.type + " " + player2.name + " played " +c2.strValue +" of "+ c2.type + "," + player1.name + " won";

        }
        if(c1.value < c2.value){
            player2.takenCards.push(c1);
            player2.takenCards.push(c2);
            this->lastTurn= player1.name + " played " +c1.strValue +" of "+ c1.type + " " + player2.name + " played " +c2.strValue +" of "+ c2.type + "," + player2.name + " won";

        }
    }
    void Game::printLastTurn(){}
    void Game::playAll(){}
    void Game::printWiner(){}
    void Game::printLog(){}
    void Game::printStats(){}
    
    Game::Game(Player& p1,Player& p2) : player1(p1),player2(p2){
        if(p1.playing == true || p2.playing == true){
            cout << "player 1 or 2 already playing and can't join another game" << endl;
            exit(1);
        }
        this->lastTurn="";
        p1.playing = true;
        p2.playing = true;
        //this->player1 = p1;
        //this->player2 = p2;
        for(int i=1;i<=13;i++){
            for(int j=1;j<=4;j++){
                string t=cardType(j);
                Card card(i,t);
                this->gameCards.push(card);
            }
        }
        vector<Card> v(this->gameCards.size());
        unsigned long gameCardsSize = gameCards.size();
        for(unsigned long a = 0; a < gameCardsSize; a++){
            v[a] = this->gameCards.top();
            this->gameCards.pop();

        }

        shuffle(v.begin(),v.end(),default_random_engine());
        for(unsigned long b=0; b < v.size(); b++){
            this->gameCards.push(v[b]);

        }
        int c=0;

        while(!this->gameCards.empty()){
            cout<< "shuffle"<<gameCards.top().toString()<<endl;
            if(c % 2 == 0){
                this->player1.myCards.push(this->gameCards.top());
            }
            else{
                this->player2.myCards.push(this->gameCards.top());
            }
            this->gameCards.pop();
            c++;
            
        }
    }
    string Game::cardType(int num){
        switch(num){
            case 1:
                return "Clover";
            case 2:
                return "Diamond";
            case 3:
                return "Heart";
            case 4:
                return "Leaf";
        }
        return "";
    }