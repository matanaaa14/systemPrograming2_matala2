namespace ariel{}
#include <iostream>
#include "card.hpp"
using namespace std;
Card::Card(int newValue,string newType){
    this->value = newValue;
    this->type = newType;
    this->strValue = createStrValue(newValue);
}
string Card::createStrValue(int num){

    switch(num){
        case 1:
            return "Ace";
        case 2:
            return "Two";
        case 3:
            return "Three";
        case 4:
            return "Four";
        case 5:
            return "Five";
        case 6:
            return "Six";
        case 7:
            return "Seven";
        case 8:
            return "Eight";
        case 9:
            return "Nine";
        case 10:
            return "Ten";
        case 11:
            return "Prince";
        case 12:
            return "Queen";
        case 13:
            return "King";

    }return "";
}
string Card::toString(){
    return this->type+" ,"+this->strValue;
}   
Card::Card(){
    this->value=0;
    this->type="";
    this->strValue="";
}