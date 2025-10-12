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