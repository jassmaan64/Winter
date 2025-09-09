
#include "Date.hpp"
//Date(): default constructor
//Arguments: none | Returns: none
Date:: Date()
{
    day=month=1;
    year = 1900;
}
//Date(): developed constructor
//Arguments: none | Returns: none
Date:: Date(int d, int m, int y)
{
    if(d>31 or d<0)
        day=1;
    else
        day=d;
    if(m>12 or m<0)
        month=1;
    else
        month=m;
    if(y>2021 or y<1900)
        year=1900;
    else
        year=y;
    
}
//setDay(): to set day
//Arguments: int | Returns: none
void Date:: setDay(int d)
{
    if(d>31 or d<0)
        day=1;
    else
        day=d;
}
//setMonth(): to set month
//Arguments: int | Returns: none
void Date:: setMonth(int m)
{
    if(m>12 or m<0)
        month=1;
    else
        month=m;
}
//setYear(): to set year
//Arguments: int | Returns: none
void Date:: setYear(int y)
{
    if(y>2021 or y<1900)
        year=1900;
    else
        year=y;
}
//getDay(): to get day
//Arguments: none | Returns: int
int Date:: getDay()
{
    return day;
}
//getMonth(): to get month
//Arguments: none | Returns: int
int Date:: getMonth()
{
    return month;
}
//getYear(): to get year
//Arguments: none | Returns: int
int Date:: getYear()
{
    return year;
}
//print(): to print data
//Arguments: none | Returns: none
void Date:: print()
{
    cout << month << "/" << day << "/" << year << "\n";
}
