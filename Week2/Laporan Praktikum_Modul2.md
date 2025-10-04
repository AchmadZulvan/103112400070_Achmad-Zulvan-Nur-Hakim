# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Achmad Zulvan Nur Hakim - 103112400070</p>

## Dasar Teori
DDasar teori mengenai manajemen memori terstruktur dalam C++ berfokus pada Array dan Pointer. Array didefinisikan sebagai koleksi elemen data sejenis yang disimpan secara berurutan, di mana konsepnya merupakan salah satu elemen dasar pemrograman. Struktur ini meluas dari Array 1 Dimensi hingga Array 3 Dimensi untuk merepresentasikan data kompleks (seperti matriks), dan secara teknis, hubungan Array dengan Pointer (sebagai implementasi pointer konstan yang memungkinkan aritmetika pointer) adalah lanjutan logis dari fondasi tersebut [1]. Sementara itu, Pointer adalah variabel khusus yang menyimpan alamat memori variabel lain, menjadikannya fitur inti yang mendukung sifat bahasa sebagai strongly typed dan berkontribusi pada keunggulan C++ dalam pembuatan berbagai jenis aplikasi [2]. Akhirnya, fitur Pointer ini juga esensial untuk implementasi fitur tingkat lanjut seperti Object-Oriented Programming (OOP) [3].
## Guided

### 1. Array 1 dimensi 

```C++
#include<iostream>
using namespace std;
int main(){
    int arr [5];
    for (int i = 0; i < 5; i++){
        cout<<"Masukkan nilai indeks ke-"<<i<<": ";
        cin>>arr[i];
    }
    int j = 0;
    while (j < 5){
        cout<< "Isi indeks ke-"<< j <<" i "<< arr[j]<< endl;
        j++;
    }
    return 0;
}
```
Program tersebut meminta pengguna memasukkan lima nilai ke dalam sebuah array dan kemudian menampilkan kembali nilai-nilai tersebut.

### 2. Array 2D 

```C++
#include<iostream>
using namespace std;

void tampilkanhasil(int arr[2][2]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };  
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};
    
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }
    
    cout<<"Hasil Penjumlahan: "<<endl;
    tampilkanhasil(arrC);

    cout<<endl;

    for (int i = 0; i < 2; i++){            
        for (int j = 0; j < 2; j++){         
            for (int k = 0; k < 2; k++){   
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout<<"Hasil Perkalian: "<<endl;
    tampilkanhasil(arrD);

    return 0;
}
```
Program ini melakukan penjumlahan dan perkalian dua buah matriks 2×2 (arrA dan arrB), menyimpan hasilnya di arrC dan arrD secara berturut-turut, dan kemudian menampilkan kedua matriks hasil tersebut.

### 3. Arrnpointer

```C++
#include <iostream>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50};
    int*ptr=arr; 
    for (int i = 0; i < 5; i++){
        cout<<"elemen array ke-"<< i+1<<" menggunakan pointer: "<<*(ptr+i)<<endl;
    }

    for (int i = 0; i < 5; i++){
        cout<<"Elemen array ke-"<< i+1 <<" menggunakan indeks: "<<arr[i]<<endl;
    }
    return 0;
}
```
Program ini mendeklarasikan sebuah array dan pointer yang menunjuk ke array tersebut, kemudian menampilkan semua elemen array tersebut dua kali, sekali melalui pointer dan sekali lagi melalui indeks array biasa.

### 4. Fungsi prosedur

```C++
#include <iostream>
using namespace std;

 int main(){
    int angka1;
    cout << "masukan angka1 : ";
    cin >> angka1;

    for (int i = 0; i  < angka1; i++){
      cout << i << " - ";
    }
    cout << endl;

    int j = 10;
    while (j > angka1){
      cout << j << " - ";
      j--;
    }

    cout << endl;
    int k = 10;
    do {
      cout << k << " - ";
    }while (k < angka1);

     return  0;
    
 }
```
Program ini mengambil sebuah input angka dari pengguna (angka1) dan kemudian mendemonstrasikan penggunaan tiga jenis loop: for, while, dan do-while.

## Unguided 

### 1. Program Menu Operasi Matriks

```C++

#include <iostream>

using namespace std;

int MatriksA[3][3] = {
    {7, 12, 22},
    {31, 6, 41},
    {15, 19, 36}
};

int MatriksB[3][3] = {
    {11, 34, 7},
    {3, 25, 41},
    {5, 18, 33}
};

void tampilMatriks(int M[3][3], const char* nama) {
    cout << nama << ":" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << M[i][j] << "\t"; 
        }
        cout << endl;
    }
}

void jmlMatriks() {
    int MatriksHasil[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            MatriksHasil[i][j] = MatriksA[i][j] + MatriksB[i][j];
        }
    }
    
    cout << "\n Penjumlahan Matriks A + B " << endl;
    tampilMatriks(MatriksHasil, "Hasil");
}

void krgMatriks() {
    int MatriksHasil[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            MatriksHasil[i][j] = MatriksA[i][j] - MatriksB[i][j];
        }
    }

    cout << "\n Pengurangan Matriks A - B " << endl;
    tampilMatriks(MatriksHasil, "Hasil");
}

void kaliMatriks() {
    int MatriksHasil[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            MatriksHasil[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                MatriksHasil[i][j] += MatriksA[i][k] * MatriksB[k][j];
            }
        }
    }
    cout << "\n Perkalian Matriks A x B " << endl;
    tampilMatriks(MatriksHasil, "Hasil");
}
int main() {
    int pilihan;
    
    cout << "------------------------------------" << endl;

    do {
        cout << "\n--- Menu Program Matriks ---" << endl;
        cout << "1. Penjumlahan Matriks" << endl;
        cout << "2. Pengurangan Matriks" << endl;
        cout << "3. Perkalian Matriks" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        
        if (!(cin >> pilihan)) {
            cout << "\nInput tidak valid. Harap masukkan angka." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            pilihan = 0;
        }

        switch (pilihan) {
            case 1:
                jmlMatriks();
                break;
            case 2:
                krgMatriks();
                break;
            case 3:
                kaliMatriks();
                break;
            case 4:
                cout << "\nProgram selesai." << endl;
                break;
        }
        cout << "------------------------------------" << endl;
    } while (pilihan != 4);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided1_1](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week2/Screenshot%20Output%20Unguided1_1.png)

##### Output 2
![Screenshot Output Unguided1_2](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week2/Screenshot%20Output%20Unguided1_2.png)

Program ini menyajikan menu interaktif yang memungkinkan pengguna untuk melakukan penjumlahan, pengurangan, dan perkalian antara dua buah matriks 3×3 (MatriksA dan MatriksB) yang telah didefinisikan.

### 2. Program Pointer untuk Menghitung Luas dan Keliling Persegi Panjang

```C++
##include <iostream>

using namespace std;

void nilaiPL(int p, int l) {
    cout << "Panjang: " << p << endl;
    cout << "Lebar: " << l << endl;
}

int main() {
    int panjang = 10;
    int lebar = 5;
    int luasAwal ; 
    int kelilingAwal; 

    int *ptrPanjang = &panjang;
    int *ptrLebar = &lebar;

    cout << "--- Nilai Awal ---" << endl;
    nilaiPL(*ptrPanjang, *ptrLebar);

    luasAwal = (*ptrPanjang) * (*ptrLebar);
    
    kelilingAwal = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "\n--- Hasil Perhitungan ---" << endl;
    cout << "Luas Persegi Panjang : " << luasAwal << endl;
    cout << "Keliling Persegi Panjang : " << kelilingAwal << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;
    
    int luasBaru = (*ptrPanjang) * (*ptrLebar);
    int kelilingBaru = 2 * ((*ptrPanjang) + (*ptrLebar));
    cout << "\n--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang Baru: " << *ptrPanjang << endl;
    cout << "Lebar Baru: " << *ptrLebar << endl;
    cout << "Luas Baru: " << luasBaru << endl;
    cout << "Keliling Baru: " << kelilingBaru << endl; 
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided2](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week2/Screenshot%20Output%20Unguided2.png)

Program  ini mendefinisikan panjang dan lebar awal persegi panjang, menggunakan pointer untuk menunjuk ke kedua variabel tersebut, kemudian menghitung dan menampilkan luas serta keliling sebelum dan setelah nilai panjang dan lebar diubah melalui pointer.

## Kesimpulan
Praktikum ini berfokus pada Array untuk mengelola koleksi data homogen, termasuk implementasi matriks. Dipelajari juga Pointer, yang menyimpan alamat memori dan vital untuk manipulasi data yang fleksibel dalam C++. Hubungan erat Array dan Pointer melalui aritmatika pointer memungkinkan akses data yang lebih dinamis. Penguasaan kedua konsep ini esensial untuk membangun struktur data dan algoritma C++ yang kompleks, seperti operasi matriks.

## Referensi
[1] Dewi, L. J. E. (2010). Media Pembelajaran Bahasa Pemrograman C++. Jurnal Pendidikan Teknologi dan Kejuruan, 7(1), 63–72. https://ejournal.undiksha.ac.id/index.php/JPTK/article/download/31/25/94
<br>[2] Amin, S. (2021). MAKALAH DASAR PEMROGRAMAN KOMPUTER “BAHASA PEMROGRAMAN C++”. OSF Preprints. https://osf.io/f697b/download/?format=pdf
<br>[3] Hossain, S., Islam, S. M., Khan, H. A., Rifat, Z., & Uddin, M. A. (2023). An Overview on C++ Programming Language. ResearchGate.https://www.researchgate.net/publication/371166631_An_Overview_on_C_Programming_Language
