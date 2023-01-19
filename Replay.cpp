#include "Ship.hpp"
#include "PTE.cpp"
#include "Mare.hpp"

using namespace std;
int main(int argc, char **args)
{
    if (argc <= 2)
    {
        PTE("Non sono stati inseriti gli argomenti necessari; rieseguire il programma.");
        return 0;
    }

    char op = *args[1];
    if (!(op == 'v' || op == 'f'))
    {
        PTE("Il codice per l'operazione inserito non è valido; rieseguire il programma.");
        return 0;
    }

    if (op == 'f' && argc == 3)
    {
        PTE("Gli argomenti inseriti non sono sufficienti per il replay su file; rieseguire il programma.");
        return 0;
    }

    if (op == 'v' && argc > 3)
    {
        PTE("Sono stati inseriti troppi argomenti per il replay a video; rieseguire il programma.");
        return 0;
    }

    if (op == 'f' && argc > 4)
    {
        PTE("Sono stati inseriti troppi argomenti per il replay su file; rieseguire il programma.");
        return 0;
    }

    string logFile(args[2]);
    string replayFile;
    if (argc >= 4)
        replayFile = args[3];
    // se il nome del file non contiene l'estensione, viene aggiunta

    if (logFile.size() < 5 || logFile.substr(logFile.size() - 4) != ".txt")
        logFile += ".txt";
    ifstream scanner(logFile);
    // controlla se file di log inserito esiste

    if (!scanner.good())
    {
        PTE("Il file di log inserito non esiste; rieseguire il programma.");
        return 0;
    }

    PTE("Benvenuto nel replay delle partite di battaglia navale!");
    // stringa usata per salvare i messaggi da stampare nel corso del programma
    string message;
    message = "Verrà effettuato il replay ";
    message += (op == 'v') ? "a video " : "sul file '" + replayFile + "' ";
    message += "della partita salvata sul file di log '" + logFile + "'!";
    PTE(message);
    // ottiene nomi giocatori (prime due righe del log)
    string scannerLine;
    getline(scanner, scannerLine);
    string player1 = scannerLine.substr(3);
    getline(scanner, scannerLine);
    string player2 = scannerLine.substr(3);

    int i = -1;
    // se viene effettuato replay su file, viene aperto oggetto per scrivere su file
    ofstream replayWrite;

    if (op == 'f')
    {
        if (replayFile.size() < 5 || replayFile.substr(replayFile.size() - 4) != ".txt")
            replayFile += ".txt";
        replayWrite.open(replayFile);
    }

    Mare board = Mare();
    int movesNumber = 0;
    char player;

    while (getline(scanner, scannerLine))
    {
        player = (i % 2 == 0) ? '1' : '2';
        string message;
        bool pb = true;
        // terza riga: riga vuota, nessuna mossa
        if (i == -1)

        {
            pb = false;
            message = "La partita inizia: " + player1 + " con le pedine bianche e ";
            message += player2 + " con le pedine nere!";
        }

        // ultima riga del log: END: [numero che identifica finale]
        else if (scannerLine.substr(0, 4) == "END:")
        {
            pb = false;
            int ending = scannerLine[4] - 48;
            switch (ending)
            {
            case 0: // Vince uno dei due giocatori
                message = (player == '1') ? player1 : player2;
                message += " perde, ";
                message += (player == '1') ? player2 : player1;
                message += " vince!";
                break;
            case 2: // patta per 50 mosse
                message = "La partita termina in patta! Sono state eseguite 50 mosse senza spostare pedoni o mangiare pezzi!";
                break;
            }

            // stampa numero totale di mosse
            message += "\nSono state effettuate " + to_string(movesNumber) + " mosse in totale!";
        }
        i++;
        // se replay a video, stampa messaggio costruito e scacchiera attuale a video
        if (op == 'v')
        {
            PTE(message);
            if (pb)
            {
                cout << board.printAMare() << "    " << board.printEMare();
                this_thread::sleep_for(chrono::seconds(3));
            }
        }

        // se replay su file, scrive messaggio costruito e scacchiera attuale sul file
        else
        {
            replayWrite << message << "\n";
            if (pb)
                replayWrite <<  board.printAMare() << "    " << board.printEMare() << "\n\n";
        }
    }

    if (op == 'f')
        PTE("Replay effettuato su " + replayFile + "!");
    PTE("Replay finito!");
}