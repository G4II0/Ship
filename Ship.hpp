#ifndef SHIP_HPP
#define SHIP_HPP

#include <iostream>
#include <vector>

    class Ship
    {
        private:

        std::vector<char> structure;
        char tipo;
        std::pair<std::pair<int, int>, std::pair<int, int> > pos;
        std::pair<int, int> pMedio;
        int direzione;
        int dimensione;
        int corazza;
        int numero;
        bool state;

        public:

        Ship();
        Ship(std::pair<std::pair<int, int>, std::pair<int, int> > pos_, int direzione_, int numero_);

        void setStructure(std::vector<char> structure_);
        void setTipo(char tipo);
        void setPos(std::pair<std::pair<int, int>, std::pair<int, int> > pos_);
        void setPMedio(std::pair<int, int> pMedio_);
        void setDirezione(int direzione_);
        void setDimensione(int dimensione_);
        void setCorazza(int corazza_);
        void setNumero(int num_);
        void setState(bool state_);

        std::vector<char> getStructure() const;
        char getTipo() const;
        std::pair<std::pair<int, int>, std::pair<int, int> > getPos() const;
        std::pair<int, int> getPMedio() const;
        int getDirezione() const;
        int getDimensione() const;
        int getCorazza() const;
        int getNumero() const;
        int getStato() const;

        std::vector<std::pair<int, int> > Moves();

        void Damage();

        void Heal();
    };
#endif