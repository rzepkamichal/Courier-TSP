/**@file*/
#ifndef PROJ2_V2_ENUMS_H
#define PROJ2_V2_ENUMS_H
#include <string>
#include <fstream>
using namespace std;

/**Typ wyliczeniowy służący do przekazywania informacji o sposobie uruchomienia programu.*/

enum InputCase {
	/**Przekazuje informację, że program został uruchomionwy w sposób nieprawidłowy lub podano nieprawidłowe ścieżki do plików lub użyto parametru -h (pomoc).*/
	ShowHelp, 
	/**Przekazuje informację, że parametry zostały poprawnie odczytane.*/
	IOGiven
};

/**Typ wyliczeniowy służący do przekazywania informacji o istniejących połączeniach. Wykorzystywany przy wczytywaniu danych wejściowych z pliku.*/

enum ConnectionStatus { 
	/**Przekazuje informację, że wczytane połączenie znajduje się już w liście połączeń.*/	
	IsAlready,
	/**Przekazuje informację, że wczytane połączenie znajduje się już na liście połączeń, lecz odległości w obu przypadkach są różne.*/ 	
	IsDifferent,
	/**Przekazuje informację, że wczytane połączenie nie zostało jeszcze dodane do listy połączeń.*/ 
	NoConnection
};

#endif //PROJ2_V2_ENUMS_H
