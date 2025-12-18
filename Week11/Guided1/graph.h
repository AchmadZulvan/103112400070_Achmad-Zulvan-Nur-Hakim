#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct elmNode *adrNode;
typedef struct elmEdge *adrEdge;

struct elmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct elmEdge {
    adrNode node;
    adrEdge next;
};

struct graph {
    adrNode first;
};

void createGraph(graph &G);
adrNode allocateNode(infoGraph x);
void insertNode(graph &G, infoGraph x);
void connectNode(graph &G, infoGraph start, infoGraph end);
void printGraph(graph G);

#endif