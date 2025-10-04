
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
    cout << "\n Perkalian Matriks A x B ===" << endl;
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