# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>
<p align="center">Achmad Zulvan Nur Hakim - 103112400070</p>

## Dasar Teori
Single Linked List (Senarai Berantai Tunggal) merupakan salah satu bentuk struktur data linear yang fundamental, di mana elemen data tidak disimpan dalam lokasi memori yang berdekatan layaknya Array [2]. Struktur ini tersusun atas serangkaian unit yang disebut node atau simpul. Setiap node terdiri dari dua bagian utama: data yang menyimpan nilai aktual, dan sebuah pointer (penunjuk) yang menyimpan alamat memori dari node berikutnya dalam urutan [1]. Struktur ini bersifat dinamis, yang menjadikannya sangat fleksibel, terutama karena ukurannya dapat bertambah atau berkurang sesuai kebutuhan tanpa harus mengalokasikan ulang memori secara keseluruhan, tidak seperti Array yang berukuran tetap [3].Fleksibilitas Single Linked List terletak pada kemudahannya dalam operasi penyisipan (insertion) dan penghapusan (deletion) elemen data. Dalam implementasi dasar seperti struktur Stack atau Queue menggunakan Linked List, operasi penambahan dan penghapusan data di awal list (misalnya, operasi push atau pop pada Stack) dapat dilakukan secara efisien dengan kompleksitas waktu[1]. Namun, kelemahan utama struktur ini adalah dalam hal akses acak, di mana untuk mengakses elemen ke-$n$, program harus menelusuri list dari node awal secara sekuensial melalui setiap pointer hingga mencapai elemen yang diinginkan, sehingga waktu akses menjadi lebih lambat dibandingkan Array [3]. Secara keseluruhan, pemilihan Linked List atau Array sangat bergantung pada kebutuhan spesifik aplikasi, terutama seberapa sering data mengalami perubahan versus seberapa cepat data harus diakses [2].
## Guided

### 1. Guided1

```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai`
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Program ini memperagakan operasi penyisipan (insertion) pada Single Linked List.

### 2. Guided2

```C++
// list.h

//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```
```C++
// list.cpp

#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {

    List.first = Nil;
}

//pembuatan node baru
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```

```C++
// main.cpp

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program untuk memperagakan operasi penghapusan (deletion) dan manajemen list secara keseluruhan, termasuk penghitungan jumlah node.
## Unguided 

### 1. ADT Singly Linked list

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>

typedef int Infotype;
struct Elmlist;
typedef Elmlist* address;
struct Elmlist {
    Infotype info;
    address next;
};
struct List {
    address First;
};
void CreateList(List& L);
address Alokasi(Infotype X);
void DeAlokasi(address& P);
void printInfo(List L);
void insFirst(List& L, address P);
#endif
```
```C++
#include "singlyList.h"
#include <iostream>
using namespace std;
const address NIL = nullptr;

void CreateList(List& L) {
    L.First = NIL;
}
address Alokasi(Infotype X) {
    address P = new Elmlist;
    if (P != NIL) {
        P->info = X;
        P->next = NIL;
    }
    return P;
}
void DeAlokasi(address& P) {
    delete P;
    P = NIL;
}
void printInfo(List L) {
    address P = L.First;
    cout << "Isi List: ";
    if (P == NIL) {
        cout << "List Kosong (Empty)";
    } else {
        while (P != NIL) {
            cout << P->info << " ";
            P = P->next;
        }
    }
    cout << endl;
}
void insFirst(List& L, address P) {
    if (P != NIL) {
        P->next = L.First;
        L.First = P;
    }
}   
```
```C++
#include "singlyList.h"
#include <iostream>
const address NIL = nullptr;

int main() {
    List L;  
    address a1 = NIL;
    address a2 = NIL;
    address a3 = NIL;
    address a4 = NIL;
    address a5 = NIL;
   
    CreateList(L);
    a1 = Alokasi(2);
    insFirst(L, a1);
    a2 = Alokasi(0);
    insFirst(L, a2);
    a3 = Alokasi(8);
    insFirst(L, a3);
    a4 = Alokasi(12);
    insFirst(L, a4);
    a5 = Alokasi(9);
    insFirst(L, a5);
    printInfo(L); 
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided1](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week4/Screenshot%20Output%20Unguided1.png)

Program untuk mengimplementasikan operasi penyisipan Insert First secara berulang untuk membentuk Single Linked List dengan urutan nilai 9 12 8 0 2.

### 2. Penghapusan Node

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;
typedef int Infotype;
struct Elmlist;
typedef Elmlist* address;
struct Elmlist {
    Infotype info;
    address next;
};
struct List {
    address First;
};
void CreateList(List& L);
address Alokasi(Infotype X);
void DeAlokasi(address& P);
void printInfo(List L);
void insFirst(List& L, address P);
address Search(List L, Infotype X);
void delFirst(List& L, address& P);
void delLast(List& L, address& P);
void delAfter(List& L, address Prec, address& P);
int nbList(List L);
void delList(List& L);

#endif
```C++
#include "singlyList.h"
#include <iostream>

using namespace std;

const address NIL = nullptr;
void CreateList(List& L) {
    L.First = NIL;
}
address Alokasi(Infotype X) {
    address P = new Elmlist;
    if (P != NIL) {
        P->info = X;
        P->next = NIL;
    }
    return P;
}
void DeAlokasi(address& P) {
    delete P;
    P = NIL;
}
void insFirst(List& L, address P) {
    if (P != NIL) {
        P->next = L.First;
        L.First = P;
    }
}
void printInfo(List L) {
    address P = L.First;
    while (P != NIL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
address Search(List L, Infotype X) {
    address P = L.First;
    while (P != NIL && P->info != X) {
        P = P->next;
    }
    return P;
}
void delFirst(List& L, address& P) {
    P = L.First;
    if (P != NIL) {
        L.First = P->next;
        P->next = NIL; 
    }
}
void delLast(List& L, address& P) {
    address Last = L.First;
    address Prec = NIL;

    if (Last == NIL) { 
        P = NIL;
        return;
    } else if (Last->next == NIL) { 
        P = Last;
        L.First = NIL;
    } else {
        while (Last->next != NIL) {
            Prec = Last;
            Last = Last->next;
        }
        P = Last;
        Prec->next = NIL;
    }
    P->next = NIL;
}
void delAfter(List& L, address Prec, address& P) {
    if (Prec != NIL && Prec->next != NIL) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NIL;
    } else {
        P = NIL; 
    }
}
int nbList(List L) {
    address P = L.First;
    int count = 0;
    while (P != NIL) {
        count++;
        P = P->next;
    }
    return count;
}
void delList(List& L) {
    address P;
    while (L.First != NIL) {
        delFirst(L, P);
        DeAlokasi(P);
    }
}
```
```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided2](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week4/Screenshot%20Output%20Unguided2.png)

Program ini mengimplementasikan dan menguji fungsi penghapusan (delFirst, delLast, delAfter), fungsi hitung node (nbList), dan penghapusan total list (delList).

## Kesimpulan
Praktikum ini berhasil mengimplementasikan Abstract Data Type (ADT) Single Linked List dan menguji semua fungsionalitas intinya. Operasi Penyisipan dan Penghapusan (insertFirst, delLast, dll.) telah terbukti bekerja dengan memanipulasi pointer next, menegaskan sifat dinamis dari list. Efisiensi operasi list bervariasi: akses ke awal list (insertFirst, delFirst) sangat cepat dengan kompleksitas O(1) (konstan), sementara operasi yang membutuhkan penelusuran sekuensial penuh (delLast, nbList) memiliki kompleksitas O(n) (linear). Keberhasilan implementasi juga ditandai dengan manajemen memori yang tepat (Alokasi dan DeAlokasi) untuk mencegah kebocoran memori.

## Referensi
<br>[1] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH : Journal Education and Technology, 5(2), 485–496. https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263
<br>[2] Wijoyo, A., Azzahra, A., Nabila, D., Silviana, F., & Lusiyanti. (2024). Perbandingan struktur linked list dan array dalam manajemen memori. JRIIN : Jurnal Riset Informatika Dan Inovasi, 1(12), 1290–1293. https://jurnalmahasiswa.com/index.php/jriin/article/view/957
<br>[3] Anggraini, N., Zulfi, F., & Butarbutar, L. E. (2024). Menganalisis Tingkat Efisiensi Struktur Data Array Dan Linked List Untuk Mengelola Data Mahasiswa. Jurnal Kajian Ilmiah Multidisipliner, 8(10), 222–227. https://sejurnal.com/pub/index.php/jkim/article/download/4900/5677/10006
