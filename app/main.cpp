/**@file*/
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include "funkcje_odczytu.h"
#include "solution_struct.h"
#include "algorytm.h"
#include "obsluga_list.h"

using namespace std;

/**Funkcja main przyjmuje argumenty wiersza poleceń. W zmiennych iPath i oPath są przechowywane ścieżki wejścia i wyjścia. Parametry konsoli i zmienne przechowujące ścieżki są przekazywane do funkcji ReadParams. Zmienna status typu InputCase jest inicjalizowana wartością, którą zwraca ReadParams. Następnie tworzone są wskaźniki, będące kolejno głową listy węzłów (połączeń) oraz listy rozwiązań. Dla pobranych ścieżek do plików tworzone są strumienie plikowe. Następuje przejście instrukcji switch, która w zależności od zmiennej status wywołuje funkcje realizujące algorytm lub wywołuje wyświetlenie komunikatu o błędzie. Ostatnim krokiem jest zwolnienie pamięci zajętej przez ww listy.*/
int main(int argc, char *argv[]) {
    string iPath, oPath;
    InputCase status = ReadParams(argc, argv, iPath, oPath);

    Node *nodesHead = nullptr;
    Solution *solutionHead = nullptr;

    ifstream iFile(iPath);
    ofstream oFile(oPath);

    switch(status){
        case IOGiven:
            if(ReadData(nodesHead, iFile)){
                calculateSolution(nodesHead, solutionHead, oFile);
                cout << "Gotowe!" << endl;
            }else{
                cout << "Wprowadzono bledne dane!" << endl;
            }
            break;
        case ShowHelp:
            cout << "Blad! Mozliwe przyczyny:" << endl;
            cout << "- poproszono o pomoc" <<endl;
            cout << "- wprowadzono bledne parametry" << endl;
            cout << "- wprowadzono bledne sciezki do plikow" << endl;
            cout << "Poprawne parametry: "<< endl;
	    cout << "-- Kurier -i <sciezka_do_plik_wejsciowego> -d <sciezka_do_pliku_wyjsciowego>" << endl;
	    cout << "-- Kurier -h //wyswietl pomoc"<< endl;
            break;
    }

    removeNodes(nodesHead);
    removeSolutionList(solutionHead);
    return 0;
}
