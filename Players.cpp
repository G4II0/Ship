#include "Players.hpp"

    Players::Players()
    {}

    Players::Players(Mare m, std::string N, char T)
    {
        this -> Name= N;
        this -> mare = m;
        this -> Type = T;
    }
    Players::Players(Mare m, std::string N, char T, Mare mN)
    {
        this -> Name= N;
        this -> MareNemico = mN;
        this -> mare = m;
        this -> Type = T;
    }

    void Players::setName(char name)
    {this -> Name = name;}
    void Players::setMare(Mare m)
    {this -> mare = m;}
    void Players::setMareN(Mare mN)
    {this -> mare = mN;}
    void Players::setType(char type)
    {this -> Type = type;}
    void Players::setCondition(int c)
    {this -> condition = c;}

    std::string Players::getName() const
    {return this -> Name;}
    Mare Players::getMare() const
    {return this -> mare;}
    Mare Players::getMareN() const
    {return this -> mareNemico;}
    char Players::getType() const
    {return this -> Type;}
    int Players::getCondition() const
    {return this -> condition;}

    // player
    void Players::Moves(pair<int, int> pos, pair<int, int> dest, Mare m, Mare mN)
    {
        m.MoveG(pos, dest, m, mN);
    }
    void Players::MovesB(Mare m, Mare mN)
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
        m.MoveG(pos, dest, m, getMareN(mN));
    }