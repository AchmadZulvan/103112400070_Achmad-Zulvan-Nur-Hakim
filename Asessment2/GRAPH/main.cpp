#include <iostream>
#include "graph.h"
using namespace std;

int main() {
    Graph G;
    initGraph(G);
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');
    addEdge(G, 'A', 'B');
    addEdge(G, 'B', 'E');
    addEdge(G, 'B', 'C');
    addEdge(G, 'C', 'D');
    checkCriticalCities(G);

    return 0;
}
