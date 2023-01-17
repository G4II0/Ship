#ifndef NDS_HPP
#define NDS_HPP

#include "Ship.hpp"
#include <iostream>

    class Nds : public Ship
    {
        private:

        char tipo;
        int direzione;
        int dimensione;
        int corazza;
        std::pair<int, int> pMedio;
        int numero;
        bool state;

        public:

        Nds();
        Nds(std::pair<int, int> pM_, int direzione_, int numero_);

        void setTipo(char tipo);
        void setDirezione(int direzione);
        void setDimensione(int dimensione_);
        void setCorazza(int corazza_);
        void setPMedio(std::pair<int, int> pMedio_);
        void setNumero(int numero_);
        void setState(int state_);

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

    bool operator==(const Nds& n1, const Nds& n2);
#endif