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
void insFirst(List& L, address P) {
    if (P != NIL) {
        P->next = L.First;
        L.First = P;
    }
}
void printInfo(List L) {
    address P = L.First;
    while (P != NIL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
address Search(List L, Infotype X) {
    address P = L.First;
    while (P != NIL && P->info != X) {
        P = P->next;
    }
    return P;
}
void delFirst(List& L, address& P) {
    P = L.First;
    if (P != NIL) {
        L.First = P->next;
        P->next = NIL; 
    }
}
void delLast(List& L, address& P) {
    address Last = L.First;
    address Prec = NIL;

    if (Last == NIL) { 
        P = NIL;
        return;
    } else if (Last->next == NIL) { 
        P = Last;
        L.First = NIL;
    } else {
        while (Last->next != NIL) {
            Prec = Last;
            Last = Last->next;
        }
        P = Last;
        Prec->next = NIL;
    }
    P->next = NIL;
}
void delAfter(List& L, address Prec, address& P) {
    if (Prec != NIL && Prec->next != NIL) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NIL;
    } else {
        P = NIL; 
    }
}
int nbList(List L) {
    address P = L.First;
    int count = 0;
    while (P != NIL) {
        count++;
        P = P->next;
    }
    return count;
}
void delList(List& L) {
    address P;
    while (L.First != NIL) {
        delFirst(L, P);
        DeAlokasi(P);
    }
}