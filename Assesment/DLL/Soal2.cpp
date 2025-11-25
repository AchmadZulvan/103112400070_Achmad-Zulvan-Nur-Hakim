#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};
Node* head = nullptr;
Node* tail = nullptr;
void insertLast(int x) {
    Node* baru = new Node{x, nullptr, nullptr};
    if (head == nullptr) {
        head = tail = baru;
        return;
    }
    tail->next = baru;
    baru->prev = tail;
    tail = baru;
}
void deleteLast() {
    if (tail == nullptr) return;
    if (head == tail) {
        delete tail;
        head = tail = nullptr;
        return;
    }
    Node* temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
}
void viewFoward() {
    Node* p = head;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}
void reverseList() {
    Node* p = head;
    while (p != nullptr) {
        Node* temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = temp;
    }
    Node* temp = head;
    head = tail;
    tail = temp;
}
int main() {
    int pilih, x;
    do {
        cout << "1 Insert\n";
        cout << "2 Delete Last\n";
        cout << "3 View Depan\n";
        cout << "4 Reverse & View Depan\n";
        cout << "5 Keluar\n";
        cin >> pilih;
        switch (pilih) {
            case 1:
                cin >> x;
                insertLast(x);
                break;
            case 2:
                deleteLast();
                break;
            case 3:
                viewFoward();
                break;
            case 4:
                reverseList();
                viewFoward();
                break;
            case 5:
                cout << "Program Selesai\n";
                break;
            default:
                cout << "Pilihan Tidak Valid\n";
        }
    } while (pilih != 5);
    return 0;
}
