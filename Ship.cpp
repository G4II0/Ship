#include "Ship.hpp"
#include "Mare.hpp"

    Ship::Ship()
    {}
    Ship::Ship(std::pair<std::pair<int, int>, std::pair<int, int> > pos_, int direzione_, int numero)
    {
        this -> tipo = ' ';
        this -> pos = pos_;
        this -> dimensione = 0;
        this -> direzione = -1;
        this -> corazza = 0;
        this -> numero = -1;
        this -> state = false;
    }

    void Ship::setTipo(char tipo_)
    {this -> tipo = tipo_;}
    void Ship::setPos(std::pair<std::pair<int, int>, std::pair<int, int> > pos_)
    {this -> pos = pos_;}
    void Ship::setPMedio(std::pair<int, int> pMedio_)
    {this -> pMedio = pMedio_;}
    void Ship::setDimensione(int dimensione_)
    {this -> dimensione = dimensione_;}
    void Ship::setDirezione(int direzione_)
    {this -> direzione = direzione_;}
    void Ship::setCorazza(int corazza_)
    {this -> corazza = corazza_;}
    void Ship::setNumero(int numero_)
    {this-> numero = numero_;}

    char Ship::getTipo() const
    {return this -> tipo;}
    std::pair<std::pair<int, int>, std::pair<int, int> > Ship::getPos() const
    {return this -> pos;}
    std::pair<int, int> Ship::getPMedio() const
    {return this -> pMedio;}
    int Ship::getDirezione() const
    {return this -> direzione;}
    int Ship::getDimensione() const
    {return this -> dimensione;}
    int Ship::getCorazza() const
    {return this -> corazza;}
    
    //possibili posizioni del pMedio
    std::vector<std::pair<int, int> > Ship::Moves()
    {}

    void Ship::Damage()
    {}

    void Ship::Heal()
    {}