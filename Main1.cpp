#include "Ship.hpp"
#include "Players.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

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

pair<int,int> stringToPair(string input)
{
    pair<int,int> output;
    int X = std::stoi(input.substr(0, 2));
    int Y = std::stoi(input.substr(3, 2));
    output.first = X;
    output.second = Y;
    return output;
}

int main()
{
    const char B = 66;
    const char U = 85;
    printTextEffect("Benvenuto nella nostra versione della battaglia navale");
    printTextEffect("Che partita vuoi fare? Inserire:");
insertGame://------------------------------------------------------------------------------------------------ Ins Game
    printTextEffect("- pc: partita player vs. computer");
    printTextEffect("- cc: partita computer vs. computer");
    string game;
    cin >> game;
    vector<string> names(2);
    vector<char> types;
    vector<Players> players;
    std::vector<std::string> botNames = {"Giorgio", "Michele", "Claudio", "Piripillo", "Roberto", "Assenzio", "Barabba", "Adolfo", "Rolando", "Maurizio"};
    if (game == "pc")
    {
        printTextEffect("Inserisci il nome del giocatore umano: ");
        cin >> names[0];
        names[1] = botNames[rand() % 10];
        printTextEffect("Il bot si chiama " + names[1]);
        types.push_back(U);
        types.push_back(B);
    }
    else if (game == "cc")
    {
        names[0] = names[rand() % 10];
        names[1] = names[rand() % 10];
        printTextEffect("Il bot1 si chiama " + names[0] + ".");
        printTextEffect("Il bot2 si chiama " + names[1] + ".");
        types.push_back(B);
        types.push_back(B);
    }
    else
    {
        printTextEffect("Input non valido, riprovare; si può inserire solo:");
        goto insertGame;//-------------------------------------------------------------------------------- InsGame
    }
    int ind = 0;
    Mare boardP1;
    Mare boardP2;
    
inizializeGrill:
    if(game == "pc" && ind <2)
    {
        printTextEffect("E' il momento che "+ names[0] + "posizioni le sue navi");
    }
    printTextEffect("Inserisci le navi nella griglia: ");
    for(int i = 0; i<3; i++)
    {
        printTextEffect("Inserisci le coordinate in cui vuoi mettere il punto medio della corazzata n" + to_string((i+1)));
        pair<int, int> p;
        int x;
        int y;
        cin>>x>>y;
        p.first = x;
        p.second = y;
        printTextEffect("Inserisci la direzione della corazzata n" + to_string((i+1)));
        int d;
        cin>>d;
        if(i==0)
        {
            Corazzata c1 = Corazzata(p, d, i);
            boardP1.insertCor(c1, p);
        }
        else          
        if(i==1)
        {
           Corazzata c2 = Corazzata(p, d, i);
           boardP1.insertCor(c2, p);
        }
        else
        if(i==2)
        {
            Corazzata c3 = Corazzata(p, d, i);
            boardP1.insertCor(c3, p);
        }
    }
    for(int i = 0; i<3; i++)
    {
        printTextEffect("Inserisci le coordinate in cui vuoi mettere il punto medio della nave da supporto (Nds) n" + to_string((i+1)));
        pair<int, int> p;
        int x;
        int y;
        cin>>x;
        cin>>y;
        p.first = x;
        p.second = y;
        printTextEffect("Inserisci la direzione della Nds n" + to_string((i+1)));
        int d;
        cin>>d;
        if(i==0)
        {
            Nds n1 = Nds(p, d, i);
            boardP1.insertNds(n1, p);
        }
        else
        if(i==1)
        {
            Nds n2 = Nds(p, d, i);
            boardP1.insertNds(n2, p);
        }
        else
        if(i==2)
        {
            Nds n3 = Nds(p, d, i);
            boardP1.insertNds(n3, p);
        }
    }
    for(int i = 0; i<2; i++)
    {
        printTextEffect("Inserisci le coordinate in cui vuoi mettere il punto medio del sottomarino da esplorazione (Sde) n" + to_string((i+1)));
        pair<int, int> p;
        int x;
        int y;
        cin>>x;
        cin>>y;
        p.first = x;
        p.second = y;
        printTextEffect("Inserisci la direzione della Sde n" + to_string((i+1)));
        int d;
        cin>>d;
        if(i==0)
        {
            Sde n1 = Sde(p, d, i);
            boardP1.insertSde(n1, p);
        }
        else
        if(i==1)
        {
            Sde n2 = Sde(p, d, i);
            boardP1.insertSde(n2, p);
        }
    }
    if(ind==0)
    {
        ind = 1;
        goto inizializeGrill;//-------------------------------------------------------------------------------------
    }

    players.push_back(Players(boardP1, names[0], types[0]));
    players.push_back(Players(boardP2, names[1], types[1]));

    int i = 0;
    int index = 1;
    int movesLimit;

    if (game == "cc")
        movesLimit = 50;
    else
        movesLimit = -1;
    bool endgame = false;
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
            }//__________________________________________________________________________________________________________
            pair<int, int> start;
            pair<int, int> end;
            int xs;
            int ys;
            int xe;
            int ye;
        insertMove1://------------------------------------------------------------------------------------------------------------------------------
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
            }
            catch (InvalidMoveException &e)
            {
                printTextEffect("La mossa inserita non è valida.");
                //______________________________________________________________________________________
                goto insertMove1;
            }
            catch (const InvalidInputException &e)
            {
                printTextEffect("L'input inserito non è valido");
                //_______________________________________________________________________________________
                goto insertMove1;
            }
        }
        else
        {
        insertMove:
            try
            {
                if(index == 0)
                {
                    p.MovesB(boardP1, players[index]);
                }
                else
                {
                    p.MovesB(boardP2, players[index]);
                }
            }
            catch (InvalidMoveException &e)
            {
                printTextEffect("La mossa inserita non è valida.");
                //______________________________________________________________________________________
                goto insertMove;
            }
            catch (InvalidInputException &e)
            {
                printTextEffect("L'input inserito non è valido");
                //_______________________________________________________________________________________
                goto insertMove;
            }
        }
        i++;
    }
    if (game == "cc" && i == movesLimit)
        printTextEffect("La partita termina in patta! È stata effettuata la 50esima mossa totale!");
    printTextEffect("Grazie per aver giocato!");
}

/*string game;
while (true) {
    printTextEffect("Che partita vuoi fare? Inserire:");
    printTextEffect("- pc: partita player vs. computer");
    printTextEffect("- cc: partita computer vs. computer");
    cin >> game;
    if (game == "pc" || game == "cc") {
        break;
    }
    printTextEffect("Input non valido, riprovare; si può inserire solo:");
}*/