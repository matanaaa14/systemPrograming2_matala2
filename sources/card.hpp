#ifndef CARD_HPP

#define CARD_HPP
#include<string>
using namespace std;
class Card{
    public:
    std::string type;
    std::string strValue;
    int value;

    string toString();
    Card(int,string);
    string createStrValue(int num);
    Card();
};

namespace ariel{}



#endif