#include "Sde.hpp"

    //costruttore vuoto
    Sde::Sde()
    {}

    //costruttore
    Sde::Sde(std::pair<int, int> pM, int numero)
    {
        this -> tipo_ = 'E';
        this -> pMedio_ = pM;
        this -> dimensione_ = 1;
        this -> corazza_ = 1;
        this -> numero_ = numero;
        this -> state_ = true;
    }

    //setter
    void Sde::setTipo(char tipo)
    {this -> tipo_ = tipo;}
    void Sde::setDimensione(int dimensione)
    {this -> dimensione_ = dimensione;}
    void Sde::setCorazza(int corazza)
    {this -> corazza_ = corazza;}
    void Sde::setPMedio(std::pair<int, int> pMedio)
    {this -> pMedio_ = pMedio;}
    void Sde::setNumero(int numero)
    {this -> numero_ = numero;}
    void Sde::setState(int state)
    {this -> state_ = state;}

    //getter
    char Sde::getTipo() const
    {return this -> tipo_;}
    int Sde::getDimensione() const
    {return this -> dimensione_;}
    int Sde::getCorazza() const
    {return this -> corazza_;}
    std::pair<int, int> Sde::getPMedio() const
    {return this -> pMedio_;}
    int Sde::getNumero() const
    {return this -> numero_;}
    int Sde::getState() const
    {return this -> state_;}

    //possibili posizioni del del sottomarino da esplorazione
    std::vector<std::pair<int, int> > Sde::Moves()
    {
        std::vector<std::pair<int, int> > Mov;
        int y = 0;
        int x = 0;
        while (x <12)
        {
            while (y < 12)
            {
                Mov.push_back(std::pair<int, int>(x, y));
                y++;
            }
            x++;
        }
        return Mov;
    }

    //metodo che toglie un punto vita ogni volta che il sottomatino da esplorazione viene colpito
    void Sde::Damage()
    {
       corazza_ = corazza_ - 1;
    }

//overload dell'operatore ==
bool operator==(const Sde& n1, const Sde& n2)
    {
        return n1.getTipo() == n2.getTipo() && n1.getNumero() == n2.getNumero() && n1.getPMedio() == n2.getPMedio();
    }