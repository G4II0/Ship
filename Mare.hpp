#ifndef MARE_HPP
#define MARE_HPP

#include <algorithm>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <random>
#include "Ship.hpp"
#include "Players.hpp"
#include "Nds.hpp"
#include "Sde.hpp"

using namespace std;

namespace M
{
    class Mare
    {
        private:

        //matrice del mare
        char mar_ [12][12];
        // matrice del mare (centri-oggetto)
        pair<int, int> marC_[12][12];
        // salva la condizione di giocatore attuale
        int condition = -1;

        //nome del file su cui effettuare il log
        string logFile;
        // mappa che salva le configurazioni apparse e il numero di apparizioni di ciascuna
        map<string, int> positions;
        // numero di mosse effettuate
        int drawMoves;

        /*
                //vettore contenente le posizioni disponibili della nave attuale
                vector<Move> nextShipMoves;
        */

    public:
        Mare(string log, string player1, string player2, vector<vector<pair<int, int>>> m);

        void setMare(pair<int, int> p, char c);

        //genera la board vuota
        void initializeMare(char mar_[12][12]);
        void initializeMareC(pair<int, int> mar_[8]);
        //inserisce la nave nella borad
        void insertCor(S::Corazzata ship, pair<int, int> pos, M::Mare m);
        void insertNds(S::Nds ship, pair<int, int> pos, M::Mare m);
        void insertSde(S::Sde ship, pair<int, int> pos, M::Mare m);
        //controlla se le coordinate di arrivo dello spostamento sono nella board
        bool legitMoveInput(S::Corazzata ship, pair<int, int> pos, M::Mare m);
        bool legitMoveInput(S::Nds ship, pair<int, int> pos, M::Mare m);
        bool legitMoveInput(S::Sde ship, pair<int, int> pos, M::Mare m);
        //spostamento Generale
        void Move(pair<int, int> start, pair<int, int> dest);
        //spostamento Corazzata
        void MoveCorazzata(pair<int, int> start, pair<int, int> dest, int direzione, S::Corazzata c, M::Mare m);
        //spostamento Nds
        void MoveNds(pair<int, int> start, pair<int, int> dest, int direzione, S::Nds n, M::Mare m);
        //spostamento Sde
        void MoveSde(pair<int, int> start, pair<int, int> dest, S::Sde s, M::Mare m);
        // s1 = Nds, s2 = Altra nave
        bool healConditions(S::Ship s1, S::Ship s2);
        // assegna la cura e aggiorna la board
        void shipHeal();
        // assegna l'hit e aggiorna la board
        void shipHit();

        // ritorna vettore con tutte le posizioni possibili per il pMedio della nave
        vector<pair<int, int>> posAvailable(S::Corazzata ship, Mare m);
        vector<pair<int, int>> posAvailable(S::Nds ship, Mare m);
        vector<pair<int, int>> posAvailable(S::Sde ship, Mare m);
        

        // aggiorna log con informazioni su vittoria
        // 0 se vittoria, 1 se stallo, 2 se patta per numero di mosse,
        // 3 se patta per raggiungimento limite mosse in partita tra bot
        int getMCondition();

        // stampa la griglia
        string printAMare();
        string printEMare();

        // aggiorna log con informazioni su vittoria
        // 0 se vittoria, 1 se stallo, 2 se patta per numero di mosse,
        // 3 se patta per raggiungimento limite mosse in partita tra bot
        void updateLogVictory(int ending);
        // aggiorna log con tipo di partita
        void updateLogGameType(string type);
        // aggiorna log con mossa
        void updateLogMove(pair<int, int> start, pair<int, int> finish);
        // eccezione: input non valido
        class InvalidInputException
        {
        };
        // eccezione: mossa non valida
        class InvalidMoveException
        {
        };
    };
}

#endif