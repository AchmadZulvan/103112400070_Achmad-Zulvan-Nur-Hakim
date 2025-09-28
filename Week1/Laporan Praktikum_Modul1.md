# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Achmad Zulvan Nur Hakim - 103112400070</p>

## Dasar Teori
Bahasa Pemrograman C++ adalah bahasa tingkat tinggi yang mendasar untuk membuat aplikasi, sering disebut "C with Classes" karena mendukung pemrograman berbasis objek (Object-Oriented Programming). Dikembangkan oleh Bjarne Stroustrup pada 1979 sebagai ekstensi dari Bahasa C, bahasa ini menjadi standar ISO pada 1998. C++ dipilih karena kemampuannya dalam menyediakan kinerja tinggi dan kontrol memori yang ketat , menjadikannya alat penting untuk pengembangan perangkat lunak sistem, Game, dan berbagai aplikasi lain.
Penggunaan C++ dalam perkuliahan sangat efektif untuk meningkatkan keterampilan pemrograman karena ia menuntut pemahaman mendalam tentang struktur data, algoritma, dan pemrograman berorientasi objek. Proses ini secara langsung membantu mahasiswa mengembangkan keterampilan berpikir kritis dan pemecahan masalah , serta mengajarkan penulisan kode yang efektif. Keahlian ini penting bagi mahasiswa Teknik Elektro untuk meningkatkan keterampilan transferabilitas dan beradaptasi dengan perkembangan teknologi industri.[1]
## Guided 

### 1. Guided 1

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "masukkan angka:";
    cin >> angka;
    cout << "angka yang anda masukkan adalah:" << angka << endl;
    return 0;
}
```
Menerima input bilangan bulat (angka) dari pengguna dan kemudian menampilkannya kembali ke layar.

### 2. ...

```C++
#include <iostream>
using namespace std;
int main() {
    int angka1, angka2;
    cout << "masukkan angka1 :";
    cin >> angka1;
    cout << "masukkan angka2:";
    cin >> angka2;

    cout << "penjumlahan :" << angka1 + angka2 << endl;
    cout << "pengurangan :" << angka1 - angka2 << endl;
    cout << "perkalian :" << angka1 * angka2 << endl;
    cout << "pembagian :" << angka1 / angka2 << endl;
    cout << "sisa bagi :" << angka1 % angka2 << endl;
    return 0;
}
```
Menerima input dua bilangan bulat, kemudian menghitung dan menampilkan hasil dari penjumlahan,pengurangan,perkalian,pembagian, dan sisa bagi.

### 3. ...

```C++
#include <iostream>
using namespace std;
int main() {
    int angka1, angka2;
    cout << "masukkan angka1 :";
    cin >> angka1;
    cout << "masukkan angka2:";
    cin >> angka2;

    if (angka1 < angka2) {
      cout << angka1 << " kurang dari " << angka2 << endl;
    } else {
        cout << angka1 << " lebih dari " << angka2 << endl;
        }

    if (angka1 == angka2){
       cout << angka1 << " sama dengan " << angka2 << endl;
    } else if (angka1 != angka2){
       cout << angka1 << " angka berbeda " << angka2 << endl;
    }

    int pilihan;
    cout << "MENU" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;   
    cout << "masukan pilihan: " << endl;
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "penjumlahan: " << angka1 + angka2 << endl;
            break;
        case 2:
            cout << " pengurangan: " << angka1 - angka2 << endl;
            break;
        default:
            cout << "pilihan salah" << endl;
}
    return 0;
}
```
 Menerima input dua bilangan bulat,kemudian membandingkan angka (lebih dari atau kurang dari) lalu memilih opsi (1 penjumlahan atau 2 pengurangan) dan menampilkan hasil dari opsi yang dipilih. 

### 4. ...

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
Menerima input satu bilangan bulat kemudian mendemonstrasikan tiga jenis perulangan.

### 5. ...

```C++
#include<iostream>
using namespace std;

int main(){
    const int MAX = 5;
    struct rapot{
        string nama;
        float nilai;
    };
    rapot siswa[MAX];

    for(int i = 0; i < MAX; i++){
        cout << "masukkan nama siswa : ";
        cin >> siswa[i].nama;
        cout << endl;
        cout << "masukkan nilai siswa : ";
        cin >> siswa[i].nilai;
    }

    int j = 0;
    while(j < MAX){
        cout << "nama siswa : " << siswa[j].nama << ", nilai : " << siswa[j].nilai << endl;
    }
    return 0;
}
```
Sebuah program untuk menyimpan dan menampilkan data rapor siswa.


## Unguided 

### 1. Soal 1

```C++
#include <iostream>
using namespace std;
int main(){
    float x1,x2;
    cout << "Masukaan angka pertama :";
    cin >> x1;
    cout << "Masukaan angka kedua :";
    cin >> x2;
    cout << "Hasil Penjumlahan :" << x1 + x2 << endl;
    cout << "Hasil Pengurangan :" << x1 - x2 << endl;
    cout << "Hasil Perkalian :" << x1 * x2 << endl;
    cout << "Hasil Pembagian :" << x1 / x2 << endl;
}
```
Menerima input dua bilangan real, kemudian menghitung dan menampilkan hasil dari penjumlahan,pengurangan,perkalian,dan pembagian.

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week1/Screenshot%20Output%20Unguided1.png)

Menerima input dua bilangan real, kemudian menghitung dan menampilkan hasil dari penjumlahan,pengurangan,perkalian,dan pembagian. 

### 2. Soal 2

```C++
#include <iostream>

std::string angkakekata(int x){
    std::string satuan[] = {"nol","satu","dua","tiga","empat","lima","enam","tujuh","delapan","sembilan"};
    std::string belasan[] = {"sepuluh","sebelas","dua belas","tiga belas","empat belas","lima belas", "enam belas","tujuh belas","delapan belas","sembilan belas"};
    std::string puluhan[] = {"","","dua puluh","tiga puluh","empat puluh","lima puluh", "enam puluh","tujuh puluh", "delapan puluh", "sembilan puluh"};
    if (x >= 0 && x<=9){
        return satuan[x];
    }else if(x>=10 && x<=19){
        return belasan[x-10];
    }else if(x>=20 && x<=99){
        if(x%10==0){
            return puluhan[x/10];
    }    else {
        return puluhan[x/10]+" "+satuan[x%10];
    }  
        }else if(x == 100){
        return "seratus";
    }
}
    int main(){
        int n;
        std:: cout<<"Masukkan angka (0-100):";
        std::cin>> n;
        if(n>=0 && n<=100){ 
            std::string hasil = angkakekata(n);
            std::cout << n << "=" << hasil << std::endl;
        }
        return 0;

    }

```

### Output Unguided 2 :
##### Output 1
![Screenshot Output Unguided 2](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week1/Screenshot%20Output%20Unguided2.png)

Program yang menerima input bilangan bulat dari 0-100 dan dikonversi menjadi string.

### 3. (isi dengan soal unguided 3)

```C++
#include <iostream>
using namespace std;

int main() {
    int x;
    int y = 1;  
    cout << "Masukkan angka: ";
    cin >> x;

for (int i = x; i >= 1; i--) { 
    for (int j = 1; j <= y; j++) {
            cout << " ";
        }
    for (int j = i; j >= 1; j--) {
            cout << j;
        }
        cout << "*"; 
    for (int j = 1; j <= i; j++) { 
            cout << j;
        }
        cout << endl;
        y = y + 1;
    }

for (int j = 1; j <= y; j++) {
        cout << " ";
    }
    cout << "*" << endl;
    
    return 0;
}
```
### Output Unguided 3 :

##### Output 3
![Screenshot Output Unguided 3](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week1/Screenshot%20Output%20Unguided3.png)

Menerima sebuah bilangan bulat, kemudian menggunakan perulangan bersarang untuk mencetak pola segitiga terbalik simetris yang tersusun dari spasi, angka, dan tanda bintang (*).

## Kesimpulan
Berdasarkan modul ini, telah dipelajari dan dipahami dasar-dasar C++, meliputi I/O, operator, struktur kontrol (if-else, switch-case), dan berbagai jenis perulangan (for, while, do-while), serta penggunaan struktur data dan array.

## Referensi
[1] Qobus Muhammad Fayazz Zhafar Effendi, et al. (2024). [Penerapan Pemrograman C++ dalam Pengembangan Alat. Jurnal Majemuk, 3 ](https://jurnalilmiah.org/journal/index.php/majemuk/article/download/664/483/1442)
<br>
<br>...
