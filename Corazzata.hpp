//Samuele Gallo
#ifndef CORAZZATA_HPP
#define CORAZZATA_HPP

#include "Ship.hpp"
#include <iostream>

    class Corazzata : public Ship
    {
        private:
        //dichiarazione delle variabili della classe Corazzata
        char tipo_;
        int direzione_;
        int dimensione_;
        int corazza_;
        std::pair<int, int> pMedio_;
        int numero_;
        bool state_;

        public:
        //costruttori
        Corazzata();
        Corazzata(std::pair<int, int> pM, int direzione, int numero);

        //setter
        void setTipo(char tipo);
        void setDirezione(int direzione);
        void setDimensione(int dimensione);
        void setCorazza(int corazza);
        void setPMedio(std::pair<int, int> pM);
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

        //metodo che restituisce un vettore di coppie con tutte le coordinate delle mosse possibili 
        std::vector<std::pair<int, int> > Moves();

        //metodo che toglie un punto vita ogni volta che la corazzata viene colpita
        void Damage();

        //metodo che ripristina la corazza della nave corazzata
        void Heal();
    };

    //overload operatore ==
    bool operator==(const Corazzata& c1, const Corazzata& c2);

#endif