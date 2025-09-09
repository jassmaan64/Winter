//
//  personType.h
//  Lab 10-4: Video Store
//
//  Created by Jass Maan on 3/22/21.
//

#ifndef personType_h
#define personType_h

#include <iostream>
#include <string>
using namespace std;

class personType
{
public:
    void print() const;
    void setName(string first, string last);
    string getFirstName() const;
    string getLastName() const;
    personType(string first = "", string last = "");

    bool operator==(const personType&) const;
    bool operator!=(const personType&) const;
    bool operator<=(const personType&) const;
    bool operator<(const personType&) const;
    bool operator>=(const personType&) const;
    bool operator>(const personType&) const;

 private:
    string firstName; //store the first name
    string lastName;  //store the last name
};

//Function to output the first name and last name
//in the form firstName lastName.
void personType::print() const
{
    cout << firstName << " " << lastName;
}

//Function to set firstName and lastName according
//to the parameters.
//Postcondition: firstName = first; lastName = last
void personType::setName(string first, string last)
{
    firstName = first;
    lastName = last;
}

//Function to return firstName and lastName via the
//parameters.
//Postcondition: The value of firstName is returned
string personType::getFirstName() const
{
    return firstName;
}

//Function to return firstName and lastName via the
//parameters.
//Postcondition: The value of lastName is returned
string personType::getLastName() const
{
    return lastName;
}

//Constructor
//Sets firstName and lastName according to the parameters.
//The default values of the parameters are empty strings.
//Postcondition: firstName = first; lastName = last
personType::personType(string first, string last)

{
    firstName = first;
    lastName = last;
}

bool personType::operator==(const personType& right) const
{
    return(firstName == right.firstName &&
           lastName == right.lastName);
}

bool personType::operator!=(const personType& right) const
{
    return(firstName != right.firstName ||
           lastName != right.lastName);
}

bool personType::operator<=(const personType& right) const
{
    return(*this < right || *this == right);
}

bool personType::operator<(const personType& right) const
{
    return((lastName < right.lastName) ||
           (lastName == right.lastName &&
            firstName < right.firstName));
}

bool personType::operator>=(const personType& right) const
{
    return(*this > right || *this == right);
}

bool personType::operator>(const personType& right) const
{
    return((lastName > right.lastName) ||
           (lastName == right.lastName &&
            firstName > right.firstName));
}


#endif /* personType_h */
