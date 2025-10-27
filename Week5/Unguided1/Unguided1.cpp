#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = nullptr;
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }
    while (last->next != nullptr)
        last = last->next;
    last->next = new_node;
}

int getLength(Node* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

Node* getNodeAt(Node* head, int index) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        if (count == index)
            return current;
        count++;
        current = current->next;
    }
    return nullptr;
}

Node* binarySearch(Node* head, int key) {
    int start = 0;
    int end = getLength(head) - 1;
    int iteration = 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        Node* midNode = getNodeAt(head, mid);
        cout << "Iterasi " << iteration << ": Mid = " << midNode->data << " (indeks tengah)";
        if (midNode->data == key) {
            cout << " -> DITEMUKAN!" << endl << endl;
            return midNode;
        } else if (midNode->data < key) {
            cout << " -> Cari di bagian kanan" << endl;
            start = mid + 1;
        } else {
            cout << " -> Cari di bagian kiri" << endl;
            end = mid - 1;
        }
        iteration++;
    }
    cout << "Tidak ada elemen tersisa" << endl << endl;
    return nullptr;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    cout << "BINARY SEARCH PADA LINKED LIST" << endl;
    Node* head = nullptr;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);
    append(&head, 60);
    cout << "Linked List yang dibuat: ";
    printList(head);
    int key;
    cout << "Mencari nilai: ";
    cin >> key;
    cout << "\nProses Pencarian:\n";
    Node* result = binarySearch(head, key);
    if (result != nullptr) {
        cout << "Hasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << result << endl;
        if (result->next != nullptr)
            cout << "Data berikutnya: " << result->next->data << endl;
        else
            cout << "Data berikutnya: NULL" << endl;
    } else {
        cout << "Hasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }
    return 0;
}
