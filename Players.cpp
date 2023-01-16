#include "Players.hpp"

    Players::Players()
    {}

    Players::Players(Mare m, std::string N, char T)
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
    void Players::setCondition(int c)
    {this -> condition = c;}

    std::string Players::getName() const
    {return this -> Name;}
    Mare Players::getMare() const
    {return this -> mare;}
    char Players::getType() const
    {return this -> Type;}
    int Players::getCondition() const
    {return this -> condition;}

    // player
    void Players::Moves(pair<int, int> pos, pair<int, int> dest, Mare m, Mare mN)
    {
        m.MoveG(pos, dest, m, mN);
    }