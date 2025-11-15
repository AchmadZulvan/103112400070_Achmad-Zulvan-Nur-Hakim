#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    cout << "Hello world!" << endl;
    printInfo(S);   
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S); 
    return 0;
}