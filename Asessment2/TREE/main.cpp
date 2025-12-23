#include <iostream>
#include <string>
#include "tree.h"
using namespace std;

int main() {
    Node* root;
    createTree(root);

    root = insertNode(root, "Rizkina Azizah", 60, "Basic");
    root = insertNode(root, "Hakan Ismail", 50, "Bronze");
    root = insertNode(root, "Olivia Saevali", 65, "Silver");
    root = insertNode(root, "Felix Pedrosa", 47, "Gold");
    root = insertNode(root, "Gamel Al Ghifari", 56, "Platinum");
    root = insertNode(root, "Hanif Al Faiz", 70, "Basic");
    root = insertNode(root, "Mutiara Fauziah", 52, "Bronze");
    root = insertNode(root, "Davi Ilyas", 68, "Silver");
    root = insertNode(root, "Abdad Mubarok", 81, "Gold");

    cout << "InOrder" << endl;
    inOrder(root);
    cout << "\n\n";
    mostLeft(root);
    mostRight(root);
    cout << "\n";
    searchBeratBadan(root, 70, NULL);
    return 0;
}