#include "mll.h"

int main() {
    ListParent LP;
    createListParent(LP);    adrParent P4 = alokasiNodeParent("G004", "Romance");
    adrParent P3 = alokasiNodeParent("G003", "Horror");
    adrParent P2 = alokasiNodeParent("G002", "Comedy");
    adrParent P1 = alokasiNodeParent("G001", "Action");

    insertFirstParent(LP, P4);
    insertFirstParent(LP, P3);
    insertFirstParent(LP, P2);
    insertFirstParent(LP, P1);
    insertLastChild(P1->childs, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));
    insertLastChild(P2->childs, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
    insertLastChild(P2->childs, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));
    insertLastChild(P3->childs, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));
    insertLastChild(P4->childs, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(P4->childs, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));

    cout << "MLL: " << endl;
    printMLL(LP);
    cout << endl;
    searchFilmRatingRange(LP, 8.0, 8.5);
    cout << endl;
    adrParent deletedNode;
    deleteAfterParent(LP, P1, deletedNode);
    if (deletedNode != NULL) {
        dealokasiNodeParent(deletedNode);
    }
    cout << "SETELAH DELETE G002 " << endl;
    printMLL(LP);

    return 0;
}