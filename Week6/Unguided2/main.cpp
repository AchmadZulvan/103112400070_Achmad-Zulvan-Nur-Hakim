#include "Doublylist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    CreateList(L);
    infotype data;
    address P;

    data = {"D001", "Hitam", 89};
    P = alokasi(data);
    insertLast(L, P);

    data = {"D002", "Putih", 88};
    P = alokasi(data);
    insertLast(L, P);

    data = {"D003", "Merah", 99};
    P = alokasi(data);
    insertLast(L, P);
    
    data = {"D004", "Biru", 98};
    P = alokasi(data);
    insertLast(L, P);

    string nopolCari;
    
    cout << "\nMasukkan Nomor Polisi yang dicari : ";
    cin >> nopolCari;
    
    address hasilCari = findElm(L, nopolCari);
    
    if (hasilCari != Nil) {
        cout << "\nNomor Polisi : " << hasilCari->info.nopol << endl;
        cout << "Warna        : " << hasilCari->info.warna << endl;
        cout << "Tahun        : " << hasilCari->info.thnBuat << endl;
    } else {
        cout << "Nomor Polisi " << nopolCari << " tidak ditemukan." << endl;
    }
    
    return 0;
}