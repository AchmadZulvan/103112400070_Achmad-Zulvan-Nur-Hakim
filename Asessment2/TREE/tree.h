#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node *left, *right;
};

void createTree(Node* &root);
bool isEmpty(Node* root);
Node* newNode(string nama, float berat, string tier);
Node* insertNode(Node* root, string nama, float berat, string tier);
void searchBeratBadan(Node* curr, float berat, Node* parent);
void mostLeft(Node* root);
void mostRight(Node* root);
void inOrder(Node* root);
void printData(Node* node);

#endif