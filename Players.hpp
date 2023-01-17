#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include "Mare.hpp"


    class Players
    {

        protected:
        //dichiarazione delle variabili della classe Players
        std::string name_;
        Mare mare_;
        char type_;
        int condition_;
        Mare mareNemico_;
        int count_;
        int count2_;
        int count3_;

        public:

        // costruttori
        Players();
        Players(Mare m, std::string N, char T, Mare mN);

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