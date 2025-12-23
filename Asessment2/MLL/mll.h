#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;
struct Film {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
};

typedef struct NodeChild *adrChild;
struct NodeChild {
    Film info;
    adrChild next;
    adrChild prev;
};

struct ListChild {
    adrChild first;
    adrChild last;
};
struct Genre {
    string IDGenre;
    string namaGenre;
};
typedef struct NodeParent *adrParent;
struct NodeParent {
    Genre info;
    adrParent next;
    adrParent prev;
    ListChild childs; 
};
struct ListParent {
    adrParent first;
    adrParent last;
};
void createListParent(ListParent &LP);
void createListChild(ListChild &LC);
adrParent alokasiNodeParent(string ID, string nama);
adrChild alokasiNodeChild(string ID, string judul, int durasi, int tahun, float rating);
void dealokasiNodeParent(adrParent &P);
void dealokasiNodeChild(adrChild &C);
void insertFirstParent(ListParent &LP, adrParent P);
void insertLastChild(ListChild &LC, adrChild C);
void deleteAfterParent(ListParent &LP, adrParent prec, adrParent &P);
void hapusListChild(ListChild &LC);
void searchFilmRatingRange(ListParent LP, float minRating, float maxRating);
void printMLL(ListParent LP);

#endif