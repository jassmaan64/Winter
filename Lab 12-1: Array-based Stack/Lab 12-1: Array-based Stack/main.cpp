
//*****************
//Program Name: Lab 12-1: Array-based Stack
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: creating a stack from scratch using a dynamic array
//*****************
#include <iostream>
using namespace std;

const int RUNS =10;

void push(int, int&, int *);
void pop(int&);
int top(int*, int);
void print(int *, int, int);
int main() {
    int sise= 5;
    int *ptr = new int[sise];
    int *tempPtr;
    int sises=0, randnum =0;
    srand(time(0));
    for(int i =0;i<RUNS;i++)
    {
        randnum =rand() % 55;
        cout << "Push operation in progress: " << randnum << "\n";
        if(sises >= sise)
        {
            cout << "Array too small for push operation; allocating new memory.\n";
            tempPtr = new int[sise*2];
            for(int j=0;j<sise;j++)
            {
                tempPtr[j]=ptr[j];
            }
            delete[] ptr;
            sise = sise*2;
            ptr = new int[sise];
            for(int j=0;j<sise;j++)
            {
                ptr[j]=tempPtr[j];
            }
        }
        push(randnum, sises, ptr);
        sises++;
        print(ptr, sises, sise);
    }
    cout << "Stack initialization in progress.\n";
    sises=0;
    print(ptr, sises, sise);
    
    return 0;
}
//push(): to push elements into a data struct
//Arguments: int, int, int* | Returns: none
void push(int randnum, int &sises, int *ptr)
{
    ptr[sises]=randnum;
}
//pop(): to pop elements from a data struct
//Arguments: lint | Returns: none
void pop( int & sises)
{
    sises--;
}
//top(): to display the last element
//Arguments: int *, int | Returns: int
int top(int *ptr, int sises)
{
    return ptr[sises-1];
}
//print(): to print some data
//Arguments: int*, int, int | Returns: none
void print(int *ptr, int sises, int sise)
{
    cout << "Current stack: ";
    if(sises == 0)
    {
        cout << "<stack empty>";
    }
    else
    {
        for(int i =0;i<sises;i++)
        {
            cout << ptr[i] << " ";
        }
    }
    cout <<endl;
    cout << "Stack size: " << sises << "\n";
    cout << "Array size: " << sise << "\n";
    cout << "Top: " ;
    if(sises != 0)
        cout << top(ptr, sises) << "\n";
    else cout << " <stack empty>\n";
    cout << "\n\n";
}
