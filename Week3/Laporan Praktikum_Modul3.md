# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Achmad Zulvan Nur Hakim - 103112400070</p>

## Dasar Teori
ADT berfungsi sebagai model konseptual yang memisahkan definisi logis sebuah tipe data (apa yang dilakukan) dari implementasi teknisnya (bagaimana itu dilakukan). Realisasi praktis ADT dalam C++ secara langsung mengacu pada fitur-fitur yang mendukung OOP, seperti Class, Object, Encapsulation (Pembungkusan), dan Abstraction [1]. Secara spesifik, prinsip Abstraction dan Encapsulation dari OOP adalah inti dari ADT, di mana detail internal (data) disembunyikan dan hanya fungsionalitas publik yang diperlihatkan kepada pengguna. Konstruksi ADT yang solid ini diperkuat oleh sifat C++ sebagai bahasa strongly typed, yang mewajibkan deklarasi tipe data yang ketat dan konsisten. Sifat strongly typed tersebut sangat penting untuk menjamin integritas data yang di-encapsulate di dalam ADT, sehingga berkontribusi pada keunggulan C++ dalam pembuatan berbagai jenis aplikasi [2].
## Guided

### 1. Mahasiswa (Modular) 

```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H

//definisi tipe (struct)
struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

//deklarasi primitif(fungsi)
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif
```

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Input NIM: "; 
    cin >> m.nim;
    cout << "Input Nilai 1: "; 
    cin >> m.nilai1;
    cout << "Input Nilai 2: "; 
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}
```
```C++
#include<iostream>
#include "mahasiswa.h"
#include <cstdlib>

using namespace std;

int main() {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "rata-rata nilai adalah: " << rata2 (mhs) << endl;
    system("pause");

 return 0;
}
```
Program ini mengimplementasikan konsep modularitas dengan memisahkan definisi struct dan deklarasi fungsi (mahasiswa.h), implementasi fungsi (mahasiswa.cpp yang tidak ditampilkan namanya), dan fungsi utama (main.cpp yang tidak ditampilkan namanya) untuk menginput data mahasiswa dan menghitung rata-ratanya.

### 2. Mahasiswa (Non Modular)

```C++
#include <iostream>
using namespace std;
struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};
void inputMhs(mahasiswa &m) {
    cout << "Input NIM: "; 
    cin >> m.nim;
    cout << "Input Nilai 1: "; 
    cin >> m.nilai1;
    cout << "Input Nilai 2: "; 
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}
int main() {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "rata-rata nilai adalah: " << rata2 (mhs) << endl;
    system("pause");

 return 0;
}
```
Program untuk menyimpan NIM dan dua nilai, kemudian menghitung dan menampilkan rata-rata kedua nilai tersebut.

## Unguided 

### 1. Program Data Mahasiswa

```C++

#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama, nim;
    float uts, uas, tugas, nilai;
};

float nilaiAkhir(float uts, float uas, float tugas) {
    return (0.3f * uts) + (0.4f * uas) + (0.3f * tugas);
}

int main() {
    const int MAX = 10;
    Mahasiswa dataMhs[MAX];
    int jmlData = 0;
    char lanjut = 'y';

    while (jmlData < MAX && (lanjut == 'y' || lanjut == 'Y')) {
        cout << "\n=== Mahasiswa ke-" << jmlData + 1 << " ===" << endl;
        cout << "Nama   : ";
        cin >> dataMhs[jmlData].nama;
        cout << "NIM    : ";
        cin >> dataMhs[jmlData].nim;
        cout << "UTS    : ";
        cin >> dataMhs[jmlData].uts;
        cout << "UAS    : ";
        cin >> dataMhs[jmlData].uas;
        cout << "Tugas  : ";
        cin >> dataMhs[jmlData].tugas;

        dataMhs[jmlData].nilai = nilaiAkhir(
            dataMhs[jmlData].uts,
            dataMhs[jmlData].uas,
            dataMhs[jmlData].tugas
        );
        
        cout << "Nilai Akhir = " << dataMhs[jmlData].nilai << endl;

        jmlData++;

        if (jmlData < MAX) {
            cout << "Input lagi? (y/n): ";
            cin >> lanjut;
        }
    }
        
    cout << "\nInput selesai. Jumlah data tersimpan: " << jmlData << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided1_1](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week2/Screenshot%20Output%20Unguided1_1.png)

Program untuk menginput data (nama, NIM, nilai UTS, UAS, dan Tugas) mahasiswa secara berulang hingga maksimal 10 data, kemudian menghitung dan menampilkan nilai akhir.

### 2. Program Implementasi ADT 

```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <string>
using namespace std;
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};


pelajaran buatMapel(const string& nama, const string& kode);

void tampilMapel(const pelajaran& pel);

#endif
```
```C++
#include "pelajaran.h" 
#include <iostream>
#include <string>
using namespace std;
pelajaran buatMapel(const string& nama, const string& kode) {
    pelajaran p;
    p.namaMapel = nama;
    p.kodeMapel = kode;
    return p;
}

void tampilMapel(const pelajaran& pel) {
    cout << "Nama Matkul : " << pel.namaMapel << endl;
    cout << "Kode Matkul : " << pel.kodeMapel << endl;
}
```
```C++
#include "pelajaran.h" 
#include <iostream>
#include <string>

using namespace std;

int main() {
    string namaMapel = "Struktur Data";
    string kodeMapel = "STD";

    pelajaran pel = buatMapel(namaMapel, kodeMapel);
    
    tampilMapel(pel);
    
    return 0;
} 
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided2](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week2/Screenshot%20Output%20Unguided1_1.png)

Pprogram tersebut mengimplementasikan konsep modularitas dengan struct untuk membuat tipe data pelajaran yang menyimpan nama dan kode mata pelajaran, lalu menampilkannya di fungsi main.

### 3.Program tukar Array dengan Pointer

```C++
#include <iostream>

using namespace std;

void tampilkan(const int M[3][3], const char* label);
void tukarArrayptr(int M1[3][3], int M2[3][3]);
void tukarNilaiptr(int *ptr1, int *ptr2); 

int main() {
    
    int MatriksA[3][3] = {
        {3, 2, 1},
        {4, 6, 5},
        {7, 9, 8}
    };
    
    int MatriksB[3][3] = {
        {12, 10, 11},
        {16, 15, 13},
        {14, 17, 19}
    };
        
    cout << "===== Matriks Awal =====" << endl;
    tampilkan(MatriksA, "Matriks A ");
    tampilkan(MatriksB, "Matriks B ");
    
 
    cout << "\nMelakukan penukaran SEMUA elemen Matriks A dan B..." << endl;
    tukarArrayptr(MatriksA, MatriksB); 
    
    cout << "\n--- Matriks Akhir ---" << endl;
    tampilkan(MatriksA, "Matriks A ");
    tampilkan(MatriksB, "Matriks B "); 

    return 0;
}

void tampilkan(const int M[3][3], const char* label) {
    cout << "\n" << label << ":" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArrayptr(int M1[3][3], int M2[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tukarNilaiptr(&M1[i][j], &M2[i][j]);
        }
    }
}
void tukarNilaiptr(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided3](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week2/Screenshot%20Output%20Unguided1_1.png)

Program untuk menukar seluruh elemen antara dua buah matriks 3×3 (MatriksA dan MatriksB) secara pass-by-pointer melalui fungsi tukarNilaiptr yang dipanggil berulang di dalam fungsi tukarArrayptr..

## Kesimpulan
Praktikum ini berfokus pada implementasi Abstract Data Type (ADT) melalui pemrograman C++, yang menekankan konsep modularitas, struktur data, dan penggunaan pointer. Implementasi modular pada ADT menunjukkan pemisahan yang jelas antara definisi logis (antarmuka) dan implementasi teknis (detail), yang merupakan prinsip inti dari Abstraction dan Encapsulation dalam Object-Oriented Programming (OOP). Selain itu, praktikum juga menguatkan pemahaman tentang manipulasi data melalui array dan struct, serta menunjukkan bagaimana pointer digunakan secara efektif untuk melakukan operasi pass-by-reference, seperti menukar elemen matriks, yang memastikan efisiensi dalam pengelolaan memori dan modifikasi data secara langsung.

## Referensi
<br>[1] Hossain, S., Islam, S. M., Khan, H. A., Rifat, Z., & Uddin, M. A. (2023). An Overview on C++ Programming Language. ResearchGate.https://www.researchgate.net/publication/371166631_An_Overview_on_C_Programming_Language
<br>[2] Amin, S. (2021). MAKALAH DASAR PEMROGRAMAN KOMPUTER “BAHASA PEMROGRAMAN C++”. OSF Preprints. https://osf.io/f697b/download/?format=pdf
