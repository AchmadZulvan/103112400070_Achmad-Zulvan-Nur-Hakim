#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

typedef struct { 
    string nopol; 
    string warna;
    int thnBuat;
} kendaraan;
typedef kendaraan infotype;

typedef struct ElmList *address;
typedef struct ElmList { 
    infotype info;
    address next;
    address prev;
} ElmList;

typedef struct { 
    address First;
    address Last;
} List;

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);
void printInfo(List L);

infotype inputKendaraan();
address findElm(List L, string nopol);
void deleteByNopol(List &L, string nopol); 

#endif