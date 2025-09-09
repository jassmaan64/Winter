
#include "Sedan.hpp"

//Sedan(): defaukt connstructor
//Arguments: none | Returns: none
Sedan:: Sedan(): Vehicle()
{
    doors = 5;
    hatchback = false;
}
//Sedan(): fully developed constructor
//Arguments: int, int, int, bool | Returns: none
Sedan:: Sedan(int y, int m, int d , bool h): Vehicle(y,m)
{
    if(d>5 or d<3)d=5;
    doors = d;
    hatchback =h;
}
//setDoors(): to set doors
//Arguments: int | Returns: none
void Sedan:: setDoors(int d)
{
    if(d>5 or d<3)d=5;
    doors=d;
}
//getDoors(): to get doors
//Arguments: none | Returns: int
int Sedan:: getDoors()
{
    return doors;
}
//setHatchback(): to set hatchback bool
//Arguments: bool | Returns: none
void Sedan:: setHatchback(bool h)
{
    hatchback=h;
}
//getHatchback(): to get hatchback bool
//Arguments: none | Returns: bool
bool Sedan:: getHatchback()
{
    return hatchback;
}
//printVehicle(): to print data
//Arguments: none | Returns: none
void Sedan:: printVehicle()
{
    Vehicle::print();
    cout << "Doors: " << doors << "\n";
    cout << "Hatchback: ";
    if(hatchback)
        cout << "Yes\n";
    else
        cout << "No\n";
}
