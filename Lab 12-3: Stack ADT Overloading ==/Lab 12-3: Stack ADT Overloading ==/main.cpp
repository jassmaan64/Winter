//*****************
//Program Name: Lab 12-3: Stack ADT Overloading ==
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: Add to the Stack ADT by adding a method that will overload the equality operator (==)
//*****************
#include <iostream>
using namespace std;
#include "stackType.h"

int main() {
    stackType<int> mystack(50);
    mystack.push(38);
    mystack.push(72);
    mystack.push(86);
    mystack.push(9);
    mystack.push(44);
    mystack.push(23);
    stackType<int> mystackdisp= mystack;
    cout << "Created stack1:\n";
    while(!mystackdisp.isEmptyStack())
    {
        cout << mystackdisp.top() << endl;
        mystackdisp.pop();
    }
    cout << endl;
    stackType<int> copystack(50);
    copystack = mystack;
    cout << "Created stack2 using assignment.\n";
    if(copystack==mystack)cout << "stack1 and stack2 are identical\n";
    else cout << "stack1 and stack2 are not identical\n";
    cout << "Stack 1's top is: " << mystack.top() << endl;
    cout << "Stack 2's top is: " << copystack.top() << endl;
    
    copystack.push(56);
//    copystack.push(88);
    copystack.pop();
    cout << "\nAfter push and pop operations on stack2...\n";
    if(copystack==mystack)cout << "stack1 and stack2 are identical\n";
    else cout << "stack1 and stack2 are not identical\n";
    cout << "\nAfter another push operation on stack2...\n";
    copystack.push(88);
    copystack.pop();
    if(copystack==mystack)cout << "stack1 and stack2 are identical\n";
    else cout << "stack1 and stack2 are not identical\n";
    cout << "This is my original work; apart from standard tutoring or class collaboration,"
    << "I neither received help nor copied this code from another source.\n";
    return 0;
}
