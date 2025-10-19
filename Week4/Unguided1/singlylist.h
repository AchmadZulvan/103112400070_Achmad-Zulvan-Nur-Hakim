#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>

typedef int Infotype;
struct Elmlist;
typedef Elmlist* address;
struct Elmlist {
    Infotype info;
    address next;
};
struct List {
    address First;
};
void CreateList(List& L);
address Alokasi(Infotype X);
void DeAlokasi(address& P);
void printInfo(List L);
void insFirst(List& L, address P);
#endif