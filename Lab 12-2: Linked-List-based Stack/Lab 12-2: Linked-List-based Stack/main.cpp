//*****************
//Program Name: Lab 12-2: Linked-List-based Stack
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: program to Alter Lab 12-1 such that the implementation is now a Linked List
//*****************

#include <iostream>
using namespace std;
#include "LinkedListType.h"
const int RUNS =10;

void push(int, int&, linkedListType<int>&);
void pop(linkedListType<int>&, int &);
int top(linkedListType<int> &, int);
void print(linkedListType<int>&, int, int);
int main() {
    linkedListType<int> myLL;
    int sise= 5;
    int sises=0, randnum =0;
    srand(time(0));
    for(int i =0;i<RUNS;i++)
    {
        randnum =rand() % 55;
        cout << "Push operation in progress: " << randnum << "\n";
        push(randnum, sises, myLL);
        sises++;
        print(myLL, sises, sise);
    }
    cout << "Poping\n";
    pop(myLL, sises);
    print(myLL, sises, sise);
    cout << "Stack initialization in progress.\n";
    int temp=sises;
    for(int i =0;i<temp;i++)
        pop(myLL, sises);
    print(myLL, sises, sise);
    cout << "This is my original work; apart from standard tutoring or class collaboration,"
    << "I neither received help nor copied this code from another source.\n";
    return 0;
}
//push(): to push elements into a data struct
//Arguments: int, int, linkedListType<int> | Returns: none
void push(int randnum, int &sises, linkedListType<int> &myLL)
{
//    if(sises == 0)
    myLL.insertFirst(randnum);
//    else
//        myLL->insertLast(randnum);
}
//pop(): to pop elements from a data struct
//Arguments: linkedListType<int>, int | Returns: none
void pop(linkedListType<int>& myLL, int &sises)
{
    if(sises >0)
    {
        myLL.deleteNode(myLL.back());
        sises--;
    }
    else
        cout << "Error!stack empty.\n";
}
//top(): to display the last element
//Arguments: linkedListType<int>, int | Returns: int
int top(linkedListType<int> &myLL, int sises)
{
    return myLL.back();
}
//print(): to print some data
//Arguments: linkedListType<int>, int, int | Returns: none
void print(linkedListType<int> &myLL, int sises, int sise)
{
    cout << "Current stack: ";
    if(sises == 0)
    {
        cout << "<stack empty>";
    }
    else
    {
        myLL.print();
    }
    cout <<endl;
    cout << "Stack size: " << sises << "\n";
//    cout << "Array size: " << sise << "\n";
    cout << "Top: " ;
    if(sises != 0)
        cout << top(myLL, sises) << "\n";
    else cout << " <stack empty>\n";
    cout << "\n\n";
}
