#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include "Mare.hpp"


    class Players
    {

        protected:

        char Name;
        Mare Mare;
        char Type;

        public:

        // costruttore
        Players();
        Players(Mare Mare, char N, char T);

        //set
        void setName(char name);
        void setMare(Mare Mare);
        void setType(char type);
        
        //get
        char getName() const;
        M::Mare getMare() const;
        char getType() const;

        //Move
        void Move(std::pair<int, int> pos, std::pair<int, int> dest, Mare m);
    };
#endif