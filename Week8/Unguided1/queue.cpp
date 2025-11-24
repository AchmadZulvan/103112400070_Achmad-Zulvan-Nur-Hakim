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
    return (Q.tail == NMax - 1);
}
void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)) {
        cout << "Queue Penuh (Overflow)!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
        }
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}
infotype dequeue(Queue &Q){
    infotype temp = 0;
    if (isEmptyQueue(Q)) {
        cout << "Queue Kosong (Underflow)!" << endl;
    } else {
        temp = Q.info[Q.head];
                for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--;
        if (Q.tail == Nil) {
            Q.head = Nil;
        }
    }
    return temp;
}
void printInfo(Queue Q){
    cout << setw(1) << Q.head << " - " << setw(1) << Q.tail << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = 0; i < NMax; i++) {
            if (i >= Q.head && i <= Q.tail) {
                cout << Q.info[i] << " ";
            } else {
                cout << "  "; 
            }
        }
        cout << endl;
    }
}