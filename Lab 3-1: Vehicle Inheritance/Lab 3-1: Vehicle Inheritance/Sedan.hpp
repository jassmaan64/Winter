//----------------------------
//Sedan :: Vehicle
//----------------------------
//- doors : int
//- hatchback : bool
//----------------------------
//+ Sedan()
//+ Sedan(int, int, int, bool)
//+ setDoors(int) : void
//+ getDoors() : int
//+ setHatchback(bool) : void
//+ getHatchback() : bool
//+ printVehicle() : void
//----------------------------

#ifndef Sedan_hpp
#define Sedan_hpp

#include <stdio.h>
#include <iostream>
#include "Vehicle.hpp"

using namespace std;

class Sedan :public Vehicle
{
private:
    int doors;
    bool hatchback;
public:
    Sedan();
    Sedan(int, int, int, bool);
    void setDoors(int);
    int getDoors();
    void setHatchback(bool);
    bool getHatchback();
    void printVehicle();
};

#endif /* Sedan_hpp */
