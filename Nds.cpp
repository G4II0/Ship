#include "Nds.hpp"

namespace S
{
    Nds::Nds(std::pair<std::pair<int, int>, std::pair<int, int>> pos_)
    {
        this -> structure = {'S', 'S', 'S'};
        this -> tipo = 'S';
        this -> pos = pos_;
        this->prua = pos_.first;
        this->poppa = pos_.second;
        this -> dimensione = 3;
        this -> corazza = 3;
        this -> pMedio;
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
    void Nds::setDimensione(int dimensione_)
    {this -> dimensione = dimensione_;}
    void Nds::setCorazza(int corazza_)
    {this -> corazza = corazza_;}

    std::vector<char> Nds::getStructure() const
    {return this -> structure;}
    char Nds::getTipo() const
    {return this -> tipo;}
    std::pair<std::pair<int, int>, std::pair<int, int>> Nds::getPos() const
    {return this -> pos;}
    std::pair<int, int> Ship::getPrua() const
    {return this->prua;}
    std::pair<int, int> Ship::getPoppa() const
    {return this->poppa;}
    std::pair<int, int> Nds::getPMedio() const
    {return this -> pMedio;}
    int Nds::getDimensione() const
    {return this -> dimensione;}
    int Nds::getCorazza() const
    {return this -> corazza;}

    //0 verticle, 1 se orizzontale
    int Nds::Direction(std::pair<int, int> prua, std::pair<int, int> poppa)
    {
        if(prua.first == poppa.first)
        return 0;
        else
        return 1;
    }

    //possibili posizioni del pMedio della Nds
    std::vector<std::pair<int, int>> Ship::Moves()
    {
        std::vector<std::pair<int, int>> Mov;
        if(Direction(prua, poppa) == 0)
        {
            int y = 2;
            int x = 1;

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
            int x = 2;
            int y = 1;

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
