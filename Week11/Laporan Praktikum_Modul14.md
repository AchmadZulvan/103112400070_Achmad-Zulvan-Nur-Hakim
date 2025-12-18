# <h1 align="center">Laporan Praktikum Modul 14 - Graph </h1>
<p align="center">Achmad Zulvan Nur Hakim - 103112400070</p>

## Dasar Teori

Graph adalah struktur data non-linear yang terdiri dari simpul (node) dan sisi (edge) yang menghubungkan simpul-simpul tersebut, yang dapat diimplementasikan menggunakan pendekatan Adjacency Matrix (berbasis array) atau Adjacency List (berbasis linked list). Penggunaan array dalam Adjacency Matrix menawarkan akses data yang cepat namun memiliki ukuran memori yang statis, sedangkan penggunaan linked list dalam Adjacency List memberikan fleksibilitas alokasi memori yang lebih dinamis [1][3]. Pemilihan metode representasi ini sangat bergantung pada karakteristik masalah yang akan diselesaikan.

Dalam aspek manajemen memori, perbandingan antara struktur linked list dan array menjadi pertimbangan utama. Linked list dinilai lebih efisien dalam penggunaan memori untuk graph yang jarang (sparse graph) karena hanya menyimpan koneksi yang benar-benar ada, berbeda dengan array yang mengalokasikan ruang untuk seluruh kemungkinan hubungan [2]. Oleh karena itu, analisis efisiensi struktur data sangat diperlukan untuk menentukan pendekatan yang paling optimal dalam pengelolaan data graph [3].

## Guided

### 1. Guided1

#### graph.h
```cpp
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
```

#### graph_init.cpp
```cpp
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
```

#### graph_edge.cpp
```cpp
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
```

#### graph_print.cpp
```cpp
#include "graph.h"

void printGraph(graph G) {
    adrNode P = G.first;
    while (P!=NULL){
        cout<<"Node"<<P->info<<"terhubung ke:";
        adrEdge E=P->firstEdge;
        while(E!=NULL){
            cout<<E->node->info<<" ";
            E=E->next;
        }
        cout<<endl;
        P=P->next;
    }
}
```

#### main.cpp
```cpp
#include "graph.h"
#include <iostream>    

using namespace std;

int main() {
    graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    cout << "isi graph : " << endl;
    printGraph(G);

    return 0;
}
```

Program ini menampilkan representasi graph menggunakan linked list, di mana setiap node terhubung ke node lainnya sesuai dengan hubungan yang telah ditentukan.

## Unguided 

### 1. Unguided 1 :

#### graph.h
```cpp
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);
void ResetVisited(Graph &G);

#endif
```

#### graph.cpp
```cpp
#include "graph.h"
#include <queue>

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->Next != NULL) Q = Q->Next;
        Q->Next = P;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL && P->info != X) P = P->Next;
    return P;
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        adrEdge E = new ElmEdge;
        E->Node = N2;
        E->Next = N1->firstEdge;
        N1->firstEdge = E;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N == NULL || N->visited == 1) return;
    
    cout << N->info << " ";
    N->visited = 1;
    
    adrEdge E = N->firstEdge;
    while (E != NULL) {
        PrintDFS(G, E->Node);
        E = E->Next;
    }
}

void PrintBFS(Graph G, adrNode N) {
    if (N == NULL) return;
    
    queue<adrNode> Q;
    N->visited = 1;
    Q.push(N);
    
    while (!Q.empty()) {
        adrNode curr = Q.front();
        Q.pop();
        cout << curr->info << " ";
        
        adrEdge E = curr->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                Q.push(E->Node);
            }
            E = E->Next;
        }
    }
}
```

#### main.cpp
```cpp
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
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided1_1](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week11/Screenshot%20Output%20Unguided1.png)

Program ini mengimplementasikan struktur data Graph menggunakan representasi Adjacency List. Program memungkinkan pengguna untuk membuat graph, menambahkan simpul (node), dan menghubungkan simpul-simpul tersebut dengan sisi (edge) berarah. Selain itu, program ini juga menyediakan fitur penelusuran graph menggunakan algoritma Depth First Search (DFS) dan Breadth First Search (BFS).

## Kesimpulan
Praktikum ini memberikan pemahaman mendalam mengenai struktur data Graph dan implementasinya menggunakan Adjacency List. Melalui praktikum ini, mahasiswa dapat memahami konsep dasar graph seperti node dan edge, serta bagaimana merepresentasikan hubungan antar data yang kompleks. Selain itu, implementasi algoritma penelusuran DFS dan BFS memberikan wawasan tentang bagaimana menavigasi struktur graph untuk berbagai keperluan pencarian data. Penggunaan linked list dalam representasi graph menunjukkan fleksibilitas dalam pengelolaan memori dinamis dibandingkan dengan representasi matriks. 

## Referensi
<br>[1] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH : Journal Education and Technology, 5(2), 485–496. https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263
<br>[2] Wijoyo, A., Azzahra, A., Nabila, D., Silviana, F., & Lusiyanti. (2024). Perbandingan struktur linked list dan array dalam manajemen memori. JRIIN : Jurnal Riset Informatika Dan Inovasi, 1(12), 1290–1293. https://jurnalmahasiswa.com/index.php/jriin/article/view/957
<br>[3] Anggraini, N., Zulfi, F., & Butarbutar, L. E. (2024). Menganalisis Tingkat Efisiensi Struktur Data Array Dan Linked List Untuk Mengelola Data Mahasiswa. Jurnal Kajian Ilmiah Multidisipliner, 8(10), 222–227. https://sejurnal.com/pub/index.php/jkim/article/download/4900/5677/10006
