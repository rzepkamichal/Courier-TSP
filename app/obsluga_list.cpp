/**@file*/
#include "node_struct.h"
#include "enums.h"
#include "solution_struct.h"
#include "obsluga_list.h"

void pushBackNode(Node *&pHead, int id){
    if(!pHead){
        pHead = new Node{ id, nullptr, nullptr };
    }else {
        pushBackNode(pHead-> pNext, id);
    }
}
Node* getLast(Node *&pHead){
    if(!pHead-> pNext){
        return pHead;
    }else{
        getLast(pHead-> pNext);
    }
}
void pushBackNbr(Nbr *&pHead, Node *node, double distance){
    if(!pHead){
        pHead = new Nbr{node, distance, nullptr};
    }else{
        pushBackNbr(pHead-> pNext, node, distance);
    }
}
void addNbr(Node *&pHead, int nodeId, int nbrId, double distance){
    bool nodeExists = false;
    bool nbrNodeExists = false;
    auto *tmpHead = pHead;

    while(tmpHead){
        if(tmpHead-> id == nodeId){
            nodeExists = true;
            break;
        }else{
            tmpHead = tmpHead-> pNext;
        }
    }
    auto *pNode = tmpHead;
    tmpHead = pHead;

    while(tmpHead){
        if(tmpHead-> id == nbrId){
            nbrNodeExists = true;
            break;
        }else{
            tmpHead = tmpHead-> pNext;
        }
    }
    auto *pNbrNode = tmpHead;
    tmpHead = pHead;

    if(!nodeExists){
        pushBackNode(pHead, nodeId);
        pNode = getLast(pHead);
    }
    if(!nbrNodeExists){
        pushBackNode(pHead, nbrId);
        pNbrNode = getLast(pHead);
    }
    pNode-> nbrs;
    auto *tmpNbrsHead = pNode-> nbrs;

    pushBackNbr(tmpNbrsHead, pNbrNode, distance);
    pNode-> nbrs = tmpNbrsHead;
}
void removeNbrs(Nbr *&pHead){
    if(!pHead->pNext){
        delete pHead;
    }else{
        removeNbrs(pHead-> pNext);
        delete pHead;
    }
}
void removeNodes(Node *&pHead){
    if(!pHead){
        return;
    }
    if(!pHead->pNext){
        if(pHead-> nbrs){
            removeNbrs(pHead-> nbrs);
        }
        delete pHead;
    }else{
        removeNodes(pHead-> pNext);
        if(pHead-> nbrs){
            removeNbrs(pHead-> nbrs);
        }
        delete pHead;
    }
}
ConnectionStatus findConnection(Node *&pHead, int firstNodeId, int secondNodeId, double distance){

    bool theSameConnection = false;
    bool theSameDistance = false;
    auto *head = pHead;

    while(head){
        if(head-> id == firstNodeId) {
            auto *nbrsHead = head->nbrs;
            while (nbrsHead) {
                if (nbrsHead->nbr->id == secondNodeId) {
                    theSameConnection = true;
                    if (nbrsHead->distance == distance) {
                        theSameDistance = true;
                        break;
                    }
                }
                nbrsHead = nbrsHead->pNext;

            }
            break;
        }
        head = head-> pNext;
    }

    if(theSameConnection){
        if(theSameDistance){
            return IsAlready;
        }else{
            return IsDifferent;
        }
    }else{
        return NoConnection;
    }

}
void pushBackId(SolutionId *&pHead, int id){
    if(!pHead){
        pHead = new SolutionId{id, nullptr};
    }else{
        pushBackId(pHead-> pNext, id);
    }
}
void removeLastFromPath(Path *&pHead){
    if(!pHead){
        return;
    }
    if(!pHead-> pNext){
        delete pHead;
        pHead = nullptr;
    }else{
        removeLastFromPath(pHead-> pNext);
    }
}
void addToPath(Path *&pHead, Node *&node, double distance){
    if(!pHead){
        pHead = new Path{node, distance, nullptr};
    }else{
        addToPath(pHead-> pNext, node, distance);
    }
}
void removePath(Path *&pHead){
    if(!pHead){
        return;
    }
    if(!pHead-> pNext){
        delete pHead;
        pHead = nullptr;
    }else{
        removePath(pHead-> pNext);
        delete pHead;
        pHead = nullptr;
    }
}
double countNodes(Node *&pHead){
    int count = 0;
    auto *head = pHead;
    while(head){
        count++;
        head = head-> pNext;
    }
    return count;
}
void writeSolutions(Solution *&pHead, ostream &out){
    if(!pHead){
        out << endl << "brak!" << endl;
        return;
    }
    if(!pHead->pNext){
        out << "droga: ";
        writeIds(pHead-> ids, out);
        out <<"| dystans: " << pHead-> sumDistance;
        out << endl;
    }else{
        out << "droga: ";
        writeIds(pHead-> ids, out);
        out <<"| dystans: " << pHead-> sumDistance;
        out << endl;
        writeSolutions(pHead-> pNext, out);
    }
}
void writeIds(SolutionId *pHead, ostream &out){
    if(!pHead){
        return;
    }else {
        out << pHead->id << "  ";
        writeIds(pHead->pNext, out);
    }

}
void removeIdList(SolutionId *&pHead){
    if(!pHead){
        return;
    }
    if(!pHead-> pNext){
        delete pHead;
        pHead = nullptr;
    }else{
        removeIdList(pHead-> pNext);
        delete pHead;
        pHead = nullptr;
    }
}
void removeSolutionList(Solution *&pHead){
    if(!pHead){
        return;
    }
    if(!pHead-> pNext){
        removeIdList(pHead-> ids);
        delete pHead;
        pHead = nullptr;
    }else{
        removeSolutionList(pHead-> pNext);
        removeIdList(pHead-> ids);
        delete pHead;
        pHead = nullptr;
    }
}
