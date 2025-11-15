#include "stack.h"
#include <iostream>
#include <limits>

using namespace std;
void CreateStack(Stack &S) {
    S.top = Nil;
}
bool isEmpty(Stack S) {
    return S.top == Nil;
}

bool isFull(Stack S) {
    return S.top == MaxEl - 1;
}
void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack Penuh!" << endl;
    }
}
infotype pop(Stack &S) {
    infotype x = -999;
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack Kosong!" << endl;
    }
    return x;
}
void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}
void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1); CreateStack(temp2);

        while (!isEmpty(S)) { push(temp1, pop(S)); }
        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }
        while (!isEmpty(temp2)) { push(S, pop(temp2)); }
    }
}
void pushAscending(Stack &S, infotype x) {
    Stack temp;
    CreateStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }
    push(S, x);
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}
void getInputStream(Stack &S) {
    char inputChar;    
    while (cin.get(inputChar) && inputChar != '\n') {
        if (inputChar >= '0' && inputChar <= '9') {
            infotype x = inputChar - '0';
            push(S, x);
        }
    }
}