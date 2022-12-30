#include "Nds.hpp"

namespace S
{
    Nds::Nds()
    {}
    
    Nds::Nds(std::pair<std::pair<int, int>, std::pair<int, int>> pos_, int direzione_, int numero_)
    {
        this -> structure = {'S', 'S', 'S'};
        this -> tipo = 'S';
        this -> pos = pos_;
        this -> prua = pos_.first;
        this -> poppa = pos_.second;
        this -> direzione;
        this -> dimensione = 3;
        this -> corazza = 3;
        this -> pMedio;
        this -> numero = numero_;
        this -> state;
    }
 
    void Nds::setStructure(std::vector<char> structure_)
    {this -> structure = structure_;}
    void Nds::setTipo(char tipo_)
    {this -> tipo = tipo_;}
    void Nds::setPos(std::pair<std::pair<int, int>, std::pair<int, int>> pos_)
    {this -> pos = pos_;}
    void Ship::setPrua(std::pair<int, int> prua_)
    {this->prua = prua_;}
    void Ship::setPrua(std::pair<int, int> poppa_)
    {this->poppa = poppa_;}
    void Nds::setPMedio(std::pair<int, int> pMedio_)
    {this -> pMedio = pMedio_;}
    void Nds::setDimensione(int direzione_)
    {this->direzione = direzione_;}
    void Nds::setDimensione(int dimensione_)
    {this -> dimensione = dimensione_;}
    void Nds::setNumero(int numero_)
    {this -> numero = numero_;}
    void Nds::setCorazza(int corazza_)
    {this -> corazza = corazza_;}

    std::vector<char> Nds::getStructure() const
    {return this -> structure;}
    char Nds::getTipo() const
    {return this -> tipo;}
    std::pair<std::pair<int, int>, std::pair<int, int>> Nds::getPos() const
    {return this -> pos;}
    std::pair<int, int> Ship::getPrua() const
    {return this -> prua;}
    std::pair<int, int> Ship::getPoppa() const
    {return this -> poppa;}
    std::pair<int, int> Nds::getPMedio() const
    {return this -> pMedio;}
    int Nds::getDirezione() const
    {return this -> direzione;}
    int Nds::getDimensione() const
    {return this -> dimensione;}
    int Nds::getCorazza() const
    {return this -> corazza;}
    int Nds::getNumero() const
    {return this -> numero;}

    //possibili posizioni del pMedio della Nds
    std::vector<std::pair<int, int>> Ship::Moves()
    {
        std::vector<std::pair<int, int>> Mov;
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
}
