#include "Players.hpp"

    //costruttore vuoto
    Players::Players()
    {}

    //costruttore
    Players::Players(Mare m, std::string N, char T, Mare mN)
    {
        this -> name_ = N;
        this -> mareNemico_ = mN;
        this -> mare_ = m;
        this -> type_ = T;
        this -> count_ = 3;
        this -> count2_ = 3;
        this -> count3_ = 3;
    }

    //setter
    void Players::setName(char name)
    {this -> name_ = name;}
    void Players::setMare(Mare m)
    {this -> mare_ = m;}
    void Players::setMareN(Mare mN)
    {this -> mare_ = mN;}
    void Players::setType(char type)
    {this -> type_ = type;}
    void Players::setCondition(int c)
    {this -> condition_ = c;}

    //getter
    std::string Players::getName() const
    {return this -> name_;}
    Mare& Players::getMare() 
    {return this -> mare_;}
    Mare Players::getMareN() const
    {return this -> mareNemico_;}
    char Players::getType() const
    {return this -> type_;}
    int Players::getCondition() const
    {return this -> condition_;}

    //metodo che lette le istruzioni da tastiera muove le navi
    void Players::Moves(pair<int, int> pos, pair<int, int> dest, Mare m, Mare mN)
    {
        m.MoveG(pos, dest, m, mN);
    }

    //mosse randomiche del bot
    void Players::MovesB(Mare m, Mare mN)
    { 
        count_=3;
        count2_=3;
        count3_=3
        int r0 = 0;
        bool esistonoNavi = true;
        srand(time(NULL));
        pair<int, int> pos;
        pair<int, int> dest;
        vector<pair<int, int> > des;
    do
    {   
        //scelta e controllo delle navi disponibili
        if(count_ == 0)
        {
            if(count2_ == 1)
            {
                if(count3_ != 2)
                {r0 = 2;}
            }
            else
            if(count3_ == 2)
            {
                r0 = 1;
            }
            else
            {
                r0 = rand()%2+1;
            }
        }
        else
        if(count2_ == 1)
        {
            if(count3_ == 2)
            {
                r0 = 0;
            }
            else
            {
                while (r0 == 1)
                {
                    r0 = rand()%3;  
                } 
            }                
        }
        else
        if(count3_ == 2)
        {
            r0 = rand()%2;
        }
        else
        {         
            r0 = rand()%3;
        }
        //scelta randomica della nave
        if(r0 == 0)
        {
            vector<Corazzata> a = m.getMarCor();

            //creazione e controllo di una coordinata randomica
            int s = a.size();
            if (s != 0)
            {
            int r1 = rand()%s;
            pos = (a[r1]).getPMedio();
            des = m.posAvailable(a[r1]);
            esistonoNavi = true;
            }
            else
            {
                count_ = 0;
                esistonoNavi = false;
            }
        }
        else
        if(r0 == 1)
        {
            vector<Nds> a = m.getMarNds();

            //creazione e controllo di una coordinata randomica
            int s = a.size();
            if (s != 0)
            {
            int r1 = rand()%s;
            pos = (a[r1]).getPMedio();
            des = m.posAvailable(a[r1]);
            esistonoNavi = true;
            }
            else
            {
                count2_ = 1;
                esistonoNavi = false;
            }
        }
        else
        if(r0 == 2)
        {
            vector<Sde> a = m.getMarSde();

            //creazione e controllo di una coordinata randomica
            int s = a.size();
            if (s != 0)
            {
                int r1 = rand()%s;
                pos = (a[r1]).getPMedio();
                des = m.posAvailable(a[r1]);
                esistonoNavi = true;
            }
            else
            {
                count3_ = 2;
                esistonoNavi = false;
            }
        }
    }while (esistonoNavi == false);
        int d = (des.size());
        dest = des[d];
        m.MoveG(pos, dest, m, mN);
    }