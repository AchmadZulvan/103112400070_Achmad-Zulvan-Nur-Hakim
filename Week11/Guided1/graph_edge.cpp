#include "graph.h"

adrNode findNode (graph G, infoGraph x) {
    adrNode p = G.first;
    while (p != NULL) {
        if (p -> info == x) {
            return p;
        }
        p = p -> next;
    }
    return NULL;
}

void connectNode (graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new elmEdge;
        newEdge -> node = pEnd;
        newEdge -> next = pStart -> firstEdge;
        pStart -> firstEdge = newEdge;
    }
}