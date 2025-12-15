#include "mll.h"
#include <iostream>
using namespace std;

void createInitialStructure(listParent &LP) {
    NodeParent P1 = allocNodeParent("G001", "Aves");
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    NodeParent P3 = allocNodeParent("G003", "Pisces");
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    NodeParent P5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LP, P1);
    insertLastParent(LP, P2);
    insertLastParent(LP, P3);
    insertLastParent(LP, P4);
    insertLastParent(LP, P5);

    NodeChild C1_1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    NodeChild C1_2 = allocNodeChild("AV002", "Bebek", "Air", true, 2.0);
    
    insertLastChild(P1->L_Child, C1_1);
    insertLastChild(P1->L_Child, C1_2);

    NodeChild C2_1 = allocNodeChild("M001", "Harimau", "Hutan", true, 200.0);
    NodeChild C2_2 = allocNodeChild("M003", "Gorila", "Hutan", false, 160.0);
    NodeChild C2_3 = allocNodeChild("M002", "Kucing", "Darat", true, 4.0);

    insertLastChild(P2->L_Child, C2_1);
    insertLastChild(P2->L_Child, C2_2);
    insertLastChild(P2->L_Child, C2_3);

    NodeChild C4_1 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);

    insertLastChild(P4->L_Child, C4_1);
}

int main() {
    listParent LParent;
    createListParent(LParent);
    
    cout << "---Insert ---" << endl;
    
    createInitialStructure(LParent);
    
    printMLLStructure(LParent);
    
    cout << "\n--- Search Hewan tanpa Ekor ---" << endl;
    
    searchHewanByEkor(LParent, false);
    
    cout << "\n--- Delete Node Parent G004 ---" << endl;
    
    NodeParent P_G004 = LParent.first;
    NodeParent P_Prev = NULL;
    
    while (P_G004 != NULL && P_G004->isidata.idGolongan != "G004") {
        P_Prev = P_G004;
        P_G004 = P_G004->next;
    }

    if (P_G004 != NULL) {
        if (P_G004 == LParent.first) {
            deleteFirstParent(LParent);
        } else if (P_Prev != NULL) {
            deleteAfterParent(LParent, P_Prev);
        }
        cout << "Node Parent G004 (Amfibi) berhasil dihapus." << endl;
    } else {
        cout << "Node Parent G004 tidak ditemukan." << endl;
    }
    
    printMLLStructure(LParent);

    return 0;
}