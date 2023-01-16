#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include "Mare.hpp"


    class Players
    {

        protected:

        std::string Name;
        Mare mare;
        char Type;
        int condition;
        Mare mareNemico;

        public:

        // costruttore
        Players();
        Players(Mare m, std::string N, char T);

        //set
        void setName(char name);
        void setMare(Mare m);
        void setMareN(Mare mN);
        void setType(char type);
        void setCondition(int c);
        
        //get
        std::string getName() const;
        Mare getMare() const;
        Mare getMareN() const;
        char getType() const;
        int getCondition() const;

        //Move
        void Moves(std::pair<int, int> pos, std::pair<int, int> dest, Mare m, Mare mN);
        void MovesB(Mare m, Mare mN);
    };
#endif