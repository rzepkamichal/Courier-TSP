/**@file*/
#ifndef PROJ2_V2_ALGORYTM_H
#define PROJ2_V2_ALGORYTM_H

#include "node_struct.h"
#include "solution_struct.h"
#include <string>
#include <fstream>
using namespace std;

/**Funkcja sprawdza, czy podana ścieżka to jest ścieżką zamkniętą, która przechodzi przez wszystkie wierzchołki grafu. Ścieżka jest już sprawdzona pod kątem powtórzeń węzłów, zatem funkcja sprawdza jedynie, czy ilość węzłów w ścieżce jest równa ilości węzłów w grafie.
*@param Path *& pHead -- wskaźnik na głowę listy przechowującą ścieżkę. Ścieżka jest już sprawdzona pod kątem niepowtarzalności węzłów!
*@param int numOfNodes -- ilość węzłów w grafie.
*@return Funkcja zwraca wartość logiczną:
*@return -- true, jeśli ścieżka spełnia warunek poprawności.
*@return -- false w przeciwnym wypadku.
*/
bool isEnclosedPath(Path *&pHead, int numOfNodes);

/**Funkcja sumująca odległości zapisane w kolejnych elementach listy reprezentującą ścieżkę.
*@param Path *& pHead -- wskaźnik na głowę listy reprezentującej ścieżkę.
*@return Funkcja zwraca sumę odległości zapisaną w zmiennej typu double.
*/
double sumDistances(Path *&pHead);

/**Funkcja sprawdzająca, czy dany sąsiedni wierzchołek jest już na ścieżce.
*@param Path *& pHead -- wskaźnik na głowę listy reprezentującej ścieżkę,
*@param Nbr *& nbrHead -- wskaźnik na wierzchołek sąsiedni.
*@return Funkcja zwraca wartość logiczną:
*@return -- true, jeśli dany sąsiad jest na ścieżce.
*@return -- false w przeciwnym przypadku.
*/
bool isOnPath(Path *&pHead, Nbr *&nbrHead);

/**Funkcja dodaje ścieżkę do listy przechowującej ścieżki spełniające warunki zadania.
*@param Solution *& sHead -- wskaźnik na głowę listy reprezentującej ścieżki spełniające warunki zadania.
*@param Path *& pHead -- wskaźnik na głowę listy reprezentującej ścieżkę.
*@param double sumDistance -- zsumowane odległości, jakie przechowuje ścieżka.
*@return Funkcja nic nie zwraca.
*/
void addPathToSolutions(Solution *&sHead, Path *&pHead, double sumDistance);

/**Funkcja znajduje najkrótszą ścieżkę z listy ścieżek spełniających wymogi zadania.
*@param Solution *& pHead -- wskaźnik na głowę listy reprezentującej ścieżki spełniające wymogi zadania.
*@return Funkcja zwraca tyo Solution* -- wskaźnik na najkrótszą ścieżkę.
*/
Solution* getShortest(Solution *&pHead);

/**Funkcja analizuje graf dla otrzymanej listy sąsiednich wierzchołków, realizując algorytm DFS. Gdy znajdzie rozwiązanie- dodaje je do listy przechowującej rozwiązania.
*
*Dla skrócenia i uproszczenia opisu metody zastosowano skrót: sąsiad -- wierzchołek sąsiedni dla danego węzła, ścieżka zamknięta -- droga zamknięta przechodząca przez wszystkie węzły grafu dokładnie raz.
*
*Najpierw następuje sprawdzenie warunku, czy podany wierzchołek sąsiedzni istnieje.
*Jeśli TAK, do ścieżki dodawany jest węzeł, na który wskazuje sąsiad. Jeżeli węzeł jeszcze nie wystąpił na ścieżce, odbywa się sprawdzanie, czy ścieżka jest rozwiązaniem. Jeśli tak, to jest dodawana do rozwiązań. Węzeł jest usuwany ze ścieżki i następuje wywołanie rekurencyjne dla kolejnego sąsiada. Jeżeli okaże się, że węzeł jednak znajduje się już na liście sąsiadów, to odbywa się wywołanie rekurencyjne -- najpierw dla kolejnych sąsiadów sąsiada, następnie dla następnego z listy sąsiadów.
*Jeśli NIE, odbywa się sprawdzenie, czy aktualna ścieżka nie jest zamknięta, jeśli tak -- to zostanie dodana do rozwiązań. Następuje usunięcie węzła ze ścieżki i powrót do funkcji wywołującej.
*@param Nbr *& nHead -- wskaźnik na głowę listy wierzchołków sąsiednich dla danego węzła.
*@param Solution *& sHead -- wskaźnik na głowę listy przechowującej rozwiązania.
*@param Path *& pHead -- wskaźnik na głowę listy reprezentującej aktualną ścieżkę.
*@param int numOfNodes -- liczba węzłów w grafie.
*@return Funkcja nic nie zwraca.
*/
void seekPathForSingleNode(Nbr *&nHead, Solution *&sHead, Path *&pHead, int numOfNodes);

/**Funkcja pobierająca listę węzłów i wywołująca dla niej funkcję seekPathForSingleNodes- realizującą algorytm.
*@param Node *& pHead -- wskaźnik na głowę listy przechowującej węzły (połączenia).
*@param Solution *& sHead -- wskaźnik na głowę listy przechowującej ścieżki będące rozwiązaniami.
*@param int numOfNodes -- ilość węsłów w grafie.
*@return Funkcja nic nie zwraca.
*/
void seekPath(Node *&pHead, Solution *&sHead, int numOfNodes);

/**Funkcja wywołująca funkcje realizujące algorytm i wypisujące dane.
*@param Node *& nodesHead -- wskaźnik na głowę listy węzłów (połączeń).
*@param Solution *& solutionsHead -- wskaźnik na głowę listy rozwiązań.
*@param ostream &out -- strumień wyjściowy.
*@return Funkcja nic nie zwraca.
*/
void calculateSolution(Node *&nodesHead, Solution *&solutionsHead, ostream &out);

#endif //PROJ2_V2_ALGORYTM_H
