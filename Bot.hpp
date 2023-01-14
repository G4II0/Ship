#ifndef BOT_HPP
#define BOT_HPP

#include "Mare.hpp"

    class Bot
    {

        protected:
        char Name;
        Mare mare;
        char Type;

        public:

        // costruttore
        Bot();
        Bot(Mare m, char N, char T);

        //set
        void setName(char name);
        void setMare(Mare m);
        void setType(char type);
        
        //get
        char getName() const;
        Mare getMare() const;
        Mare getMareN(Bot b) const;
        char getType() const;

        //Move
        void Move(Mare m, Bot bN);
    };

#endif