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