#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

typedef struct {
    string idGolongan;
    string namaGolongan;
} golonganHewan;

typedef struct {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
} dataHewan;

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

typedef struct listChild {
    NodeChild first;
    NodeChild last;
} listChild;

typedef struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
} nodeChild;

typedef struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
} nodeParent;

typedef struct listParent {
    NodeParent first;
    NodeParent last;
} listParent;

bool isEmptyParent(listParent LParent);
void createListParent(listParent &LParent);
NodeParent allocNodeParent(string idGol, string namaGol);
void deallocNodeParent(NodeParent &NParent);
void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

bool isEmptyChild(listChild LChild);
void createListChild(listChild &LChild);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeChild(NodeChild &NChild);
void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);
void deleteListChild(listChild &LChild);

void printMLLStructure(listParent LParent);
void searchHewanByEkor(listParent LParent, bool tail);

#endif