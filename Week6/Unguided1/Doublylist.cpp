#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

infotype inputKendaraan() {
    infotype data;
    cout << "masukkan nomor polisi: ";
    cin >> data.nopol;
    cout << "masukkan warna kendaraan: ";
    cin >> data.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> data.thnBuat;
    return data;
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last; 
        (L.Last)->next = P; 
        L.Last = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.First; 
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next; 
    }
    return Nil;
}

void deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == Nil) {
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else {
        if (P == L.First && P == L.Last) {
            L.First = Nil; L.Last = Nil;
        } else if (P == L.First) {
            L.First = P->next; 
            (L.First)->prev = Nil;
        } else if (P == L.Last) {
            L.Last = P->prev; 
            (L.Last)->next = Nil; P->prev = Nil;
        } else {
            address Prec = P->prev;
            address Succ = P->next;
            Prec->next = Succ; Succ->prev = Prec;
            P->next = Nil; P->prev = Nil;
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}

void printInfo(List L) {
    address P = L.Last; 
    
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            
            P = P->prev; 
        }
    }
}