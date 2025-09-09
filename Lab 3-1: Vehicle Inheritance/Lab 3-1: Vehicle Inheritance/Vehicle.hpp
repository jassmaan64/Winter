//----------------------------
//Vehicle
//----------------------------
//- year : int
//- mileage : int
//----------------------------
//+ Vehicle()
//+ Vehicle(int, int)
//+ setYear(int) : void
//+ getYear() : int
//+ setMileage(int) : void
//+ getMileage() : int
//+ print() : void
//----------------------------

#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Vehicle
{
private:
    int year;
    int mileage;
public:
    Vehicle();
    Vehicle(int, int);
    void setYear(int);
    int getYear();
    void setMileage(int);
    int getMileage();
    void print();
};

#endif /* Vehicle_hpp */
