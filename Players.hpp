#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include "Mare.hpp"

namespace P
{
    class Players
    {

        protected:

        char Name;
        M::Mare Mare;
        char Type;

        public:

        // costruttore
        Players();
        Players(M::Mare Mare, char N, char T);

        //set
        void Players::setName(char name);
        void Players::setMare(M::Mare Mare);
        void Players::setType(char type);
        
        //get
        char Players::getName() const;
        M::Mare Players::getMare() const;
        char Players::getType() const;

        //Move
        void Players::Move(pair<int, int> pos, pair<int, int> dest, M::Mare m);
    };
}
#endif