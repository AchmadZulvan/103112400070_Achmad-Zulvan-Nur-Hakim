#include <iostream>
#include "singlyList.h" 

using namespace std;

const address NIL = nullptr;

int main() {
    List L;
    address p_del = NIL;
    address Prec = NIL;
    
    CreateList(L);
    insFirst(L, Alokasi(2));
    insFirst(L, Alokasi(0));
    insFirst(L, Alokasi(8));
    insFirst(L, Alokasi(12));
    insFirst(L, Alokasi(9));
    delFirst(L, p_del);
    DeAlokasi(p_del);
    p_del = NIL; 
    delLast(L, p_del);
    DeAlokasi(p_del);
    p_del = NIL;
    Prec = Search(L, 12);
    delAfter(L, Prec, p_del);
    DeAlokasi(p_del);
    p_del = NIL;

    printInfo(L); 
    cout << "Jumlah node : " << nbList(L) << endl;
    delList(L);
    cout << "=== List Berhasil Terhapus ===" << endl; 
    cout << "Jumlah node : " << nbList(L) << endl;
    
    return 0;
}