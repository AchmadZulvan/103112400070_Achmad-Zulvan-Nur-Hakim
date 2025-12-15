#include "mll.h"
#include <iomanip>

bool isEmptyParent(listParent LParent) {
    return LParent.first == NULL;
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent NParent = new nodeParent;
    NParent->isidata.idGolongan = idGol;
    NParent->isidata.namaGolongan = namaGol;
    NParent->next = NULL;
    NParent->prev = NULL;
    createListChild(NParent->L_Child);
    return NParent;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = NULL;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        insertFirstParent(LParent, newNParent);
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent P = LParent.first;
        
        deleteListChild(P->L_Child); 

        if (LParent.first == LParent.last) {
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = P->next;
            LParent.first->prev = NULL;
            P->next = NULL;
        }
        deallocNodeParent(P);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent P = NPrev->next;
        
        deleteListChild(P->L_Child); 

        if (P == LParent.last) {
            LParent.last = NPrev;
            NPrev->next = NULL;
        } else {
            NPrev->next = P->next;
            P->next->prev = NPrev;
            P->next = NULL;
        }
        P->prev = NULL;
        deallocNodeParent(P);
    }
}

bool isEmptyChild(listChild LChild) {
    return LChild.first == NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild NChild = new nodeChild;
    NChild->isidata.idHewan = idHwn;
    NChild->isidata.namaHewan = namaHwn;
    NChild->isidata.habitat = habitat;
    NChild->isidata.ekor = tail;
    NChild->isidata.bobot = weight;
    NChild->next = NULL;
    NChild->prev = NULL;
    return NChild;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = NULL;
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        insertFirstChild(LChild, newNChild);
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild P = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = P->next;
            LChild.first->prev = NULL;
            P->next = NULL;
        }
        deallocNodeChild(P);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild P = NPrev->next;
        if (P == LChild.last) {
            LChild.last = NPrev;
            NPrev->next = NULL;
        } else {
            NPrev->next = P->next;
            P->next->prev = NPrev;
            P->next = NULL;
        }
        P->prev = NULL;
        deallocNodeChild(P);
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void printMLLStructure(listParent LParent) {
    cout << "\n=== Multi Linked List Structure ===" << endl;
    NodeParent P = LParent.first;
    int parentCount = 1;
    while (P != NULL) {
        cout << "=== Parent " << parentCount << endl;
        cout << "ID Golongan: " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan: " << P->isidata.namaGolongan << endl;

        NodeChild C = P->L_Child.first;
        int childCount = 1;
        if (C == NULL) {
            cout << "(tidak ada child)" << endl;
        } else {
            while (C != NULL) {
                cout << "- Child " << childCount << ":" << endl;
                cout << "ID Hewan: " << C->isidata.idHewan << endl;
                cout << "Nama Hewan: " << C->isidata.namaHewan << endl;
                cout << "Habitat: " << C->isidata.habitat << endl;
                cout << "Ekor: " << (C->isidata.ekor ? 1 : 0) << endl;
                cout << fixed << setprecision(1) << "Bobot: " << C->isidata.bobot << endl;
                C = C->next;
                childCount++;
            }
        }
        P = P->next;
        parentCount++;
    }
}

void searchHewanByEkor(listParent LParent, bool tail) {
    cout << "\n=== Hasil Pencarian Hewan dengan Ekor: " << (tail ? "TRUE (1)" : "FALSE (0)") << " ===" << endl;
    NodeParent P = LParent.first;
    int parentPos = 1;

    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        int childPos = 1;

        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                cout << "Data ditemukan pada list anak dari node parent " << P->isidata.namaGolongan << " pada posisi ke-" << childPos << "!" << endl;
                cout << "--- Data Child ---" << endl;
                cout << "ID Child: " << C->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << childPos << endl;
                cout << "Nama Hewan: " << C->isidata.namaHewan << endl;
                cout << "Habitat: " << C->isidata.habitat << endl;
                cout << "Ekor: " << (C->isidata.ekor ? 1 : 0) << endl;
                cout << fixed << setprecision(1) << "Bobot: " << C->isidata.bobot << endl;

                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent: " << P->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << parentPos << endl;
                cout << "Nama golongan: " << P->isidata.namaGolongan << endl;
            }
            C = C->next;
            childPos++;
        }

        P = P->next;
        parentPos++;
    }
}