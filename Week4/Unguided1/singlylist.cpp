#include "singlyList.h"
#include <iostream>
using namespace std;
const address NIL = nullptr;

void CreateList(List& L) {
    L.First = NIL;
}
address Alokasi(Infotype X) {
    address P = new Elmlist;
    if (P != NIL) {
        P->info = X;
        P->next = NIL;
    }
    return P;
}
void DeAlokasi(address& P) {
    delete P;
    P = NIL;
}
void printInfo(List L) {
    address P = L.First;
    cout << "Isi List: ";
    if (P == NIL) {
        cout << "List Kosong (Empty)";
    } else {
        while (P != NIL) {
            cout << P->info << " ";
            P = P->next;
        }
    }
    cout << endl;
}
void insFirst(List& L, address P) {
    if (P != NIL) {
        P->next = L.First;
        L.First = P;
    }
}