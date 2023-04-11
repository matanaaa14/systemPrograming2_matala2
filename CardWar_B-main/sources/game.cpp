#include "game.hpp"
#include "card.hpp"
using namespace std;
#include <vector>
#include <algorithm> // for shuffle
#include <iostream>
#include <random>
#include <stdexcept>
#include<string.h>

using namespace std;
    void Game::playTurn(){
        this->numOfRounds+=1;
        if(this->player1.myCards.size() == 0 || this->player2.myCards.size() == 0 ){
             throw logic_error("on of the players already finish all his cards ");
        }
        
        Card c1=this->player1.myCards.top();
        Card c2=this->player2.myCards.top();
        //cout << "the card is: "<< c1.toString() <<endl;
        //cout << "the second card is: "<< c2.toString() <<endl;
        player1.myCards.pop();
        player2.myCards.pop();
        //cout << "card 1 value: " << c1.value <<endl;
        //cout << "card 2 value: " << c2.value <<endl;

        if(c1.value == c2.value){
            //cout << "-----------------" << endl;
            //cout << player1.myCards.size() <<endl;//check
            this->lastTurn= player1.name + " played " +c1.strValue +" of "+ c1.type + " " + player2.name + " played " +c2.strValue +" of "+ c2.type ;
            this->allTurns.push(this->lastTurn);

            while(c1.value == c2.value && player1.myCards.size() >= 2 && player2.myCards.size() >= 2 ){
                //cout << "$$$$$$$$$$" << endl;
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
                cardsOnTable1.push(c1);
                cardsOnTable2.push(c2);
                this->lastTurn+= ", " + player1.name + " played " +c1.strValue +" of "+ c1.type + " " + player2.name + " played " +c2.strValue +" of "+ c2.type ;
                this->allTurns.push(this->lastTurn);
            }
            if(this->player1.stacksize() == 0 || this->player2.stacksize() ==0){
            this->player1.playing = false;
            this->player2.playing = false;} 
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
            this->player1.numOfWins+=1;
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
            this->player2.numOfWins+=1;
            return;
        }
        }
        if(this->player1.stacksize() == 0 || this->player2.stacksize() ==0){
        this->player1.playing = false;
        this->player2.playing = false;} 
        if(c1.value > c2.value){
            player1.takenCards.push(c1);
            player1.takenCards.push(c2);
            this->lastTurn= player1.name + " played " +c1.strValue +" of "+ c1.type + " " + player2.name + " played " +c2.strValue +" of "+ c2.type + "," + player1.name + " won";
            this->allTurns.push(this->lastTurn);
            this->player1.numOfWins+=1;
            return;
        }
        if(c1.value < c2.value){
            player2.takenCards.push(c1);
            player2.takenCards.push(c2);
            this->lastTurn= player1.name + " played " +c1.strValue +" of "+ c1.type + " " + player2.name + " played " +c2.strValue +" of "+ c2.type + "," + player2.name + " won";
            this->allTurns.push(this->lastTurn);
            this->player2.numOfWins+=1;
            return;

        }
    }
    void Game::printLastTurn(){
        if(this->lastTurn.empty()){
            throw logic_error("not played yet");
        }
        cout << this->lastTurn <<endl;
    }
    void Game::playAll(){
        while(this->player1.stacksize() > 0 && this->player2.stacksize() > 0){
            playTurn();
        }
        player1.playing = false;
        player2.playing = false;
        cout << "game over" << endl;
    }
    void Game::printWiner(){
        if(this->player1.cardesTaken() == this->player2.cardesTaken()){
            cout << "there is no winner " << endl;
        }
        if(this->player1.cardesTaken() > this->player2.cardesTaken()){
            cout << "the winner is: " << this->player1.name << endl;
        }
        else{
            cout << "the winner is: " << this->player2.name << endl;
        }
    }
    void Game::printLog(){
        if(this->allTurns.empty()){
            throw logic_error("not played yet");
        }
        stack<string> temp;
        while(!this->allTurns.empty()){
            temp.push(this->allTurns.top());
            this->allTurns.pop();
        }
        while(!temp.empty()){
            cout << temp.top() << endl;
            this->allTurns.push(temp.top());
            temp.pop();
        }
    }
    void Game::printStats(){
        double winRate1, winRate2;
        winRate1 =100 * (double) this->player1.numOfWins/this->numOfRounds;
        winRate2 =100 * (double) this->player2.numOfWins/this->numOfRounds;
        cout << player2.numOfWins << endl;
        cout << player1.name + " won " << winRate1 << "% " << "and have " << player1.cardesTaken() << " cards" << endl; 
        cout << player2.name + " won " << winRate2 << "% " << "and have " << player2.cardesTaken() << " cards" << endl; 

    }
    
    Game::Game(Player& p1,Player& p2) : player1(p1),player2(p2){
        if(p1.playing == true || p2.playing == true){
            cout << "player 1 or 2 already playing and can't join another game" << endl;
            exit(1);
        }
        this->numOfRounds = 0;
        this->lastTurn = "";
        p1.playing = true;
        p2.playing = true;
        //this->player1 = p1;
        //this->player2 = p2;
        for(int i=2;i<=14;i++){
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

        std::shuffle(v.begin(),v.end(),default_random_engine(7));
        for(unsigned long b=0; b < v.size(); b++){
            this->gameCards.push(v[b]);

        }
        int c=0;

        while(!this->gameCards.empty()){
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