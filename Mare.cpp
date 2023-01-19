#include "Mare.hpp"

using namespace std;
    //costruttore
    Mare::Mare()
    {
        this -> condition_ = -1;
        this -> drawMoves_ = 0;
        initializeMare(mar_);
    }

    //setter
    void Mare::setMareA(pair<int, int> p, vector<vector<char> > mar_)
    {
        int x = p.first;
        int y = p.second;
        for (int i = 0; i < mar_.size(); i++) 
        {
            for (int j = 0; j < mar_[i].size(); j++)
             {
                if (i == x && j == y) 
                {
                    mar_[i].insert(mar_[i].begin() + j, ' ');
                }
            }
        }
    }

    void Mare::setMareAc(pair<int, int> &p)
    {
        int x = p.first;
        int y = p.second;

        mar_[x].erase(mar_[x].begin() + y);
        mar_[x].insert(mar_[x].begin() + y, 'C');

        printAMare();
    }

    void Mare::setMareAs(pair<int, int> &p)
    {
        int x = p.first;
        int y = p.second;

        mar_[x].erase(mar_[x].begin() + y);
        mar_[x].insert(mar_[x].begin() + y, 'S');

        printAMare();
    }

    void Mare::setMareAe(pair<int, int> &p)
    {
        int x = p.first;
        int y = p.second;

        mar_[x].erase(mar_[x].begin() + y);
        mar_[x].insert(mar_[x].begin() + y, 'E');

        printAMare();
    }

    void Mare::setMareE(pair<int, int> p, char c)
    {
        int x = p.first;
        int y = p.second;
        marE_[x][y] = c;
    }

    void Mare::setMareES(pair<int, int> p, char c)
    {
        int x = p.first;
        int y = p.second;
        marES_[x][y] = c;
    }

    //getter
    vector<vector<char> > Mare::getMare()
    {
        return this-> mar_;
    }

    void Mare::getMareE(Mare& mN)
    {
        vector<vector<char> > v;
        vector<char> v1;
        v=mN.getMare();

        for(int y=0; y<12; y++)
        {
            v1 = v[y];
            for(int x=0; x<12; x++)
            {
               marE_[x][y] = v1[x];
            }
        }
    }

    //setter
    void Mare::setMarCor(Corazzata c)
    {
        marCor_.push_back(c);
    }
    void Mare::setMarNds(Nds n)
    {
        marNds_.push_back(n);
    }
    void Mare::setMarSde(Sde s)
    {
        marSde_.push_back(s);
    }

    //getter
    vector<Corazzata> Mare::getMarCor()
    {return this -> marCor_;}

    vector<Nds> Mare::getMarNds()
    {return this -> marNds_;}
    
    vector<Sde> Mare::getMarSde()
    {return this -> marSde_;}

    //metodo che restituisce la corazzata situata alla posizione passata per valore
    Corazzata Mare::whichCor(vector<Corazzata> marCor, pair<int, int> pos)
    {
        int t;
        for(int i=0; i<3; i++)
        {
            if((marCor[i]).getPMedio() == pos)
            {
                t=i;
            }
        }
        return marCor[t];
    }

    //metodo che restituisce la nave da supporto situata alla posizione passata per valore
    Nds Mare::whichNds(vector<Nds> marNds, pair<int, int> pos)
    {
        int t;
        for(int i=0; i<3; i++)
        {
            if((marNds[i]).getPMedio() == pos)
            {
                t=i;
            }
        }
        return marNds[t];
    }

    //metodo che restituisce il sottomarino situata alla posizione passata per valore
    Sde Mare::whichSde(vector<Sde> marSde, pair<int, int> pos)
    {
        int t;
        for(int i=0; i<2; i++)
        {
            if((marSde[i]).getPMedio() == pos)
            {
                t=i;
            }
        }
        return marSde[t];
    }

    //metodo che controlla se la posizione inserita è disponibile
    bool Mare::legitMoveInput(Corazzata ship, pair<int, int> pos)
    {
        vector<pair<int, int> > v = posAvailable(ship);
        for(int i = 0; i<v.size(); i++)
        {
            if(v[i].first == pos.first && v[i].second == pos.second)
            {return true;}
        }
        return false;
    }
    bool Mare::legitMoveInput(Nds ship, pair<int, int> pos)
    {
        vector<pair<int, int> > v = posAvailable(ship);
        for(int i = 0; i<v.size(); i++)
        {
            if(v[i].first == pos.first && v[i].second == pos.second)
            {return true;} 
        }
        return false;
    }
        bool Mare::legitMoveInput(Sde ship, pair<int, int> pos)
    {
        vector<pair<int, int> > v = posAvailable(ship);
        for(int i = 0; i<v.size(); i++)
        {
            if(v[i].first == pos.first && v[i].second == pos.second)
            {return true;} 
        }
        return false;
    }

    //inizializza il mare
    void Mare::initializeMare(vector<vector<char> >& mar_)
    {
        mar_.resize(12);
        for (int x = 0; x < 12; x++) 
        {
            std::vector<char> innerVec;
            for (int y = 0; y < 12; y++) 
            {
                mar_[x].insert(mar_[x].begin() + y, ' ');
            }
            mar_.push_back(innerVec);
        }
    }

    void Mare::initializeMareES(vector<vector<char> > marES_)
    {
        vector<char> v;
        for (int x = 0; x < 12; x++)
        {
            for (int y = 0; y < 12; y++)
            {
                v.push_back(' ');
            }
            marES_.push_back(v);
        }
    }

    void Mare::initializeMare(vector<Corazzata> marCor)
    {
        int i = 0;

        while (i < 3)
        {
                marCor[i] = Corazzata();
            i++;
        }
    }

        void Mare::initializeMare(vector<Nds> marNds)
    {
        int i = 0;

        while (i < 3)
        {
                marNds[i] = Nds();
            i++;
        }
    }
        void Mare::initializeMare(vector<Sde> marSde)
    {
        int i = 0;

        while (i < 2)
        {
                marSde[i] = Sde();
            i++;
        }
    }

//inserimento corazzata
    void Mare::insertCor(Corazzata& ship, pair<int, int> pos)
    {
        bool b = legitMoveInput(ship, pos);
        if (b == true)
        {
            pair<int,int> temp0;
            pair<int, int> temp1;
            pair<int, int> temp2;
            pair<int, int> temp3;
            pair<int, int> temp4;
            temp0.first = pos.first;
            temp0.second = pos.second;
            int d = ship.getDirezione();
            if(d == 1)
            {
                temp1.first = (temp0.first);         // x prua
                temp1.second = (temp0.second) - 2; // y prua
                temp2.first = (temp0.first);         // x poppa
                temp2.second = (temp0.second) + 2; // y poppa
                temp3.first = (temp0.first);
                temp3.second = (temp0.second) - 1;
                temp4.first = (temp0.first);
                temp4.second = (temp0.second) + 1;
            }

            else
            {
                temp1.first = (temp0.first) + 2; // x prua
                temp1.second = (temp0.second);     // y prua
                temp2.first = (temp0.first) - 2; // x poppa
                temp2.second = (temp0.second);     // y poppa
                temp3.first = (temp0.first) + 1;
                temp3.second = (temp0.second);
                temp4.first = (temp0.first) - 1;
                temp4.second = (temp0.second);
            }
            ship.setPMedio(pos);
            setMarCor(ship);
            // posizionamento nel mare
            setMareAc(temp0);
            setMareAc(temp1);
            setMareAc(temp2);
            setMareAc(temp3);
            setMareAc(temp4);
            // posizionamento nel mareC
        }
        else
        {
            throw InvalidInputException("Inserimento non valido");
        }
    }

//inserimento Nds
    void Mare::insertNds(Nds& ship, pair<int, int> pos)
    {
        bool b = legitMoveInput(ship, pos);
        if (b == true)
        {
            pair<int, int> temp0;
            pair<int, int> temp1;
            pair<int, int> temp2;
            temp0.first = pos.first;
            temp0.second = pos.second;
            int d = ship.getDirezione();
            if (d == 1)
            {
                temp1.first = (temp0.first);       // x prua
                temp1.second = (temp0.second) - 1; // y prua
                temp2.first = (temp0.first);       // x poppa
                temp2.second = (temp0.second) + 1; // y poppa
            }

            else
            {
                temp1.first = (temp0.first) + 1; // x prua
                temp1.second = (temp0.second);   // y prua
                temp2.first = (temp0.first) - 1; // x poppa
                temp2.second = (temp0.second);   // y poppa
            }
            ship.setPMedio(pos);
            // posizionamento nel mareC
            setMarNds(ship);
            // posizionamento nel mare
            setMareAs(temp0);
            setMareAs(temp1);
            setMareAs(temp2);

        }
        else
        {
            throw InvalidInputException("Inserimento non valido");
        }
    }

    // inserimento Sde
    void Mare::insertSde(Sde& ship, pair<int, int> pos)
    {
        bool b = legitMoveInput(ship, pos);
        if (b == true)
        {
            pair<int, int> temp0;
            temp0.first = pos.first;
            temp0.second = pos.second;
            if (b == false)
            {
                throw InvalidInputException("Inserimento non valido");
            }
            if (b == true)
            {
                ship.setPMedio(temp0);
                // posizionamento nel mareC
                setMarSde(ship);
                // posizionamento nella board
                setMareAe(temp0);
            }
        }
    }

    //move generico
    void Mare::MoveG(pair<int, int> start, pair<int, int> dest, Mare m, Mare mN)
    {
        if(mar_[start.first][start.second] == 'C')
        {
            Corazzata t = m.whichCor(m.getMarCor(), start);
            Move(start, dest, t, mN);
        }
        else
        if(mar_[start.first][start.second] == 'S')
        {
            Nds t = m.whichNds(m.getMarNds(), start);
            Move(start, dest, t.getDirezione(), t, m);
        }
        else
        if(mar_[start.first][start.second] == 'E')
        {
            Sde t = m.whichSde(m.getMarSde(), start);
            Move(start, dest, t, m);
        }
    }

    //move Corazzata
    void Mare::Move(pair<int, int> start, pair<int, int> dest, Corazzata s, Mare mN)
    {
        getMareE(mN);
        if(marE_[dest.first][dest.second] == 'C')
        {
            Corazzata t = mN.whichCor(mN.getMarCor(), dest);
            CorHit(t, mN);
        }
        else
        if(mar_[dest.first][dest.second] == 'S')
        {
            Nds t = mN.whichNds(mN.getMarNds(), dest);
            NdsHit(t, mN);
        }
        else
        if(mar_[dest.first][dest.second] == 'E')
        {
            Sde t = mN.whichSde(mN.getMarSde(), dest);
            SdeHit(t, mN);
        }
        HitSet(dest, mN);  
    }

    //move Nds
    void Mare::Move(pair<int, int> start, pair<int, int> dest, int direzione, Nds s, Mare m)
    {   
        if(legitMoveInput(s,dest) == false)
        {
            throw InvalidMoveException("Spostamento non valido");
        }
        else
        if (legitMoveInput(s, dest) == true)
        {
            int d = s.getDirezione();
            pair<int, int> tmp = s.getPMedio();
            pair<int, int> tmp1;
            pair<int, int> tmp2;
            if(d==0)
            {
                tmp1.second = tmp.second + 1;
                tmp2.second = tmp.second - 1;
            }
            else
            {
                tmp1.first = tmp.second + 1;
                tmp2.first = tmp.second - 1;
            }
            setMareA(tmp, mar_);
            setMareA(tmp1, mar_);
            setMareA(tmp2, mar_);
            pair<int, int> temp1;
            pair<int, int> temp2;
            pair<pair<int, int>, pair<int, int> > temp3;
            if (d == 0)
            {
                temp1.first = dest.first;         // x prua
                temp1.second = (dest.second) + 1; // y prua
                temp2.first = dest.first;         // x poppa
                temp2.second = (dest.second) - 1; // y poppa
                temp3.first = temp1;             // c prua
                temp3.second = temp2;            // c poppa
                //s.setPos(temp3);
            }
            else
            {
                temp1.first = (dest.first) + 1;
                temp1.second = dest.second;
                temp2.first = (dest.first) - 1;
                temp2.second = dest.second;
                temp3.first = temp1;
                temp3.second = temp2;
            }
            // posizionamento nella board
            setMareAs(dest);
            setMareAs(temp1);
            setMareAs(temp2);
        }
    }

    //move Sde
    void Mare::Move(pair<int, int> start, pair<int, int> dest, Sde s, Mare m)
    {   
         if(legitMoveInput(s,dest) == false)
        {
            throw InvalidMoveException("Spostamento non valido");
        }
        if (legitMoveInput(s, dest) == true)
        {
            setMareA(start, mar_);
            pair<int, int> temp1;
            pair<int, int> temp2;
            pair<pair<int, int>, pair<int, int> > temp3;
            temp1.first = dest.first;         // x prua
            temp1.second = (dest.second);     // y prua
            temp3.first = temp1;             // c prua
            temp3.second = temp1;            // c poppa
            //s.setPos(temp3);
            // posizionamento nella board
            setMareAe(dest);
        }
    }

    //controllare se hanno almeno 1 coppia di coordinate adiacenti lungo x o y
    bool healConditions(Nds Nds, Corazzata Cor)
    {
        pair<int, int> cNds = Nds.getPMedio();
        int dNds = Nds.getDirezione();
        pair<int, int> cCor = Cor.getPMedio();
        int dCor = Cor.getDirezione();
        pair<int, int> tempN;
        tempN.first = 0;
        tempN.second = 0;
        pair<int, int> tempN1;
        tempN1.first = 0;
        tempN1.second = 0;
        //s = v, c = v;
        if(dNds == 0 || dCor == 0)
        {
            //dx
            for(int y = -3; y <= 3; y++)
            {
                tempN.first = (cCor.first + 1);
                tempN.second = (cCor.second + y);
                if((cNds) == (tempN))
                {return true;}
            }
            //sx
            for(int y = -3; y <= 3; y++)
            {
                tempN.first = (cCor.first - 1);
                tempN.second = (cCor.second + y);
                if((cNds) == (tempN))
                {return true;}
            }
        }
        //s = o, c = o;
        else if(dNds == 1 || dCor == 1)
        {
            //dx
            for(int x = -3; x <= 3; x++)
            {
                tempN.first = (cCor.first + x);
                tempN.second = (cCor.second + 1);
                if((cNds) == (tempN))
                {return true;}
            }
            //sx
            for(int x = -3; x <= 3; x++)
            {
                tempN.first = (cCor.first + x);
                tempN.second = (cCor.second - 1);
                if((cNds) == (tempN))
                {return true;}
            }
        }
        else
        //s = v, c = o;
        if(dNds == 0 || dCor == 1)
        {
            //sopra
            for(int y = -1; y <= 1; y++)
            {
                tempN.first = (cCor.first + 3);
                tempN.second = (cCor.second + y);
                if((cNds) == (tempN))
                {return true;}
            }
            //sotto
            for(int y = -1; y <= 1; y++)
            {
                tempN.first = (cCor.first - 3);
                tempN.second = (cCor.second + y);
                if((cNds) == (tempN))
                {return true;}
            }
        }
        else
        //s = o, c = v;
        if(dNds == 0 || dCor == 1)
        {
            //sopra
            for(int x = -1; x <= 1; x++)
            {
                tempN.first = (cCor.first + x);
                tempN.second = (cCor.second + 3);
                if((cNds) == (tempN))
                {return true;}
            }
            //sotto
            for(int x = -1; x <= 1; x++)
            {
                tempN.first = (cCor.first + x);
                tempN.second = (cCor.second - 3);
                if((cNds) == (tempN))
                {return true;}
            }
        }

        return false;
    }

    //controllare se hanno almeno 1 coppia di coordinate adiacenti lungo x o y
    bool healConditions(Nds NdsC, Nds Nds)
    {
        pair<int, int> cNds = Nds.getPMedio();
        int dNds = Nds.getDirezione();
        pair<int, int> cNdsC = NdsC.getPMedio();
        int dNdsC = NdsC.getDirezione();
        pair<int, int> tempN;
        tempN.first = 0;
        tempN.second = 0;
        //s = v, sc = v;
        if(dNds == 0 || dNdsC == 0)
        {
            //dx
            for(int y = -2; y <= 2; y++)
            {
                tempN.first = (cNdsC.first + 1);
                tempN.second = (cNdsC.second + y);
                if((cNds) == (tempN))
                {return true;}
            }
            //sx
            for(int y = -2; y <= 2; y++)
            {
                tempN.first = (cNdsC.first - 1);
                tempN.second = (cNdsC.second + y);
                if((cNds) == (tempN))
                {return true;}
            }
        }
        else
        //s = o, sc = o;
        if(dNds == 1 || dNdsC == 1)
        {
            //dx
            for(int x = -2; x <= 2; x++)
            {
                tempN.first = (cNdsC.first + x);
                tempN.second = (cNdsC.second + 1);
                if((cNds) == (tempN))
                {return true;}
            }
            //sx
            for(int x = -2; x <= 2; x++)
            {
                tempN.first = (cNdsC.first + x);
                tempN.second = (cNdsC.second - 1);
                if((cNds) == (tempN))
                {return true;}
            }
        }
        else
        //s = v, sc = o;
        if(dNds == 0 || dNdsC == 1)
        {
            // sopra
            for(int x = -1; x <= 1; x++)
            {
                tempN.first = (cNdsC.first + x);
                tempN.second = (cNdsC.second + 2);
                if((cNds) == (tempN))
                {return true;}
            }
            // sotto
            for(int x = -1; x <= 1; x++)
            {
                tempN.first = (cNdsC.first + x);
                tempN.second = (cNdsC.second - 2);
                if((cNds) == (tempN))
                {return true;}
            }
        }
        else
        //s = o, sc = v;
        if(dNds == 0 || dNdsC == 1)
        {
            //sopra
            for(int y = -1; y <= 1; y++)
            {
                tempN.first = (cNdsC.first + 2);
                tempN.second = (cNdsC.second + y);
                if((cNds) == (tempN))
                {return true;}
            }
            //sotto
            for(int y = -1; y <= 1; y++)
            {
                tempN.first = (cNdsC.first - 2);
                tempN.second = (cNdsC.second + y);
                if((cNds) == (tempN))
                {return true;}
            }
        }

        return false;
    }

    //ripristina la corazza della corazzata
    void Mare::CorHeal(Corazzata& s)
    {int c = 5; s.setCorazza(c);}


    //ripristina la corazza della nave da supporto
    void Mare::NdsHeal(Nds& s)
    {int c = 3; s.setCorazza(c);}


    //potere del sottomarino
    void Mare::SdeScan(Sde s)
    {
        pair <int, int> c = s.getPMedio();
        int x=c.first;
        int y=c.second;
        
        for(int y1=y-2; y1<=y+2; y1++)
        {
            for(int x1 = x-2; x1 <= x+2; x1++)
            {
                if(marE_[x1][y1] != ' ')
                {
                    marES_[x1][y1] = 'y';
                }
            }
        }
    }

    //sistemare
    void Mare::HitSet(pair<int, int> p, Mare mN)
    {
        getMareE(mN);
        int x = p.first;
        int y = p.second;
        if(marE_[x][y] != ' ')
        {
            setMareES(p, 'X');
        }
        else
        {
            setMareES(p, 'O');
        }
    }

    //corazzata viene colpita
    void Mare::CorHit(Corazzata s, Mare mN)
    {
        int c = s.getCorazza() - 1;
        s.setCorazza(c);
        if(s.getCorazza() == 0)
        {
            CorAff(s);
        }
        HitSet(s.getPMedio(), mN);
    }

    //nave da supporto viene colpita
    void Mare::NdsHit(Nds s, Mare mN)
    {
        int c = s.getCorazza() - 1;
        s.setCorazza(c);
        if(s.getCorazza() == 0)
        {
            NdsAff(s);
        }
        HitSet(s.getPMedio(), mN);
    }

    //sottomarino viene colpita
    void Mare::SdeHit(Sde s, Mare mN)
    {
        int c = s.getCorazza() - 1;
        s.setCorazza(c);
        if(s.getCorazza() == 0)
        {
            SdeAff(s);
        }
        HitSet(s.getPMedio(), mN);
    }

    //corazzata viene affondata
    void Mare::CorAff(Corazzata s)
    {//-
        s.setState((-1));
        marCor_.erase(remove(marCor_.begin(), marCor_.end(), s));
        int d = s.getDirezione();
        pair<int, int> p = s.getPMedio();
        int x = p.first;
        int y = p.second;
        if(d==0)
        {
            mar_[x][y+1] = ' ';
            mar_[x][y+2] = ' ';
            mar_[x][y-1] = ' ';
            mar_[x][y-2] = ' ';
        }
        else
        {
            mar_[x+1][y] = ' ';
            mar_[x+2][y] = ' ';
            mar_[x-1][y] = ' ';
            mar_[x-2][y] = ' ';
        }
    }

    //nave da supporto viene affondata
    void Mare::NdsAff(Nds s)
    {
        s.setState((-1));
        marNds_.erase(remove(marNds_.begin(), marNds_.end(), s));
        int d = s.getDirezione();
        pair<int, int> p = s.getPMedio();
        int x = p.first;
        int y = p.second;
        if(d==0)
        {
            mar_[x][y+1] = ' ';
            mar_[x][y-1] = ' ';
        }
        else
        {
            mar_[x+1][y] = ' ';
            mar_[x-1][y] = ' ';
        }
    }

    //sottomarino viene affondato
    void Mare::SdeAff(Sde s)
    {
        s.setState((-1));
        if(s.getDirezione() == 0)
        {
            pair<int, int> pM = s.getPMedio();
        }
        marSde_.erase(remove(marSde_.begin(), marSde_.end(), s));
        int d = s.getDirezione();
        pair<int, int> p = s.getPMedio();
        int x = p.first;
        int y = p.second;
        //mar_[x][y];
    }

/*____________________________________________________________________________________________________________________________________________________________*/

//sistemare sopra
/*
    //fixare
    void Mare::updateLogMove(pair<int, int> start, pair<int, int> end)
    {
        ofstream write;
        write.open(logFile_, ofstreaapp);
        string out;
        out += to_string(start.first) + to_string(start.second) + " ";
        out += to_string(end.first) + to_string(end.second) + "\n";
        write << out;
        write.close();
    }

    void Mare::updateLogVictory(int ending)
    {
        ofstream write;
        write.open(logFile_, ofstreaapp);
        write << "END:" << ending;
        write.close();
    }

    void Mare::updateLogGameType(string type)
    {
        ofstream write;
        write.open(logFile_, ofstreaapp);
        write << type << "\n";
        write.close();
    }
*/
/*____________________________________________________________________________________________________________________________________________________________*/

    //stampa mare
    string Mare::printAMare()
    {
        vector<string> vec;
        for (char c = 'A'; c <= 'I'; c++) 
        {
            vec.push_back(string(1, c));
        }
        for (char c = 'L'; c <= 'N'; c++) 
        {
            vec.push_back(string(1, c));
        }
        string out = "";
        out += "   +-----------------------------------------------+\n";
        int i = 0;
        for (const auto &row : mar_)
        {
            if ((i + 1) >= 10)
            {
                out += " ";
                out += vec[i];
            }
            else
            {
                out += " ";
                out += vec[i];
            }
            out += " ¦ ";
            for (const auto &element : row)
            {
                if (element == ' ')
                {
                    out += " ";
                }
                else
                {
                    char s = element;
                    out += s;
                }
                out += " ¦ ";
            }
            out += "\n";
            if (i >= 0 && i < 11)
            {out += "   +---+---+---+---+---+---+---+---+---+---+---+---¦\n";}
            else
            {
            out += "   +-----------------------------------------------+\n";
            out += "     1   2   3   4   5   6   7   8   9   10  11  12\n";
            break;
            }

            if (i == 11)
            {i = 0;}
            else
            {i++;}
        }
        cout << out << endl;
        return out;
    }

    string Mare::printEMare()
    {
        vector<string> vec;
        for (char c = 'A'; c <= 'I'; c++) 
        {
            vec.push_back(string(1, c));
        }
        for (char c = 'L'; c <= 'N'; c++) 
        {
            vec.push_back(string(1, c));
        }
        string out = "";
        out += "   +-----------------------------------------------+\n";
        int i = 0;
        for (const auto &row : marES_)
        {
            if ((i + 1) >= 10)
            {
                out += " ";
                out += vec[i];
            }
            else
            {
                out += " ";
                out += vec[i];
            }
            out += " ¦ ";
            for (const auto &element : row)
            {
                if (element == ' ')
                {
                    out += " ";
                }
                else
                {
                    char s = element;
                    out += s;
                }
                out += " ¦ ";
            }
            out += "\n";
            if (i >= 0 && i < 11)
            {out += "   +---+---+---+---+---+---+---+---+---+---+---+---¦\n";}
            else
            {
            out += "   +-----------------------------------------------+\n";
            out += "     1   2   3   4   5   6   7   8   9   10  11  12\n";
            break;
            }

            if (i == 11)
            {i = 0;}
            else
            {i++;}
        }
        cout << out << endl;
        return out;
    }

    //getter
    int Mare::getMCondition()
    { return condition_;}

    //metodo ceh restituisce un vettore contenente le posiz disponibili dove inserire la corazzata
    vector<pair<int, int> > Mare::posAvailable(Corazzata shi)
    {
        vector<pair<int, int> > v1 = shi.Moves();
        pair<int, int> p;
        int d = shi.getDirezione();
        if(d==0)
        {
            for(int x = 0; x < 12; x++)
            {
                for(int y = 2; y < 10; y++)
                {
                    if (mar_[x][y+2] != ' ' || mar_[x][y+1] != ' ' || mar_[x][y] != ' ' || mar_[x][y-1] != ' ' || mar_[x][y-2] != ' ')
                    {
                        for(int i = 0; i<v1.size()-1; i++)
                        {
                            if (v1[i].first == x && v1[i].second == y)
                            {
                                v1.erase(v1.begin() + i);
                                break;
                            }
                        }
                    }
                    else
                    {
                        int temp = 0;
                        for(int i = 0; i<v1.size(); i++)
                        {
                            if(v1[i].first == x && v1[i].second == y)
                            {
                                temp = 1;
                            }
                        }
                        if(temp == 0)
                        {
                            p.first = x;
                            p.second = y;
                            v1.push_back(p);
                        }
                    }
                }
            }
        }
        else
        {
            for(int x = 2; x < 10; x++)
            {
                for(int y = 0; y < 12; y++)
                {
                    if (mar_[x][y] != ' ' || mar_[x+1][y] != ' ' || mar_[x-1][y] != ' ' || mar_[x+2][y] != ' ' || mar_[x-2][y] != ' ')
                    {
                        for(int i = 0; i<v1.size(); i++)
                        {
                            if(v1[i].first == x && v1[i].second == y)
                            {
                                v1.erase(v1.begin() + i);
                                break;
                            }
                        }
                    }
                    else
                    {
                        int temp = 0;
                        for(int i = 0; i<v1.size(); i++)
                        {
                            if(v1[i].first == x && v1[i].second == y)
                            {
                                temp = 1;
                                break;
                            }
                        }
                        if(temp == 0)
                        {
                            p.first = x;
                            p.second = y;
                            v1.push_back(p);
                        }
                    }
                }
            }
        }
        return v1;
    }

    //metodo ceh restituisce un vettore contenente le posiz disponibili dove inserire la nave da supporto
    vector<pair<int, int> > Mare::posAvailable(Nds shi)
    {
        vector<pair<int, int> > v1 = shi.Moves();
        pair<int, int> p;
        int d = shi.getDirezione();
        if(d==0)
        {
            for (int x = 0; x < 12; x++)
            {
                for(int y = 1; y < 11; y++)
                {
                    if (mar_[x][y] != ' ' || mar_[x][y+1] != ' ' || mar_[x][y-1] != ' ')
                    {
                        for(int i = 0; i<v1.size(); i++)
                        {
                            if(v1[i].first == x && v1[i].second == y)
                            {
                                v1.erase(v1.begin() + i);
                                break;
                            }
                        }
                    }
                    else
                    {
                        int temp = 0;
                        for(int i = 0; i<v1.size(); i++)
                        {
                            if(v1[i].first == x && v1[i].second == y)
                            {
                                temp = 1;
                                break;
                            }
                        }
                        if(temp == 0)
                        {
                            p.first = x;
                            p.second = y;
                            v1.push_back(p);
                        }
                    }
                }
            }
        }
        else
        {
            for(int x = 1; x < 11; x++)
            {
                for(int y = 0; y < 12; y++)
                {
                    if (mar_[x][y] != ' ' || mar_[x+1][y] != ' ' || mar_[x-1][y] != ' ')
                    {
                        for(int i = 0; i<v1.size(); i++)
                        {
                            if(v1[i].first == x && v1[i].second == y)
                            {
                                v1.erase(v1.begin() + i);
                                break;
                            }
                        }
                    }
                    else
                    {
                        int temp = 0;
                        for(int i = 0; i<v1.size(); i++)
                        {
                            if(v1[i].first == x && v1[i].second == y)
                            {
                                temp = 1;
                                break;
                            }
                        }
                        if(temp == 0)
                        {
                            p.first = x;
                            p.second = y;
                            v1.push_back(p);
                        }
                    }
                }
            }
        }
        return v1;
    }

    //metodo ceh restituisce un vettore contenente le posiz disponibili dove inserire il sottomarino
    vector<pair<int, int> > Mare::posAvailable(Sde shi)
    {
        vector<pair<int, int> > v1 = shi.Moves();
        pair<int, int> p;
        for(int x = 0; x < 12; x++)
        {
            for(int y = 0; y < 12; y++)
            {
                if(mar_[x][y] != ' ')
                {
                    for(int i = 0; i<v1.size(); i++)
                    {
                        if(v1[i].first == x && v1[i].second == y)
                        {
                            v1.erase(v1.begin() + i);
                            break;
                        }
                    }
                }
                else
                {
                    int temp = 0;
                    for(int i = 0; i<v1.size(); i++)
                    {
                        if(v1[i].first == x && v1[i].second == y)
                        {
                            temp = 1;
                        }
                    }
                    if(temp == 0)
                    {
                        p.first = x;
                        p.second = y;
                        v1.push_back(p);
                    }
                }
            }
        }
        return v1;
    }
