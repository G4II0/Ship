#include "Nds.hpp"
    //costruttore vuoto
    Nds::Nds()
    {}
    
    //costruttore
    Nds::Nds(std::pair<int, int> pM, int direzione, int numero)
    {
        this -> tipo_ = 'S';
        this -> pMedio_ = pM;
        this -> direzione_ = direzione;
        this -> dimensione_ = 3;
        this -> corazza_ = 3;
        this -> numero_ = numero;
        this -> state_ = true;
    }
 
    //setter
    void Nds::setTipo(char tipo)
    {this -> tipo_ = tipo;}
    void Nds::setDirezione(int direzione)
    {this->direzione_ = direzione;}
    void Nds::setDimensione(int dimensione)
    {this -> dimensione_ = dimensione;}
    void Nds::setCorazza(int corazza)
    {this -> corazza_ = corazza;}
    void Nds::setPMedio(std::pair<int, int> pMedio)
    {this -> pMedio_ = pMedio;}
    void Nds::setNumero(int numero)
    {this -> numero_ = numero;}
    void Nds::setState(int state)
    {this -> state_ = state;}

    //getter
    char Nds::getTipo() const
    {return this -> tipo_;}
    int Nds::getDirezione() const
    {return this -> direzione_;}
    int Nds::getDimensione() const
    {return this -> dimensione_;}
    int Nds::getCorazza() const
    {return this -> corazza_;}
    std::pair<int, int> Nds::getPMedio() const
    {return this -> pMedio_;}
    int Nds::getNumero() const
    {return this -> numero_;}
    int Nds::getState() const
    {return this -> state_;}

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

    //metodo che toglie un punto vita ogni volta che la nave da supporto viene colpita
    void Nds::Damage()
    {
       corazza_ = corazza_ - 1;
    }

    //metodo che ripristina la corazza della nave da supporto
    void Nds::Heal()
    {
       corazza_ = 3;
    }

    //overload dell'operatore ==
    bool operator==(const Nds& n1, const Nds& n2)
    {
        return n1.getTipo() == n2.getTipo() &&
            n1.getNumero() == n2.getNumero() &&
            n1.getPMedio() == n2.getPMedio();
    }
