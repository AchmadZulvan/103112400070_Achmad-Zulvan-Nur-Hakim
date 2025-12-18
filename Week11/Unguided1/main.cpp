#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    char nodes[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for (char c : nodes) InsertNode(G, c);

    ConnectNode(FindNode(G, 'A'), FindNode(G, 'B'));
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'C'));
    ConnectNode(FindNode(G, 'B'), FindNode(G, 'D'));
    ConnectNode(FindNode(G, 'B'), FindNode(G, 'E'));
    ConnectNode(FindNode(G, 'C'), FindNode(G, 'F'));
    ConnectNode(FindNode(G, 'C'), FindNode(G, 'G'));
    ConnectNode(FindNode(G, 'D'), FindNode(G, 'H'));
    ConnectNode(FindNode(G, 'E'), FindNode(G, 'H'));
    ConnectNode(FindNode(G, 'F'), FindNode(G, 'H'));
    ConnectNode(FindNode(G, 'G'), FindNode(G, 'H'));

    cout << "--- Struktur Graph ---" << endl;
    PrintInfoGraph(G);

    cout << "\n--- Penelusuran DFS (Mulai dari A) ---" << endl;
    ResetVisited(G);
    PrintDFS(G, FindNode(G, 'A'));
    
    cout << "\n\n--- Penelusuran BFS (Mulai dari A) ---" << endl;
    ResetVisited(G);
    PrintBFS(G, FindNode(G, 'A'));
    cout << endl;

    return 0;
}