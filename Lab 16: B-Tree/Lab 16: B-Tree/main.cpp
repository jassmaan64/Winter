//*****************
//Program Name: Lab 16: B-Tree
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: inserts 100 random numbers (range up to 10000) into the B-Tree
//*****************

#include <iostream>
using namespace std;
#include "bTree.h"
const int RUNS=100, MAX=10000;

int main() {
//    bTreeNode tempss;
//    tempss.recCount
    bTree<int, 3 > bluh;
    srand(time(0));
    int temp =0;
    for(int i=0;i < RUNS; i++)
    {
        temp=rand()%MAX;
        bluh.insert(temp);
    }
    cout << "In order traversal: \n";
    bluh.inOrder();
    cout << "\nThis is my original work; apart from standard tutoring or class collaboration,"
    << "I neither received help nor copied this code from another source.\n";
    return 0;
}
