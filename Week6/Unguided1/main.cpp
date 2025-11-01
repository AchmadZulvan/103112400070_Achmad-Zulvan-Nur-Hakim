#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    infotype data;
    address P;
    address found;

    cout << endl; 

    data = inputKendaraan();
    found = findElm(L, data.nopol);
    if (found == Nil) {
        P = alokasi(data);
        insertLast(L, P);
    } else {
        cout << "nomor polisi sudah terdaftar" << endl;
    }
    
    data = inputKendaraan();
    found = findElm(L, data.nopol);
    if (found == Nil) {
        P = alokasi(data);
        insertLast(L, P);
    } else {
        cout << "nomor polisi sudah terdaftar" << endl;
    }

    data = inputKendaraan();
    found = findElm(L, data.nopol);
    if (found == Nil) {
        P = alokasi(data);
        insertLast(L, P);
    } else {
        cout << "nomor polisi sudah terdaftar" << endl;
    }
    
    data = inputKendaraan();
    found = findElm(L, data.nopol);
    if (found == Nil) {
        P = alokasi(data);
        insertLast(L, P);
    } else {
        cout << "nomor polisi sudah terdaftar" << endl;
    }

    cout << "\nDATA LIST 1" << endl;
    
    printInfo(L); 
    
    return 0;
}