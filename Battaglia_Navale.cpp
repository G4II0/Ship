#include "Ship.hpp"
#include "Players.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

//produce un ritardo nella stampa per creare un effetto grafico
using namespace std;
void printTextEffect(string s, int delayShort = 1, int delayLong = 250)
{
    for (int i = 0; i < s.size(); i++)
    {
        this_thread::sleep_for(chrono::milliseconds(delayShort));
        cout << s[i];
    }
    this_thread::sleep_for(chrono::milliseconds(delayLong));
    cout << endl;
}

// restituisce erroneamente sempre 0 (per cui rimosso prima della sua sistemazione)
/*
int convertI(char l)
{
    if(l == 'A' || 'a')
    {return 0;}
    else
    if (l == 'B' || 'b')
    {return 1;}
    else
    if (l == 'C' || 'c')
    {return 2;}
    else
    if (l == 'D' || 'd')
    {return 3;}
    else
    if (l == 'E' || 'e')
    {return 4;}
    else
    if (l == 'F' || 'f')
    {return 5;}
    else
    if (l == 'G' || 'g')
    {return 6;}
    else
    if (l == 'H' || 'h')
    {return 7;}
    else
    if (l == 'I' || 'i')
    {return 8;}
    else
    if (l == 'L' || 'l')
    {return 9;}
    else
    if (l == 'M' || 'n')
    {return 10;}
    else
    if (l == 'N' || 'm')
    {return 11;}
}
*/
int main()
{
    //char equivalente al player umano
    const char B = 66;
    // char equivalente al player umano
    const char U = 85;

    string game;
    vector<string> names(2);
    // vettore di tipi d players ( bot o umano)
    vector<char> types;
    // vettore di players
    vector<Players> players;
    // vettore nomi possibili del bot
    std::vector<std::string> botNames = {"Giorgio", "Michele", "Claudio", "Piripillo", "Roberto", "Assenzio", "Barabba", "Adolfo", "Rolando", "Maurizio"};
    printTextEffect("Benvenuto nella nostra versione della battaglia navale");
    printTextEffect("Che partita vuoi fare? Inserire:");
    while(true)
    {
        printTextEffect("- pc: partita player vs. computer");
        printTextEffect("- cc: partita computer vs. computer");
        cin >> game;
        if (game == "pc") 
        {
            printTextEffect("Inserisci il nome del giocatore umano: ");
            cin >> names[0];
            names[1] = botNames[rand() % 10];
            printTextEffect("Il bot si chiama " + names[1]);
            types.push_back(U);
            types.push_back(B);
            break;
        }
        else if (game == "cc") 
        {
            names[0] = botNames[rand() % 10];
            names[1] = botNames[rand() % 10];
            printTextEffect("Il bot1 si chiama " + names[0] + ".");
            printTextEffect("Il bot2 si chiama " + names[1] + ".");
            types.push_back(B);
            types.push_back(B);
            break;
        } 
        else 
        {
            printTextEffect("Input non valido, riprovare; si pu?? inserire solo:");
        }
    }

    Mare boardP1;
    Mare boardP2;
    players.push_back(Players(boardP1, names[0], types[0], boardP2));
    players.push_back(Players(boardP2, names[1], types[1], boardP1));

    pair<int, int> p;
    //rimosso in quanto la conversione non funzionava prima della consegna
    //char x0;
    int x;
    int x2;
    int x1;
    int y;
    int d;

    int ind = 0;
    while (ind < 2)
    {
        if(game == "pc")
        {
            printTextEffect("E' il momento per "+ names[0] + " di posizionare le sue navi: " + "\n");
            printTextEffect("Inserisci le navi nella griglia: ");
        }
        //richiede al player o al bot di inserire la corazzata, continua finch?? tutte le corazzate sono inserite
        //Corazzata
        int i = 0;
        while(i < 3) 
        {
            try
            {
                if(players[ind].getType() == U)
                {
                    printTextEffect("Inserisci la direzione della Corazzata C" + to_string((i+1)) + ": 0 = verticale, 1 = orizzontale ");
                    cin>>d;
                    printTextEffect("Inserisci le coordinate in cui vuoi mettere il punto medio della Corazzata C" + to_string((i+1)));
                    //cin >> x0 >> y;
                    cin >> x2 >> y;
                    //x1 = convertI(x0);
                    p.first = y -1;
                    //p.second = x1;
                    p.second = x2 -1;

                    if(i==0)
                    {
                        Corazzata c1 = Corazzata(p, d, i);
                        c1.setNumero(i);
                        players[ind].getMare().insertCor(c1, p);
                    }
                    else
                    if(i==1)
                    {
                        Corazzata c2 = Corazzata(p, d, i);
                        c2.setNumero(i);
                        players[ind].getMare().insertCor(c2, p);
                    }
                    else
                    if(i==2)
                    {
                        Corazzata c3 = Corazzata(p, d, i);
                        c3.setNumero(i);
                        players[ind].getMare().insertCor(c3, p);
                    }
                }
                else
                if (players[ind].getType() != U && ind == 0)
                {
                    d = rand()%2;
                    if(d==0)
                    {
                        x = rand()%12;
                        y = rand()%8+2;
                    }
                    else
                    {
                        x = rand()%8+2;
                        y = rand()%12;
                    }
                    if (i == 0)
                    {
                        Corazzata c1 = Corazzata(p, d, i);
                        c1.setNumero(i);
                        players[ind].getMare().insertCor(c1, p);
                    }
                    else if (i == 1)
                    {
                        Corazzata c2 = Corazzata(p, d, i);
                        c2.setNumero(i);
                        players[ind].getMare().insertCor(c2, p);
                    }
                    else if (i == 2)
                    {
                        Corazzata c3 = Corazzata(p, d, i);
                        c3.setNumero(i);
                        players[ind].getMare().insertCor(c3, p);
                    }
                }
                if (players[ind].getType() != U && ind == 1)
                {
                    d = rand() % 2;
                    if (d == 0)
                    {
                        x = rand() % 12;
                        y = rand() % 8 + 2;
                    }
                    else
                    {
                        x = rand() % 8 + 2;
                        y = rand() % 12;
                    }
                    if (i == 0)
                    {
                        Corazzata c4 = Corazzata(p, d, i);
                        c4.setNumero(i);
                        players[ind].getMare().insertCor(c4, p);
                    }
                    else if (i == 1)
                    {
                        Corazzata c5 = Corazzata(p, d, i);
                        c5.setNumero(i);
                        players[ind].getMare().insertCor(c5, p);
                    }
                    else if (i == 2)
                    {
                        Corazzata c6 = Corazzata(p, d, i);
                        c6.setNumero(i);
                        players[ind].getMare().insertCor(c6, p);
                    }
                }
                i++;
            }
            catch(const InvalidInputException &e)
            {
                printTextEffect(e.what());
            }
        }
        
        //richiede al player o al bot di inserire le Nds, continua finch?? tutte le Nds sono inserite
        //Nds
        i = 0;
        while(i < 3)
        {
            try
            {
                if(players[ind].getType() == U)
                {
                    printTextEffect("Inserisci la direzione della Nds: " + to_string((i+1)) + " 0 = verticale, 1 = orizzontale");
                    cin>>d;
                    printTextEffect("Inserisci le coordinate in cui vuoi mettere il punto medio della Nave da Supporto Nds" + to_string((i+1)));
                    // cin >> x0 >> y;
                    cin >> x2 >> y;
                    // x1 = convertI(x0);
                    p.first = y - 1;
                    // p.second = x1;
                    p.second = x2 - 1;

                    if(i==0)
                    {
                        Nds s1 = Nds(p, d, i);
                        s1.setNumero(i);
                        players[ind].getMare().insertNds(s1, p);
                    }
                    else          
                    if(i==1)
                    {
                        Nds s2 = Nds(p, d, i);
                        s2.setNumero(i);
                        players[ind].getMare().insertNds(s2, p);
                    }
                    else
                    if(i==2)
                    {
                        Nds s3 = Nds(p, d, i);
                        s3.setNumero(i);
                        players[ind].getMare().insertNds(s3, p);
                    }
                }
                else
                if (players[ind].getType() != U && ind == 0)
                {
                    d = rand()%2;
                    if(d==0)
                    {
                        x = rand()%12;
                        y = rand()%10+1;
                    }
                    else
                    {
                        x = rand()%10+1;
                        y = rand()%12;
                    }
                    if(i==0)
                    {
                        Nds s1 = Nds(p, d, i);
                        s1.setNumero(i);
                        players[ind].getMare().insertNds(s1, p);
                    }
                    else          
                    if(i==1)
                    {
                        Nds s2 = Nds(p, d, i);
                        s2.setNumero(i);
                        players[ind].getMare().insertNds(s2, p);
                    }
                    else
                    if(i==2)
                    {
                        Nds s3 = Nds(p, d, i);
                        s3.setNumero(i);
                        players[ind].getMare().insertNds(s3, p);
                    }
                }
                else if (players[ind].getType() != U && ind == 1)
                {
                    d = rand() % 2;
                    if (d == 0)
                    {
                        x = rand() % 12;
                        y = rand() % 10 + 1;
                    }
                    else
                    {
                        x = rand() % 10 + 1;
                        y = rand() % 12;
                    }
                    if (i == 0)
                    {
                        Nds s4 = Nds(p, d, i);
                        s4.setNumero(i);
                        players[ind].getMare().insertNds(s4, p);
                    }
                    else if (i == 1)
                    {
                        Nds s5 = Nds(p, d, i);
                        s5.setNumero(i);
                        players[ind].getMare().insertNds(s5, p);
                    }
                    else if (i == 2)
                    {
                        Nds s6 = Nds(p, d, i);
                        s6.setNumero(i);
                        players[ind].getMare().insertNds(s6, p);
                    }
                }
                i++;
            }
            catch(const InvalidInputException &e)
            {
                printTextEffect(e.what());
            }
        }
        //richiede al player o al bot di inserire i Sde, continua finch?? tutti i Sde sono inseriti
        //Sde
        i = 0;
        while(i < 2)
        {
            try
            {
                if(players[ind].getType() == U)
                {
                    printTextEffect("Inserisci le coordinate in cui vuoi mettere il punto medio del Sottomarino da Esplorazione Sde" + to_string((i+1)));
                    // cin >> x0 >> y;
                    cin >> x2 >> y;
                    // x1 = convertI(x0);
                    p.first = y - 1;
                    // p.second = x1;
                    p.second = x2 -1;

                    //non ?? necessario richiedere la direzione dell'sde poich?? la sua dimensione ?? = 1
                    if(i==0)
                    {
                        Sde e1 = Sde(p, i);
                        e1.setNumero(i);
                        players[ind].getMare().insertSde(e1, p);
                    }
                    else          
                    if(i==1)
                    {
                        Sde e2 = Sde(p, i);
                        e2.setNumero(i);
                        players[ind].getMare().insertSde(e2, p);
                    }
                }
                else
                if (players[ind].getType() == U && ind == 0)
                {
                    x = rand()%12;
                    y = rand()%12;
                    p.first = x;
                    p.second = y;
                    if(i==0)
                    {
                        Sde e1 = Sde(p, i);
                        e1.setNumero(i);
                        players[ind].getMare().insertSde(e1, p);
                    }
                    else
                    if(i==1)
                    {
                        Sde e2 = Sde(p, i);
                        e2.setNumero(i);
                        players[ind].getMare().insertSde(e2, p);
                    }
                }
                else if (players[ind].getType() == U && ind == 1)
                {
                    x = rand() % 12;
                    y = rand() % 12;
                    p.first = x;
                    p.second = y;
                    if (i == 0)
                    {
                        Sde e3 = Sde(p, i);
                        e3.setNumero(i);
                        players[ind].getMare().insertSde(e3, p);
                    }
                    else if (i == 1)
                    {
                        Sde e4 = Sde(p, i);
                        e4.setNumero(i);
                        players[ind].getMare().insertSde(e4, p);
                    }
                }
                i++;
            }
            catch(const InvalidInputException &e)
            {
                printTextEffect(e.what());
            }
        }
        ind++;
    }
    int i = 0;
    int index = 1;
    int movesLimit;

    if (game == "cc")
        movesLimit = 50;
    else
        movesLimit = -1;
    bool endgame = false;
    //inizio del gioco
    while (i != movesLimit && !endgame)
    {
        if(index == 0)
        {index = 1;}
        else{index = 0;}
        string message = "Turno di " + names[index];
        int cond = players[index].getCondition();
        switch (cond)
        {
        case 0:
            message = names[index] + " tutte le navi di " + names[index] + " sono state affondate" + "\n";
            if (index == 0)
                message += names[1];
            else
                message += names[0];
            message += " vince!";
            printTextEffect(message);
            endgame = true;
            continue;
        case 1:
            printTextEffect("La partita termina in patta! Sono state eseguite 50 mosse:");
            endgame = true;
            continue;
        }
        printTextEffect(message);
        Players p = players[index];
        if (types[index] == 'U')
        {
            printTextEffect("Se vuoi stampare le griglie, inserire 'XX XX': ");
            string code;
            cin >> code;
            if (code == "XX XX")
            {
                cout << boardP1.printAMare();
                cout << boardP2.printEMare();
            }
            pair<int, int> start;
            pair<int, int> end;
            int xs;
            int ys;
            int xe;
            int ye;
            int a = 0;
            while(a < 1)//------------------------------------------------------------------------------------------------------------------------------
            {
                printTextEffect("Inserisci le coordinate della nave a cui vuoi far fare un azione e le coordinate di dove avverra': ");
                cin >> xs;
                cin >> ys;
                start. first = xs;
                start.second = ys;
                cin >> xs;
                cin >> ys;
                end. first = xe;
                end.second = ye;
                try
                {
                    if(index == 0)
                    {
                        p.Moves(start, end, boardP1, boardP2);
                    }
                    else
                    {
                        p.Moves(start, end, boardP2, boardP1);
                    }
                    a++;
                }
                catch (InvalidMoveException &e)
                {
                    printTextEffect(e.what());
                }
                catch (const InvalidInputException &e)
                {
                    printTextEffect(e.what());
                }
            }
        }
        else
        {
            int b = 0;
            while(b < 1)
            {
                try
                {
                    if(index == 0)
                    {
                        p.MovesB(boardP1, players[index].getMareN());
                    }
                    else
                    {
                        p.MovesB(boardP2, players[index].getMareN());
                    }
                    b++;
                }
                catch (InvalidMoveException &e)
                {
                    printTextEffect(e.what());
                }
                catch (InvalidInputException &e)
                {
                    printTextEffect(e.what());
                }
            }
        }
        i++;
    }
    if (game == "cc" && i == movesLimit) 
    {
        printTextEffect("La partita termina in patta! ?? stata effettuata la 50esima mossa totale!");
    }
    printTextEffect("Grazie per aver giocato!");
}
