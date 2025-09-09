//*****************
//Program Name: Lab 12-4: Stack ADT Reverse Stack
//Author: Jaspreet Singh
//IDE Used: X-code
//Program description: add to the Stack ADT with a method that will make a reverse copy of a target stack
//*****************

#include <iostream>
using namespace std;
#include "stackType.h"

int main() {
    stackType <int> stack1(50);
    stack1.push(15);
    stack1.push(6);
    stack1.push(19);
    stack1.push(90);
    stack1.push(12);
    stack1.push(84);
    stack1.push(71);
    stackType <int> stack2(50);
    stack1.reverseStack(stack2);
    cout << "The original stack1:\n";
    stackType <int> disp;
    disp=stack1;
    while(!disp.isEmptyStack())
    {
        cout << disp.top();
        cout << endl;
        disp.pop();
    }
    disp=stack2;
    cout << "\nstack2 which is a reverse copy of stack1:\n";
    while(!disp.isEmptyStack())
    {
        cout << disp.top();
        cout << endl;
        disp.pop();
    }
    cout << "This is my original work; apart from standard tutoring or class collaboration,"
    << "I neither received help nor copied this code from another source.\n";
    return 0;
}
