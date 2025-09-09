//*****************
//Program Name: Lab 3-1: Vehicle Inheritance
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: showing Vehicle Inheritance
//*****************

#include <iostream>
using namespace std;
#include "Vehicle.hpp"
#include "Sedan.hpp"

int main() {
    Vehicle motorVehicle(1992, 40000);//declaring vehivle
    Sedan yaris(1994, 50500, 4, true);//declaring sedan
    cout << "Information about Vehicle ""Motor Vehicle"":\n";
    motorVehicle.print();//printing vehicle info
    cout << "\nInformation about Sedan ""Yaris"":\n";
    yaris.printVehicle();//printing sedan information
    cout << "I attest that this code is my original work, that I received no help writing it apart from standard tutoring or class collaboration, and that I did not copy this code nor any portion of it from any source.";
    return 0;
}
