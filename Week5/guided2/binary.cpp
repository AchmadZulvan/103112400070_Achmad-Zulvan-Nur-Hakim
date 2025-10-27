#include <iostream>
using namespace std;

//Definisi node untuk linked list
struct Node { 
    int data;      // Menyimpan nilai data
    Node* next;    // Pointer ke node selanjutnya
};

// Fungsi untuk menghitung panjang linked list
int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Fungsi binary search untuk linked list (data harus terurut)
// Parameter: head (pointer awal list), key (nilai yang dicari)
// Return: pointer ke node jika ditemukan, nullptr jika tidak
Node* binarySearch(Node* head, int key) {
    int length = getLength(head);      // Hitung panjang list
    int left = 0;
    int right = length - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;  // Cari posisi tengah
        
        // Traverse ke posisi mid
        Node* temp = head;
        for(int i = 0; i < mid; i++) {
            temp = temp->next;
        }
        
        if(temp->data == key) {           // Jika ditemukan
            return temp;
        }
        else if(temp->data < key) {       // Cari di bagian kanan
            left = mid + 1;
        }
        else {                            // Cari di bagian kiri
            right = mid - 1;
        }
    }
    return nullptr;                       // Tidak ditemukan
}

// Fungsi untuk menambahkan node baru di akhir list
void append(Node* &head, int value){
    Node *newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;  // Inisialisasi linked list kosong

    // Menambahkan elemen terurut ke linked list (penting untuk binary search!)
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    
    int key = 30;  // Nilai yang dicari
    Node* result = binarySearch(head, key); // Panggil fungsi binary search

    if(result != nullptr) {
        cout << "Nilai " << key << " ditemukan dalam linked list." << endl;
    } else {
        cout << "Nilai " << key << " tidak ditemukan dalam linked list." << endl;
    }

    return 0;
}