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
#include "Corazzata.hpp"
#include "Nds.hpp"
#include "Sde.hpp"


using namespace std;


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
        vector<Corazzata> marCor;
        /*matrice del mare (centri-Supporto)*/
        vector<Nds> marNds;
        /*matrice del mare (centri-Esplorazione)*/
        vector<Sde> marSde;
        /*salva la condizione di giocatore attuale*/
        int condition;
        /*nome player*/
        string player1;
        /*nome del file su cui effettuare il log*/
        string logFile;
        /*numero di mosse effettuate*/
        int drawMoves;

    public:

        Mare();

        void setMareA(pair<int, int> p, char c);
        void setMareE(pair<int, int> p, char c);
        void setMareES(pair<int, int> p, char c);
        vector<vector<char> > getMare();
        void getMareE(Mare& mN);

        vector<Corazzata> getMarCor();
        vector<Nds> getMarNds();
        vector<Sde> getMarSde();

        Corazzata whichCor(vector<Corazzata> marCor, pair<int, int> pos);
        Nds whichNds(vector<Nds> marNds, pair<int, int> pos);
        Sde whichSde(vector<Sde> marSde, pair<int, int> pos);

        //genera la board vuota
        void initializeMare(char (&mar_)[12][12]);
        void initializeMareES(char (&marES_)[12][12]);
        void initializeMare(vector<Corazzata> marCor);
        void initializeMare(vector<Nds> marNds);
        void initializeMare(vector<Sde> marSde);
        //inserisce la nave nella borad
        void insertCor(Corazzata& ship, pair<int, int> pos, Mare m);
        void insertNds(Nds& ship, pair<int, int> pos, Mare m);
        void insertSde(Sde& ship, pair<int, int> pos, Mare m);
        //controlla se le coordinate di arrivo dello spostamento sono nella board
        bool legitMoveInput(Corazzata ship, pair<int, int> pos, Mare m);
        bool legitMoveInput(Nds ship, pair<int, int> pos, Mare m);
        bool legitMoveInput(Sde ship, pair<int, int> pos, Mare m);
        //spostamento Generale
        void Move(pair<int, int> start, pair<int, int> dest, Mare m, Mare mN);
        //spostamento Corazzata
        void Move(pair<int, int> start, pair<int, int> dest, Corazzata c, Mare m);
        //spostamento Nds
        void Move(pair<int, int> start, pair<int, int> dest, int direzione, Nds n, Mare m);
        //spostamento Sde
        void Move(pair<int, int> start, pair<int, int> dest, Sde s, Mare m);
        // s1 = Nds, s2 = Corazzata
        void healConditions(Nds s1);
        // assegna la cura
        void CorHeal(Corazzata& s);
        void NdsHeal(Nds& s);
        // scansione del sottomarino
        void SdeScan(Sde s);
        // assegna la x dell'hit
        void HitSet(pair<int, int> p, Mare mN);
        // assegna l'hit
        void CorHit(Corazzata s);
        void NdsHit(Nds s);
        void SdeHit(Sde s);

        // affonda la nave
        void CorAff(Corazzata s);
        void NdsAff(Nds s);
        void SdeAff(Sde s);
 
        // ritorna vettore con tutte le posizioni possibili per il pMedio della nave
        vector<pair<int, int> > posAvailable(Corazzata ship);
        vector<pair<int, int> > posAvailable(Nds ship);
        vector<pair<int, int> > posAvailable(Sde ship);
        

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
};

bool operator==(const Nds& c1, const Nds& c2);

#endif