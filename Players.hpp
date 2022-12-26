#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include "Mare.hpp"

namespace P
{
    //sucamiao
    class Players
    {

        protected:

        string Name;
        M::Mare *Mare;
        char Type;

        public:

        // costruttore
        Players(M::Mare *chessBoard, string N, char T);

        // player
        bool Move(string start, string end);
        int GetCondition();
        // bot
        bool Move();
    };
}
#endif