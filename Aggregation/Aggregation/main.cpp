//*****************
//Program Name: Lab 3-2: Composition/Aggregation
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: one-sentence summary of what your program does
//*****************

#include <iostream>
using namespace std;
#include "Date.hpp"
#include "Person.hpp"


int main() {
    Date d1(7,7,2010);
    d1.print();
    Person p1(546784753,d1);
    p1.print();
    cout << endl;
    Date d2(11,11,2005);
    Person p2(345687624,d2);
    p2.print();
    return 0;
}
