#include "mare.hpp"

using namespace std;
namespace M
{
    Mare::Move::Move(S::Ship *p, pair<int, int> dest) : ship{p}, destination{dest} {}

    Mare::Move::Move() : ship{nullptr}, destination{pair(-1, -1)} {}

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

    void Mare::initializeMare(int row)
    {
    }

    void Mare::insertShip(S::Ship *ship, pair<int, int> *pos)
    {
        mare_[pos->first][pos->second] = ship;
        sList.push_back(ship);
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

    Mare::Mare(string log, string playerBlack, string playerWhite)
    {
        for (int i = 0; i < 8; i++)
            mare_.push_back(vector<S::Ship *>(8, nullptr));
        // inizializzare file
        initializeMare(0);
        initializeMare(1);
        initializeMare(7);
        initializeMare(6);
        lastMove = Move();
        logFile = log;
        if (log != "" && playerBlack != "" && playerWhite != "")
        {
            ofstream write(logFile);
            string playerRow = "B: " + playerWhite + " N: " + playerBlack + "\n";
            write << playerRow;
            write.close();
        }
    }

    string Mare::printMare()
    {
        string out = "";
        out += "  ---------------------------------\n";
        for (int i = 11; i >= 0; i--)
        {
            out += to_string(i + 1);
            out += " | ";
            for (int j = 0; j < 12; j++)
            {
                if (mare_[i][j] != nullptr)
                    out += mare_[i][j] -> getTipo();
                else
                    out += " ";
                out += " | ";
            }
            out += "\n";
            out += "  ---------------------------------\n";
        }
        out += "    A   B   C   D   E   F   G   H   I   J   K   L";
        return out;
    }



    int Mare::getCondition(char name)
    { return condition; }

    int Mare::getCondition(char name)
    {
    }

    vector<Mare::Move> Mare::posAvailable(char name)
    {
    }



    bool Mare::performMove()
    {
    }

    bool Mare::performMove(pair<int, int> &start, pair<int, int> &destination, char name)
    {
    }
}