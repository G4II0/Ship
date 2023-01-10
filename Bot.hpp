#ifndef BOT_HPP
#define BOT_HPP

#include <iostream>
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
        void setName(char name);
        void setMare(M::Mare mare);
        void setType(char type);
        
        //get
        char getName() const;
        M::Mare getMare() const;
        M::Mare getMareN(Bot b) const;
        char getType() const;

        //Move
        void Move(M::Mare mare, B::Bot bN);
    };
}
#endif