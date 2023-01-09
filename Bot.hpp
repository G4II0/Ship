#ifndef BOT_HPP
#define BOT_HPP

#include "Mare.hpp"

namespace B
{
    class Bot
    {

        protected:

        char Name;
        M::Mare Mare;
        char Type;

        public:

        // costruttore
        Bot();
        Bot(M::Mare Mare, char N, char T);

        //set
        void Bot::setName(char name);
        void Bot::setMare(M::Mare mare);
        void Bot::setType(char type);
        
        //get
        char Bot::getName() const;
        M::Mare Bot::getMare() const;
        char Bot::getType() const;

        //Move
        void Bot::Move(M::Mare mare);
    };
}
#endif