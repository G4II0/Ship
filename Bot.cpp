#include "Bot.hpp"
#include "Mare.hpp"
#include <cstdlib>


    Bot::Bot()
    {}

    Bot::Bot(Mare m, char N, char T)
    {
        this -> Name= N;
        this -> mare = m;
        this -> Type = T;
    }

    void Bot::setName(char name)
    {this -> Name = name;}
    void Bot::setMare(Mare m)
    {this -> mare = m;}
    void Bot::setType(char type)
    {this -> Type = type;}
    void Bot::setCondition(int c)
    {this -> condition = c;}

    char Bot::getName() const
    {return this -> Name;}
    Mare Bot::getMare() const
    {return this -> mare;}
    Mare Bot::getMareN(Bot b) const
    {return b.getMare();}
    Mare Bot::getMareN(Players p) const
    {return b.getMare();}
    char Bot::getType() const
    {return this -> Type;}
    int Bot::getCondition() const
    {return this -> condition;}
    // bot
    void Bot::MovesB(Mare m, Players pN)
    { 
        srand(time(NULL));
        pair<int, int> pos;
        pair<int, int> dest;
        vector<pair<int, int> > des;
        int r0 = rand()%3;
        int r1_1 = rand()%2;
        if(r0 == 0)
        {
            vector<Corazzata> a = m.getMarCor();
            int s = a.size();
            int r1 = rand()%s;
            pos = (a[r1]).getPMedio();
            des = m.posAvailable(a[r1]);
        }
        else
        if(r0 == 1)
        {
            vector<Nds> a = m.getMarNds();
            int s = a.size();
            int r1 = rand()%s;
            pos = (a[r1]).getPMedio();
            des = m.posAvailable(a[r1]);
        }
        else
        if(r0 == 2)
        {
            vector<Sde> a = m.getMarSde();
            int s = a.size();
            int r1 = rand()%s;
            pos = (a[r1_1]).getPMedio();
            des = m.posAvailable(a[r1]);
        }
        int d = (des.size());
        dest = des[d];
        m.MoveG(pos, dest, m, getMareN(pN));
    }
