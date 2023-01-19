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
    string game;
    vector<string> names(2);
    vector<char> types;
    vector<Players> players;
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
            printTextEffect("Input non valido, riprovare; si può inserire solo:");
        }
    }

    Mare boardP1;
    Mare boardP2;
    players.push_back(Players(boardP1, names[0], types[0], boardP2));
    players.push_back(Players(boardP2, names[1], types[1], boardP1));

    int ind = 0;
    while (ind < 2)
    {
        if(game == "pc")
        {
            printTextEffect("E' il momento per "+ names[0] + " di posizionare le sue navi: " + "\n");
            printTextEffect("Inserisci le navi nella griglia: ");
        }
        //richiede al player o al bot di inserire la corazzata, continua finchè tutte le corazzate sono inserite
        //Corazzata
        int i = 0;
        while(i < 3) 
        {
            pair<int, int> p;
            int x;
            int y;
            int d;
            try
            {                           
                if(players[ind].getType() == U)
                {
                    printTextEffect("Inserisci la direzione della Corazzata C" + to_string((i+1)) + ": 0 = verticale, 1 = orizzontale ");
                    cin>>d;
                    printTextEffect("Inserisci le coordinate in cui vuoi mettere il punto medio della Corazzata C" + to_string((i+1)));
                    cin>>x>>y;
                    p.first = x;
                    p.second = y;
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
                        //printTextEffect(players[ind].getMare().printAMare());
                    }
                }
                else
                if (players[ind].getType() != U && ind == 0)
                {
                    d = rand()%2;
                    if(d==0)
                    {
                        x = rand()%12;
                        cout<<" x bot = "<<x<<endl;
                        y = rand()%8+2;
                        cout <<" y bot = "<<y<<endl;
                    }
                    else
                    {
                        x = rand()%8+2;
                        cout << " x bot = " << x << endl;
                        y = rand()%12;
                        cout << " y bot = " << y << endl;
                    }
                    if (i == 0)
                    {
                        Corazzata c1 = Corazzata(p, d, i);
                        c1.setNumero(i);
                        players[ind].getMare().insertCor(c1, p);
                        // printTextEffect(players[ind].getMare().printAMare());
                    }
                    else if (i == 1)
                    {
                        Corazzata c2 = Corazzata(p, d, i);
                        c2.setNumero(i);
                        players[ind].getMare().insertCor(c2, p);
                        // printTextEffect(players[ind].getMare().printAMare());
                    }
                    else if (i == 2)
                    {
                        Corazzata c3 = Corazzata(p, d, i);
                        c3.setNumero(i);
                        players[ind].getMare().insertCor(c3, p);
                        // printTextEffect(players[ind].getMare().printAMare());
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
                        // printTextEffect(players[ind].getMare().printAMare());
                    }
                    else if (i == 1)
                    {
                        Corazzata c5 = Corazzata(p, d, i);
                        c5.setNumero(i);
                        players[ind].getMare().insertCor(c5, p);
                        // printTextEffect(players[ind].getMare().printAMare());
                    }
                    else if (i == 2)
                    {
                        Corazzata c6 = Corazzata(p, d, i);
                        c6.setNumero(i);
                        players[ind].getMare().insertCor(c6, p);
                        // printTextEffect(players[ind].getMare().printAMare());
                    }
                }
                i++;
            }
            catch(const InvalidInputException &e)
            {
                printTextEffect(e.what());
            }
        }
        
        //richiede al player o al bot di inserire le Nds, continua finchè tutte le Nds sono inserite
        //Nds
        i = 0;
        while(i < 3)
        {
            pair<int, int> p;
            int x;
            int y;
            int d;
            try
            {
                if(players[ind].getType() == U)
                {
                    printTextEffect("Inserisci la direzione della Nds: " + to_string((i+1)) + " 0 = verticale, 1 = orizzontale");
                    cin>>d;
                    printTextEffect("Inserisci le coordinate in cui vuoi mettere il punto medio della Nave da Supporto Nds" + to_string((i+1)));
                    cin>>x>>y;
                    p.first = x;
                    p.second = y;
                    
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
        //richiede al player o al bot di inserire i Sde, continua finchè tutti i Sde sono inseriti
        //Sde
        i = 0;
        while(i < 2)
        {
            pair<int, int> p;
            int x;
            int y;
            int d;
            try
            {
                if(players[ind].getType() == U)
                {
                    printTextEffect("Inserisci le coordinate in cui vuoi mettere il punto medio del Sottomarino da Esplorazione Sde" + to_string((i+1)));
                    cin>>x>>y;
                    p.first = x;
                    p.second = y;
                    //non è necessario richiedere la direzione dell'sde poichè la sua dimensione è = 1
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
    //____________________________________________________________________________________________________________
    //inizio del gioco_________________
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
            //if (code == "XX XX")
            //{
                //cout << boardP1.printAMare(mar_);
                //cout << boardP2.printEMare(mar_);
            //}//__________________________________________________________________________________________________________
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
        printTextEffect("La partita termina in patta! È stata effettuata la 50esima mossa totale!");
    }
    printTextEffect("Grazie per aver giocato!");
}
