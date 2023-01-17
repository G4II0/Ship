#ifndef CORAZZATA_HPP
#define CORAZZATA_HPP

#include "Ship.hpp"
#include <iostream>

    class Corazzata : public Ship
    {
        private:

        char tipo_;
        int direzione_;
        int dimensione_;
        int corazza_;
        std::pair<int, int> pMedio_;
        int numero_;
        bool state_;

        public:
        Corazzata();
        Corazzata(std::pair<int, int> pM, int direzione, int numero);

        void setTipo(char tipo);
        void setDirezione(int direzione);
        void setDimensione(int dimensione);
        void setCorazza(int corazza);
        void setPMedio(std::pair<int, int> pM);
        void setNumero(int numero);
        void setState(int state);

        char getTipo() const;
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