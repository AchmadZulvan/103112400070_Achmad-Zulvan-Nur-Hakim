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