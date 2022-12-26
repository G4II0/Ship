#include "Players.hpp"

namespace P
{

    P::Players(Mare *mare, string N, char T)
    {
        Color = C;
        mare = B;
        Type = T;
    }

    // playe
    bool P::Move(string start, string end)
    {
        int sFirst = start[1] - 49;
        int sSecond = start[0] - 65;
        if (sSecond > 7)
            sSecond -= 32;
        int fFirst = end[1] - 49;
        int fSecond = end[0] - 65;
        if (fSecond > 7)
            fSecond -= 32;
        pair<int, int> s = pair<int, int>(sFirst, sSecond);
        pair<int, int> f = pair<int, int>(fFirst, fSecond);

        return mare->performMove(s, f);
    }

    int Players::GetCondition()
    {
        return mare->getCondition(Color);
    }

    void Players::PerformPromotion(char code)
    {
        char c = code;
        if (c > 90)
            c -= 32;
        mare->performPromotion(c);
    }

    // Bot
    bool Players::Move()
    {
        return mare->performMove();
    }

    char Players::PerformPromotion()
    {

        char P[4]{'A', 'T', 'C', 'D'};

        int r = rand() % 4;

        mare->performPromotion(P[r]);

        return P[r];
    }
}