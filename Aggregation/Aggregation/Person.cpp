
#include "Person.hpp"
//Person(): default constructor
//Arguments: none | Returns: none
Person:: Person():Date()
{
    social = 234546357;
}
//Person(): developed constructor
//Arguments: length, width (double) | Returns: none
Person:: Person(int s, Date dw):Date(dw)
{
    if(s <=99999999)
        social = 234546357;
    else
        social = s;
}
//setSocial(): to set SSN
//Arguments: int | Returns: none
void Person:: setSocial(int s)
{
    if(s <=99999999)
        social = 234546357;
    else
        social = s;
}
//setDates(): to set date
//Arguments: Date | Returns: none
void Person:: setDates(Date dq)
{
    dw=dq;
}
//getSocial(): to get SSN
//Arguments: none | Returns: int
int Person:: getSocial()
{
    return social;
}
//getDates(): to get date
//Arguments: none | Returns: Date
Date Person:: getDates()
{
    return dw;
}
//print(): to print date
//Arguments: none | Returns: none
void Person:: print()
{
    cout << "Person's SSN: " << social << "\n";
    cout << "Person's Birthday: ";
    Date::print();
    cout << endl;
}
