#include "Corazzata.hpp"

    //costruttore vuoto
    Corazzata::Corazzata()
    {}
    
    //costruttore
    Corazzata::Corazzata(std::pair<int, int> pM, int direzione, int numero)
    {
        this -> tipo_ = 'C';
        this -> pMedio_ = pM;
        this -> direzione_ = direzione;
        this -> dimensione_ = 5;
        this -> corazza_ = 5;
        this -> numero_ = numero;
        this -> state_ = true;
    }

    //setter
    void Corazzata::setTipo(char tipo)
    {this -> tipo_ = tipo;}
    void Corazzata::setDirezione(int direzione)
    {this->direzione_ = direzione;}
    void Corazzata::setDimensione(int dimensione)
    {this -> dimensione_ = dimensione;}
    void Corazzata::setCorazza(int corazza)
    {this -> corazza_ = corazza;}
    void Corazzata::setPMedio(std::pair<int, int> pMedio)
    {this -> pMedio_ = pMedio;}
    void Corazzata::setNumero(int numero)
    {this -> numero_ = numero;}
    void Corazzata::setState(int state)
    {this -> state_ = state;}

    //getter
    char Corazzata::getTipo() const
    {return this -> tipo_;}
    int Corazzata::getDirezione() const
    {return this -> direzione_;}
    int Corazzata::getDimensione() const
    {return this -> dimensione_;}
    int Corazzata::getCorazza() const
    {return this -> corazza_;}
    std::pair<int, int> Corazzata::getPMedio() const
    {return this -> pMedio_;}
    int Corazzata::getNumero() const
    {return this -> numero_;}
    int Corazzata::getState() const
    {return this -> state_;}

    //metodo che restituisce tutte le posizioni in cui può essere posizionata la corazzata
    std::vector<std::pair<int, int> > Corazzata::Moves()
    {
        std::vector<std::pair<int, int> > Mov;
        std::cout << "sono in Corazzata::Moves" << std::endl;
        if(direzione_ == 0)
        {
            int y = 2;
            int x = 0;

            while (x <12)
            {
                while (y < 10)
                {
                    Mov.push_back(std::pair<int, int>(x, y));
                    y++;
                }
                x++;
            }
        }
        else
        {
            int x = 2;
            int y = 0;

            while (y <12)
            {
                while (x < 10)
                {
                    Mov.push_back(std::pair<int, int>(x, y));
                    x++;
                }
                y++;
            }
        }
        return Mov;
    }

    //metodo che toglie un punto vita ogni volta che la corazzata viene colpita
    void Corazzata::Damage()
    {
       corazza_ = corazza_ - 1;
    }

    //metodo che ripristina la corazza della nave corazzata
    void Corazzata::Heal()
    {
       corazza_ = 5;
    }

    //overload dell'operatore ==
    bool operator==(const Corazzata& n1, const Corazzata& n2)
    {
        return n1.getTipo() == n2.getTipo() && n1.getNumero() == n2.getNumero() && n1.getPMedio() == n2.getPMedio();
    }

