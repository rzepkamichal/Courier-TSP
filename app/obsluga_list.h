/**@file*/
#ifndef PROJ2_V2_OBSLUGA_LIST_H
#define PROJ2_V2_OBSLUGA_LIST_H

#include "node_struct.h"
#include "enums.h"
#include "solution_struct.h"
#include <string>
#include <fstream>
using namespace std;
/**Funkcja dodaje kolejny wierzchołek na koniec listy wierzchołków.
*@param Node *& pHead -- wskaźnik na głowę listy wierzchołków.
*@param	int  id -- numer identyfikacyjny wierzchołka.
*@return Funkcja nic nie zwraca.	
*/
void pushBackNode(Node *&pHead, int id);

/**Funkcja pobiera ostatni element z listy wierzchołków.
*@param Node *& pHead -- wskaźnik na głowę listy wierzchołków.
*@return Funkcja zwraca wskaźnik na ostatni element listy wierzchołków.
*/
Node* getLast(Node *&pHead);

/**Funkcja dodaje sąsiedni wierzchołek do listy sąsiednich wierzchołków dla danego węzła.
*@param Node * node -- wskaźnik na wierzchołek, któremu zostatnie dodany kolejny wierzchołek sąsiedni.
*@param Nbr *& pHead -- wskaźnik na głowę listy sąsiednich wierzchołków danego wierzchołka.
*@param double distance -- odległośc wierzchołka sąsiedniego od danego.
*@return Funkcja nic nie zwraca.
*/
void pushBackNbr(Nbr *&pHead, Node *node, double distance);

/**Funkcja dodająca połączenie jednokierunkowe do listy wierzchołków (połączeń), czyli wierzchołek i odpowiadający mu wierzchołek sąsiedni. Jeżeli wierzchołki, które tworzą połączenie jeszcze nie istnieją w liście, to zostają dodane.
*@param Node *& pHead -- wskaźnik na głowę listy wierzchołków.
*@param int nodeId -- identyfikator węzła wyjściowego.
*@param int nbrId -- identyfikator węzła sąsiedniego.
*@param double distance -- odległość pomiędzy wierzchołkami.
*@return Funkcja nic nie zwraca.
*/
void addNbr(Node *&pHead, int nodeId, int nbrId, double distance);

/**Funkcja usuwająca listę wierzchołków sąsiednich.
*@param Nbr *& pHead -- wskaźnik na głowę listy wierzchołków sąsiednich.
*@return Funkcja nic nie zwraca.
*/
void removeNbrs(Nbr *&pHead);

/**Funkcja usuwająca listę węzłów.
*@param Node *& pHead -- wskaźnik na głowę listy wierzchołków.
*@return Funkcja nic nie zwraca.
*/
void removeNodes(Node *&pHead);

/**Funkcja sprawdza status połączenia zawartego w liście względem przekazanego jako parametr (a wcześniej odczytanego z pliku.)
*@param Node *& pHead -- wskaźnik na listę węzłów.
*@param int     firstNodeId -- identyfikator pierwszego węzła tworzącego połączenie.
*@param int	secondNodeId -- identyfikator drugiego węzła tworzącego połączenie.
*@param double distance -- długość połączenia odczytanego z pliku.
*@return Funkcja zwraca typ wyliczeniowy ConnectionStatus:
*@return-- IsAlready, jeśli połączenie przekazane za pomocą parametrów znajduje się już na liście.
*@return-- IsDifferenc, jeśli połączenie przekazane za pomocą parametrów znajduje się już na liście, lecz oba przypadki różnią się odległością
*@return-- NoConnection, jeśli połączenie przekazane za pomocą parametrów jeszcze nie istnieje.
*/
ConnectionStatus findConnection(Node *&pHead, int firstNodeId, int secondNodeId, double distance);

/**Funkcja usuwająca listę identyfikatorów wyznaczających ścieżkę.
*@param SolutionId *& pHead -- wskaźnik na głowę listy identyfikatorów.
*@return Funkcja nic nie zwraca.
*/
void removeIdList(SolutionId *&pHead);

/**Funkcja usuwająca listę przechowującą rozwiązania.
*@param Solution *& pHead -- wskaźnik na głowę listy przechowującej rozwiązania.
*@return Funkcja nic nie zwraca.
*/
void removeSolutionList(Solution *&pHead);

/**Funkcja wypisująca identyfikatory ścieżki na przekazane w parametrze wyjście.
*@param SolutionId *pHead -- wskaźnik na głowę listy identyfikatorów.
*@param ostream &out -- strumień wyjściowy.
*@return Funkcja nic nie zwraca.
*/
void writeIds(SolutionId *pHead, ostream &out);

/**Funkcja wypisująca rozwiązanie na przekazane w parametrze wyjście.
*@param Solution *& pHead -- wskaźnik na głowę listy rozwiązań
*@param ostream &out -- strumień wyjściowy.
*@return Funkcja nic nie zwraca.
*/
void writeSolutions(Solution *&pHead, ostream &out);

/**Funkcja zliczająca węzły w liście węzłów.
*@param Node *& pHead -- wskaźnik na głowę listy węzłów.
*@return Funkcja zwraca wartość typu double- ilość węzłów.
*/
double countNodes(Node *&pHead);

/**Funkcja dodająca identyfikator na koniec listy identyfikatorów.
*@param SolutionId *& pHead -- wskaźnik na głowę listy identyfikatorów.
*@return Funkcja nic nie zwraca.
*/
void pushBackId(SolutionId *&pHead, int id);

/**Funkcja dodająca wierzchołek do ścieżki.
*@param Path *& pHead -- wskaźnik na głowę listy reprezentującą ścieżkę.
*@param Node *& node -- wskaźnik na wierzchołek, który ma zostać dodany do ścieżki.
*@param double distance -- odległość, która dzieli dodawany wierzchołek od poprzedniego.
*@return Funkcja nic nie zwraca.
*/
void addToPath(Path *&pHead, Node *&node, double distance);

/**Funkcja usuwająca ostatni wierzchołek ze ścieżki
*@param Path *& pHead -- wskaźnik na głowę listy reprezentującej ścieżkę.
*@return Funkcja nic nie zwraca.
*/
void removeLastFromPath(Path *&pHead);

/**Funkcja usuwająca ścieżkę.
*@param Path *& pHead -- wskaźnik na głowę listy reprezentującej ścieżkę.
*@return Funkcja nic nie zwraca.
*/
void removePath(Path *&pHead);

#endif //PROJ2_V2_OBSLUGA_LIST_H
