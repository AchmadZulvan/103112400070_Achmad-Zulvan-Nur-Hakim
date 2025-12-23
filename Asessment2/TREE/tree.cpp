#include "tree.h"
#include <iostream>
using namespace std;

void createTree(Node* &root) {
    root = NULL;
}

bool isEmpty(Node* root) {
    return root == NULL;
}

Node* newNode(string nama, float berat, string tier) {
    Node* node = new Node();
    node->namaMember = nama;
    node->beratBadan = berat;
    node->tierMember = tier;
    node->left = node->right = NULL;
    return node;
}

Node* insertNode(Node* root, string nama, float berat, string tier) {
    if (root == NULL) {
        return newNode(nama, berat, tier);
    }
    if (berat < root->beratBadan) {
        root->left = insertNode(root->left, nama, berat, tier);
    } else if (berat > root->beratBadan) {
        root->right = insertNode(root->right, nama, berat, tier);
    }
    return root;
}

void printData(Node* node) {
    if (node == NULL) {
        cout << "Tidak Ada" << endl;
        return;
    }
    cout << "Nama Member  : " << node->namaMember << endl;
    cout << "Berat Badan  : " << node->beratBadan << endl;
    cout << "Tier Member  : " << node->tierMember << endl;
}

void searchBeratBadan(Node* curr, float berat, Node* parent) {
    if (curr == NULL) {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }

    if (curr->beratBadan == berat) {
        cout << "Data ditemukan" << endl;
        cout << "Node Yang Dicari" << endl;
        printData(curr);
        cout << "" << endl;
        cout << "Parent" << endl;
        if (parent != NULL) {
            printData(parent);
            cout << "" << endl;
            Node* sibling = (parent->left == curr) ? parent->right : parent->left;
            if (sibling != NULL) {
                cout << "Sibling" << endl;
                printData(sibling);
            } else {
                cout << "Tidak Memiliki Sibling" << endl;
            }
        } else {
            cout << "Root (Tidak memiliki parent)" << endl;
        }
        cout << "" << endl;
        cout << "Child Kiri" << endl;
        printData(curr->left);
        cout << "" << endl;
        cout << "Child Kanan" << endl;
        printData(curr->right);
        cout << "" << endl;
    } 
    else if (berat < curr->beratBadan) {
        searchBeratBadan(curr->left, berat, curr);
    } else {
        searchBeratBadan(curr->right, berat, curr);
    }
}

void mostLeft(Node* root) {
    if (root == NULL) return;
    Node* curr = root;
    while (curr->left != NULL) curr = curr->left;
    cout << "MostLeft : " << curr->beratBadan << endl;
}

void mostRight(Node* root) {
    if (root == NULL) return;
    Node* curr = root;
    while (curr->right != NULL) curr = curr->right;
    cout << "MostRight : " << curr->beratBadan << endl;
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->beratBadan << " - ";
        inOrder(root->right);
    }
}