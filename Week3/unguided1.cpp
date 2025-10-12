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