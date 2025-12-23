#ifndef GRAPH_H
#define GRAPH_H

struct Edge; 

struct Node {
    char name;
    bool visited;
    bool isLockdown;
    Edge* firstEdge;
    Node* nextNode;
};

struct Edge {
    Node* destination;
    Edge* nextEdge;
};

struct Graph {
    Node* headNode;
};

void initGraph(Graph &G);
Node* createNode(char name);
void insertNode(Graph &G, char name);
void addEdge(Graph &G, char src, char dest); 
void resetFlags(Graph &G);
void dfs(Node* current, int &count);
void checkCriticalCities(Graph &G);
int countTotalNodes(Graph &G);

#endif