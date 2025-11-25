#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H
#include <string>
using namespace std
const int MAX = 6;
struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
    float NilaiAkhir;
};
struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};
bool isEmpty(StackMahasiswa S);
bool isFull(StackMahasiswa S);
void createStack(StackMahasiswa& S);
void Push(StackMahasiswa& S, Mahasiswa data);
void Pop(StackMahasiswa& S, Mahasiswa& data);
void Update(StackMahasiswa& S, int posisi, Mahasiswa newData);
void View(StackMahasiswa S);
void SearchNilaiAkhir(StackMahasiswa S, float NilaiMin, float NilaiMax);
float hitungNilaiAkhir(float tugas, float uts, float uas);
Mahasiswa inputMahasiswa();
#endif 