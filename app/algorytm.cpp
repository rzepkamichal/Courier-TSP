/**@file*/
#include "node_struct.h"
#include "solution_struct.h"
#include "obsluga_list.h"

bool isEnclosedPath(Path *&pHead, int numOfNodes){
  
    int count = 0;
    int idHead = pHead-> node-> id;
    auto *head = pHead;
    auto *headLast = pHead;
    
    while(head){
        count++;
        headLast = head;
        head = head-> pNext;
    }
    
    if(count == numOfNodes && headLast-> node-> id == idHead){
        return true;
    }else{
        return false;
    }
}
double sumDistances(Path *&pHead){
    double sum = 0;
    auto *head = pHead;

    while(head){
        sum += head-> distance;
        head = head-> pNext;
    }

    return sum;
}
void addPathToSolutions(Solution *&sHead, Path *&pHead, double sumDistance){

    if(!sHead){
        sHead = new Solution{nullptr, sumDistance, nullptr};
        auto *tmpHead = pHead;
        while(tmpHead){
            pushBackId(sHead-> ids,tmpHead-> node-> id);
            tmpHead = tmpHead-> pNext;
        }

    }else{
        addPathToSolutions(sHead-> pNext, pHead, sumDistance);
    }
}
bool isOnPath(Path *&pHead, Nbr *&nbrHead){

    auto *pathHead = pHead;
    while(pathHead){
        if(pathHead-> node-> id == nbrHead-> nbr-> id){
            return true;
        }
        pathHead = pathHead -> pNext;
    }
    return false;
}
void seekPathForSingleNode(Nbr *&nHead, Solution *&sHead, Path *&pHead, int numOfNodes){
    if(nHead){
        if(isOnPath(pHead,nHead)){
            addToPath(pHead,nHead-> nbr, nHead->distance);
            if(isEnclosedPath(pHead,numOfNodes + 1)){
                addPathToSolutions(sHead, pHead, sumDistances(pHead));
            }
            removeLastFromPath(pHead);
            seekPathForSingleNode(nHead-> pNext, sHead, pHead, numOfNodes);
        }else{
            addToPath(pHead, nHead-> nbr, nHead-> distance);
            seekPathForSingleNode(nHead-> nbr-> nbrs, sHead, pHead, numOfNodes);
            seekPathForSingleNode(nHead-> pNext, sHead, pHead, numOfNodes);
        }
    }else{

        if(isEnclosedPath(pHead, numOfNodes + 1)) {
            addPathToSolutions(sHead, pHead, sumDistances(pHead));
        }
        removeLastFromPath(pHead);
        return;
    }
}
void seekPath(Node *&pHead, Solution *&sHead, int numOfNodes){
    auto *nodesHead = pHead;
    if(nodesHead){ 

        if(nodesHead->nbrs) {
            Path *pathHead = new Path{nodesHead, 0, nullptr};
            seekPathForSingleNode(nodesHead->nbrs, sHead, pathHead, numOfNodes);
            removePath(pathHead);
        }

    }

}
Solution* getShortest(Solution *&pHead){
    auto *head = pHead;
    auto *tmpHead = pHead;
    if(head){
        double min = head-> sumDistance;
        head = head-> pNext;
        while(head){
            if(head-> sumDistance < min){
                min = head-> sumDistance;
                tmpHead = head;
            }
            head = head-> pNext;
        }
    }
    return tmpHead;
}
void calculateSolution(Node *&nodesHead, Solution *&solutionsHead, ostream &out){
    seekPath(nodesHead, solutionsHead, countNodes(nodesHead));
    Solution *theShortest = getShortest(solutionsHead);
    if(theShortest){
        writeIds(theShortest-> ids,out);
        out << "| dystans: " << theShortest-> sumDistance;
    }else{
        out << "nie znaleziono drog spelniajacych wymagania!";
    }

}
