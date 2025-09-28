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