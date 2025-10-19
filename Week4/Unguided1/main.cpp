#include "singlyList.h"
#include <iostream>
const address NIL = nullptr;

int main() {
    List L;  
    address a1 = NIL;
    address a2 = NIL;
    address a3 = NIL;
    address a4 = NIL;
    address a5 = NIL;
   
    CreateList(L);
    a1 = Alokasi(2);
    insFirst(L, a1);
    a2 = Alokasi(0);
    insFirst(L, a2);
    a3 = Alokasi(8);
    insFirst(L, a3);
    a4 = Alokasi(12);
    insFirst(L, a4);
    a5 = Alokasi(9);
    insFirst(L, a5);
    printInfo(L); 
    return 0;
}