#include "Corazzata.hpp"

namespace S
{
    Corazzata::Corazzata(std::pair<std::pair<int, int>, std::pair<int, int>> pos_)
    {
        this -> structure = {'C', 'C', 'C', 'C', 'C'};
        this -> tipo = 'C';
        this -> pos = pos_;
        this->prua = pos_.first;
        this->poppa = pos_.second;
        this -> dimensione = 5;
        this -> corazza = 5;
        this -> pMedio;
        this -> state;
    }

    void Ship::setStructure(std::vector<char> structure_)
    {this -> structure = structure_;}
    void Ship::setTipo(char tipo_)
    {this -> tipo = tipo_;}
    void Ship::setPos(std::pair<std::pair<int, int>, std::pair<int, int>> pos_)
    {this -> pos = pos_;}
    void Ship::setPrua(std::pair<int, int> prua_)
    {this->prua = prua_;}
    void Ship::setPrua(std::pair<int, int> poppa_)
    {this->poppa = poppa_;}
    void Ship::setPMedio(std::pair<int, int> pMedio_)
    {this -> pMedio = pMedio_;}
    void Ship::setDimensione(int dimensione_)
    {this -> dimensione = dimensione_;}
    void Ship::setCorazza(int corazza_)
    {this -> corazza = corazza_;}

    std::vector<char> Ship::getStructure() const
    {return this -> structure;}
    char Ship::getTipo() const
    {return this -> tipo;}
    std::pair<std::pair<int, int>, std::pair<int, int>> Ship::getPos() const
    {return this -> pos;}
    std::pair<int, int> Ship::getPrua() const
    {return this->prua;}
    std::pair<int, int> Ship::getPoppa() const
    {return this->poppa;}
    std::pair<int, int> Ship::getPMedio() const
    {return this -> pMedio;}
    int Ship::getDimensione() const
    {return this -> dimensione;}
    int Ship::getCorazza() const
    {return this -> corazza;}

    void Corazzata::Damage()
    {
       corazza = corazza - 1;
    }

    void Corazzata::Damage()
    {
       corazza = 5;
    }
}
