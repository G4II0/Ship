#ifndef SDE_HPP
#define SDE_HPP

#include "Ship.hpp"
#include <iostream>

    class Sde : public Ship
    {
        private:

        std::vector<char> structure;
        char tipo;
        std::pair<std::pair<int, int>, std::pair<int, int> > pos;
        std::pair<int, int> prua;
        std::pair<int, int> poppa;
        int dimensione;
        std::vector<bool> segmenti;
        int corazza;
        std::pair<int, int> pMedio;
        int numero;
        bool state;

        public:

        Sde();
        Sde(std::pair<std::pair<int, int>, std::pair<int, int> > pos, int numero);

        void setStructure(std::vector<char> structure_);
        void setTipo(char tipo);
        void setPos(std::pair<std::pair<int, int>, std::pair<int, int> > pos_);
        void setPrua(std::pair<int, int> prua_);
        void setPoppa(std::pair<int, int> poppa_);
        void setDimensione(int dimensione_);
        void setSegmenti(bool Ssegmento_, int nS);
        void setCorazza(int corazza_);
        void setPMedio(std::pair<int, int> pMedio_);
        void setNumero(int numero_);
        void setState(int state_);

        std::vector<char> getStructure() const;
        char getTipo() const;
        std::pair<std::pair<int, int>, std::pair<int, int> > getPos() const;
        std::pair<int, int> getPrua() const;
        std::pair<int, int> getPoppa() const;
        int getDimensione() const;
        std::vector<bool> getSegmenti() const;
        int getCorazza() const;
        std::pair<int, int> getPMedio() const;
        int getNumero() const;
        int getState() const;

        //0 verticale, 1 se orizzontale
        int Direction(std::pair<std::pair<int, int>, std::pair<int, int> > pos);

        std::vector<std::pair<int, int> > Moves();

        void Damage();

        bool operator==(const Sde& c1, const Sde& c2);
    };
#endif