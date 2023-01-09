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

    // bot
    void Bot::Move(M::Mare mare)
    { 
        srand(time(NULL));
        pair<int, int> pos;
        pair<int, int> dest;
        int dx = rand()%3;
        int dy = rand()%3;
        int r0 = rand()%3;
        int r1 = rand()%3;
        int r1_1 = rand()%2;
        dest.first= dx;
        dest.second = dy;
        if(r0 = 0)
        {
            S::Corazzata a[3] = mare.getMarCor();
            pos = (a[r1]).getPMedio();
        }
        else
        if(r0 = 1)
        {
            S::Nds a[3] = mare.getMarNds();
            pos = (a[r1]).getPMedio();
        }
        else
        if(r0 = 2)
        {
            S::Sde a[2] = mare.getMarSde();
            pos = (a[r1_1]).getPMedio();
        }
        Mare.Move(pos, dest, mare);
    }
}