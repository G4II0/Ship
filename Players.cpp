#include "Players.hpp"
#include "Mare.hpp"

namespace P
{
    P::Players()
    {}

    P::Players(Mare *mare, char N, char T)
    {
        this -> Name= N;
        this -> Mare = mare;
        this -> Type = T;
    }

    void Players::setName(char name)
    {this -> Name = name;}
    void Players::setType(Mare mare)
    {this -> Mare = mare;}
    void Players::setType(char type)
    {this -> Type = type;}

    char Players::getName() const
    {return this -> Name;}
    Mare Players::getMare() const
    {return this -> Mare;}
    char Players::getType() const
    {return this -> Type;}

    // player
    void Players::Move(pair<int, int> pos, pair<int, int> dest, Mare m)
    {
        Mare::Move(pos, dest, m);
    }
}