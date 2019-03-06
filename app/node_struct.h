/** @file */
#ifndef PROJ2_V2_NODE_STRUCT_H
#define PROJ2_V2_NODE_STRUCT_H
#include <string>
#include <fstream>
using namespace std;

struct Node;
struct Nbr;
struct Path;

/**Lista przechowująca kolejne węzły grafu. */
struct Node{
    /**Numer identyfikacyjny, za pomocą którego rozróżniane sa kolejne węzły.*/
    int id;
/**Wskaźnik na listę wierzchołków sąsiednich (sąsiadów) dla danego wierzchołka.*/
    Nbr *nbrs;
/**Wskaźnik na następny element listy, tzn. na następny wierzchołek.*/
    Node *pNext;
};

/**Lista sąsiednich wierzchołków. Każdy element listy wierzchołków zawiera pole będące wskaźnikiem na taką listę.*/
struct Nbr{
/**Wskaźnik na wierzchołek sąsiedni.*/
    Node *nbr;
/**Zmienna przechowująca odleglość danego sąsiada od wierzchołka wyjściowego */
    double distance;
/**Wskaźnik na następny element, tzn. na następny sąsiedni wierzchołek.*/
    Nbr *pNext;
};

/**Lista przechowująca aktualną ścieżkę- kolejno występujące na niej węzły. Wykorzystywana tymczasowo w trakcie analizy grafu.*/
struct Path{
    Node *node;/**Wskaźnik na wierzchołek tworzący scieżkę.*/
    double distance;/**Zmienna przechowująca odległość danego wierzchołka ścieżki od poprzednika.*/
    Path *pNext;/**Wskaźnik na następny element, tzn. następny wierzchołek tworzący ścieżkę.*/
};
#endif //PROJ2_V2_NODE_STRUCT_H
