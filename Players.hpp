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
        Players(M::Mare *Mare, char N, char T);

        //set
        void Players::setName(char name);
        void Players::setMare(M::Mare Mare);
        void Players::setType(char type);
        
        //get
        void Players::getName() const;
        void Players::getMare() const;
        void Players::getType() const;

        //Move
        void Players::Move(pair<int, int> pos, pair<int, int> dest, M::Mare m);
    };
}
#endif