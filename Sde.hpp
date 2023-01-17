#ifndef SDE_HPP
#define SDE_HPP

#include "Ship.hpp"
#include <iostream>

    class Sde : public Ship
    {
        private:

        char tipo_;
        int dimensione_;
        std::vector<bool> segmenti_;
        int corazza_;
        std::pair<int, int> pMedio_;
        int numero_;
        bool state_;

        public:

        Sde();
        Sde(std::pair<int, int> pM, int numero);

        void setTipo(char tipo);
        void setDimensione(int dimensione);
        void setCorazza(int corazza);
        void setPMedio(std::pair<int, int> pMedio);
        void setNumero(int numero);
        void setState(int state);

        char getTipo() const;
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