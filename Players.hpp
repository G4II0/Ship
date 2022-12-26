#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include "Mare.hpp"


class Gamers
{

    protected:

    string Name;
    char Color;
    M::Mare *Mare;
    char Type;

    public:

    // costruttore
    Gamers(M::Mare *chessBoard, string N, char T);

    // player
    bool Move(string start, string end);
    int GetCondition();
    // bot
    bool Move();
};

#endif