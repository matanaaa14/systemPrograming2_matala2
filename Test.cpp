#include "doctest.h"
#include "sources/game.hpp"
#include "sources/player.hpp"
#include "sources/card.hpp"
#include <iostream>
//#include <catch.hpp>

TEST_CASE("test player constructor"){
    CHECK_NOTHROW(Player player("player"));
    //CHECK_THROWS(Player player2("l"));
}

TEST_CASE("test stacksize"){
    Player player("player");
    CHECK_NOTHROW(player.stacksize());
    CHECK(player.stacksize() == 0);
}

TEST_CASE("test cardesTaken"){
    Player player("player");
    CHECK_NOTHROW(player.cardesTaken());
    CHECK(player.cardesTaken() == 0);
}

TEST_CASE("test game constructor"){
    Player player1("player1");
    Player player2("player2");
    CHECK_NOTHROW(Game game(player1,player2));
    //CHECK_THROWS(Game game2(player1,9));
    CHECK(player1.stacksize() == 26);
    CHECK(player2.stacksize() == 26);
    CHECK(player1.cardesTaken() == 0);
    CHECK(player2.cardesTaken() == 0);
}
TEST_CASE("test playturn"){
    Player player1("player1");
    Player player2("player2");
    Game game(player1,player2);
    for(int i=1;i<=10;i++){
        CHECK_NOTHROW(game.playTurn());
        CHECK(player1.stacksize()+player2.stacksize()<=56-(2*i));
        CHECK(player1.stacksize()+player2.stacksize()>=0);        
        CHECK(player1.cardesTaken()+player2.cardesTaken()>=(2*i));
        CHECK(player1.cardesTaken()+player2.cardesTaken()<=56);
        CHECK(player1.stacksize()+player1.cardesTaken()+player2.stacksize()+player2.cardesTaken() == 56);
    }
}
TEST_CASE("test void"){
    Player player1("player1");
    Player player2("player2");
    Game game(player1,player2);
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printLastTurn());
    
}
TEST_CASE("test playAll"){
    Player player1("player1");
    Player player2("player2");
    Game game(player1,player2);
    CHECK_NOTHROW(game.playAll());
    int flag1=0,flag2=0,flag=0;
    if(player1.cardesTaken() == 0 && player2.cardesTaken() == 56)
        flag1=1;
    if(player1.cardesTaken() == 56 && player2.cardesTaken() == 0)
        flag2=1;
    if( flag1 == 1 || flag2 == 1)
        flag=1;
    //CHECK((player1.cardesTaken() == 0 && player2.cardesTaken() == 56)||(player1.cardesTaken() == 56 && player2.cardesTaken() == 0));
    //CHECK(flag1 == 1|| flag2 == 1);
    CHECK(flag == 1);
}

