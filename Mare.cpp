#include "Mare.hpp"

using namespace std;
  
    Mare::Mare()
    {
        this -> condition_ = -1;
        this -> drawMoves_ = 0;
        initializeMare(mar_);
    }

    void Mare::setMareA(pair<int, int> p, vector<vector<char> > mar_)
    {
        int x = p.first;
        int y = p.second;
        cout<<"spazio"<<endl;
        mar_[x][y] = ' ';
    }

    vector<vector<char>> Mare::setMareAc(pair<int, int> p, vector<vector<char> > mar_)
    {
        int x = p.first;
        int y = p.second;
        mar_.resize(12);
        for (int i = 0; i < 12; i++) {
            mar_[i].resize(12);
        }
        mar_[x][y] = 'C';
        cout << "c di palle" << endl;
        printAMare();
        cout << "c di figa" << endl;
        return mar_;
    }

    void Mare::setMareAs(pair<int, int> p, vector<vector<char> > mar_)
    {
        int x = p.first;
        int y = p.second;
        cout<<"s di stronzo"<<endl;
        mar_[x][y] = 'S';
    }

    void Mare::setMareAe(pair<int, int> p, vector<vector<char> > mar_)
    {
        int x = p.first;
        int y = p.second;
        cout<<"e di esucchiamelo"<<endl;
        mar_[x][y] = 'E';
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

    vector<vector<char> > Mare::getMare()
    {
        vector<vector<char> > v;
        vector<char> v1;

        for(int y=0; y<12; y++)
        {
            for(int x=0; x<12; x++)
            {
                v1.push_back(this -> mar_[x][y]);
            }
            v.push_back(v1);
        }
        return v;
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

    void Mare::setMarCor(Corazzata c)
    {
        cout << "inserisco" << endl;
        marCor_.push_back(c);
        cout << "ho fatto collione" << endl;
    }
    void Mare::setMarNds(Nds n)
    {
        marNds_.push_back(n);
    }
    void Mare::setMarSde(Sde s)
    {
        marSde_.push_back(s);
    }

    vector<Corazzata> Mare::getMarCor()
    {return this -> marCor_;}

    vector<Nds> Mare::getMarNds()
    {return this -> marNds_;}
    
    vector<Sde> Mare::getMarSde()
    {return this -> marSde_;}

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

    bool Mare::legitMoveInput(Corazzata ship, pair<int, int> pos)
    {   
        cout << "legitMoveInput" << endl;
        vector<pair<int, int> > v = posAvailable(ship);
        for(int i = 0; i<v.size(); i++)
        {
            cout << "xC = " << v[i].first << "yC = " << v[i].second << endl;
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
            cout << "xN =" << v[i].first << " yN = " << v[i].second <<endl;
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
            cout << "xS =" << v[i].first << " yS = " << v[i].second <<endl;
            if(v[i].first == pos.first && v[i].second == pos.second)
            {return true;} 
        }
        return false;
    }

    void Mare::initializeMare(vector<vector<char> > mar_)
    {
        vector<char> v;
        for(int x = 0; x < 12; x++)
        {
            for(int y = 0; y < 12; y++)
            {
                v.push_back(' ');
            }
            mar_.push_back(v);
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
        cout << "chiamata prima di legit" << endl;
        bool b = legitMoveInput(ship, pos);
        cout << "b = " << b << endl;
        if (b == true)
        {   
            cout << " b è in true!!!!" << endl;
            pair<int, int> temp1;
            pair<int, int> temp2;
            pair<int, int> temp3;
            pair<int, int> temp4;
            int d = ship.getDirezione();
            if(d == 0)
            {
                cout << "sono in d == 0" << endl;
                temp1.first = pos.first;         // x prua
                temp1.second = (pos.second) + 2; // y prua
                temp2.first = pos.first;         // x poppa
                temp2.second = (pos.second) - 2; // y poppa
                temp3.first = pos.first;
                temp3.second = (pos.second) + 1;
                temp4.first = pos.first;
                temp4.second = (pos.second) - 1;
                cout << "ho finito il d == 0" << endl; 
            }
            else
            {
                cout << "sono in d == 1" << endl;
                temp1.first = (pos.first) + 2; // x prua
                temp1.second = pos.second;     // y prua
                temp2.first = (pos.first) - 2; // x poppa
                temp2.second = pos.second;     // y poppa
                temp3.first = (pos.first) + 1;
                temp3.second = pos.second;
                temp4.first = (pos.first) - 1;
                temp4.second = pos.second;
            }
            cout << "setto pmedio" << endl;
            ship.setPMedio(pos);
            cout << "inserisco in marCor_" << endl;
            setMarCor(ship);
            cout << "ho inserito in marCor_" << endl; 
            // posizionamento nel mare
            cout << "setto il mare" << endl;
            setMareAc(pos, mar_);
            setMareAc(temp1, mar_);
            setMareAc(temp2, mar_);
            setMareAc(temp3, mar_);
            setMareAc(temp4, mar_);
            // posizionamento nel mareC
        }
        else
        {
            cout << "errore" << endl;
            throw InvalidInputException("Inserimento non valido");
        }
    }

//inserimento Nds
    void Mare::insertNds(Nds& ship, pair<int, int> pos)
    {
        bool b =legitMoveInput(ship, pos);
        if(b == false)
        {
            throw InvalidInputException("Inserimento non valido");
        }
        if (b == true)
        {
            pair<int, int> temp1;
            pair<int, int> temp2;
            if (ship.getDirezione() == 0)
            {
                temp1.first = pos.first;         // x prua
                temp1.second = (pos.second) + 1; // y prua
                temp2.first = pos.first;         // x poppa
                temp2.second = (pos.second) - 1; // y poppa
            }
            else
            {
                temp1.first = (pos.first) + 1;
                temp1.second = pos.second;
                temp2.first = (pos.first) - 1;
                temp2.second = pos.second;
            }
            // posizionamento nella board
            ship.setPMedio(pos);
            setMareAs(pos, mar_);
            setMareAs(temp1, mar_);
            setMareAs(temp2, mar_);
            // posizionamento nel mareC
            setMarNds(ship);
        }
    }

    // inserimento Sde
    void Mare::insertSde(Sde& ship, pair<int, int> pos)
    {   
        bool b = legitMoveInput(ship, pos);
        cout << "torno in insertSde" << endl;
        if(b == false)
        {
            cout << "torno in b == false" << endl;
            //throw InvalidInputException("Inserimento non valido");
        }
        if (b == true)
        {
            cout << "b è true!!!!!!" << endl;
            ship.setPMedio(pos);
            // posizionamento nella board
            setMareAe(pos, mar_);
            // posizionamento nel mareC
            setMarSde(ship);
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
            setMareAs(dest, mar_);
            setMareAs(temp1, mar_);
            setMareAs(temp2, mar_);
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
            setMareAe(dest, mar_);
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

    void Mare::CorHeal(Corazzata& s)
    {int c = 5; s.setCorazza(c);}

    void Mare::NdsHeal(Nds& s)
    {int c = 3; s.setCorazza(c);}

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

    string Mare::printAMare()
    {
        cout<<"suca stea no so una funxion de merda"<<endl;
        string out = "";
        //out += "   ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐\n";
        cout<<mar_.size()<<endl;
        out += "   +-----------------------------------------------+\n";
        for (int i = mar_.size()-1; i >= 0; i--)
        {
            if ((i + 1) >= 10)
            {out += to_string(i + 1);}
            else
            {out += " ";out += to_string(i + 1);}
            //out += " │ ";
            out += " ¦ ";
            for (int j = 0; j < mar_[i].size(); j++)
            {
                if (mar_[i][j] == ' ')
                    {
                        out += " ";
                        //out += " │ ";
                    }
                else
                {
                    //string s = to_string(mar_[i][j]);
                    //out += s;
                }
                out += mar_[i][j];
                out += " ¦ ";
            }
            out += "\n";
            if (i >= 1)
                out += "   +---+---+---+---+---+---+---+---+---+---+---+---¦\n";
                //out += "   ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤\n";
                
        }
        //out += "   └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘\n";
        out += "   +-----------------------------------------------+\n";
        out += "     A   B   C   D   E   F   G   H   I   J   K   L";
        cout<<out<<endl;
        return out;
    }

    string Mare::printEMare()
    {
        string out = "";
        // out += "   ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐\n";
        out += "   +-----------------------------------------------+\n";
        for (int i = 11; i >= 0; i--)
        {
            if ((i + 1) >= 10)
            {
                out += to_string(i + 1);
            }
            else
            {
                out += " ";
                out += to_string(i + 1);
            }
            // out += " │ ";
            out += " ¦ ";
            for (int j = 0; j < 12; j++)
            {
                if (marES_[i][j] != ' ')
                    out += marES_[i][j];
                else
                    out += "   ";
                // out += " │ ";
                out += " ¦ ";
            }
            out += "\n";
            if (i >= 1)
                out += "   +---+---+---+---+---+---+---+---+---+---+---+---¦\n";
            // out += "   ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤\n";
        }
        // out += "   └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘\n";
        out += "   +-----------------------------------------------+\n";
        out += "     A   B   C   D   E   F   G   H   I   J   K   L";
        return out;
    }

    int Mare::getMCondition()
    { return condition_;}

    vector<pair<int, int> > Mare::posAvailable(Corazzata shi)
    {
        cout << "sono in PosAvailableCor" << endl;
        vector<pair<int, int> > v1 = shi.Moves();
        pair<int, int> p;
        int d = shi.getDirezione();
        //---------------------------------------------------
        if(d==0)
        {
            cout<<"C1"<<endl;
            for(int x = 0; x < mar_.size(); x++)
            {
                cout<<"C2"<<endl;
                cout<< "Xtemp = " << x << " "; 
                for(int y = 2; y < mar_[x].size()-2; y++)
                {
                    cout << "C3" << endl;
                    cout << "Ytemp = " << y << " ";
                    cout << "C4" << endl;
                    if (mar_[x][y+2] != ' ' || mar_[x][y+1] != ' ' || mar_[x][y] != ' ' || mar_[x][y-1] != ' ' || mar_[x][y-2] != ' ')
                    {
                        cout << "C5" << endl;
                        for(int i = 0; i<v1.size()-1; i++)
                        {
                            cout << "C6" << endl;
                            if (v1[i].first == x && v1[i].second == y)
                            {
                                cout << "C7" << endl;
                                v1.erase(v1.begin() + i);
                                break;
                            }
                        }
                    }
                    else
                    {
                        cout << "C7" << endl;
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
            for(int x = 2; x < mar_.size()-2; x++)
            {
                cout<< "Xtemp = " << x << " ";
                for(int y = 0; y < mar_[x].size(); y++)
                {
                    cout << "Ytemp = " << y << " ";
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
        cout << "v1 = " << " ";
        for (int i = 0; i < v1.size(); i++)
        {
            cout << v1.at(i).first << " " << v1.at(i).second << endl;;
        }
        return v1;
    }

    vector<pair<int, int> > Mare::posAvailable(Nds shi)
    {
        vector<pair<int, int> > v1 = shi.Moves();
        pair<int, int> p;
        int d = shi.getDirezione();
        if(d==0)
        {
            for (int x = 0; x < mar_.size(); x++)
            {
                for(int y = 1; y < mar_[x].size() - 1; y++)
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
            for(int x = 1; x < mar_.size() - 1; x++)
            {
                for(int y = 0; y < mar_[x].size(); y++)
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

    vector<pair<int, int> > Mare::posAvailable(Sde shi)
    {
        vector<pair<int, int> > v1 = shi.Moves();
        pair<int, int> p;
        for(int x = 0; x < mar_.size(); x++)
        {
            for(int y = 0; y < mar_[x].size(); y++)
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
