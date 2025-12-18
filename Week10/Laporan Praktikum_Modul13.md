# <h1 align="center">Laporan Praktikum Modul 13 - Multi Linked List </h1>
<p align="center">Achmad Zulvan Nur Hakim - 103112400070</p>

## Dasar Teori
Multi Linked List (MLL) adalah struktur data berlapis yang menghubungkan node utama ke node sekunder melalui lebih dari satu pointer, sehingga memfasilitasi representasi relasi satu-ke-banyak atau banyak-ke-banyak. Seperti pada studi Stack dengan pendekatan linked list [1], MLL memanfaatkan alokasi memori dinamis untuk menambah node tanpa batasan ukuran awal serta memungkinkan operasi push/pop antar level yang tetap terjaga kompleksitasnya di O(1) pada masing-masing rantai. Perbandingan linked list dengan array [2] menegaskan bahwa linked list lebih efisien dalam operasi sisip/hapus karena tidak memerlukan shifting data; keunggulan ini semakin penting pada MLL yang sering memodifikasi relasi antar node. Pada pengelolaan data mahasiswa [3], penggunaan linked list terbukti adaptif terhadap variasi ukuran data; MLL memperluas manfaat ini dengan memisahkan data utama (misal entitas mahasiswa) dan data terkait (misal mata kuliah) sehingga pencarian terarah pada sub-list tertentu dapat menurunkan overhead traversal dan menjaga penggunaan memori tetap fleksibel. Dengan desain pointer ganda atau lebih, MLL memungkinkan modularitas data, menjaga konsistensi referensi antar level, dan meningkatkan locality dalam operasi akses terstruktur.
## Guided

### 1. Guided1
## multilist.h
```C++
#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
using namespace std;

typedef struct nodeParent *NodeParent; //alias pointer ke struct nodeParent
typedef struct nodeChild *NodeChild;   //alias pointer ke struct nodeChild

struct  nodeChild{ //node child
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};

struct listAnak{ //list child
    NodeChild first;    
    NodeChild last;
};

struct nodeParent{ //node parent
 string idKategoriMakanan;
 string namaKategoriMakanan;
 NodeParent next;
 NodeParent prev;
 listAnak L_Anak; //list child
};

struct listInduk{ //list parent
    NodeParent first;
    NodeParent last;
};

//create list 
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &Lanak);

//alokasi &d elokasi parent
NodeParent alokasiNodeParent(string idkategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &NodeInduk);

//alokasi & delokasi child
NodeChild alokasiNodeChild(string idmakanan, string namamakanan);
void dealokasiNodeChild(NodeChild &NodeAnak);

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev); 
void findChildByID(listInduk &LInduk, string IDCari);

//operasi print
void printStrukturMLL(listInduk &LInduk);

#endif
```
## multilist.cpp
```C++
#include "multilist.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & delaokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}
void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}
```
## main.cpp
```C++
#include "multilist.h"
#include <iostream>
using namespace std;

int main(){
    //1.instalasi List
    listInduk LInduk;
    createListInduk(LInduk);

    //2.membuat Data Parent (kategori makanan)
    NodeParent k01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, k01);
    NodeParent k02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, k02);
    NodeParent k03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, k03);
    cout<<endl;

    //3.masukkan Data Child (menu makanan) ke kategori tertentu
    //-->isi kategori makanan berat (k01)
    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng");
    insertLastChild(k01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(k01->L_Anak, M02);  
    //--> isi kategori minuman (k02)
    NodeChild D02 = alokasiNodeChild("D02", "Jus Alpukat");
    insertLastChild(k02->L_Anak, D02);
    NodeChild D03 = alokasiNodeChild("D03", "Jus Alpukat");
    insertLastChild(k02->L_Anak, D03);
    //--> isi kategori dessert (k03)
    NodeChild S01 = alokasiNodeChild("DS01", "Puding Coklat");
    insertLastChild(k03->L_Anak, S01);
    cout << endl;  

    //4.print mll setelah insert-insert
    printStrukturMLL(LInduk);
    cout << endl;

    //5.searching node child
    findChildByID(LInduk, "D01");
    cout << endl;
    //6.delete node child
    deleteAfterChild(k01->L_Anak, M01);//menghapus node child ayam bakar madu
    cout<< endl;
    //7.delete node parent
    deleteAfterParent(LInduk, k02); //menghapus node parent minuman
    cout << endl;
    //8.print mll setelah delete
    printStrukturMLL(LInduk);
    cout << endl;
    
    return 0;
}

```
Program ini mengimplementasikan struktur data Multi Linked List untuk mengelola kategori makanan dan menu makanan terkait. Setiap node parent mewakili kategori makanan dengan atribut ID dan nama kategori, sementara setiap node child menyimpan informasi detail tentang menu makanan, termasuk ID dan nama makanan. Program ini memungkinkan penambahan, penghapusan, pencarian, dan pencetakan struktur data secara efisien.

## Unguided 

### 1. Unguided 1 :

## mll.h
```C++
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

typedef struct {
    string idGolongan;
    string namaGolongan;
} golonganHewan;

typedef struct {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
} dataHewan;

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

typedef struct listChild {
    NodeChild first;
    NodeChild last;
} listChild;

typedef struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
} nodeChild;

typedef struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
} nodeParent;

typedef struct listParent {
    NodeParent first;
    NodeParent last;
} listParent;

bool isEmptyParent(listParent LParent);
void createListParent(listParent &LParent);
NodeParent allocNodeParent(string idGol, string namaGol);
void deallocNodeParent(NodeParent &NParent);
void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

bool isEmptyChild(listChild LChild);
void createListChild(listChild &LChild);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeChild(NodeChild &NChild);
void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);
void deleteListChild(listChild &LChild);

void printMLLStructure(listParent LParent);
void searchHewanByEkor(listParent LParent, bool tail);

#endif
```
## mll.cpp
```C++
#include "mll.h"
#include <iomanip>

bool isEmptyParent(listParent LParent) {
    return LParent.first == NULL;
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent NParent = new nodeParent;
    NParent->isidata.idGolongan = idGol;
    NParent->isidata.namaGolongan = namaGol;
    NParent->next = NULL;
    NParent->prev = NULL;
    createListChild(NParent->L_Child);
    return NParent;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = NULL;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        insertFirstParent(LParent, newNParent);
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent P = LParent.first;
        
        deleteListChild(P->L_Child); 

        if (LParent.first == LParent.last) {
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = P->next;
            LParent.first->prev = NULL;
            P->next = NULL;
        }
        deallocNodeParent(P);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent P = NPrev->next;
        
        deleteListChild(P->L_Child); 

        if (P == LParent.last) {
            LParent.last = NPrev;
            NPrev->next = NULL;
        } else {
            NPrev->next = P->next;
            P->next->prev = NPrev;
            P->next = NULL;
        }
        P->prev = NULL;
        deallocNodeParent(P);
    }
}

bool isEmptyChild(listChild LChild) {
    return LChild.first == NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild NChild = new nodeChild;
    NChild->isidata.idHewan = idHwn;
    NChild->isidata.namaHewan = namaHwn;
    NChild->isidata.habitat = habitat;
    NChild->isidata.ekor = tail;
    NChild->isidata.bobot = weight;
    NChild->next = NULL;
    NChild->prev = NULL;
    return NChild;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = NULL;
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        insertFirstChild(LChild, newNChild);
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild P = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = P->next;
            LChild.first->prev = NULL;
            P->next = NULL;
        }
        deallocNodeChild(P);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild P = NPrev->next;
        if (P == LChild.last) {
            LChild.last = NPrev;
            NPrev->next = NULL;
        } else {
            NPrev->next = P->next;
            P->next->prev = NPrev;
            P->next = NULL;
        }
        P->prev = NULL;
        deallocNodeChild(P);
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void printMLLStructure(listParent LParent) {
    cout << "\n=== Multi Linked List Structure ===" << endl;
    NodeParent P = LParent.first;
    int parentCount = 1;
    while (P != NULL) {
        cout << "=== Parent " << parentCount << endl;
        cout << "ID Golongan: " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan: " << P->isidata.namaGolongan << endl;

        NodeChild C = P->L_Child.first;
        int childCount = 1;
        if (C == NULL) {
            cout << "(tidak ada child)" << endl;
        } else {
            while (C != NULL) {
                cout << "- Child " << childCount << ":" << endl;
                cout << "ID Hewan: " << C->isidata.idHewan << endl;
                cout << "Nama Hewan: " << C->isidata.namaHewan << endl;
                cout << "Habitat: " << C->isidata.habitat << endl;
                cout << "Ekor: " << (C->isidata.ekor ? 1 : 0) << endl;
                cout << fixed << setprecision(1) << "Bobot: " << C->isidata.bobot << endl;
                C = C->next;
                childCount++;
            }
        }
        P = P->next;
        parentCount++;
    }
}

void searchHewanByEkor(listParent LParent, bool tail) {
    cout << "\n=== Hasil Pencarian Hewan dengan Ekor: " << (tail ? "TRUE (1)" : "FALSE (0)") << " ===" << endl;
    NodeParent P = LParent.first;
    int parentPos = 1;

    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        int childPos = 1;

        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                cout << "Data ditemukan pada list anak dari node parent " << P->isidata.namaGolongan << " pada posisi ke-" << childPos << "!" << endl;
                cout << "--- Data Child ---" << endl;
                cout << "ID Child: " << C->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << childPos << endl;
                cout << "Nama Hewan: " << C->isidata.namaHewan << endl;
                cout << "Habitat: " << C->isidata.habitat << endl;
                cout << "Ekor: " << (C->isidata.ekor ? 1 : 0) << endl;
                cout << fixed << setprecision(1) << "Bobot: " << C->isidata.bobot << endl;

                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent: " << P->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << parentPos << endl;
                cout << "Nama golongan: " << P->isidata.namaGolongan << endl;
            }
            C = C->next;
            childPos++;
        }

        P = P->next;
        parentPos++;
    }
}
```
## main.cpp
```C++
#include "mll.h"
#include <iostream>
using namespace std;

void createInitialStructure(listParent &LP) {
    NodeParent P1 = allocNodeParent("G001", "Aves");
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    NodeParent P3 = allocNodeParent("G003", "Pisces");
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    NodeParent P5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LP, P1);
    insertLastParent(LP, P2);
    insertLastParent(LP, P3);
    insertLastParent(LP, P4);
    insertLastParent(LP, P5);

    NodeChild C1_1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    NodeChild C1_2 = allocNodeChild("AV002", "Bebek", "Air", true, 2.0);
    
    insertLastChild(P1->L_Child, C1_1);
    insertLastChild(P1->L_Child, C1_2);

    NodeChild C2_1 = allocNodeChild("M001", "Harimau", "Hutan", true, 200.0);
    NodeChild C2_2 = allocNodeChild("M003", "Gorila", "Hutan", false, 160.0);
    NodeChild C2_3 = allocNodeChild("M002", "Kucing", "Darat", true, 4.0);

    insertLastChild(P2->L_Child, C2_1);
    insertLastChild(P2->L_Child, C2_2);
    insertLastChild(P2->L_Child, C2_3);

    NodeChild C4_1 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);

    insertLastChild(P4->L_Child, C4_1);
}

int main() {
    listParent LParent;
    createListParent(LParent);
    
    cout << "---Insert ---" << endl;
    
    createInitialStructure(LParent);
    
    printMLLStructure(LParent);
    
    cout << "\n--- Search Hewan tanpa Ekor ---" << endl;
    
    searchHewanByEkor(LParent, false);
    
    cout << "\n--- Delete Node Parent G004 ---" << endl;
    
    NodeParent P_G004 = LParent.first;
    NodeParent P_Prev = NULL;
    
    while (P_G004 != NULL && P_G004->isidata.idGolongan != "G004") {
        P_Prev = P_G004;
        P_G004 = P_G004->next;
    }

    if (P_G004 != NULL) {
        if (P_G004 == LParent.first) {
            deleteFirstParent(LParent);
        } else if (P_Prev != NULL) {
            deleteAfterParent(LParent, P_Prev);
        }
        cout << "Node Parent G004 (Amfibi) berhasil dihapus." << endl;
    } else {
        cout << "Node Parent G004 tidak ditemukan." << endl;
    }
    
    printMLLStructure(LParent);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided1_1](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week10/Screenshot%20Output%20Unguided1_1.png)

##### Output 2
![Screenshot Output Unguided1_2](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week10/Screenshot%20Output%20Unguided1_2.png)
 
##### Output 2
![Screenshot Output Unguided1_3](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week10/Screenshot%20Output%20Unguided1_3.png)

Program ini mengimplementasikan struktur data Multi Linked List untuk mengelola informasi tentang golongan hewan dan data hewan terkait. Setiap node parent mewakili golongan hewan dengan atribut ID dan nama golongan, sementara setiap node child menyimpan informasi detail tentang hewan, termasuk ID, nama, habitat, keberadaan ekor, dan bobot. Program ini memungkinkan penambahan, penghapusan, pencarian, dan pencetakan struktur data secara efisien.

## Kesimpulan
Praktikum ini menunjukkan bahwa Multi Linked List efektif memodelkan relasi berlapis dengan memori dinamis, menjaga operasi sisip/hapus tetap ringan tanpa pergeseran data, serta memisahkan entitas utama dan data terkait untuk akses yang lebih terstruktur dan adaptif.

## Referensi
<br>[1] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH : Journal Education and Technology, 5(2), 485–496. https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263
<br>[2] Wijoyo, A., Azzahra, A., Nabila, D., Silviana, F., & Lusiyanti. (2024). Perbandingan struktur linked list dan array dalam manajemen memori. JRIIN : Jurnal Riset Informatika Dan Inovasi, 1(12), 1290–1293. https://jurnalmahasiswa.com/index.php/jriin/article/view/957
<br>[3] Anggraini, N., Zulfi, F., & Butarbutar, L. E. (2024). Menganalisis Tingkat Efisiensi Struktur Data Array Dan Linked List Untuk Mengelola Data Mahasiswa. Jurnal Kajian Ilmiah Multidisipliner, 8(10), 222–227. https://sejurnal.com/pub/index.php/jkim/article/download/4900/5677/10006
