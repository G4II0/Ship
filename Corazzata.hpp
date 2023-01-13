#ifndef CORAZZATA_HPP
#define CORAZZATA_HPP

#include "Ship.hpp"
#include <iostream>

    class Corazzata : public Ship
    {
        private:

        char tipo;
        std::pair<std::pair<int, int>, std::pair<int, int> > pos;
        std::pair<int, int> prua;
        std::pair<int, int> poppa;
        int direzione;
        int dimensione;
        std::vector<bool> segmenti;
        int corazza;
        std::pair<int, int> pMedio;
        int numero;
        bool state;

        public:
        Corazzata();
        Corazzata(std::pair<std::pair<int, int>, std::pair<int, int> > pos_, int direzione_, int numero_);

        void setTipo(char tipo);
        void setPos(std::pair<std::pair<int, int>, std::pair<int, int> > pos_);
        void setPrua(std::pair<int, int> prua_);
        void setPoppa(std::pair<int, int> poppa_);
        void setDirezione(int direzione);
        void setDimensione(int dimensione_);
        void setSegmenti(bool Ssegmento_, int nS);
        void setCorazza(int corazza_);
        void setPMedio(std::pair<int, int> pMedio_);
        void setNumero(int numero_);
        void setState(int state_);

        char getTipo() const;
        std::pair<std::pair<int, int>, std::pair<int, int> > getPos() const;
        std::pair<int, int> getPrua() const;
        std::pair<int, int> getPoppa() const;
        int getDirezione() const;
        int getDimensione() const;
        std::vector<bool> getSegmenti() const;
        int getCorazza() const;
        std::pair<int, int> getPMedio() const;
        int getNumero() const;
        int getState() const;

        std::vector<std::pair<int, int> > Moves();

        void Damage();

        void Heal();
        
        bool operator==(const Corazzata& c1);
    };
#endif