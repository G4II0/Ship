#include "Mare.hpp"
using namespace std;
    Mare::Mare()
    {
        //this -> mar_ [12][12];
        this -> condition = -1;
        this -> drawMoves = 0;
    }

    void Mare::setMareA(pair<int, int> p, char c)
    {
        int x = p.first;
        int y = p.second;
        this -> mar_[x][y] = c;
    }

    void Mare::setMareE(pair<int, int> p, char c)
    {
        int x = p.first;
        int y = p.second;
        this -> marE_[x][y] = c;
    }

    void Mare::setMareES(pair<int, int> p, char c)
    {
        int x = p.first;
        int y = p.second;
        this -> marES_[x][y] = c;
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

    vector<Corazzata> Mare::getMarCor()
    {return this -> marCor;}

    vector<Nds> Mare::getMarNds()
    {return this -> marNds;}
    
    vector<Sde> Mare::getMarSde()
    {return this -> marSde;}

    Corazzata whichCor(vector<Corazzata> marCor, pair<int, int> pos)
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

    Nds whichNds(vector<Nds> marNds, pair<int, int> pos)
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

    Sde whichSde(vector<Sde> marSde, pair<int, int> pos)
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

    bool Mare::legitMoveInput(Corazzata ship, pair<int, int> pos, Mare m)
    {
        vector<pair<int, int> > v = posAvailable(ship);
        if (find(v.begin(), v.end(), pos) != v.end())
        return true;
        else
        return false;
    }
        bool Mare::legitMoveInput(Nds ship, pair<int, int> pos, Mare m)
    {
        vector<pair<int, int> > v = posAvailable(ship);
        if (find(v.begin(), v.end(), pos) != v.end())
        return true;
        else
        return false;
    }
        bool Mare::legitMoveInput(Sde ship, pair<int, int> pos, Mare m)
    {
        vector<pair<int, int> > v = posAvailable(ship);
        if (find(v.begin(), v.end(), pos) != v.end())
        return true;
        else
        return false;
    }

    void Mare::initializeMare(char (&mar_)[12][12])
    {int x=0, y=0;

        while (x < 12)
        {
            while (y < 12)
            {
                mar_[x][y] = ' ';
                    y++;
            }
            x++;
        }
    }

    void Mare::initializeMareES(char (&marES_) [12][12])
    {int x=0, y=0;

        while (x < 12)
        {
            while (y < 12)
            {
                marES_[x][y] = ' ';
                    y++;
            }
            x++;
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
    void Mare::insertCor(Corazzata& ship, pair<int, int> pos, Mare m)
    {
        if (legitMoveInput(ship, pos, m) == true)
        {
            pair<int, int> temp1;
            pair<int, int> temp2;
            pair<int, int> temp3;
            pair<int, int> temp4;
            pair<pair<int, int>, pair<int, int> > temp5;
            if (ship.getDirezione() == 0)
            {
                temp1.first = pos.first;         // x prua
                temp1.second = (pos.second) + 2; // y prua
                temp2.first = pos.first;         // x poppa
                temp2.second = (pos.second) - 2; // y poppa
                temp3.first = pos.first;
                temp3.second = (pos.second) + 1;
                temp4.first = pos.first;
                temp2.second = (pos.second) - 1;
                temp5.first = temp1;  // c prua
                temp5.second = temp2; // c poppa
                ship.setPos(temp5);
            }
            else
            {
                temp1.first = (pos.first) + 2; // x prua
                temp1.second = pos.second;     // y prua
                temp2.first = (pos.first) - 2; // x poppa
                temp2.second = pos.second;     // y poppa
                temp3.first = (pos.first) + 1;
                temp3.second = pos.second;
                temp4.first = (pos.first) - 1;
                temp2.second = pos.second;
                temp5.first = temp1;  // c prua
                temp5.second = temp2; // c poppa
                ship.setPos(temp5);
            }
            // posizionamento nel mare
            m.setMareA(pos, 'C');
            m.setMareA(temp1, 'C');
            m.setMareA(temp2, 'C');
            m.setMareA(temp3, 'C');
            m.setMareA(temp4, 'C');
            // posizionamento nel mareC
            marCor[ship.getNumero()] = ship;
        }
        //throw InvalidMoveException();
    }

//inserimento Nds
    void Mare::insertNds(Nds& ship, pair<int, int> pos, Mare m)
    {
        if (legitMoveInput(ship, pos, m) == true)
        {
            pair<int, int> temp1;
            pair<int, int> temp2;
            pair<pair<int, int>, pair<int, int> > temp3;
            if (ship.getDirezione() == 0)
            {
                temp1.first = pos.first;         // x prua
                temp1.second = (pos.second) + 1; // y prua
                temp2.first = pos.first;         // x poppa
                temp2.second = (pos.second) - 1; // y poppa
                temp3.first = temp1;             // c prua
                temp3.second = temp2;            // c poppa
                ship.setPos(temp3);
            }
            else
            {
                temp1.first = (pos.first) + 1;
                temp1.second = pos.second;
                temp2.first = (pos.first) - 1;
                temp2.second = pos.second;
                temp3.first = temp1;
                temp3.second = temp2;
                ship.setPos(temp3);
            }
            // posizionamento nella board
            m.setMareA(pos, 'S');
            m.setMareA(temp1, 'S');
            m.setMareA(temp2, 'S');
            // posizionamento nel mareC
            marNds[ship.getNumero()] = ship;
        }
        //throw InvalidMoveException();
    }

    // inserimento Sde
    void Mare::insertSde(Sde& ship, pair<int, int> pos, Mare m)
    {
        if (legitMoveInput(ship, pos, m) == true)
        {
            pair<int, int> temp1;
            pair<int, int> temp2;
            pair<pair<int, int>, pair<int, int> > temp3;
            temp1.first = pos.first;         // x prua
            temp1.second = (pos.second);     // y prua
            temp3.first = temp1;             // c prua
            temp3.second = temp1;            // c poppa
            ship.setPos(temp3);
            // posizionamento nella board
            m.setMareA(pos, 'E');
            // posizionamento nel mareC
            marSde[ship.getNumero()] = ship;
        }
        //throw InvalidMoveException();
    }

    //move generico
    void Mare::Move(pair<int, int> start, pair<int, int> dest, Mare m, Mare mN)
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
        //throw InvalidMoveException();
    }

    //move Corazzata
    void Mare::Move(pair<int, int> start, pair<int, int> dest, Corazzata s, Mare mN)
    {
        getMareE(mN);
        if(marE_[dest.first][dest.second] == 'C')
        {
            Corazzata t = mN.whichCor(mN.getMarCor(), dest);
            CorHit(t);
        }
        else
        if(mar_[dest.first][dest.second] == 'S')
        {
            Nds t = mN.whichNds(mN.getMarNds(), dest);
            NdsHit(t);
        }
        else
        if(mar_[dest.first][dest.second] == 'E')
        {
            Sde t = mN.whichSde(mN.getMarSde(), dest);
            SdeHit(t);
        }
        HitSet(dest, mN);  
    }

    //move Nds
    void Mare::Move(pair<int, int> start, pair<int, int> dest, int direzione, Nds s, Mare m)
    {
        if (legitMoveInput(s, dest, m) == true)
        {
            setMareA(start, ' ');
            setMareA(s.getPrua(), ' ');
            setMareA(s.getPoppa(), ' ');
            pair<int, int> temp1;
            pair<int, int> temp2;
            pair<pair<int, int>, pair<int, int> > temp3;
            if (s.getDirezione() == 0)
            {
                temp1.first = dest.first;         // x prua
                temp1.second = (dest.second) + 1; // y prua
                temp2.first = dest.first;         // x poppa
                temp2.second = (dest.second) - 1; // y poppa
                temp3.first = temp1;             // c prua
                temp3.second = temp2;            // c poppa
                s.setPos(temp3);
            }
            else
            {
                temp1.first = (dest.first) + 1;
                temp1.second = dest.second;
                temp2.first = (dest.first) - 1;
                temp2.second = dest.second;
                temp3.first = temp1;
                temp3.second = temp2;
                s.setPos(temp3);
            }
            // posizionamento nella board
            setMareA(dest, 'S');
            setMareA(temp1, 'S');
            setMareA(temp2, 'S');
            healConditions(s);
        }
        //throw InvalidMoveException();
    }

    //move Sde
    void Mare::Move(pair<int, int> start, pair<int, int> dest, Sde s, Mare m)
    {
        if (legitMoveInput(s, dest, m) == true)
        {
            setMareA(start, ' ');
            pair<int, int> temp1;
            pair<int, int> temp2;
            pair<pair<int, int>, pair<int, int> > temp3;
            temp1.first = dest.first;         // x prua
            temp1.second = (dest.second);     // y prua
            temp3.first = temp1;             // c prua
            temp3.second = temp1;            // c poppa
            s.setPos(temp3);
            // posizionamento nella board
            setMareA(dest, 'E');
        }
    }

    //controllare se hanno almeno 1 coppia di coordinate adiacenti lungo x o y
    void healConditions(Nds Nds)
    {
        pair<int, int> cNds = Nds.getPMedio();
        pair<int, int> cNds1 = Nds.getPMedio();
        int dNds = Nds.getDirezione();
        vector<Corazzata> marCor;
        marCor = getMarCor();
        pair<int, int> cCor;
        pair<int, int> tempN;
        tempN.first = 0;
        tempN.second = 0;
        int c = 0;
        if(dNds == 0)
        {
            for(int i = 0; i<marCor.size(); i++)
            {
                cCor = marCor[i].getPMedio();
                int dCor = marCor[i].getDirezione();
                for(int y = -3; y <= 3; y++)
                {
                    tempN.first = (cCor.first + 1);
                    tempN.second = (cCor.second + y);
                    if((cNds) == (tempN) || dCor == 0)
                    {CorHeal(marCor[i])}
                }
                for(int y = -3; y <= 3; y++)
                {
                    tempN.first = (cCor.first - 1);
                    tempN.second = (cCor.second + y);
                    if((cNds) == (tempN) || dCor == 0)
                    {CorHeal(marCor[i])}
                }
                for(int x = -1; x <= 1; x++)
                {
                    tempN.first = (cCor.first + x);
                    tempN.second = (cCor.second + 3);
                    if((cNds) == (tempN) || dCor == 0)
                    {CorHeal(marCor[i])}
                }
                for(int x = -1; x <= 1; x++)
                {
                    tempN.first = (cCor.first + x);
                    tempN.second = (cCor.second - 3);
                    if((cNds) == (tempN) || dCor == 0)
                    {CorHeal(marCor[i])}
                }
            }
            for(int i = 0; i<marNds.size(); i++)
            {
                cNds = marNds[i].getPMedio();
                int dNds1 = marNds[i].getDirezione();
                for(int y = -2; y <= 2; y++)
                {
                    tempN.first = (cNds1.first + 1);
                    tempN.second = (cNds1.second + y);
                    if((cNds) == (tempN) || dNds1 == 0)
                    {NdsHeal(marNds[i])}
                }
                for(int y = -2; y <= 2; y++)
                {
                    tempN.first = (cNds1.first - 1);
                    tempN.second = (cNds1.second + y);
                    if((cNds) == (tempN) || dNds1 == 0)
                    {NdsHeal(marNds[i])}
                }
                for(int x = -1; x <= 1; x++)
                {
                    tempN.first = (cNds1.first + x);
                    tempN.second = (cNds1.second + 2);
                    if((cNds) == (tempN) || dNds1 == 0)
                    {NdsHeal(marNds[i])}
                }
                for(int x = -1; x <= 1; x++)
                {
                    tempN.first = (cNds1.first + x);
                    tempN.second = (cNds1.second - 2);
                    if((cNds) == (tempN) || dNds1 == 0)
                    {NdsHeal(marCorNds[i])}
                }
            }
        }
        if(dNds == 1)
        {
            for(int i = 0; i<marCor.size(); i++)
            {
                for(int x = -3; x <= 3; x++)
                {
                    tempN.first = (cCor.first + x);
                    tempN.second = (cCor.second + 1);
                    if((cNds) == (tempN) || dCor == 1)
                    {CorHeal(marCor[i])}
                }
            
                for(int x = -3; x <= 3; x++)
                {
                    tempN.first = (cCor.first + x);
                    tempN.second = (cCor.second - 1);
                    if((cNds) == (tempN) || dCor == 1)
                    {CorHeal(marCor[i])}
                }
                for(int y = -3; y <= 3; y++)
                {
                    tempN.first = (cCor.first + 3);
                    tempN.second = (cCor.second + y);
                    if((cNds) == (tempN) || dCor == 1)
                    {CorHeal(marCor[i])}
                }
                for(int y = -3; y <= 3; y++)
                {
                    tempN.first = (cCor.first - 3);
                    tempN.second = (cCor.second + y);
                    if((cNds) == (tempN) || dCor == 1)
                    {CorHeal(marCor[i])}
                }
            }
            for(int i = 0; i<marNds.size(); i++)
            {
                cNds = marNds[i].getPMedio();
                int dNds = marNds[i].getDirezione();
                for(int x = -2; x <= 2; x++)
                {
                    tempN.first = (cNds1.first + x);
                    tempN.second = (cNds1.second + 1);
                    if((cNds) == (tempN) || dNds == 1)
                    {NdsHeal(marNds[i])}
                }
                for(int x = -2; x <= 2; x++)
                {
                    tempN.first = (cNds1.first - x);
                    tempN.second = (cNds1.second - 1);
                    if((cNds) == (tempN) || dNds == 1)
                    {NdsHeal(marNds[i])}
                }
                for(int y = -2; y <= 2; x++)
                {
                    tempN.first = (cNds1.first + 2);
                    tempN.second = (cNds1.second + y);
                    if((cNds) == (tempN) || dNds == 1)
                    {NdsHeal(marNds[i])}
                }
                for(int x = -2; x <= 2; x++)
                {
                    tempN.first = (cNds1.first - 2);
                    tempN.second = (cNds1.second + y);
                    if((cNds) == (tempN) || dNds == 1)
                    {NdsHeal(marNds[i])}
                }
            }
        }
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

    void Mare::CorHit(Corazzata s)
    {
        int c = s.getCorazza() - 1;
        s.setCorazza(c);
        if(s.getCorazza() == 0)
        {
            CorAff(s); //sistemare
        }
    }

    void Mare::NdsHit(Nds s)
    {
        int c = s.getCorazza() - 1;
        s.setCorazza(c);
        if(s.getCorazza() == 0)
        {
            NdsAff(s); //sistemare
        }
    }

    void Mare::SdeHit(Sde s)
    {
        int c = s.getCorazza() - 1;
        s.setCorazza(c);
        if(s.getCorazza() == 0)
        {
            SdeAff(s); //sistemare
        }
    }

    void Mare::CorAff(Corazzata s)
    {
        /* s.setState((-1));
        if(s.getDirezione() == 0)
        {
            pair<int, int> pM = s.getPMedio();
        }
        marCor.erase(remove(marCor.begin(), marCor.end(), s));
        int d = s.getDirezione();
        pair<int, int> p = s.getPMedio();
        int x = p.first;
        int y = p.second;
        //mar_[x][y];
        if(d==0)
        {
            mar_[x][y+1];
            mar_[x][y+2];
            mar_[x][y-1];
            mar_[x][y-2];
        }
        else
        {
            mar_[x+1][y];
            mar_[x+2][y];
            mar_[x-1][y];
            mar_[x-2][y];
        }
    */
    }

    void Mare::NdsAff(Nds s)
    {
        /* s.setState((-1));
        if(s.getDirezione() == 0)
        {
            pair<int, int> pM = s.getPMedio();
        }
        marNds.erase(remove(marNds.begin(), marNds.end(), s));
        int d = s.getDirezione();
        pair<int, int> p = s.getPMedio();
        int x = p.first;
        int y = p.second;
        mar_[x][y];
        if(d==0)
        {
            mar_[x][y+1];
            mar_[x][y-1];
        }
        else
        {
            mar_[x+1][y];
            mar_[x-1][y];
        }
        */
    }

    void Mare::SdeAff(Sde s)
    {
        s.setState((-1));
        if(s.getDirezione() == 0)
        {
            pair<int, int> pM = s.getPMedio();
        }
        marSde.erase(remove(marSde.begin(), marSde.end(), s));
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
        write.open(logFile, ofstreaapp);
        string out;
        out += to_string(start.first) + to_string(start.second) + " ";
        out += to_string(end.first) + to_string(end.second) + "\n";
        write << out;
        write.close();
    }

    void Mare::updateLogVictory(int ending)
    {
        ofstream write;
        write.open(logFile, ofstreaapp);
        write << "END:" << ending;
        write.close();
    }

    void Mare::updateLogGameType(string type)
    {
        ofstream write;
        write.open(logFile, ofstreaapp);
        write << type << "\n";
        write.close();
    }
*/
/*____________________________________________________________________________________________________________________________________________________________*/

    string Mare::printAMare()
    {
        string out = "";
        out += "   ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐\n";
        for (int i = 11; i >= 0; i--)
        {
            out += to_string(i + 1);
            out += " │ ";
            for (int j = 0; j < 12; j++)
            {
                if (mar_[i][j] != ' ')
                    out += mar_[i][j];
                else
                    out += " ";
                out += " │ ";
            }
            out += "\n";
            if (i >= 1) out += "   ├───┼───┼───┼───┼───┼───┼───┼───┤\n";
        }
        out += "   └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘\n";
        out += "     A   B   C   D   E   F   G   H   I   J   K   L";
        return out;
    }

    string Mare::printEMare()
    {
        string out = "";
        out += "   ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐\n";
        for (int i = 11; i >= 0; i--)
        {
            out += to_string(i + 1);
            out += " │ ";
            for (int j = 0; j < 12; j++)
            {
                if (mar_[i][j] != ' ')
                    out += marES_[i][j];
                else
                    out += " ";
                out += " │ ";
            }
            out += "\n";
            if (i >= 1)
                out += "   ├───┼───┼───┼───┼───┼───┼───┼───┤\n";
        }
        out += "   └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘\n";
        out += "     A   B   C   D   E   F   G   H   I   J   K   L";
        return out;
    }

    int Mare::getMCondition()
    { return condition;}

    vector<pair<int, int> > Mare::posAvailable(Corazzata shi)
    {
        vector<pair<int, int> > v1 = shi.Moves();
        pair<int, int> p;
        int d = shi.getDirezione();
        if(d==0)
        {
            int x = 0, y = 1;
            while (x < 12)
            {
                while (y < 11)
                {
                    if (mar_[x][y] != ' ' || mar_[x][y+1] != ' ' || mar_[x][y-1] != ' ' || mar_[x][y+2] != ' ' || mar_[x][y-2] != ' ')
                        {v1.pop_back();}
                    else
                    {
                        p.first = x;
                        p.second = y;
                        v1.push_back(p);
                    }
                    y++;
                }
                x++;
            }
        }
        else
        {
            int x = 1, y = 0;
            while (x < 11)
            {
                while (y < 12)
                {
                    if (mar_[x][y] != ' ' || mar_[x+1][y] != ' ' || mar_[x-1][y] != ' ' || mar_[x+2][y] != ' ' || mar_[x-2][y] != ' ')
                    {v1.pop_back();}
                    else
                    {
                        p.first = x;
                        p.second = y;
                        v1.push_back(p);
                    }
                    y++;
                }
                x++;
            }
        }
        shi.Moves() = v1;
        return v1;
    }

    vector<pair<int, int> > Mare::posAvailable(Nds shi)
    {
        vector<pair<int, int> > v1 = shi.Moves();
        pair<int, int> p;
        int d = shi.getDirezione();
        if(d==0)
        {
            int x = 0, y = 1;
            while (x < 12)
            {
                while (y < 11)
                {
                    if (mar_[x][y] != ' ' || mar_[x][y+1] != ' ' || mar_[x][y-1] != ' ')
                        {v1.pop_back();}
                    else
                    {
                        p.first = x;
                        p.second = y;
                        v1.push_back(p);
                    }
                    y++;
                }
                x++;
            }
        }
        else
        {
            int x = 1, y = 0;
            while (x < 11)
            {
                while (y < 12)
                {
                    if (mar_[x][y] != ' ' || mar_[x+1][y] != ' ' || mar_[x-1][y] != ' ')
                    {v1.pop_back();}
                    else
                    {
                        p.first = x;
                        p.second = y;
                        v1.push_back(p);
                    }
                    y++;
                }
                x++;
            }
        }
        shi.Moves() = v1;
        return v1;
    }

    vector<pair<int, int> > Mare::posAvailable(Sde shi)
    {
        vector<pair<int, int> > v1 = shi.Moves();
        pair<int, int> p;
        int x=0, y=0;
        while (x <12)
        {
            while (y < 12)
            {
                if(mar_[x][y] != ' ')
                v1.pop_back();
                else
                p.first = x;
                p.second = y;
                v1.push_back(p);
                y++;
            }
            x++;
        }
        shi.Moves() = v1;
        return v1;
    }

    bool operator==(const Nds& n1, const Nds& n2)
    {
        return n1.getTipo() == n2.getTipo() && n1.getNumero() == n2.getNumero() && n1.getPMedio() == n2.getPMedio();
    }

