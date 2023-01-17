#ifndef NDS_HPP
#define NDS_HPP

#include "Ship.hpp"
#include <iostream>

    class Nds : public Ship
    {
        private:
        //dichiarazioni delle variabili
        char tipo_;
        int direzione_;
        int dimensione_;
        int corazza_;
        std::pair<int, int> pMedio_;
        int numero_;
        bool state_;

        public:
        
        //costruttori
        Nds();
        Nds(std::pair<int, int> pM, int direzione, int numero);

        //setter
        void setTipo(char tipo);
        void setDirezione(int direzione);
        void setDimensione(int dimensione);
        void setCorazza(int corazza);
        void setPMedio(std::pair<int, int> pMedio);
        void setNumero(int numero);
        void setState(int state);

        //getter
        char getTipo() const;
        int getDirezione() const;
        int getDimensione() const;
        int getCorazza() const;
        std::pair<int, int> getPMedio() const;
        int getNumero() const;
        int getState() const;
        
        
        //possibili posizioni del pMedio della Nds
        std::vector<std::pair<int, int> > Moves();

        //metodo che toglie un punto vita ogni volta che la nave da supporto viene colpita
        void Damage();

        //metodo che ripristina la corazza della nave da supporto
        void Heal();
    };

    //overload dell'operatore ==
    bool operator==(const Nds& n1, const Nds& n2);
#endif