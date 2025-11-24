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
    if (Q.head == 0 && Q.tail == NMax - 1) {
        return true;
    }
    if (Q.tail + 1 == Q.head) {
        return true;
    }
    return false;
}
void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)) {
        cout << "Queue Penuh (Overflow)!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[Q.tail] = x;
        } else {
            Q.tail = (Q.tail + 1) % NMax;
            Q.info[Q.tail] = x;
        }
    }
}
infotype dequeue(Queue &Q){
    infotype temp = UNDERFLOW_VALUE;   
    if (isEmptyQueue(Q)) {
        cout << "Queue Kosong (Underflow)!" << endl;
    } else {
        temp = Q.info[Q.head];
        
        if (Q.head == Q.tail) {
            Q.head = Nil;
            Q.tail = Nil;
        } else {
            Q.head = (Q.head + 1) % NMax;
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
            bool isActive = false; 
            if (Q.head <= Q.tail) {
                if (i >= Q.head && i <= Q.tail) {
                    isActive = true;
                }
            } else {
                if (i >= Q.head || i <= Q.tail) {
                    isActive = true;
                }
            } 
            if (isActive) {
                cout << Q.info[i] << " ";
            } else {
                cout << "  "; 
            }
        }
        cout << endl;
    }
}