#ifndef SDE_HPP
#define SDE_HPP

#include "Ship.hpp"
#include <iostream>

    class Sde : public Ship
    {
        private:

        char tipo;
        std::pair<std::pair<int, int>, std::pair<int, int> > pos;
        int dimensione;
        std::vector<bool> segmenti;
        int corazza;
        std::pair<int, int> pMedio;
        int numero;
        bool state;

        public:

        Sde();
        Sde(std::pair<std::pair<int, int>, std::pair<int, int> > pos, int numero);

        void setTipo(char tipo);
        void setPos(std::pair<std::pair<int, int>, std::pair<int, int> > pos_);
        void setDimensione(int dimensione_);
        void setCorazza(int corazza_);
        void setPMedio(std::pair<int, int> pMedio_);
        void setNumero(int numero_);
        void setState(int state_);

        char getTipo() const;
        std::pair<std::pair<int, int>, std::pair<int, int> > getPos() const;
        int getDimensione() const;
        int getCorazza() const;
        std::pair<int, int> getPMedio() const;
        int getNumero() const;
        int getState() const;

        //0 verticale, 1 se orizzontale
        int Direction(std::pair<std::pair<int, int>, std::pair<int, int> > pos);

        std::vector<std::pair<int, int> > Moves();

        void Damage();
    };

    bool operator==(const Sde& c1, const Sde& c2);

#endif