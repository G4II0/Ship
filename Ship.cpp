#include "Ship.hpp"
#include "Mare.hpp"

    Ship::Ship()
    {}
    Ship::Ship(std::pair<int, int> pM, int direzione, int numero)
    {
        this -> tipo_ = ' ';
        this -> dimensione_ = 0;
        this -> direzione_ = -1;
        this -> pMedio_ = pM;
        this -> corazza_ = 0;
        this -> numero_ = -1;
        this -> state_ = false;
    }

    void Ship::setTipo(char tipo)
    {this -> tipo_ = tipo;}
    void Ship::setPMedio(std::pair<int, int> pMedio)
    {this -> pMedio_ = pMedio;}
    void Ship::setDimensione(int dimensione)
    {this -> dimensione_ = dimensione;}
    void Ship::setDirezione(int direzione)
    {this -> direzione_ = direzione;}
    void Ship::setCorazza(int corazza)
    {this -> corazza_ = corazza;}
    void Ship::setNumero(int numero)
    {this-> numero_ = numero;}

    char Ship::getTipo() const
    {return this -> tipo_;}
    std::pair<int, int> Ship::getPMedio() const
    {return this -> pMedio_;}
    int Ship::getDirezione() const
    {return this -> direzione_;}
    int Ship::getDimensione() const
    {return this -> dimensione_;}
    int Ship::getCorazza() const
    {return this -> corazza_;}