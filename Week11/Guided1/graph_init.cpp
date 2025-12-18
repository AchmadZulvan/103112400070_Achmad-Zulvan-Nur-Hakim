#include "graph.h"

void createGraph (graph &G) {
    G.first = NULL;
}

adrNode allocateNode (infoGraph x) {
    adrNode P = new elmNode;
    P -> info = x;
    P -> visited = false;
    P -> firstEdge = NULL;
    P -> next = NULL;
    return P;
}

void insertNode (graph &G, infoGraph x) {
    adrNode P = allocateNode(x);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q -> next != NULL) {
            Q = Q -> next;
        }
        Q -> next = P;
    }
}