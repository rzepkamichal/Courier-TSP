/**@file*/
#ifndef PROJ2_V2_SOLUTION_STRUCT_H
#define PROJ2_V2_SOLUTION_STRUCT_H
#include <string>
#include <fstream>
using namespace std;
struct Solution;
struct SolutionId;

/**Lista przechowująca kolejne numery identyfikacyjne wierzchołków tworzących ścieżkę będącą rozwiązaniem.*/
struct SolutionId{
    /**Zmienna przechowująca numer identyfikacyjne kolejnych wierzchołków.*/
    int id;
    /**Wskaźnik na następny element.*/
    SolutionId *pNext;
};

/**Lista przechowująca kolejne kolejne ścieżki spełniające warunki zadania. Ostateczne rozwiązanie stanowi najkrótsza ze ścieżek.*/
struct Solution{
    /**Wskaźnik na listę numerów indentyfikacyjnych charakteryzującą ścieżkę.*/
    SolutionId *ids;
    /**Zmienna przechowująca sumaryczną długość ścieżki*/
    double sumDistance;
    /**Wskaźnik na następny element, tzn. następną ścieżkę spełniającą warunki zadania*/
    Solution *pNext;
};
#endif //PROJ2_V2_SOLUTION_STRUCT_H
