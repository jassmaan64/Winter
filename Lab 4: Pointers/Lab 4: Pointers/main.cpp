//*****************
//Program Name: Lab 4: Pointers Part 1
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: one-sentence summary of what your program does
//*****************

#include <iostream>
using namespace std;

void switchOperands(int *, int *);
int main() {
    int *x=nullptr;
    int *y=nullptr;
    int a=2,b=4;
    x=&a;
    y=&b;
    cout << "The value of x is " << *x << endl;
    cout << "The value of y is " << *y << endl;
    switchOperands(x,y);
    cout << "The new value of x is " << *x << endl;
    cout << "The new value of y is " << *y << endl;
cout << "This is my original work; apart from standard tutoring or class collaboration,I neither received help nor copied this code from another source.";
    return 0;
}
//functionName(): quick description of the function
//Arguments: length, width (double) | Returns: area (double)
void switchOperands(int *x, int *y)
{
int *temp;
temp= x;
x = y;
y = temp;
}

//*****************
//Program Name: Lab 4: Pointers Part 2
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: one-sentence summary of what your program does
//*****************

#include <iostream>
using namespace std;
const int SIZE=5;

void enterArrayData(int *);
void outputArrayData(int *);
void sumArray(int *);
int main() {
    int arr[SIZE];
    int *arrPtr= arr;
    enterArrayData(arrPtr);
    outputArrayData(arrPtr);
    sumArray(arrPtr);
cout << "This is my original work; apart from standard tutoring or class collaboration,I neither received help nor copied this code from another source.";
    return 0;
}

void enterArrayData(int *ptr)
{
    cout << "Please enter " << SIZE << " integer to complete an array :- ";
    for(int i =0; i<SIZE;i++){cin >> ptr[i];}
}
void outputArrayData(int *ptr)
{
    cout << "\n\nLet's diplay the data in an array using pointers:\n";
    for(int i =0; i<SIZE;i++){cout << ptr[i] << " " ;}
    cout << endl;
}
void sumArray(int *ptr)
{
    int sum=0;
    for(int i =0; i<SIZE;i++){sum+=ptr[i] ;}
    cout << "The sum of all the elements in the array is " << sum << "\n";
}

//*****************
//Program Name: Lab 4: Pointers Part 3
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: one-sentence summary of what your program does
//*****************

#include <iostream>
using namespace std;
const int SIZE=5;
const int MIN=5,MAX=10;
template <class Type>
Type* reverseOrder(Type []);
template <class Type>
void display(Type []);
int main() {
    int arr[SIZE];
    for(int i =0; i<SIZE;i++){arr[i]=rand()%(MAX-MIN-1)+1;}
    display(arr);
    int *copy =reverseOrder(arr);
    display(copy);
    cout << "This is my original work; apart from standard tutoring or class collaboration,I neither received help nor copied this code from another source.";

    return 0;
}
template <class Type>
Type* reverseOrder(Type orig[])
{
    Type *copy= new Type[SIZE];
    for(int i =0; i<SIZE;i++)
    {
        *(copy+((SIZE-1)-i))=orig[i];
    }
    return copy;
}
template <class Type>
void display(Type arr[])
{
    for(int i =0; i<SIZE;i++){cout << arr[i]<<" ";}
    cout << endl;
}
