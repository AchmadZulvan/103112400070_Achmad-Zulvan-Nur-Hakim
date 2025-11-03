# <h1 align="center">Laporan Praktikum Modul 6 - Duobly Linked List (Bagian Pertama)</h1>
<p align="center">Achmad Zulvan Nur Hakim - 103112400070</p>

## Dasar Teori
Double Linked List adalah modifikasi dari struktur data Linked List linear, yang dikategorikan sebagai struktur data dinamis karena alokasi memori elemen-elemennya tidak harus berdekatan (kontigu) [2]. Setiap unit data, yang disebut node, dalam Double Linked List terdiri dari tiga komponen inti: data, pointer "next" yang menunjuk pada node penerus, dan pointer "previous" yang menunjuk kembali pada node pendahulu [1]. Tambahan pointer previous ini adalah fitur pembeda utama yang memberikan list kemampuan untuk melakukan traversal (penelusuran) secara dua arah (maju dan mundur) [2].
Keunggulan struktural ini secara signifikan meningkatkan efisiensi operasi modifikasi data. Karena setiap node memiliki referensi ke pendahulu dan penerusnya, operasi penyisipan (insertion) dan penghapusan (deletion) elemen data di lokasi mana pun, termasuk di tengah list, dapat diselesaikan dengan kompleksitas waktu yang optimal, yaitu O(1) [1], [3]. Efisiensi ini menjadi keunggulan utama struktur ini, terutama dibandingkan dengan Single Linked List dan Array yang memerlukan penelusuran list dari awal untuk menghapus node tengah. Namun, perlu dicatat bahwa setiap node membutuhkan memori ekstra untuk menyimpan pointer previous, yang menghasilkan overhead memori yang lebih tinggi per elemen dibandingkan dengan Single Linked List [2].
## Guided

### 1. Guided1
## listMakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```
## listMakanan.cpp
```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodeNext) tidak valid!" << endl;
        }
    }
}
```
## main.cpp
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```
Program ini mengimplementasikan Doubly Linked List untuk mengelola data makanan.Fungsi yang diimplementasikan mencakup operasi dasar penyisipan dan pembaruan data pada list.

### 2. Guided2

## Doublylist.h
```C++
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
```
## Doublylist.cpp
```C++
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
```
## main.cpp
```C++
#include "Doublylist.h"

using namespace std;

int main() { // penggunaan fungsi-fungsi dalam Doublylist
    List L; // deklarasi list
    CreateList(L); // buat list kosong
    address P; // deklarasi pointer elemen list
    infotype data; // deklarasi variabel info kendaraan

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    cout << "DATA LIST AWAL" << endl;
    printInfo(L);


    string cariNopol = "D001";
    cout << "MENCARI NOPOL " << cariNopol << " -" << endl;
    address found = findElm(L, cariNopol); //Manggil fungsi pencarian di Doublylist.cpp
    if (found != Nil) { // Ketemu
        cout << "Ditemukan: " << found->info.nopol << ", Warna: " << found->info.warna << endl << endl;
    } else {
        cout << cariNopol << " tidak ditemukan." << endl << endl;
    }

    string hapusNopol = "D003";
    cout << "MENGHAPUS NOPOL " << hapusNopol << " -" << endl;
    deleteByNopol(L, hapusNopol); //Manggil fungsi delete di Doublylist.cpp
    cout << endl;

    cout << "DATA LIST SETELAH HAPUS" << endl;
    printInfo(L);

    // Contoh delete elemen pertama
    cout << "MENGHAPUS ELEMEN PERTAMA " << endl;
    deleteByNopol(L, L.first->info.nopol); //Menghapus elemen pertama
    cout << endl;
    printInfo(L);


    return 0;
}
```
Program ini Program ini mengimplementasikan Doubly Linked List untuk mengelola data kendaraan.Fungsi utama yang diimplementasikan adalah penyisipan di akhir, pencarian berdasarkan nomor polisi, dan penghapusan elemen berdasarkan nomor polisi.
## Unguided 

### 1. Doubly Linked List

## Doublylist.h
```C++
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
```
## Doublylist.cpp
```C++
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
```
## main.cpp
```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided1](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week6/Screenshot%20Output%20Unguided1.png)

Program ini mengimplementasikan Doubly Linked List di mana data kendaraan diinput oleh pengguna.

### 2. Cari Elemen

## Doublylist.h
```C++
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
```
## Doublylist.cpp
```C++
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
```
## main.cpp
```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided2](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week6/Screenshot%20Output%20Unguided2.png)

Program ini mengimplementasikan fungsi pencarian pada Doubly Linked List. List diinisialisasi dengan data kendaraan tetap, dan pengguna diminta memasukkan Nomor Polisi yang dicari.

### 3.Hapus Elemen

## Doublylist.h
```C++
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
```
## Doublylist.cpp
```C++
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
```
## main.cpp
```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided3](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week6/Screenshot%20Output%20Unguided3.png)

Program ini mengimplementasikanfungsi penghapusan elemen berdasarkan Nomor Polisi pada Doubly Linked List.

## Kesimpulan
Praktikum ini menyimpulkan Doubly Linked List merupakan pilihan optimal dalam pemrograman ketika aplikasi menuntut akses dan modifikasi yang cepat pada elemen-elemen di tengah list serta kemampuan untuk menjelajahi data secara bolak-balik, menjadikannya sangat cocok untuk manajemen data dinamis.

## Referensi
<br>[1] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH : Journal Education and Technology, 5(2), 485–496. https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263
<br>[2] Wijoyo, A., Azzahra, A., Nabila, D., Silviana, F., & Lusiyanti. (2024). Perbandingan struktur linked list dan array dalam manajemen memori. JRIIN : Jurnal Riset Informatika Dan Inovasi, 1(12), 1290–1293. https://jurnalmahasiswa.com/index.php/jriin/article/view/957
<br>[3] Anggraini, N., Zulfi, F., & Butarbutar, L. E. (2024). Menganalisis Tingkat Efisiensi Struktur Data Array Dan Linked List Untuk Mengelola Data Mahasiswa. Jurnal Kajian Ilmiah Multidisipliner, 8(10), 222–227. https://sejurnal.com/pub/index.php/jkim/article/download/4900/5677/10006


