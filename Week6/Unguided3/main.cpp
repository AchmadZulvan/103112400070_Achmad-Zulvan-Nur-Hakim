#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    infotype data;
    address P;
    string nopolHapus ="D003";

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

    
    cout << "Masukkan Nomor Polisi yang akan dihapus : " << nopolHapus << endl;
    
    deleteByNopol(L, nopolHapus); 

    
    cout << "\nDATA LIST 1" << endl;
    
    printInfo(L); 
    
    return 0;
}