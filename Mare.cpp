#include "Mare.hpp"
#include "Ship.hpp"
#include "Corazzata.hpp"
#include "Nds.hpp"
#include "Sde.hpp"

using namespace std;
namespace M
{

    void Mare::setMare(pair<int, int> p, char c)
    {
        int x = p.first;
        int y = p.second;
        this -> mar_[x][y] = c;
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

    void Mare::initializeMare(char mar_[12][12])
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
    void Mare::insertCor(S::Corazzata ship, pair<int, int> pos, M::Mare m)
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
            setMare(pos, 'C');
            setMare(temp1, 'C');
            setMare(temp2, 'C');
            setMare(temp3, 'C');
            setMare(temp4, 'C');
            // posizionamento nel mareC
            marCor[ship.getNumero()] = ship;
        }
        // else
        // error;
    }

//inserimento Nds
    void Mare::insertNds(S::Nds ship, pair<int, int> pos, M::Mare m)
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
            setMare(pos, 'S');
            setMare(temp1, 'S');
            setMare(temp2, 'S');
            // posizionamento nel mareC
            marNds[ship.getNumero()] = ship;
        }
        // else
        // error;
    }

    // inserimento Sde
    void Mare::insertSde(S::Sde ship, pair<int, int> pos, M::Mare m)
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
            setMare(pos, 'E');
            // posizionamento nel mareC
            marSde[ship.getNumero()] = ship;
        }
        // else
        // error;
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
        //errore
        
    }

    //move generico
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
            setMare(dest, 'C');
            setMare(temp1, 'C');
            setMare(temp2, 'C');
            setMare(temp3, 'C');
            setMare(temp4, 'C');
        }
        // else
        // error;
    }

    //move generico
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
            setMare(dest, 'S');
            setMare(temp1, 'S');
            setMare(temp2, 'S');
        }
        // else
        // error;
    }

    //move generico
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
            setMare(dest, 'E');
        }
    }

    void Mare::shipHit()
    {
    }

    void Mare::shipHit()
    {
    }

//_______________________________________________________________________________________________________________________________________________

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

//________________________________________________________________________________________________________________________________________________________

    bool healConditions(S::Ship *p1, S::Ship *p2)
    {}

    // sistemare
/*
    Mare::Mare(string log, string player1, string player2, vector<vector<pair<int, int>>> m)
    {
        lastMove = Move();
        nextShipMoves.push_back(Move());
        logFile = log;
        drawMoves = 0;
        if (log != "" && player1!= "" && player2 != "")
        {
            ofstream write(logFile);
            string playerRow = "P1: " + player1 + "\nP2: " + player2 + "\n\n";
            write << playerRow;
            write.close();
        }
    }
*/

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

//sistemare !!!!!!!!!!!!!!
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
                    out += mar_[i][j];
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
