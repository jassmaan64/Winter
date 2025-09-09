//----------------------------
//      Person: Date
//----------------------------
//- social : int
//- dw : Date
//----------------------------
//+ Person()
//+ Person(int, Date)
//+ setSocial(int) : void
//+ setDates(Date) : void
//+ getSocial() : int
//+ getDates() : Date
//+ print() : void
//----------------------------

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
#include "Date.hpp"

class Person: public Date
{
    int social;
    Date dw;
public:
    Person();
    Person(int , Date);
    void setSocial(int);
    void setDates(Date);
    int getSocial();
    Date getDates();
    void print();
};

#endif /* Person_hpp */
