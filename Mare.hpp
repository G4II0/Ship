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
#include "Corazzata.hpp"
#include "Nds.hpp"
#include "Sde.hpp"

using namespace std;

namespace M
{
    class Mare
    {
        private:

        /*matrice del mare alleato*/
        char mar_ [12][12];
        /*matrice del mare nemico*/
        char marE_ [12][12];
        /*stampa matrice del mare nemico*/
        char marES_ [12][12];
        /*matrice del mare (centri-Corazzate)*/
        S::Corazzata marCor[3];
        /*matrice del mare (centri-Supporto)*/
        S::Nds marNds[3];
        /*matrice del mare (centri-Esplorazione)*/
        S::Sde marSde[2];
        /*salva la condizione di giocatore attuale*/
        int condition;
        /*nome player*/
        string player1;
        /*nome del file su cui effettuare il log*/
        string logFile;
        /*numero di mosse effettuate*/
        int drawMoves;

    public:

        Mare::Mare();
        Mare(string log, char mar_ [12][12], string player1);

        void setMareA(pair<int, int> p, char c);
        void setMareE(pair<int, int> p, char c);
        void setMareES(pair<int, int> p, char c);
        vector<vector<char>> getMare();
        void getMareE(Mare& mN);

        //genera la board vuota
        void initializeMare(char (&mar_)[12][12]);
        void initializeMareES(char (&marES_)[12][12]);
        void initializeMare(S::Corazzata marCor_[3]);
        void initializeMare(S::Nds marNds_[3]);
        void initializeMare(S::Sde marSde_[2]);
        //inserisce la nave nella borad
        void insertCor(S::Corazzata& ship, pair<int, int> pos, M::Mare m);
        void insertNds(S::Nds& ship, pair<int, int> pos, M::Mare m);
        void insertSde(S::Sde& ship, pair<int, int> pos, M::Mare m);
        //controlla se le coordinate di arrivo dello spostamento sono nella board
        bool legitMoveInput(S::Corazzata ship, pair<int, int> pos, M::Mare m);
        bool legitMoveInput(S::Nds ship, pair<int, int> pos, M::Mare m);
        bool legitMoveInput(S::Sde ship, pair<int, int> pos, M::Mare m);
        //spostamento Generale
        void Move(pair<int, int> start, pair<int, int> dest, Mare m);
        //spostamento Corazzata
        void Move(pair<int, int> start, pair<int, int> dest, int direzione, S::Corazzata c, M::Mare m);
        //spostamento Nds
        void Move(pair<int, int> start, pair<int, int> dest, int direzione, S::Nds n, M::Mare m);
        //spostamento Sde
        void Move(pair<int, int> start, pair<int, int> dest, S::Sde s, M::Mare m);
        // s1 = Nds, s2 = Corazzata
        bool healConditions(S::Nds s1, S::Corazzata s2);
        // s1 = Nds, s2 = Nds
        bool healConditions(S::Nds s1, S::Nds s2);
        // assegna la cura
        void CorHeal(S::Corazzata& s);
        void NdsHeal(S::Nds& s);
        // scansione del sottomarino
        void SdeScan(S::Sde s);
        // assegna la x dell'hit
        void Mare::HitSet(pair<int, int> p, Mare mN);
        // assegna l'hit
        void CorHit(S::Corazzata s);
        void NdsHit(S::Nds s);
        void SdeHit(S::Sde s);
 
        // ritorna vettore con tutte le posizioni possibili per il pMedio della nave
        vector<pair<int, int>> posAvailable(S::Corazzata ship, Mare m);
        vector<pair<int, int>> posAvailable(S::Nds ship, Mare m);
        vector<pair<int, int>> posAvailable(S::Sde ship, Mare m);
        

        // aggiorna log con informazioni su vittoria
        // 0 se vittoria, 1 se stallo, 2 se patta per numero di mosse,
        // 3 se patta per raggiungimento limite mosse in partita tra bot
        int getMCondition();

        // stampa la griglia alleata
        string printAMare();
        // stampa la griglia nemica
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
    };
}

#endif