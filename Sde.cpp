#include "Sde.hpp"

namespace S
{
    Sde::Sde(std::pair<std::pair<int, int>, std::pair<int, int>> pos_)
    {
        this -> structure = {'E'};
        this -> tipo = 'E';
        this -> pos = pos_;
        this->prua = pos_.first;
        this->poppa = pos_.second;
        this -> dimensione = 3;
        this -> corazza = 3;
        this -> pMedio;
        this -> state;
    }

    void Sde::setStructure(std::vector<char> structure_)
    {this -> structure = structure_;}
    void Sde::setTipo(char tipo_)
    {this -> tipo = tipo_;}
    void Sde::setPos(std::pair<std::pair<int, int>, std::pair<int, int>> pos_)
    {this -> pos = pos_;}
    void Ship::setPrua(std::pair<int, int> prua_)
    {this->prua = prua_;}
    void Ship::setPrua(std::pair<int, int> poppa_)
    {this->poppa = poppa_;}
    void Sde::setPMedio(std::pair<int, int> pMedio_)
    {this -> pMedio = pMedio_;}
    void Sde::setDimensione(int dimensione_)
    {this -> dimensione = dimensione_;}
    void Sde::setCorazza(int corazza_)
    {this -> corazza = corazza_;}

    std::vector<char> Sde::getStructure() const
    {return this -> structure;}
    char Sde::getTipo() const
    {return this -> tipo;}
    std::pair<std::pair<int, int>, std::pair<int, int>> Sde::getPos() const
    {return this -> pos;}
    std::pair<int, int> Ship::getPrua() const
    {return this->prua;}
    std::pair<int, int> Ship::getPoppa() const
    {return this->poppa;}
    std::pair<int, int> Sde::getPMedio() const
    {return this -> pMedio;}
    int Sde::getDimensione() const
    {return this -> dimensione;}
    int Sde::getCorazza() const
    {return this -> corazza;}

    //possibili posizioni del pMedio della Sde
    std::vector<std::pair<int, int>> Moves()
    {
        std::vector<std::vector<std::pair<int, int> >> Moves;
        int y = 0;
        int x = 0;
        std::vector<std::pair<int, int> > m1;
        while (x <12)
        {
            while (y < 12)
            {
                m1.push_back(std::pair<int, int>(x, y));
                y++;
            }
            x++;
        }
        Moves.push_back(m1);
    }

    void Sde::Damage()
    {
       corazza = corazza - 1;
    }
}
