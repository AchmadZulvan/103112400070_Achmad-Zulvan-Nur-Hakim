# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Achmad Zulvan Nur Hakim - 103112400070</p>

## Dasar Teori
Single Linked List (Senarai Berantai Tunggal) merupakan salah satu bentuk struktur data linear yang fundamental, di mana elemen data tidak disimpan dalam lokasi memori yang berdekatan layaknya Array [2]. Struktur ini tersusun atas serangkaian unit yang disebut node atau simpul. Setiap node terdiri dari dua bagian utama: data yang menyimpan nilai aktual, dan sebuah pointer (penunjuk) yang menyimpan alamat memori dari node berikutnya dalam urutan [1]. Struktur ini bersifat dinamis, yang menjadikannya sangat fleksibel, terutama karena ukurannya dapat bertambah atau berkurang sesuai kebutuhan tanpa harus mengalokasikan ulang memori secara keseluruhan, tidak seperti Array yang berukuran tetap [3].Fleksibilitas Single Linked List terletak pada kemudahannya dalam operasi penyisipan (insertion) dan penghapusan (deletion) elemen data. Dalam implementasi dasar seperti struktur Stack atau Queue menggunakan Linked List, operasi penambahan dan penghapusan data di awal list (misalnya, operasi push atau pop pada Stack) dapat dilakukan secara efisien dengan kompleksitas waktu[1]. Namun, kelemahan utama struktur ini adalah dalam hal akses acak, di mana untuk mengakses elemen ke-n, program harus menelusuri list dari node awal secara sekuensial melalui setiap pointer hingga mencapai elemen yang diinginkan, sehingga waktu akses menjadi lebih lambat dibandingkan Array [3]. Secara keseluruhan, pemilihan Linked List atau Array sangat bergantung pada kebutuhan spesifik aplikasi, terutama seberapa sering data mengalami perubahan versus seberapa cepat data harus diakses [2].
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

#endif#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil nullptr

#include <iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};
typedef buah dataBuah;
typedef struct node *address;
struct node{
    dataBuah isidata;
    address next;
};

struct linkedList{
    address first;
};

bool listEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodebaru);
void insertAfter(linkedList &List, address nodebaru, address Prev);
void insertLast(linkedList &List, address nodebaru);
void deleteFirst(linkedList &List);
void delLast(linkedList &List);
void deleteAfter(address &List, address &nodehapus, address nodeprev);
int nbList(linkedList List);
void deletelist(linkedList &List);

//materi modul 5 (part 1 update)
void updateFirst(linkedList List);
void updateLast(linkedList List);
void updateAfter(linkedList List, address prev);

#endif
```

```C++

#include "listbuah.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedList &List) {
    List.first = Nil;
}

address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
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
void delFirst(linkedList &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
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
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedList &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

//Materi Modul 5 - Update Operations
void updateFirst(linkedList List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedList List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedList List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```
```C++
#include "listbuah.h"
#include <iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC,nodeD,nodeE;   
    createList(List);

    nodeA=alokasi("jeruk",100,3000);
    nodeB=alokasi("apel",75,4000);
    nodeC=alokasi("pir",87,5000);
    nodeD=alokasi("semangka",43,11500); 
    nodeE=alokasi("durian",15,31450);

    insertFirst(List,nodeA);
    insertLast(List,nodeB);
    insertAfter(List,nodeC,nodeA);
    insertAfter(List,nodeD,nodeC);
    insertLast(List,nodeE);

    cout<<" isi list buat dilakukan insert"<<endl;
    printList(List);
    cout<<"jumlah node:"<<nbList(List)<<endl;
    cout<<endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List,nodeD);

    cout<<" isi list buah setelah dilakukan update"<<endl;
    printList(List);
    cout<<"jumlah node:"<<nbList(List)<<endl;
    cout<<endl;

    return 0;
}   
```
Program ini Program Guided 1 mengimplementasikan Single Linked List untuk mengelola data buah dengan menambahkan dan menguji operasi pembaruan pada node di posisi awal, akhir , dan setelah node tertentu, di mana efisiensi tergantung pada waktu pencarian node target.

### 2. Guided2

```C++
#include <iostream>
using namespace std;

struct Node { 
    int data;
    Node* next;
};

Node *linearSearch(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void append(Node* &head, int value){
    Node *newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    
    Node* result = linearSearch(head, 20);

    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
```
Program ini mengimplementasikan linear search sebagai metode pencarian yang paling sesuai karena sifat akses sekuensial list.
## Unguided 

### 1. Binary Search

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = nullptr;
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }
    while (last->next != nullptr)
        last = last->next;
    last->next = new_node;
}

int getLength(Node* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

Node* getNodeAt(Node* head, int index) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        if (count == index)
            return current;
        count++;
        current = current->next;
    }
    return nullptr;
}

Node* binarySearch(Node* head, int key) {
    int start = 0;
    int end = getLength(head) - 1;
    int iteration = 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        Node* midNode = getNodeAt(head, mid);
        cout << "Iterasi " << iteration << ": Mid = " << midNode->data << " (indeks tengah)";
        if (midNode->data == key) {
            cout << " -> DITEMUKAN!" << endl << endl;
            return midNode;
        } else if (midNode->data < key) {
            cout << " -> Cari di bagian kanan" << endl;
            start = mid + 1;
        } else {
            cout << " -> Cari di bagian kiri" << endl;
            end = mid - 1;
        }
        iteration++;
    }
    cout << "Tidak ada elemen tersisa" << endl << endl;
    return nullptr;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    cout << "BINARY SEARCH PADA LINKED LIST" << endl;
    Node* head = nullptr;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);
    append(&head, 60);
    cout << "Linked List yang dibuat: ";
    printList(head);
    int key;
    cout << "Mencari nilai: ";
    cin >> key;
    cout << "\nProses Pencarian:\n";
    Node* result = binarySearch(head, key);
    if (result != nullptr) {
        cout << "Hasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << result << endl;
        if (result->next != nullptr)
            cout << "Data berikutnya: " << result->next->data << endl;
        else
            cout << "Data berikutnya: NULL" << endl;
    } else {
        cout << "Hasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }
    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided1_1](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week5/Screenshot%20Output%20Unguided1_1.png)
##### Output 2
![Screenshot Output Unguided1_2](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week5/Screenshot%20Output%20Unguided1_2.png)

Program untuk mengimplementasikan operasi binary search dalam single linked list.

### 2. Linear Search

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = nullptr;
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }
    while (last->next != nullptr)
        last = last->next;
    last->next = new_node;
}

Node* linearSearch(Node* head, int key) {
    Node* current = head;
    int index = 1;
    while (current != nullptr) {
        cout << "Memeriksa node " << index << ": " << current->data;
        if (current->data == key) {
            cout << " (SAMA) -> DITEMUKAN!" << endl << endl;
            return current;
        } else {
            cout << " (tidak sama)" << endl;
        }
        current = current->next;
        index++;
    }
    cout << "Tidak ada node lagi yang tersisa" << endl << endl;
    return nullptr;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;
    Node* head = nullptr;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);
    cout << "Linked List yang dibuat: ";
    printList(head);
    int key;
    cout << "Mencari nilai: ";
    cin >> key;
    cout << "\nProses Pencarian:\n";
    Node* result = linearSearch(head, key);
    if (result != nullptr) {
        cout << "Hasil: Nilai " << key << " DITEMUKAN dalam linked list!" << endl;
        cout << "Alamat node: " << result << endl;
        if (result->next != nullptr)
            cout << "Node berikutnya: " << result->next->data << endl;
        else
            cout << "Node berikutnya: NULL" << endl;
    } else {
        cout << "Hasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }
    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided2_1](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week5/Screenshot%20Output%20Unguided2_1.png)
##### Output 2
![Screenshot Output Unguided2_2](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week5/Screenshot%20Output%20Unguided2_2.png)

Program ini mengimplementasikan operasi linear search dalam single linked list.

## Kesimpulan
Praktikum ini menyimpulkan bahwa Single Linked List adalah struktur yang efisien untuk operasi insert/delete di awal dan mendukung operasi Update data. Namun, keterbatasan utamanya adalah tidak adanya akses acak, yang membuat linear search menjadi metode pencarian yang sesuai, sementara binary search menjadi tidak praktis dan tidak efisien.

## Referensi
<br>[1] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH : Journal Education and Technology, 5(2), 485–496. https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263
<br>[2] Wijoyo, A., Azzahra, A., Nabila, D., Silviana, F., & Lusiyanti. (2024). Perbandingan struktur linked list dan array dalam manajemen memori. JRIIN : Jurnal Riset Informatika Dan Inovasi, 1(12), 1290–1293. https://jurnalmahasiswa.com/index.php/jriin/article/view/957
<br>[3] Anggraini, N., Zulfi, F., & Butarbutar, L. E. (2024). Menganalisis Tingkat Efisiensi Struktur Data Array Dan Linked List Untuk Mengelola Data Mahasiswa. Jurnal Kajian Ilmiah Multidisipliner, 8(10), 222–227. https://sejurnal.com/pub/index.php/jkim/article/download/4900/5677/10006
