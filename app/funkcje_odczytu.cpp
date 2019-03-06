/**@file*/
#include <sstream>
#include "enums.h"
#include "node_struct.h"
#include "funkcje_odczytu.h"
#include "obsluga_list.h"

InputCase ReadParams(int number, char *argv[], string &inputPath, string &outputPath){
    
    string param;
    if(number == 1) {
        return ShowHelp;

    }else{
        if (number == 5){
            bool inputGiven = false;
            bool outputGiven = false;

            for(int i = 1; i < number; i++){
                param = argv[i];

                if(param == "-i" && i < number-1 && !inputGiven){
                    i++;
                    param = argv[i];
                    ifstream tmpInput(param);
                    if(tmpInput.is_open()){
                        inputPath = param;
                        inputGiven = true;
                        tmpInput.close();
                    }
                }

                if(param == "-d" && i < number-1 && !outputGiven){
                    i++;
                    param = argv[i];
                    fstream tmpOutput(param);
                    if(tmpOutput.is_open()){
                        outputPath = param;
                        outputGiven = true;
                        tmpOutput.close();
                    }
                }
            }

            if(inputGiven && outputGiven){
                return IOGiven;
            }else{
                return ShowHelp;
            }

        }else {
            return ShowHelp;
        }
    }
}
bool addDataToList(Node *&pHead, string data){
    bool isOneWay;
    int indexStartOfSecondNum,indexEndOfFirstNum,indexStartOfDistance,indexEndOfSecondNum;
    int firstNum, secondNum;
    double distance;

    for(int i = 1; i < data.length(); i++){//badamy pierwsza liczbe (lewy wezel)
        if(i < data.length()-1 && data.at(i) == '-' && isdigit(data.at(i+1))){
            isOneWay = false;
            indexStartOfSecondNum = i+1;
            indexEndOfFirstNum = i-1;
            break;
        }else if(i < data.length()-1 && data.at(i) == '-' && data.at(i+1) == '>'){
            isOneWay = true;
            indexStartOfSecondNum = i+2;
            indexEndOfFirstNum = i-1;
            break;
        }
    }
    if(IsNatural(data.substr(0,indexEndOfFirstNum+1))){//badamy druga liczbe (lewy wezel)
        firstNum = stoi(data.substr(0,indexEndOfFirstNum+1));

        for(int i = indexStartOfSecondNum; i < data.length(); i++) {
            if (data.at(i) == ':' && i > 0) {
                indexEndOfSecondNum = i - 1;
                break;
            }
        }
        if(IsNatural(data.substr(indexStartOfSecondNum,indexEndOfSecondNum - indexStartOfSecondNum+1))){
            secondNum = stoi(data.substr(indexStartOfSecondNum,indexEndOfSecondNum-indexStartOfSecondNum+1));
            if(indexEndOfSecondNum+2 < data.length() && isReal(data.substr(indexEndOfSecondNum+2))){
                distance = stold(data.substr(indexEndOfSecondNum+2));
                //<linia do testowani> cout << endl << "lewy: " << firstNum << endl << "prawy: " << secondNum << endl << "dystans: " << distance << endl;
                if(isOneWay){
                    ConnectionStatus statusOneWay = findConnection(pHead, firstNum,secondNum,distance);
                    if(statusOneWay == IsAlready){
                        return true;
                    }else if(statusOneWay == IsDifferent){
                        return false;
                    }else if(statusOneWay == NoConnection) {
                        addNbr(pHead, firstNum, secondNum, distance);
                    }
                }else{
                    ConnectionStatus statusThere, statusBack;
                    statusThere = findConnection(pHead, firstNum,secondNum,distance);
                    statusBack = findConnection(pHead, secondNum, firstNum,distance);

                    if(statusThere == IsAlready && statusBack == IsAlready){
                        return true;
                    }else if(statusThere ==IsDifferent || statusBack == IsDifferent){
                        return false;
                    }else if(statusThere == NoConnection && statusBack == NoConnection){
                        addNbr(pHead,firstNum,secondNum,distance);
                        addNbr(pHead,secondNum,firstNum,distance);
                    }else{
                        return false;
                    }
                }
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }


    }else{
        return false;
    }


}
bool ReadData(Node *&pHead, istream &iFile){

    string tmpLine; // przechowuje bezposrednio pobrana linie z bialymi znakami
    string safeLine; // przechowuje "urwane" czesci danych,  zeby dopisac je do nowej lini
    bool oneLineRead = false;
    bool readDataStarted = false;
    bool skipFirstBracket = false;
    while(getline(iFile,tmpLine)){
        oneLineRead = true;
        stringstream tmpStream(tmpLine); // sstream - za jego pomoca z linii zostana usuniete biale znaki
        string tmpString;//sluzy do przechowywania "kawalkow" odczytanych przez sstream
        string line;// przechowuje linie wyjsciowa juz bez bialych znakow

        line.append(safeLine);
        safeLine.clear();
        while(tmpStream >> tmpString){
            line.append(tmpString);
        }

        while(line.length()){

            if(line.at(0) == '(' || skipFirstBracket){
                skipFirstBracket = false;
                readDataStarted = true;
                int indexBracketEnd;
                bool foundBracketEnd = false;

                for(int i = 1; i < line.length(); i++){
                    if(line.at(i) == ')'){
                        indexBracketEnd = i;
                        foundBracketEnd = true;
                        break;
                    }
                }

                if(foundBracketEnd){
                    foundBracketEnd = false;

                    if(indexBracketEnd + 1 < line.length() && line.at(indexBracketEnd + 1) == ','){
                        if(addDataToList(pHead, line.substr(1,indexBracketEnd - 1))){
                            line.erase(0,indexBracketEnd + 2);
                            readDataStarted = false;
                            continue;
                        }else{
                            return false;
                        }

                    }else{

                        if(iFile.eof()){
                            if(line.length() > indexBracketEnd +1 && addDataToList(pHead, line.substr(1,indexBracketEnd -1))){
                                line.erase(0,indexBracketEnd + 2);
                                readDataStarted = false;
                                continue;
                            }else if(addDataToList(pHead, line.substr(1,indexBracketEnd -1))){
                                readDataStarted = false;
                                return true;
                            }else{
                                return false;
                            }
                        }else{
                            safeLine = line;
                            line.clear();
                            continue;
                        }
                    }

                }else{
                    if(iFile.eof()){
                        return false;
                    }else{
                        safeLine = line;
                        line.clear();
                        continue;
                    }
                }

            }else{
                if(readDataStarted){
                    skipFirstBracket = true;
                    continue;
                }else{
                    return false;
                }
            }
        }

    }
    if(oneLineRead) {
        return true;
    }else{
        return false;
    }

}
bool IsNatural(string line){

    bool isNatural;
    bool isNotZero = false;
    for (int i = 0; i < line.length(); i++)
    {
        if (line.at(i) >= 48 && line.at(i) <= 57)
        {
            if (line.at(i) != '0')
            {
                isNotZero = true;
            }
            isNatural = true;
        }
        else
        {
            isNatural = false;
            break;
        }
    }
    return isNatural && isNotZero;
}
bool isReal(string line){
    if(IsNatural(line)){
        return true;
    }else{
        bool isReal;
        bool pointAppeared = false;
        bool isNotZero = false;
        for(int i = 0; i < line.length(); i++){
            if(i !=  0 && i != line.at(line.length()-1) && line.at(i) == '.' && !pointAppeared){
                pointAppeared = true;
            }else if(line.at(i) >= 48 && line.at(i) <= 57){
                if (line.at(i) != '0'){
                    isNotZero = true;
                }
                isReal = true;
            }else{
                isReal = false;
                break;
            }
        }
        return isReal && isNotZero;
    }
}

