#include "Sde.hpp"

    Sde::Sde()
    {}

    Sde::Sde(std::pair<std::pair<int, int>, std::pair<int, int> > pos_, int numero_)
    {
        this -> tipo = 'E';
        this -> pos = pos_;
        this -> dimensione = 3;
        this -> corazza = 3;
        this -> numero = numero_;
        this -> state = true;
    }

    void Sde::setTipo(char tipo_)
    {this -> tipo = tipo_;}
    void Sde::setPos(std::pair<std::pair<int, int>, std::pair<int, int> > pos_)
    {this -> pos = pos_;}
    void Sde::setDimensione(int dimensione_)
    {this -> dimensione = dimensione_;}
    void Sde::setCorazza(int corazza_)
    {this -> corazza = corazza_;}
    void Sde::setPMedio(std::pair<int, int> pMedio_)
    {this -> pMedio = pMedio_;}
    void Sde::setNumero(int numero_)
    {this -> numero = numero_;}
    void Sde::setState(int state_)
    {this -> state = state_;}

    char Sde::getTipo() const
    {return this -> tipo;}
    std::pair<std::pair<int, int>, std::pair<int, int> > Sde::getPos() const
    {return this -> pos;}
    int Sde::getDimensione() const
    {return this -> dimensione;}
    int Sde::getCorazza() const
    {return this -> corazza;}
    std::pair<int, int> Sde::getPMedio() const
    {return this -> pMedio;}
    int Sde::getNumero() const
    {return this -> numero;}
    int Sde::getState() const
    {return this -> state;}

    //possibili posizioni del pMedio della Sde
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

    void Sde::Damage()
    {
       corazza = corazza - 1;
    }

bool operator==(const Sde& n1, const Sde& n2)
    {
        return n1.getTipo() == n2.getTipo() && n1.getNumero() == n2.getNumero() && n1.getPMedio() == n2.getPMedio();
    }