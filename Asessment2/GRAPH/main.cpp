#include <iostream>
#include "graph.h"
using namespace std;

int main() {
    Graph vaccineNet;
    initGraph(vaccineNet);

    insertNode(vaccineNet, 'A');
    insertNode(vaccineNet, 'B');
    insertNode(vaccineNet, 'C');
    insertNode(vaccineNet, 'D');
    insertNode(vaccineNet, 'E');
    addEdge(vaccineNet, 'A', 'B');
    addEdge(vaccineNet, 'B', 'E');
    addEdge(vaccineNet, 'B', 'C');
    addEdge(vaccineNet, 'C', 'D');

    cout << "Membangun Jaringan Distribusi Vaksin\n";
    cout << "Node A terhubung ke: B\n";
    cout << "Node B terhubung ke: E C A\n";
    cout << "Node C terhubung ke: D B\n";
    cout << "Node D terhubung ke: C\n";
    cout << "Node E terhubung ke: B\n";
    checkCriticalCities(vaccineNet);

    return 0;
}