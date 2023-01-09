#include "Bot.hpp"
#include <cstdlib>

namespace B
{
    Bot::Bot()
    {}

    Bot::Bot(M::Mare mare, char N, char T)
    {
        this -> Name= N;
        this -> Mare = mare;
        this -> Type = T;
    }

    void Bot::setName(char name)
    {this -> Name = name;}
    void Bot::setMare(M::Mare mare)
    {this -> Mare = mare;}
    void Bot::setType(char type)
    {this -> Type = type;}

    char Bot::getName() const
    {return this -> Name;}
    M::Mare Bot::getMare() const
    {return this -> Mare;}
    char Bot::getType() const
    {return this -> Type;}

    // player
    void Bot::Move(M::Mare mare)
    { 
        srand(time(NULL));
        int q = 0;
        int n = rand()%7;
        pair<int, int> pos;
        pair<int, int> dest;
        pos = ;
        do{
        int x = rand()%12;
        int y = rand()%12;
        dest.first= x;
        dest.second = y;
        Mare.Move(pos, dest, mare);
        if 
        }while(q == 0);
    }
}