#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;
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
address Search(List L, Infotype X);
void delFirst(List& L, address& P);
void delLast(List& L, address& P);
void delAfter(List& L, address Prec, address& P);
int nbList(List L);
void delList(List& L);

#endif