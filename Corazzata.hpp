#ifndef CORAZZATA_HPP
#define CORAZZATA_HPP

#include "Ship.hpp"
#include <iostream>

    class Corazzata : public Ship
    {
        private:

        char tipo;
        std::pair<std::pair<int, int>, std::pair<int, int> > pos;
        int direzione;
        int dimensione;
        int corazza;
        std::pair<int, int> pMedio;
        int numero;
        bool state;

        public:
        Corazzata();
        Corazzata(std::pair<int, int> pM_, int direzione_, int numero_);

        void setTipo(char tipo);
        void setPos(std::pair<std::pair<int, int>, std::pair<int, int> > pos_);
        void setDirezione(int direzione);
        void setDimensione(int dimensione_);
        void setCorazza(int corazza_);
        void setPMedio(std::pair<int, int> pMedio_);
        void setNumero(int numero_);
        void setState(int state_);

        char getTipo() const;
        std::pair<std::pair<int, int>, std::pair<int, int> > getPos() const;
        int getDirezione() const;
        int getDimensione() const;
        int getCorazza() const;
        std::pair<int, int> getPMedio() const;
        int getNumero() const;
        int getState() const;

        std::vector<std::pair<int, int> > Moves();

        void Damage();

        void Heal();
    };

    bool operator==(const Corazzata& c1, const Corazzata& c2);

#endif