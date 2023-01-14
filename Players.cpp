#include "Players.hpp"

    Players::Players()
    {}

    Players::Players(Mare m, char N, char T)
    {
        this -> Name= N;
        this -> mare = m;
        this -> Type = T;
    }

    void Players::setName(char name)
    {this -> Name = name;}
    void Players::setMare(Mare m)
    {this -> mare = m;}
    void Players::setType(char type)
    {this -> Type = type;}

    char Players::getName() const
    {return this -> Name;}
    Mare Players::getMare() const
    {return this -> mare;}
    char Players::getType() const
    {return this -> Type;}

    // player
    /*void Players::Move(pair<int, int> pos, pair<int, int> dest, Mare m)
    {
        mare.Move(pos, dest, m);
    }*/