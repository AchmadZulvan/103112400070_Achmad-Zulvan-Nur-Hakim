#include <iostream>

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