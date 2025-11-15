# <h1 align="center">Laporan Praktikum Modul 7 - Stack </h1>
<p align="center">Achmad Zulvan Nur Hakim - 103112400070</p>

## Dasar Teori
Bayangkan Stack itu seperti tumpukan nampan di kantin. Aturan mainnya cuma satu: LIFO (Last-In, First-Out) [1]. Artinya, nampan terakhir yang ditaruh di paling atas (Push), itu juga yang harus pertama kali diambil (Pop) [1]. Semua kegiatan (menambah atau mengambil data) cuma boleh dilakukan di puncak (Top) tumpukan saja. Dalam praktiknya, Stack bisa dibangun menggunakan dua cara: menggunakan Array (Stack Statis), yang ukurannya kaku dan berisiko overflow jika datanya kebanyakan; atau menggunakan Linked List (Stack Dinamis) [2].Kebanyakan programmer lebih suka menggunakan Linked List untuk implementasi Stack karena sifatnya dinamis, artinya ukurannya bisa memanjang dan memendek sesuai kebutuhan, sehingga mengurangi risiko overflow [3]. Keuntungan lainnya, operasi Push dan Pop pada Stack yang berbasis Linked List sangatlah cepat, hanya memerlukan waktu O(1) (waktu konstan), karena data selalu ditangani di ujung list yang sama [1]. Singkatnya, Stack adalah struktur penting yang menjamin data diolah secara berurutan, menjadikannya fondasi untuk banyak fitur penting dalam pemrograman, seperti pelacakan pemanggilan fungsi atau fitur undo/redo.
## Guided

### 1. Guided1
## Stack.h
```C++
#ifndef STACK_H
#define STACK_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef struct node* address;

struct node{
    int dataAngka;
    address next;
};

struct stack {
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka); 
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update (stack &listStack, int posisi);
void view (stack listStack);
void searchData(stack listStack, int data);

#endif
```
## Stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
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

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
## main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Program ini mengimplementasikan ADT Stack Dinamis (berbasis Linked List), di mana top menjadi penanda elemen teratas.

### 2. Guided2
## Stack.h
```C++
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl]; //Array untuk menyimpan eleman stack
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x); // Menambahkan elemen ke dalam stack
infotype pop(Stack &S); // Mengambil elemen teratas dari stack
void printInfo(Stack S);
void balikStack(Stack &S); // Membalik urutan elemen dalam stack

#endif
```
## Stack.cpp
```C++
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```
## main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```
Program ini mengimplementasikan ADT Stack Statis (berbasis Array dengan MaxEl=20).

## Unguided 

### 1. Balik Stack

## Stack.h
```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl];
    int top;
};
void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);
#endif
```
## Stack.cpp
```C++
#include "stack.h"
#include <iostream>
#include <limits>

using namespace std;
void CreateStack(Stack &S) {
    S.top = Nil;
}
bool isEmpty(Stack S) {
    return S.top == Nil;
}

bool isFull(Stack S) {
    return S.top == MaxEl - 1;
}
void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack Penuh!" << endl;
    }
}
infotype pop(Stack &S) {
    infotype x = -999;
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack Kosong!" << endl;
    }
    return x;
}
void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}
void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1); CreateStack(temp2);

        while (!isEmpty(S)) { push(temp1, pop(S)); }
        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }
        while (!isEmpty(temp2)) { push(S, pop(temp2)); }
    }
}
void pushAscending(Stack &S, infotype x) {
    Stack temp;
    CreateStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }
    push(S, x);
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}
void getInputStream(Stack &S) {
    char inputChar;    
    while (cin.get(inputChar) && inputChar != '\n') {
        if (inputChar >= '0' && inputChar <= '9') {
            infotype x = inputChar - '0';
            push(S, x);
        }
    }
}
```
## main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    cout << "Hello world!" << endl;
    printInfo(S);   
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S); 
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided1](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week7/Screenshot%20Output%20Unguided1.png)

Program ini mengimplementasikan fungsi balikStack pada Stack berbasis Array, yang membalik urutan elemen dengan memindahkan data melalui Stack temporer.

### 2. Push Ascending
## Stack.h
```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl];
    int top;
};
void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);
#endif
```
## Stack.cpp
```C++
#include "stack.h"
#include <iostream>
#include <limits>

using namespace std;
void CreateStack(Stack &S) {
    S.top = Nil;
}
bool isEmpty(Stack S) {
    return S.top == Nil;
}

bool isFull(Stack S) {
    return S.top == MaxEl - 1;
}
void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack Penuh!" << endl;
    }
}
infotype pop(Stack &S) {
    infotype x = -999;
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack Kosong!" << endl;
    }
    return x;
}
void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}
void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1); CreateStack(temp2);

        while (!isEmpty(S)) { push(temp1, pop(S)); }
        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }
        while (!isEmpty(temp2)) { push(S, pop(temp2)); }
    }
}
void pushAscending(Stack &S, infotype x) {
    Stack temp;
    CreateStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }
    push(S, x);
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}
void getInputStream(Stack &S) {
    char inputChar;    
    while (cin.get(inputChar) && inputChar != '\n') {
        if (inputChar >= '0' && inputChar <= '9') {
            infotype x = inputChar - '0';
            push(S, x);
        }
    }
}
```
## main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);
    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);
    cout << "Hello world!" << endl;
    printInfo(S); 
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S); 
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided2](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week7/Screenshot%20Output%20Unguided2.png)

Program ini mengimplementasikan pungsi pushAscending pada Stack berbasis Array memastikan Stack selalu terurut menaik (Ascending) dari Dasar ke Top.

### 3.GetInputStream

## Stack.h
```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl];
    int top;
};
void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);
#endif
```
## Stack.cpp
```C++
#include "stack.h"
#include <iostream>
#include <limits>

using namespace std;
void CreateStack(Stack &S) {
    S.top = Nil;
}
bool isEmpty(Stack S) {
    return S.top == Nil;
}

bool isFull(Stack S) {
    return S.top == MaxEl - 1;
}
void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack Penuh!" << endl;
    }
}
infotype pop(Stack &S) {
    infotype x = -999;
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack Kosong!" << endl;
    }
    return x;
}
void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}
void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1); CreateStack(temp2);

        while (!isEmpty(S)) { push(temp1, pop(S)); }
        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }
        while (!isEmpty(temp2)) { push(S, pop(temp2)); }
    }
}
void pushAscending(Stack &S, infotype x) {
    Stack temp;
    CreateStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }
    push(S, x);
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}
void getInputStream(Stack &S) {
    char inputChar;    
    while (cin.get(inputChar) && inputChar != '\n') {
        if (inputChar >= '0' && inputChar <= '9') {
            infotype x = inputChar - '0';
            push(S, x);
        }
    }
}
```
## main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    getInputStream(S); 
    printInfo(S); 
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided3](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week7/Screenshot%20Output%20Unguided3.png)

Program ini mengimplementasikan fungsi getInputStream yang membaca stream karakter digit dari input pengguna menggunakan cin.get(), mengonversinya menjadi integer, dan me-push-nya ke Stack.

## Kesimpulan
Praktikum ini menyimpulkan bahwa stack adalah struktur data dasar yang bekerja berdasarkan prinsip LIFO (Last-In, First-Out), artinya semua aksi penambahan (Push) dan pengambilan (Pop) data wajib dilakukan hanya pada bagian puncak (Top) tumpukan. Stack dapat diimplementasikan dengan dua cara utama: Array (Statis), yang ukurannya kaku dan rentan terhadap overflow, atau Linked List (Dinamis), yang lebih fleksibel dan minim risiko overflow. Implementasi berbasis Linked List sangat efisien karena operasi Push dan Pop hanya membutuhkan kompleksitas waktu konstan $O(1)$. Selain operasi dasar, fungsionalitas lanjutan seperti balikStack (membalik urutan) atau pushAscending (memasukkan data secara terurut) dimungkinkan dengan memanfaatkan satu atau lebih Stack Temporer sebagai area kerja untuk memproses dan menyisipkan kembali data.

## Referensi
<br>[1] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH : Journal Education and Technology, 5(2), 485–496. https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263
<br>[2] Wijoyo, A., Azzahra, A., Nabila, D., Silviana, F., & Lusiyanti. (2024). Perbandingan struktur linked list dan array dalam manajemen memori. JRIIN : Jurnal Riset Informatika Dan Inovasi, 1(12), 1290–1293. https://jurnalmahasiswa.com/index.php/jriin/article/view/957
<br>[3] Anggraini, N., Zulfi, F., & Butarbutar, L. E. (2024). Menganalisis Tingkat Efisiensi Struktur Data Array Dan Linked List Untuk Mengelola Data Mahasiswa. Jurnal Kajian Ilmiah Multidisipliner, 8(10), 222–227. https://sejurnal.com/pub/index.php/jkim/article/download/4900/5677/10006

