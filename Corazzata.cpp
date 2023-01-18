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
            std::pair<int, int> p;
            for(int x =0; x<12; x++)
            {
                for (int y = 2; y < 10; y++)
                {
                    p.first = x;
                    p.second = y;
                    cout << "iniziato push" << endl;
                    Mov.push_back(p);
                    cout << "finito push" << endl;
                }
            }
        }
        else
        {
            std::pair<int, int> p;
            for (int x = 2; x < 10; x++)
            {
                for (int y = 0; y < 12; y++)
                {
                    p.first = x;
                    p.second = y;
                    Mov.push_back(p);
                }
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

