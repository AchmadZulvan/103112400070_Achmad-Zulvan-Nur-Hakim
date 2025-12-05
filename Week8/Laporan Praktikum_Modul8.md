# <h1 align="center">Laporan Praktikum Modul 8 - Queue </h1>
<p align="center">Achmad Zulvan Nur Hakim - 103112400070</p>

## Dasar Teori
Queue merupakan struktur data linear fundamental yang beroperasi secara ketat berdasarkan prinsip FIFO (First-In, First-Out) [1]. Struktur ini mereplikasi model antrian fisik, di mana elemen data pertama yang ditambahkan adalah elemen pertama yang diproses dan dikeluarkan. Operasi pada Queue terbatas pada dua titik akses yang berbeda: enqueue (penambahan elemen) dilakukan di ujung rear (belakang), sementara dequeue (pengambilan elemen) dieksekusi di ujung front (depan) [1].Implementasi Queue dapat dilakukan melalui Array atau Linked List [1], [2]. Implementasi menggunakan Array menghasilkan Queue Statis dengan ukuran memori yang tetap [3]. Kelemahan utama pendekatan ini adalah keterbatasan kapasitas yang berpotensi menimbulkan kondisi overflow, serta inefisiensi memori (wasted space) jika elemen sering dihapus tanpa mekanisme circular array yang memadai [2]. Sebaliknya, implementasi menggunakan Linked List menghasilkan Queue Dinamis, menawarkan fleksibilitas dan kemampuan alokasi memori yang disesuaikan dengan kebutuhan [3]. Karena penambahan dan penghapusan dilakukan di ujung yang berlawanan, Linked List memungkinkan kedua operasi utama (Enqueue dan Dequeue) dieksekusi dengan efisiensi waktu $O(1)$ (waktu konstan) [1]. Oleh karena optimalitas dan kemampuannya menangani volume data tak terbatas, implementasi Queue berbasis Linked List sering menjadi solusi yang lebih disukai dalam sistem yang memerlukan manajemen antrian berkelanjutan, seperti buffering atau penjadwalan proses (task scheduling) [2].
## Guided

### 1. Guided1
## Queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL 

#include <iostream>
using namespace std;

typedef struct node *address;
struct node {
    int dataAngka;
    address next;
} ;

struct queue {
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchQueue(queue Q, int data);

#endif
```
## Queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchQueue(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```
## main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah updateQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchQueue(Q, 4);
    searchQueue(Q, 9);

    return 0;
}
```
Program ini Mmngimplementasikan Queue Dinamis. Operasi enQueue (tambah di tail) dan deQueue (hapus di head) dilakukan melalui manipulasi pointer.

### 2. Guided2
## Queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info [MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
## Queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```
## main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main(){
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout << "\n Enqueue 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    cout << "\n Dequeue 1 elemen" <<  endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\n Enqueue 2 elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```
Program ini mengimplementasikan Queue Statis yang efisien. Menggunakan variabel count untuk cek penuh/kosong, dan head/tail bergerak melingkar menggunakan modulo(%).

## Unguided 

### 1. Alternatif 1 (head diam, tail bergerak)

## Queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;
const int NMax = 5;
const int Nil = -1; 

struct Queue {
    infotype info[NMax];
    int head;
    int tail; 
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x); 
infotype dequeue(Queue &Q);
void printInfo(Queue Q); 

#endif
```
## Queue.cpp
```C++
#include "queue.h"
#include <iostream>
#include <iomanip>

using namespace std;

void createQueue(Queue &Q){
    Q.head = Nil;
    Q.tail = Nil;
    for (int i = 0; i < NMax; i++) {
        Q.info[i] = 0;
    }
}
bool isEmptyQueue(Queue Q){
    return (Q.head == Nil);
}
bool isFullQueue(Queue Q){
    return (Q.tail == NMax - 1);
}
void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)) {
        cout << "Queue Penuh (Overflow)!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
        }
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}
infotype dequeue(Queue &Q){
    infotype temp = 0;
    if (isEmptyQueue(Q)) {
        cout << "Queue Kosong (Underflow)!" << endl;
    } else {
        temp = Q.info[Q.head];
                for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--;
        if (Q.tail == Nil) {
            Q.head = Nil;
        }
    }
    return temp;
}
void printInfo(Queue Q){
    cout << setw(1) << Q.head << " - " << setw(1) << Q.tail << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = 0; i < NMax; i++) {
            if (i >= Q.head && i <= Q.tail) {
                cout << Q.info[i] << " ";
            } else {
                cout << "  "; 
            }
        }
        cout << endl;
    }
}
```
## main.cpp
```C++
#include "queue.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided1](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week8/Screenshot%20Output%20Unguided1.png)

Program ini mengimplementasikan ADT Queue menggunakan Array dengan teknik Head Diam (Non-Circular Array)

### 2. Alternatif 2 (head bergerak, tail bergerak)
## Queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;
const int NMax = 5;
const int Nil = -1; 
const int UNDERFLOW_VALUE = -999; 

struct Queue {
    infotype info[NMax];
    int head;
    int tail; 
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x); 
infotype dequeue(Queue &Q);
void printInfo(Queue Q); 

#endif
```
## Queue.cpp
```C++
#include "queue.h"
#include <iostream>
#include <iomanip>

using namespace std;

void createQueue(Queue &Q){
    Q.head = Nil;
    Q.tail = Nil;
    for (int i = 0; i < NMax; i++) {
        Q.info[i] = 0;
    }
}
bool isEmptyQueue(Queue Q){
    return (Q.head == Nil);
}
bool isFullQueue(Queue Q){
    if (Q.head == 0 && Q.tail == NMax - 1) {
        return true;
    }
    if (Q.tail + 1 == Q.head) {
        return true;
    }
    return false;
}
void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)) {
        cout << "Queue Penuh (Overflow)!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[Q.tail] = x;
        } else {
            Q.tail = (Q.tail + 1) % NMax;
            Q.info[Q.tail] = x;
        }
    }
}
infotype dequeue(Queue &Q){
    infotype temp = UNDERFLOW_VALUE;   
    if (isEmptyQueue(Q)) {
        cout << "Queue Kosong (Underflow)!" << endl;
    } else {
        temp = Q.info[Q.head];
        
        if (Q.head == Q.tail) {
            Q.head = Nil;
            Q.tail = Nil;
        } else {
            Q.head = (Q.head + 1) % NMax;
        }
    }
    return temp;
}
void printInfo(Queue Q){   
    cout << setw(1) << Q.head << " - " << setw(1) << Q.tail << " | ";    
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = 0; i < NMax; i++) {
            bool isActive = false; 
            if (Q.head <= Q.tail) {
                if (i >= Q.head && i <= Q.tail) {
                    isActive = true;
                }
            } else {
                if (i >= Q.head || i <= Q.tail) {
                    isActive = true;
                }
            } 
            if (isActive) {
                cout << Q.info[i] << " ";
            } else {
                cout << "  "; 
            }
        }
        cout << endl;
    }
}
```
## main.cpp
```C++
#include "queue.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided2](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week8/Screenshot%20Output%20Unguided2.png)

Program ini mengimplementasikan ADT Queue menggunakan Array dengan mekanisme Circular Queue. Head dan tail bergerak maju secara melingkar (menggunakan modulo).
### 3. Alternatif 3 (head dan tail berputar)

## Queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;
const int NMax = 5;
const int Nil = -1; 


struct Queue {
    infotype info[NMax];
    int head;
    int tail; 
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x); 
infotype dequeue(Queue &Q);
void printInfo(Queue Q); 

#endif
```
## Queue.cpp
```C++
#include "queue.h"
#include <iostream>
#include <iomanip>

using namespace std;

void createQueue(Queue &Q){
    Q.head = Nil;
    Q.tail = Nil;
    for (int i = 0; i < NMax; i++) {
        Q.info[i] = 0;
    }
}

bool isEmptyQueue(Queue Q){
    return (Q.head == Nil);
}

bool isFullQueue(Queue Q){
    return ((Q.tail + 1) % NMax == Q.head);
}

void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)) {
        cout << "Queue Penuh (Overflow)!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % NMax;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)) {
        cout << "Queue Kosong !" << endl;
        return 0; 
    }

    infotype temp = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = Nil;
        Q.tail = Nil;
    } else {
        Q.head = (Q.head + 1) % NMax;
    }

    return temp;
}


void printInfo(Queue Q){
    cout << setw(1) << Q.head << " - " << setw(1) << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = 0; i < NMax; i++) {
            bool isActive = false;

            if (Q.head <= Q.tail) {
                if (i >= Q.head && i <= Q.tail)
                    isActive = true;
            } else {
                if (i >= Q.head || i <= Q.tail)
                    isActive = true;
            }

            if (isActive) cout << Q.info[i] << " ";
            else cout << "  ";
        }
        cout << endl;
    }
}

```
## main.cpp
```C++
#include "queue.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided3](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week8/Screenshot%20Output%20Unguided3.png)

Program ini mengimplementasikan ADT Queue menggunakan Array dengan mekanisme Circular Queue, yang pada dasarnya sama dengan Alternatif 2. Penamaan ini secara eksplisit merujuk pada pergerakan melingkar (head dan tail kembali ke index 0) yang diatur oleh operator modulo.

## Kesimpulan
Praktikum ini menyimpulkan bahwa meskipun ketiga mekanisme implementasi ADT Queue berbasis Array berhasil mematuhi prinsip FIFO (First-In, First-Out), mereka sangat berbeda dalam hal efisiensi waktu operasi. Implementasi Alternatif 1 (Head Diam) terbukti tidak efisien karena operasi dequeue memerlukan pergeseran (shifting) seluruh elemen yang tersisa di dalam array. Proses shifting ini menyebabkan kompleksitas waktu operasi dequeue menjadi $O(N)$ (linear, di mana N adalah jumlah elemen), menjadikannya solusi yang suboptimal untuk antrian besar. Sebaliknya, Alternatif 2 dan 3 (Circular Queue) adalah solusi berbasis Array yang sangat efisien. Mekanisme ini memungkinkan head dan tail untuk berputar (menggunakan operasi modulo), secara efektif menghilangkan kebutuhan akan pergeseran elemen. Eliminasi shifting ini memastikan bahwa operasi enqueue dan dequeue dapat diselesaikan dalam waktu konstan O(1), menjadikannya metode Array yang optimal. Selain Circular Array, Queue berbasis Linked List (seperti pada Guided 1) juga merupakan solusi optimal O(1) karena alokasi memori dinamisnya hanya memerlukan manipulasi pointer untuk operasi dasar.

## Referensi
<br>[1] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH : Journal Education and Technology, 5(2), 485–496. https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263
<br>[2] Wijoyo, A., Azzahra, A., Nabila, D., Silviana, F., & Lusiyanti. (2024). Perbandingan struktur linked list dan array dalam manajemen memori. JRIIN : Jurnal Riset Informatika Dan Inovasi, 1(12), 1290–1293. https://jurnalmahasiswa.com/index.php/jriin/article/view/957
<br>[3] Anggraini, N., Zulfi, F., & Butarbutar, L. E. (2024). Menganalisis Tingkat Efisiensi Struktur Data Array Dan Linked List Untuk Mengelola Data Mahasiswa. Jurnal Kajian Ilmiah Multidisipliner, 8(10), 222–227. https://sejurnal.com/pub/index.php/jkim/article/download/4900/5677/10006

