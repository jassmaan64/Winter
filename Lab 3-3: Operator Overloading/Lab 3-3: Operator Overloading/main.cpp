//*****************
//Program Name: Lab 3-3: Operator Overloading
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: Operator Overloading in a class
//*****************

#include <iostream>
using namespace std;
#include "Box.hpp"

int main() {
    Box box1;
    Box box2(3.5, 2.5, 4.0);
    Box box3(4.5, 3.5, 3.0);
    Box box4(5.5, 4.5, 5.0);
    
    cout << "Volume of box #1: " << box1.volume();
    cout << "\nVolume of box #2: " << box2.volume();
    cout << "\nVolume of box #3: " << box3.volume();
    cout << "\nVolume of box #4: " << box4.volume();
    
    cout << "\n\nTesting equality:";
    cout << "\nTesting if box1 = box2: ";
    box1 == box2;
    cout << "\nTesting if box3 = box4: ";
    box3 == box4;
    cout << "\nTesting if box1 = box3: ";
    box1 == box3;
    
    cout << "\n\nTesting (volume) greater than:";
    cout << "\nTesting if box1 > box2: ";
    box1>box2;
    cout << "\nTesting if box2 > box3: ";
    box2>box3;
    
    cout << "\n\nTesting (volume) less than:";
    cout << "\nTesting if box2 < box4: ";
    box2<box4;
    cout << "\nTesting if box3 < box2: ";
    box3<box2;
    
    cout << "\n\nTesting (all dimensions) less than: ";
    cout << "\nTesting if box1 <= box2: ";
    box1<=box2;
    cout << "\nTesting if box3 <= box2: ";
    box3<=box2;
    cout << endl;
    return 0;
}
