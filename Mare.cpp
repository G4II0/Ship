#include "Mare.hpp"
#include "Ship.hpp"
#include "Corazzata.hpp"
#include "Nds.hpp"
#include "Sde.hpp"
#include "Exception.cpp"

using namespace std;
namespace M
{

    Mare::Mare(string log, char mar[12][12], string p1)
    {
        this -> mar_ [12][12] = mar[12][12];
        this -> condition = -1;
        this -> player1 = p1;
        this -> logFile = log;
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

    vector<vector<char>> Mare::getMare()
    {
        vector<vector<char>> v;
        vector<char> v1;

        for(int y=0; y<12; y++)
        {
            for(int x=0; x<12; x++)
            {
                v1.push_back(this -> mar_[x][y]);
            }
            v.push_back(v1);
        }
    }

    void Mare::getMareE(Mare& mN)
    {
        vector<vector<char>> v;
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

    bool Mare::legitMoveInput(S::Corazzata ship, pair<int, int> pos, M::Mare m)
    {
        vector<pair<int, int>> v = posAvailable(ship, m);
        if (find(v.begin(), v.end(), pos) != v.end())
        return true;
        else
        return false;
    }
        bool Mare::legitMoveInput(S::Nds ship, pair<int, int> pos, M::Mare m)
    {
        vector<pair<int, int>> v = posAvailable(ship, m);
        if (find(v.begin(), v.end(), pos) != v.end())
        return true;
        else
        return false;
    }
        bool Mare::legitMoveInput(S::Sde ship, pair<int, int> pos, M::Mare m)
    {
        vector<pair<int, int>> v = posAvailable(ship, m);
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

    void Mare::initializeMareCor(S::Corazzata marCor_[3])
    {
        int i = 0;

        while (i < 12)
        {
                marCor_[i] = S::Corazzata();
            i++;
        }
    }

        void Mare::initializeMareNds(S::Nds marNds_[3])
    {
        int i = 0;

        while (i < 12)
        {
                marNds_[i] = S::Nds();
            i++;
        }
    }
        void Mare::initializeMareSde(S::Sde marSde_[2])
    {
        int i = 0;

        while (i < 12)
        {
                marSde_[i] = S::Sde();
            i++;
        }
    }

//inserimento corazzata
    void Mare::insertCor(S::Corazzata& ship, pair<int, int> pos, M::Mare m)
    {
        if (legitMoveInput(ship, pos, m) == true)
        {
            pair<int, int> temp1;
            pair<int, int> temp2;
            pair<int, int> temp3;
            pair<int, int> temp4;
            pair<pair<int, int>, pair<int, int>> temp5;
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
            setMareA(pos, 'C');
            setMareA(temp1, 'C');
            setMareA(temp2, 'C');
            setMareA(temp3, 'C');
            setMareA(temp4, 'C');
            // posizionamento nel mareC
            marCor[ship.getNumero()] = ship;
        }
        throw InvalidMoveException();
    }

//inserimento Nds
    void Mare::insertNds(S::Nds& ship, pair<int, int> pos, M::Mare m)
    {
        if (legitMoveInput(ship, pos, m) == true)
        {
            pair<int, int> temp1;
            pair<int, int> temp2;
            pair<pair<int, int>, pair<int, int>> temp3;
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
            setMareA(pos, 'S');
            setMareA(temp1, 'S');
            setMareA(temp2, 'S');
            // posizionamento nel mareC
            marNds[ship.getNumero()] = ship;
        }
        throw InvalidMoveException();
    }

    // inserimento Sde
    void Mare::insertSde(S::Sde& ship, pair<int, int> pos, M::Mare m)
    {
        if (legitMoveInput(ship, pos, m) == true)
        {
            pair<int, int> temp1;
            pair<int, int> temp2;
            pair<pair<int, int>, pair<int, int>> temp3;
            temp1.first = pos.first;         // x prua
            temp1.second = (pos.second);     // y prua
            temp3.first = temp1;             // c prua
            temp3.second = temp1;            // c poppa
            ship.setPos(temp3);
            // posizionamento nella board
            setMareA(pos, 'E');
            // posizionamento nel mareC
            marSde[ship.getNumero()] = ship;
        }
        throw InvalidMoveException();
    }

    //move generico
    void Mare::Move(pair<int, int> start, pair<int, int> dest, Mare m)
    {
        if(mar_[start.first][start.second] == 'C')
        {S::Corazzata t = marCor[3];
            MoveCorazzata(start, dest, t.getDirezione(), t, m);
        }
        else
        if(mar_[start.first][start.second] == 'S')
        {S::Nds t = marNds[3];
            MoveNds(start, dest, t.getDirezione(), t, m);
        }
        else
                if(mar_[start.first][start.second] == 'C')
        {S::Sde t = marSde[2];
            MoveSde(start, dest, t, m);
        }
        throw InvalidMoveException();
    }

    //move Corazzata
    void Mare::MoveCorazzata(pair<int, int> start, pair<int, int> dest, int direzione, S::Corazzata s, Mare m)
    {
        if (legitMoveInput(s, dest, m) == true)
        {
            pair<int, int> temp1;
            pair<int, int> temp2;
            pair<int, int> temp3;
            pair<int, int> temp4;
            pair<pair<int, int>, pair<int, int>> temp5;
            if (s.getDirezione() == 0)
            {
                temp1.first = dest.first;         // x prua
                temp1.second = (dest.second) + 2; // y prua
                temp2.first = dest.first;         // x poppa
                temp2.second = (dest.second) - 2; // y poppa
                temp3.first = dest.first;
                temp3.second = (dest.second) + 1;
                temp4.first = dest.first;
                temp2.second = (dest.second) - 1;
                temp5.first = temp1;  // c prua
                temp5.second = temp2; // c poppa
                s.setPos(temp5);
            }
            else
            {
                temp1.first = (dest.first) + 2; // x prua
                temp1.second = dest.second;     // y prua
                temp2.first = (dest.first) - 2; // x poppa
                temp2.second = dest.second;     // y poppa
                temp3.first = (dest.first) + 1;
                temp3.second = dest.second;
                temp4.first = (dest.first) - 1;
                temp2.second = dest.second;
                temp5.first = temp1;  // c prua
                temp5.second = temp2; // c poppa
                s.setPos(temp5);
            }
            // posizionamento nel mare
            setMareA(dest, 'C');
            setMareA(temp1, 'C');
            setMareA(temp2, 'C');
            setMareA(temp3, 'C');
            setMareA(temp4, 'C');
        }
        throw InvalidMoveException();
    }

    //move Nds
    void Mare::MoveNds(pair<int, int> start, pair<int, int> dest, int direzione, S::Nds s, Mare m)
    {
        if (legitMoveInput(s, dest, m) == true)
        {
            pair<int, int> temp1;
            pair<int, int> temp2;
            pair<pair<int, int>, pair<int, int>> temp3;
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
        }
        throw InvalidMoveException();
    }

    //move Sde
    void Mare::MoveSde(pair<int, int> start, pair<int, int> dest, S::Sde s, Mare m)
    {
        if (legitMoveInput(s, dest, m) == true)
        {
            pair<int, int> temp1;
            pair<int, int> temp2;
            pair<pair<int, int>, pair<int, int>> temp3;
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
    bool healConditionsCor(S::Nds Nds, S::Corazzata Cor)
    {
        pair<int, int> cNds = Nds.getPMedio();
        int dNds = Nds.getDirezione();
        pair<int, int> cCor = Cor.getPMedio();
        int dCor = Cor.getDirezione();
        pair<int, int> tempN = {0, 0};
        pair<int, int> tempN1 = {0, 0};
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
        else
        //s = o, c = o;
        if(dNds == 1 || dCor == 1)
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
    }

    //controllare se hanno almeno 1 coppia di coordinate adiacenti lungo x o y
    bool healConditionsNds(S::Nds NdsC, S::Nds Nds)
    {
        pair<int, int> cNds = Nds.getPMedio();
        int dNds = Nds.getDirezione();
        pair<int, int> cNdsC = NdsC.getPMedio();
        int dNdsC = NdsC.getDirezione();
        pair<int, int> tempN = {0, 0};
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
    }

    void Mare::CorHeal(S::Corazzata& s)
    {int c = 5; s.setCorazza(c);}

    void Mare::NdsHeal(S::Nds& s)
    {int c = 3; s.setCorazza(c);}

    void Mare::SdeScan(S::Sde s)
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

    void Mare::HitSet(pair<int, int> p, Mare mN)
    {
        getMareE(mN);
        int x = p.first;
        int y = p.second;
        if(marE_[x][y] != ' ')
        {
            setMareES(p, 'X');
        }
    }

    void Mare::CorHit(S::Corazzata s)
    {int c = s.getCorazza() - 1; s.setCorazza(c);}

    void Mare::NdsHit(S::Nds s)
    {int c = s.getCorazza() - 1; s.setCorazza(c);}

    void Mare::SdeHit(S::Sde s)
    {int c = s.getCorazza() - 1; s.setCorazza(c);}

//_______________________________________________________________________________________________________________________________________________

    //fixare
    void Mare::updateLogMove(pair<int, int> start, pair<int, int> end)
    {
        ofstream write;
        write.open(logFile, ofstream::app);
        string out;
        out += to_string(start.first) + to_string(start.second) + " ";
        out += to_string(end.first) + to_string(end.second) + "\n";
        write << out;
        write.close();
    }

    void Mare::updateLogVictory(int ending)
    {
        ofstream write;
        write.open(logFile, ofstream::app);
        write << "END:" << ending;
        write.close();
    }

    void Mare::updateLogGameType(string type)
    {
        ofstream write;
        write.open(logFile, ofstream::app);
        write << type << "\n";
        write.close();
    }
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
                if (mar_[i][j] != '\0')
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
                if (mar_[i][j] != '\0')
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

    vector<pair<int, int>> Mare::posAvailable(S::Corazzata shi, M::Mare m)
    {
        vector<pair<int, int>> v1 = shi.Moves();
        pair<int, int> p;
        int d = shi.getDirezione();
        if(d=0)
        {
            int x = 0, y = 1;
            while (x < 12)
            {
                while (y < 11)
                {
                    if (mar_[x][y] != '\0' || mar_[x][y+1] != '\0' || mar_[x][y-1] != '\0' || mar_[x][y+2] != '\0' || mar_[x][y-2] != '\0')
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
                    if (mar_[x][y] != '\0' || mar_[x+1][y] != '\0' || mar_[x-1][y] != '\0' || mar_[x+2][y] != '\0' || mar_[x-2][y] != '\0')
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

    vector<pair<int, int>> Mare::posAvailable(S::Nds shi, M::Mare m)
    {
        vector<pair<int, int>> v1 = shi.Moves();
        pair<int, int> p;
        int d = shi.getDirezione();
        if(d=0)
        {
            int x = 0, y = 1;
            while (x < 12)
            {
                while (y < 11)
                {
                    if (mar_[x][y] != '\0' || mar_[x][y+1] != '\0' || mar_[x][y-1] != '\0')
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
                    if (mar_[x][y] != '\0' || mar_[x+1][y] != '\0' || mar_[x-1][y] != '\0')
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

    vector<pair<int, int>> Mare::posAvailable(S::Sde shi, M::Mare m)
    {
        vector<pair<int, int>> v1 = shi.Moves();
        pair<int, int> p;
        int x=0, y=0;
        while (x <12)
        {
            while (y < 12)
            {
                if(mar_[x][y] != '\0')
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
}
