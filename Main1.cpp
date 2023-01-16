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

int main()
{
    const char B = 66;
    const char U = 85;
    printTextEffect("Benvenuto nella nostra versione della battaglia navale");
    printTextEffect("Che partita vuoi fare? Inserire:");
insertGame:
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
        goto insertGame;
        //da sistemare ______________________________________________________________________________________________
    }
    Mare boardP1;
    Mare boardP2;
    
    players.push_back(Players(boardP1, names[0], types[0]));
    players.push_back(Players(boardP2, names[1], types[1]));
    //__________________________________________________________________
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
            string start;
            string end;
            bool result;
        insertMove:
            printTextEffect("Inserisci le coordinate della nave a cui vuoi far fare un azione e le coordinate di dove avverra': ");
            cin >> start >> end;
            try
            {
                if(index == 0)
                {
                    result = p.Move(start, end, boardP1);
                }
                else
                {
                    result = p.Move(start, end, boardP2);
                }
            }
            catch (InvalidMoveException e)
            {
                printTextEffect("La mossa inserita non è valida.");
                //______________________________________________________________________________________
                goto insertMove;
            }
            catch (InvalidInputException e)
            {
                printTextEffect("L'input inserito non è valido");
                //_______________________________________________________________________________________
                goto insertMove;
            }
        }
        else
        {
        insertMove:
            try
            {
                if(index == 0)
                {
                    result = p.Move(boardP1, players[index].getName());
                }
                else
                {
                    result = p.Move(boardP2, players[index].getName());
                }
            }
            catch (InvalidMoveException e)
            {
                printTextEffect("La mossa inserita non è valida.");
                //______________________________________________________________________________________
                goto insertMove;
            }
            catch (InvalidInputException e)
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