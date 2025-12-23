#include "mll.h"
#include <iostream>
using namespace std;

void createListParent(ListParent &LP) {
    LP.first = NULL;
    LP.last = NULL;
}
void createListChild(ListChild &LC) {
    LC.first = NULL;
    LC.last = NULL;
}
adrParent alokasiNodeParent(string ID, string nama) {
    adrParent P = new NodeParent;
    P->info.IDGenre = ID;
    P->info.namaGenre = nama;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->childs);
    return P;
}
adrChild alokasiNodeChild(string ID, string judul, int durasi, int tahun, float rating) {
    adrChild C = new NodeChild;
    C->info.IDFilm = ID;
    C->info.judulFilm = judul;
    C->info.durasiFilm = durasi;
    C->info.tahunTayang = tahun;
    C->info.ratingFilm = rating;
    C->next = NULL;
    C->prev = NULL;
    return C;
}
void dealokasiNodeParent(adrParent &P) {
    delete P;
    P = NULL;
}
void dealokasiNodeChild(adrChild &C) {
    delete C;
    C = NULL;
}
void insertFirstParent(ListParent &LP, adrParent P) {
    if (LP.first == NULL) {
        LP.first = P;
        LP.last = P;
    } else {
        P->next = LP.first;
        LP.first->prev = P;
        LP.first = P;
    }
}
void insertLastChild(ListChild &LC, adrChild C) {
    if (LC.first == NULL) {
        LC.first = C;
        LC.last = C;
    } else {
        C->prev = LC.last;
        LC.last->next = C;
        LC.last = C;
    }
}
void hapusListChild(ListChild &LC) {
    adrChild Q;
    while (LC.first != NULL) {
        Q = LC.first;
        LC.first = LC.first->next;
        dealokasiNodeChild(Q);
    }
    LC.last = NULL;
}
void deleteAfterParent(ListParent &LP, adrParent prec, adrParent &P) {
    if (prec == NULL || prec->next == NULL) return;
    P = prec->next;
    hapusListChild(P->childs); 
    if (P == LP.last) {
        LP.last = prec;
        prec->next = NULL;
    } else {
        prec->next = P->next;
        P->next->prev = prec;
    }
    P->next = NULL;
    P->prev = NULL;
}

void searchFilmRatingRange(ListParent LP, float minRating, float maxRating) {
    cout << "Data Film ditemukan " << minRating << " - " << maxRating << " :" << endl;
    adrParent P = LP.first;
    int pIdx = 1;
    while (P != NULL) {
        adrChild C = P->childs.first;
        int cIdx = 1;
        while (C != NULL) {
            if (C->info.ratingFilm >= minRating && C->info.ratingFilm <= maxRating) {
                cout << "Data Film " << endl;
                cout << "Judul Film : " << C->info.judulFilm << endl;
                cout << "Posisi dalam list child : posisi ke-" << cIdx << endl;
                cout << "ID Film : " << C->info.IDFilm << endl;
                cout << "Durasi Film : " << C->info.durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << C->info.tahunTayang << endl;
                cout << "Rating Film : " << C->info.ratingFilm << endl;
                cout << "Data Genre  " << endl;
                cout << "ID Genre : " << P->info.IDGenre << endl;
                cout << "Posisi dalam list parent : posisi ke-" << pIdx << endl;
                cout << "Nama Genre : " << P->info.namaGenre << endl;
                cout << "" << endl;
            }
            C = C->next;
            cIdx++;
        }
        P = P->next;
        pIdx++;
    }
}

void printMLL(ListParent LP) {
    adrParent P = LP.first;
    int i = 1;
    while (P != NULL) {
        cout << "Parent " << i << " " << endl;
        cout << "ID Genre : " << P->info.IDGenre << endl;
        cout << "Nama Genre : " << P->info.namaGenre << endl;
        adrChild C = P->childs.first;
        int j = 1;
        while (C != NULL) {
            cout << "    Child " << j << " :" << endl;
            cout << "    ID Film : " << C->info.IDFilm << endl;
            cout << "    Judul Film : " << C->info.judulFilm << endl;
            cout << "    Durasi Film : " << C->info.durasiFilm << " menit" << endl;
            cout << "    Tahun Tayang : " << C->info.tahunTayang << endl;
            cout << "    Rating Film : " << C->info.ratingFilm << endl;
            C = C->next;
            j++;
        }
        cout << "" << endl;
        P = P->next;
        i++;
    }
}