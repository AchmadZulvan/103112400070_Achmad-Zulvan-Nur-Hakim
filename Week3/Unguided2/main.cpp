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