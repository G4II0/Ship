#ifndef NDS_HPP
#define NDS_HPP

#include "Ship.hpp"
#include <iostream>

namespace S
{
    class Nds : public Ship
    {
        private:

        std::vector<char> structure;
        char tipo;
        std::pair<std::pair<int, int>, std::pair<int, int>> pos;
        std::pair<int, int> prua;
        std::pair<int, int> poppa;
        std::pair<int, int> pMedio;
        int direzione;
        int dimensione;
        int corazza;
        bool state;

        public:

        Nds(std::pair<std::pair<int, int>, std::pair<int, int>> pos_, int direzione_);

        void setStructure(std::vector<char> structure_);
        void setTipo(char tipo);
        void setPos(std::pair<std::pair<int, int>, std::pair<int, int>> pos_);
        void setPrua(std::pair<int, int> prua_);
        void setPoppa(std::pair<int, int> poppa_);
        void setPMedio(std::pair<int, int> pMedio_);
        void setDirezione(int direzione_);
        void setDimensione(int dimensione_);
        void setCorazza(int corazza_);

        std::vector<char> getStructure() const;
        char getTipo() const;
        std::pair<std::pair<int, int>, std::pair<int, int>> getPos() const;
        std::pair<int, int> getPrua() const;
        std::pair<int, int> getPoppa() const;
        std::pair<int, int> getPMedio() const;
        int getDirezione() const;
        int getDimensione() const;
        int getCorazza() const;

        std::vector<std::pair<int, int>> Moves();

        void Damage();

        void Heal();
    };
}
#endif