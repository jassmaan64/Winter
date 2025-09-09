
#include "Vehicle.hpp"

//Vehicle(): default constructor
//Arguments: none | Returns: none
Vehicle:: Vehicle()
{
    year= 1990;
    mileage=0;
}
//Vehicle(): fully developed contructor
//Arguments: int, int | Returns: none
Vehicle:: Vehicle(int y, int m)
{
    if(y>2021 or y <1990)y=1990;
    year=y;
    if(m <0)m =0;
    mileage=m;
}
//setYear(): to set year
//Arguments: int | Returns: none
void Vehicle:: setYear(int y)
{
    if(y>2021 or y <1990)y=1990;
    year=y;
}
//getYear(): to get year
//Arguments: none | Returns: int
int Vehicle:: getYear()
{
    return year;
}
//setMileage(): to set mileage
//Arguments: int | Returns: none
void Vehicle:: setMileage(int m)
{
    if(m <0)m =0;
    mileage=m;
}
//getMileage(): to get mileage
//Arguments: none | Returns: int
int Vehicle:: getMileage()
{
    return mileage;
}
//print(): to print data
//Arguments: none | Returns: none
void Vehicle:: print()
{
    cout << "Year: " << year << "\nMileage: " << mileage << "\n";
}
