//----------------------------
//          Date
//----------------------------
//- day : int
//- month : int
//- year : int
//----------------------------
//+ Date()
//+ Date(int, int, int)
//+ setDay(int) : void
//+ setMonth(int) : void
//+ setYear(int) : void
//+ getDay() : int
//+ getMonth() : int
//+ getYear() : int
//+ print() : void
//----------------------------

#ifndef Date_hpp
#define Date_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date();
    Date(int, int, int);
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    int getDay();
    int getMonth();
    int getYear();
    void print();
};

#endif /* Date_hpp */
