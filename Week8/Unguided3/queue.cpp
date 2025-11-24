#include "queue.h"
#include <iostream>
#include <iomanip>

using namespace std;

void createQueue(Queue &Q){
    Q.head = Nil;
    Q.tail = Nil;
    for (int i = 0; i < NMax; i++) {
        Q.info[i] = 0;
    }
}

bool isEmptyQueue(Queue Q){
    return (Q.head == Nil);
}

bool isFullQueue(Queue Q){
    return ((Q.tail + 1) % NMax == Q.head);
}

void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)) {
        cout << "Queue Penuh (Overflow)!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % NMax;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)) {
        cout << "Queue Kosong !" << endl;
        return 0; 
    }

    infotype temp = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = Nil;
        Q.tail = Nil;
    } else {
        Q.head = (Q.head + 1) % NMax;
    }

    return temp;
}


void printInfo(Queue Q){
    cout << setw(1) << Q.head << " - " << setw(1) << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = 0; i < NMax; i++) {
            bool isActive = false;

            if (Q.head <= Q.tail) {
                if (i >= Q.head && i <= Q.tail)
                    isActive = true;
            } else {
                if (i >= Q.head || i <= Q.tail)
                    isActive = true;
            }

            if (isActive) cout << Q.info[i] << " ";
            else cout << "  ";
        }
        cout << endl;
    }
}
