#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};
Node* head = nullptr;
void insertLast(string nama) {
    Node* baru = new Node{nama, nullptr};
    if (head == nullptr) {
        head = baru;
        return;
    }
    Node* p = head;
    while (p->next != nullptr) p = p->next;
    p->next = baru;
}
void deleteNama(string nama) {
    if (head == nullptr) return;

    if (head->nama == nama) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* p = head;
    while (p->next != nullptr && p->next->nama != nama)
        p = p->next;

    if (p->next != nullptr) {
        Node* temp = p->next;
        p->next = temp->next;
        delete temp;
    }
}
void listInfo() {
    Node* p = head;
    while (p != nullptr) {
        cout << p->nama << " ";
        p = p->next;
    }
    cout << "\n";
}
void hitungGenap() {
    int c = 0;
    Node* p = head;
    while (p != nullptr) {
        if (p->nama.length() % 2 == 0) c++;
        p = p->next;
    }
    cout << c << "\n";
}
int main() {
    int pilih;
    string nama;
    do {
        cout << "1.Insert Nama\n";
        cout << "2.Delete Nama\n";
        cout << "3.Info List\n";
        cout << "4.Hitung & Tampilkan Nama Mahasiswa(Genap)\n";
        cout << "5.Keluar\n";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cin >> nama;
                insertLast(nama);
                break;
            case 2:
                cin >> nama;
                deleteNama(nama);
                break;
            case 3:
                listInfo();
                break;
            case 4:
                hitungGenap();
                break;
            case 5:
                cout << "Program Selesai\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
                break;
        }
    } while (pilih != 5);

    return 0;
}
