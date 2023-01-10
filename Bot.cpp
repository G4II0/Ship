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
    M::Mare Bot::getMareN(B::Bot b) const
    {return b.getMare();}
    char Bot::getType() const
    {return this -> Type;}

    // bot
    void Bot::Move(M::Mare mare, B::Bot bN)
    { 
        srand(time(NULL));
        pair<int, int> pos;
        pair<int, int> dest;
        vector<pair<int, int>> des;
        int r0 = rand()%3;
        int r1_1 = rand()%2;
        if(r0 = 0)
        {
            vector<S::Corazzata> a = mare.getMarCor();
            int s = a.size();
            int r1 = rand()%s;
            pos = (a[r1]).getPMedio();
            des = mare.posAvailable(a[r1]);
        }
        else
        if(r0 = 1)
        {
            vector<S::Nds> a = mare.getMarNds();
            int s = a.size();
            int r1 = rand()%s;
            pos = (a[r1]).getPMedio();
            des = mare.posAvailable(a[r1]);
        }
        else
        if(r0 = 2)
        {
            vector<S::Sde> a = mare.getMarSde();
            int s = a.size();
            int r1 = rand()%s;
            pos = (a[r1_1]).getPMedio();
            des = mare.posAvailable(a[r1]);
        }
        int d = (des.size());
        dest = des[d];
        Mare.Move(pos, dest, mare, getMareN(bN));
    }
}