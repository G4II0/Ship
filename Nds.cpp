#include "Nds.hpp"

    Nds::Nds()
    {}
    
    Nds::Nds(std::pair<int, int> pM_, int direzione_, int numero_)
    {
        this -> tipo = 'S';
        this -> pMedio = pM_;
        this -> direzione = direzione_;
        this -> dimensione = 3;
        this -> corazza = 3;
        this -> numero = numero_;
        this -> state = true;
    }
 
    void Nds::setTipo(char tipo_)
    {this -> tipo = tipo_;}
    void Nds::setPos(std::pair<std::pair<int, int>, std::pair<int, int> > pos_)
    {this -> pos = pos_;}
    void Nds::setDirezione(int direzione_)
    {this->direzione = direzione_;}
    void Nds::setDimensione(int dimensione_)
    {this -> dimensione = dimensione_;}
    void Nds::setCorazza(int corazza_)
    {this -> corazza = corazza_;}
    void Nds::setPMedio(std::pair<int, int> pMedio_)
    {this -> pMedio = pMedio_;}
    void Nds::setNumero(int numero_)
    {this -> numero = numero_;}
    void Nds::setState(int state_)
    {this -> state = state_;}

    char Nds::getTipo() const
    {return this -> tipo;}
    std::pair<std::pair<int, int>, std::pair<int, int> > Nds::getPos() const
    {return this -> pos;}
    int Nds::getDirezione() const
    {return this -> direzione;}
    int Nds::getDimensione() const
    {return this -> dimensione;}
    int Nds::getCorazza() const
    {return this -> corazza;}
    std::pair<int, int> Nds::getPMedio() const
    {return this -> pMedio;}
    int Nds::getNumero() const
    {return this -> numero;}
    int Nds::getState() const
    {return this -> state;}

    //possibili posizioni del pMedio della Nds
    std::vector<std::pair<int, int> > Nds::Moves()
    {
        std::vector<std::pair<int, int> > Mov;
        if(getDirezione() == 0)
        {
            int y = 1;
            int x = 0;

            while (x <12)
            {
                while (y < 11)
                {
                    Mov.push_back(std::pair<int, int>(x, y));
                    y++;
                }
                x++;
            }
        }
        else
        {
            int x = 1;
            int y = 0;

            while (y <12)
            {
                while (x < 11)
                {
                    Mov.push_back(std::pair<int, int>(x, y));
                    x++;
                }
                y++;
            }
        }
        return Mov;
    }

    void Nds::Damage()
    {
       corazza = corazza - 1;
    }

    void Nds::Heal()
    {
       corazza = 3;
    }

    bool operator==(const Nds& n1, const Nds& n2)
    {
        return n1.getTipo() == n2.getTipo() &&
            n1.getNumero() == n2.getNumero() &&
            n1.getPMedio() == n2.getPMedio();
    }
