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