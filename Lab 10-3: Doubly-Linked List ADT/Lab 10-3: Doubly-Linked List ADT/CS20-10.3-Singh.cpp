//*****************
//Program Name: Lab 10-3: Doubly-Linked List ADT
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: demonstrates all capabilities of the Doubly-Linked List ADT
//*****************
#include <iostream>
using namespace std;
#include "DLL.h"

int main() {
    doublyLinkedList <int> doublyBubbly;
    doublyBubbly.initializeList();
    cout << "Initialy ";
    if(doublyBubbly.isEmptyList())cout << "the list is empty.\n";
    else cout << "the list has some values.\n";
    doublyBubbly.insert(23);
    doublyBubbly.insert(56);
    doublyBubbly.insert(546);
    doublyBubbly.insert(234);
    doublyBubbly.insert(634);
    cout << "Printing the Doubly linked list: \n";
    doublyBubbly.print();
    cout << "\nPrinting the Doubly linked list in reverse: \n";
    doublyBubbly.reversePrint();
    cout << "/nNow ";
    if(doublyBubbly.isEmptyList())cout << "the list is empty.\n";
    else cout << "the list has some values.\n";
    cout << "The Doubly-linked list has " << doublyBubbly.length() << " number of elements.\n";
    cout << "The front elemet of the doubly linked list is " << doublyBubbly.front() << " .\n";
    cout << "The last elemet of the doubly linked list is " << doublyBubbly.back() << " .\n";
    cout << "Deleting the element 56 from the list : \n";
    doublyBubbly.deleteNode(56);
    doublyBubbly.print();
    cout<< "Searching the list for 546 : \n";
    if(doublyBubbly.search(546))cout << "The element exists in the list.\n";
    else cout << "MAGIC!! The element is not in the list.\n";
    doublyLinkedList <int> doublyCopy;
    doublyCopy=doublyBubbly;
    cout << "Printing the copy List :\n";
    doublyCopy.print();
    return 0;
}
