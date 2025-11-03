#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    infotype data;
    address P;
    string nopolHapus; 

    data = {"D001", "hitam", 90}; 
    P = alokasi(data);
    insertLast(L, P);

    data = {"D003", "merah", 70}; 
    P = alokasi(data);
    insertLast(L, P);

    data = {"D004", "kuning", 90}; 
    P = alokasi(data);
    insertLast(L, P);

    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> nopolHapus; 
    
    deleteByNopol(L, nopolHapus); 
    
    cout << "\nDATA LIST 1" << endl;
    
    printInfo(L); 
    
    return 0;
}

