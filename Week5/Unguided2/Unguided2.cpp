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

Node* linearSearch(Node* head, int key) {
    Node* current = head;
    int index = 1;
    while (current != nullptr) {
        cout << "Memeriksa node " << index << ": " << current->data;
        if (current->data == key) {
            cout << " (SAMA) -> DITEMUKAN!" << endl << endl;
            return current;
        } else {
            cout << " (tidak sama)" << endl;
        }
        current = current->next;
        index++;
    }
    cout << "Tidak ada node lagi yang tersisa" << endl << endl;
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
    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;
    Node* head = nullptr;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);
    cout << "Linked List yang dibuat: ";
    printList(head);
    int key;
    cout << "Mencari nilai: ";
    cin >> key;
    cout << "\nProses Pencarian:\n";
    Node* result = linearSearch(head, key);
    if (result != nullptr) {
        cout << "Hasil: Nilai " << key << " DITEMUKAN dalam linked list!" << endl;
        cout << "Alamat node: " << result << endl;
        if (result->next != nullptr)
            cout << "Node berikutnya: " << result->next->data << endl;
        else
            cout << "Node berikutnya: NULL" << endl;
    } else {
        cout << "Hasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }
    return 0;
}
