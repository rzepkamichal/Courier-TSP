/**@file*/
#ifndef PROJ2_V2_FUNKCJE_ODCZYTU_H
#define PROJ2_V2_FUNKCJE_ODCZYTU_H

#include "enums.h"
#include "node_struct.h"
#include <string>
#include <fstream>
using namespace std;

/**Funkcja sprawdza parametry konsoli i ewentualnie odczytuje odpowiednie ścieżki do plików.
*@param int number -- ilość parametrów wiersza poleceń.
*@param char *argv[] -- parametry wiersza poleceń.
*@param string &inputPath -- łańcuch znaków, do którego będzie wczytana ścieżka pliku wejściowego.
*@param string &outputPath -- łańcuch znaków, do którego będzie wczytana ścieżka pliku wyjściowego.
*@return Funkcja zwraca typ wyliczeniowy InputCase:
*@return -- IOGiven, jeśli odczytane parametry i ścieżki są poprawne.
*@return -- ShowHelp, jeśli odczytane parametry lub ścieżki nie są poprawne albo użytkownik użyje przełącznika '-h' zamierzając wylistować 'pomoc'.
*/
InputCase ReadParams(int number, char *argv[], string &inputPath, string &outputPath);

/**Funkcja odczytująca zawratość z pliku z pomiędzy nawiasów. Zawartość ta jest sprawdzana pod kątem poprawności i ewentualnie dodawana jako połączenie do listy węzłów
*@param Node *& pHead -- wskaźnik na głowę listy węzłów.
*@string data -- pobrana zawartość, analizowana w ciele funkcji.
*@return Funkcja zwraca wartość logiczną:
*@return true, jeśli odczyt i dodanie do listy powiedzie się.
*@return false, jeśli odczytane dane okażą się błędne.
*/
bool addDataToList(Node *&pHead, string data);

/**Funkcja odczytująca dane z pliku- linia po linii. Funkcja zapisuje pobraną linie do łańcucha znaków
i sprawdza dane szukając nawiasów i przecinków oddzielających poszczególne dane. Zawartość z pomiędzy nawiasów jest
przekazywana do funkcji addDataToList.
*@param Node *& pHead -- wskaźnik na głowę listy węzłów. Funkcja nie wykorzystjue parametru bezpośrednio, lecz przekazuje go do funkcji addDataToList.
*@patam istream &iFile -- strumień pliku wejściowego, z którego dane są odczytywane.
*@return Funkcja zwraca wartość logiczną:
*@return -- true, jeśli odczyt się powiedzie.
*@return -- false, jeśli odczytane dane okażą się błędne.
*/
bool ReadData(Node *&pHead, istream &iFile);

/**Funkcja sprawdza, czy zawartość przekazanego łańcucha znaków stanowi dodatnią liczbę naturalną.
*@param string line -- łańcuch znaków, który będzie analizowany.
*@return Funkcja zwraca wartość logiczną:
*@return -- true, jeśli łańcuch stanowi dodatnią liczbę naturalną.
*@return -- false w przeciwnym przypadku.
*/
bool IsNatural(string line);

/**Funkcja sprawdza, czy zawartość przekazanego łańcucha znaków stanowi dodatnią liczbę zmiennoprzecinkową.
*@param string line -- łańcuch znaków, który będzie analizowany.
*@return Funkcja zwraca wartość logiczną:
*@return -- true, jeśli łańcuch stanowi dodatnią liczbę naturalną.
*@return -- false w przeciwynm przypadku.
*/
bool isReal(string line);

#endif //PROJ2_V2_FUNKCJE_ODCZYTU_H
