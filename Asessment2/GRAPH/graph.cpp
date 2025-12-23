#include <iostream>
#include "graph.h"
using namespace std;

void initGraph(Graph &G) {
    G.headNode = nullptr;
}

Node* createNode(char name) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->visited = false;
    newNode->isLockdown = false;
    newNode->firstEdge = nullptr;
    newNode->nextNode = nullptr;
    return newNode;
}

void insertNode(Graph &G, char name) {
    Node* newNode = createNode(name);
    if (!G.headNode) G.headNode = newNode;
    else {
        Node* temp = G.headNode;
        while (temp->nextNode) temp = temp->nextNode;
        temp->nextNode = newNode;
    }
}

void addEdge(Graph &G, char src, char dest) {
    Node *u = nullptr, *v = nullptr;
    Node *temp = G.headNode;
    while (temp) {
        if (temp->name == src) u = temp;
        if (temp->name == dest) v = temp;
        temp = temp->nextNode;
    }

    if (u && v) {
        Edge* e1 = new Edge{v, u->firstEdge};
        u->firstEdge = e1;
        Edge* e2 = new Edge{u, v->firstEdge};
        v->firstEdge = e2;
    }
}

void resetFlags(Graph &G) {
    Node* temp = G.headNode;
    while (temp) {
        temp->visited = false;
        temp = temp->nextNode;
    }
}

void dfs(Node* current, int &count) {
    if (!current || current->visited || current->isLockdown) return;
    current->visited = true;
    count++;
    Edge* e = current->firstEdge;
    while (e) {
        dfs(e->destination, count);
        e = e->nextEdge;
    }
}

int countTotalNodes(Graph &G) {
    int total = 0;
    Node* temp = G.headNode;
    while (temp) {
        total++;
        temp = temp->nextNode;
    }
    return total;
}

void checkCriticalCities(Graph &G) {
    int totalNodes = countTotalNodes(G);
    Node* currentCheck = G.headNode;
    cout << "\nAnalisis Kota Kritis\n";
    while (currentCheck) {
        currentCheck->isLockdown = true; 
        Node* startNode = (currentCheck == G.headNode) ? G.headNode->nextNode : G.headNode;      
        int reachableCount = 0;
        resetFlags(G);
        if (startNode) dfs(startNode, reachableCount);
        if (reachableCount < (totalNodes - 1)) {
            cout << "[PERINGATAN] Kota " << currentCheck->name << " adalah KOTA KRITIS!\n";
            cout << "-> Jika " << currentCheck->name << " lockdown, distribusi terputus.\n";
        } else {
            cout << "Kota " << currentCheck->name << " aman (redundansi oke).\n";
        }
        currentCheck->isLockdown = false; 
        currentCheck = currentCheck->nextNode;
    }
}