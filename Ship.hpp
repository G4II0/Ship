//Alvise Molino
#ifndef SHIP_HPP
#define SHIP_HPP

#include <iostream>
#include <vector>

    class Ship
    {
        private:
        //dichiarazioni delle variabili
        char tipo_;
        std::pair<int, int> pMedio_;
        int direzione_;
        int dimensione_;
        int corazza_;
        int numero_;
        bool state_;

        public:

        //costruttori
        Ship();
        Ship(std::pair<int, int> pM, int direzione, int numero);

        //setter
        void setTipo(char tipo);
        void setPMedio(std::pair<int, int> pMedio);
        void setDirezione(int direzione);
        void setDimensione(int dimensione);
        void setCorazza(int corazza);
        void setNumero(int num);
        void setState(bool state);

        //getter
        char getTipo() const;
        std::pair<int, int> getPMedio() const;
        int getDirezione() const;
        int getDimensione() const;
        int getCorazza() const;
        int getNumero() const;
        int getStato() const;

        void Damage(); //metodo da sovrascrivere
        void Heal(); //metodo da sovrascrivere
        std::vector<std::pair<int, int> > Moves(); //metodo da sovrascrivere
    };
#endif