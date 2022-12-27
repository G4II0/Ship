#include "Mare.hpp"
#include "Ship.hpp"

using namespace std;
namespace M
{
    //move
    Mare::Move::Move(S::Ship *p, pair<int, int> st, pair<int, int> dest) : ship{p}, start{st}, destination{dest} {}
    Mare::Move::Move() : ship{nullptr}, start{pair(-1, -1)}, destination{pair(-1, -1)} {}

    //operator
    bool operator==(const Mare::Move &m1, const Mare::Move &m2)
    {
        return (m1.ship == m2.ship && m1.destination == m2.destination);
    }

    bool Mare::legitMoveInput(pair<int, int> &x)
    {
        return (x.first >= 0 && x.first < 12 && x.second >= 0 && x.second < 12);
    }

    bool Mare::scanBoundaries(pair<int, int> &pos)
    {
        return (pos.first >= 0 && pos.first < SIZE && pos.second >= 0 && pos.second < SIZE);
    }

    bool Mare::scanBoundaries(int row, int column)
    {
        pair<int, int> tmp = pair(row, column);
        bool result = scanBoundaries(tmp);
        return result;
    }

    char Mare::scanOccupied(int row, int column)
    {
    }

    void Mare::initializeMare(char mar_[12][12])
    {int x=0, y=0;

        while (x < 12)
        {
            while (y < 12)
            {
                mar_[x][y] = '"\0"';
                    y++;
            }
            x++;
        }
    }

    void Mare::insertShip(S::Ship* ship, pair<int, int> *pos)
    {

    }

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

    void Mare::updateLogHit()
    {
    }

    bool healConditions(S::Ship *p1, S::Ship *p2)
    {}

    // sistemare

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
 
    string Mare::printMare()
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

    int Mare::getCondition()
    { return condition; }

    vector<pair<int, int>> Mare::posAvailable(S::Nds shi, M::Mare m)
    {
        vector<pair<int, int>> v1 = shi.Moves();
        pair<int, int> p;
        int d = shi.Direction(shi.getPrua(), shi.getPoppa());
        if(d=0)
        {
            int x = 0, y = 1;
            while (x < 12)
            {
                while (y < 11)
                {
                    if (mar_[x][y] != '\0' || mar_[x][y+1] != '\0' || mar_[x][y-1] != '\0')
                        v1.pop_back();
                    else
                        p.first = x;
                    p.second = y;
                    v1.push_back(p);
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
                    if (mar_[x][y] != '\0' || mar_[x+1][y + 1] != '\0' || mar_[x-1][y - 1] != '\0')
                        v1.pop_back();
                    else
                        p.first = x;
                    p.second = y;
                    v1.push_back(p);
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

    bool Mare::performMove()
    {
    }

    bool Mare::performMove(string name, pair<int, int> &destination, char type)
    {
    }
}