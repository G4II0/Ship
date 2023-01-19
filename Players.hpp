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

        //setter
        void setName(char name);
        void setMare(Mare m);
        void setMareN(Mare mN);
        void setType(char type);
        void setCondition(int c);
        
        //getter
        std::string getName() const;
        Mare &getMare();
        Mare getMareN() const;
        char getType() const;
        int getCondition() const;

        //metodo che lette le istruzioni da tastiera muove le navi
        void Moves(std::pair<int, int> pos, std::pair<int, int> dest, Mare m, Mare mN);
        
        //mosse randomiche del bot
        void MovesB(Mare m, Mare mN);
    };
#endif