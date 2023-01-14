#include "Corazzata.hpp"

    Corazzata::Corazzata()
    {}
    
    Corazzata::Corazzata(std::pair<std::pair<int, int>, std::pair<int, int> > pos_, int direzione_, int numero_)
    {
        this -> tipo = 'C';
        this -> pos = pos_;
        this -> prua = pos_.first;
        this -> poppa = pos_.second;
        this -> direzione = direzione_;
        this -> dimensione = 5;
        this -> corazza = 5;
        this -> corazza = 3;
        this -> numero = numero_;
        this -> state = true;
    }

    void Corazzata::setTipo(char tipo_)
    {this -> tipo = tipo_;}
    void Corazzata::setPos(std::pair<std::pair<int, int>, std::pair<int, int> > pos_)
    {this -> pos = pos_;}
    void Ship::setPrua(std::pair<int, int> prua_)
    {this->prua = prua_;}
    void Ship::setPoppa(std::pair<int, int> poppa_)
    {this->poppa = poppa_;}
    void Corazzata::setDirezione(int direzione_)
    {this->direzione = direzione_;}
    void Corazzata::setDimensione(int dimensione_)
    {this -> dimensione = dimensione_;}
    void Corazzata::setSegmenti(bool Ssegmento_, int nS)
    {this -> segmenti[nS] = Ssegmento_;}
    void Corazzata::setCorazza(int corazza_)
    {this -> corazza = corazza_;}
    void Corazzata::setPMedio(std::pair<int, int> pMedio_)
    {this -> pMedio = pMedio_;}
    void Corazzata::setNumero(int numero_)
    {this -> numero = numero_;}
    void Corazzata::setState(int state_)
    {this -> state = state_;}

    char Corazzata::getTipo() const
    {return this -> tipo;}
    std::pair<std::pair<int, int>, std::pair<int, int> > Corazzata::getPos() const
    {return this -> pos;}
    std::pair<int, int> Ship::getPrua() const
    {return this->prua;}
    std::pair<int, int> Ship::getPoppa() const
    {return this->poppa;}
    int Corazzata::getDirezione() const
    {return this -> direzione;}
    int Corazzata::getDimensione() const
    {return this -> dimensione;}
    std::vector<bool> Corazzata::getSegmenti() const
    {return this -> segmenti;}
    int Corazzata::getCorazza() const
    {return this -> corazza;}
    std::pair<int, int> Corazzata::getPMedio() const
    {return this -> pMedio;}
    int Corazzata::getNumero() const
    {return this -> numero;}
    int Corazzata::getState() const
    {return this -> state;}

    std::vector<std::pair<int, int> > Corazzata::Moves()
    {
        std::vector<std::pair<int, int> > Mov;
        if(getDirezione() == 0)
        {
            int y = 2;
            int x = 0;

            while (x <12)
            {
                while (y < 10)
                {
                    Mov.push_back(std::pair<int, int>(x, y));
                    y++;
                }
                x++;
            }
        }
        else
        {
            int x = 2;
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

    void Corazzata::Damage()
    {
       corazza = corazza - 1;
    }

    void Corazzata::Heal()
    {
       corazza = 5;
    }

    bool operator==(const Corazzata& n1, const Corazzata& n2)
    {
        return n1.getTipo() == n2.getTipo() && n1.getNumero() == n2.getNumero() && n1.getPMedio() == n2.getPMedio();
    }

