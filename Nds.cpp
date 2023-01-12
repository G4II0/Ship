#include "Nds.hpp"

    Nds::Nds()
    {}
    
    Nds::Nds(std::pair<std::pair<int, int>, std::pair<int, int> > pos_, int direzione_, int numero_)
    {
        this -> structure = {'S', 'S', 'S'};
        this -> tipo = 'S';
        this -> pos = pos_;
        this -> prua = pos_.first;
        this -> poppa = pos_.second;
        this -> direzione = direzione_;
        this -> dimensione = 3;
        this -> segmenti = {true, true, true};
        this -> corazza = 3;
        this -> pMedio = {0, 0};
        this -> numero = numero_;
        this -> state = true;
    }
 
    void Nds::setStructure(std::vector<char> structure_)
    {this -> structure = structure_;}
    void Nds::setTipo(char tipo_)
    {this -> tipo = tipo_;}
    void Nds::setPos(std::pair<std::pair<int, int>, std::pair<int, int> > pos_)
    {this -> pos = pos_;}
    void Ship::setPrua(std::pair<int, int> prua_)
    {this->prua = prua_;}
    void Ship::setPoppa(std::pair<int, int> poppa_)
    {this->poppa = poppa_;}
    void Nds::setDirezione(int direzione_)
    {this->direzione = direzione_;}
    void Nds::setDimensione(int dimensione_)
    {this -> dimensione = dimensione_;}
    void Nds::setSegmenti(bool Ssegmento_, int nS)
    {this -> segmenti[nS] = Ssegmento_;}
    void Nds::setCorazza(int corazza_)
    {this -> corazza = corazza_;}
    void Nds::setPMedio(std::pair<int, int> pMedio_)
    {this -> pMedio = pMedio_;}
    void Nds::setNumero(int numero_)
    {this -> numero = numero_;}
    void Nds::setState(int state_)
    {this -> state = state_;}

    std::vector<char> Nds::getStructure() const
    {return this -> structure;}
    char Nds::getTipo() const
    {return this -> tipo;}
    std::pair<std::pair<int, int>, std::pair<int, int> > Nds::getPos() const
    {return this -> pos;}
    std::pair<int, int> Ship::getPrua() const
    {return this->prua;}
    std::pair<int, int> Ship::getPoppa() const
    {return this->poppa;}
    int Nds::getDirezione() const
    {return this -> direzione;}
    int Nds::getDimensione() const
    {return this -> dimensione;}
    std::vector<bool> Nds::getSegmenti() const
    {return this -> segmenti;}
    int Nds::getCorazza() const
    {return this -> corazza;}
    std::pair<int, int> Nds::getPMedio() const
    {return this -> pMedio;}
    int Nds::getNumero() const
    {return this -> numero;}
    int Nds::getState() const
    {return this -> state;}

    //possibili posizioni del pMedio della Nds
    std::vector<std::pair<int, int> > Ship::Moves()
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

    void Nds::Damage()
    {
       corazza = 3;
    }

    bool operator==(const Nds& n1)
    {
        return n1.getTipo() == this.getTipo() && n1.getNumero() == this.getNumero() && n1.getPMedio() == this.getPMedio();
    }
