#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include "Mare.hpp"

namespace P
{
    class Players
    {

        protected:

        char Name;
        M::Mare *Mare;
        char Type;

        public:

        // costruttore
        Players();
        Players(M::Mare *chessBoard, string N, char T);

        //set
        void Players::setName(char name);
        void Players::setMare(char Mare);
        void Players::setType(char type);
        
        //get
        void Players::getName();
        void Players::getMare();
        void Players::getType();

        //Move
        void Players::Move(pair<int, int> pos, pair<int, int> dest, Mare m);
    };
}
#endif