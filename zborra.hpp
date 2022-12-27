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
        char mare [12][12];
        //ultima mossa effettuata
        Mare::Move lastMove;
        //nome del file su cui effettuare il log
        string logFile;
        //salva la condizione di giocatore attuale
        int condition = -1;
        //vettore contenente le posizioni disponibili della nave attuale
        vector<Mare::Move> nextShypMoves;
        //mappa che salva le configurazioni apparse e il numero di apparizioni di ciascuna
        map<string, int> positions;
        //numero di mosse effettuate
        int drawMoves;
        //numero di righe e colonne della scacchiera
        const int SIZE = 12;
        bool legitMoveInput(pair<int, int>& x);
        bool scanBoundaries(pair<int, int>& pos);
        bool scanBoundaries(int row, int column);
        ///se casella occupata, ritorna 1
        //altrimenti, ritorna 0
        char scanOccupied(pair<int, int>& pos);
        char scanOccupied(int row, int column);
        void initializeMare(int row);
        void insertShip(S::Ship* piece, pair<int, int>* pos);
        //s1 = Nds, s2 = Altra nave
        bool healConditions(S::Ship* p1, S::Ship* p2);
        //aggiorna log con mossa
        void updateLogMove(pair<int, int> start, pair<int, int> finish);
        //aggiorna log con hitMarker
        void updateLogHit();

        public:
        //nave, destinazione
        struct Move
        {
            //nave mossa
            S::Ship* ship;
            //posizione di arrivo
            pair<int, int> destination;
            Move(S::Ship* p, pair<int, int> dest);
            Move();
        };
        
        Mare(string log = "", string player1 = "", string player2 = "", vector<vector<pair<int, int>>> m);

        //ritorna vettore con tutte le posizioni possibili per il pMedio della nave
        vector<vector<pair<int, int>>> posAvailable(S::Nds ship, Mare m);
        //ritorna vettore con tutte le posizioni possibili per il pMedio della nave
        vector<vector<pair<int, int>>> posAvailable(S::Sde ship, Mare m);

        //metodo generale
        //ritorna true se è possibile la mossa
        bool performMove();
        //metodo per computer: mossa presa automaticamente da nextPlayerMoves
        //ritorna true se è possibile muovere
        bool performMove();
        //metodo per giocatore: fornire posizioni
        //ritorna true se è possibile muovere
        bool performMove(string name, pair<int, int> &destination, char type);

        // aggiorna log con informazioni su vittoria
        // 0 se vittoria, 1 se stallo, 2 se patta per numero di mosse,
        // 3 se patta per raggiungimento limite mosse in partita tra bot
        int getCondition();

        //ritorna la matrice del mar
        char getMar();

        //stampa la griglia
        string printMare();

        //aggiorna log con informazioni su vittoria
        //0 se vittoria, 1 se stallo, 2 se patta per numero di mosse,
        //3 se patta per raggiungimento limite mosse in partita tra bot
        void updateLogVictory(int ending);
        //aggiorna log con tipo di partita
        void updateLogGameType(string type);
        //eccezione: input non valido
        class InvalidInputException {};
        //eccezione: mossa non valida
        class InvalidMoveException {};

    }
}

#endif