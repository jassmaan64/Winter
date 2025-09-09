//------------------------
//       RomanTwist
//------------------------
//–num: int
//-ro: string
//---------------------------
//+RomanTwist():
//+setNum(int): void
//+setRoman(int): void
//+getNum(): int
//+getRoman(): string
//+print(): void
//---------------------------
#ifndef RomanTwist_h
#define RomanTwist_h

#include <iostream>
using namespace std;

class RomanTwist
{
private:
    int num;
    string ro;
    
public:
    //RomanTwist(): constructor
    //Arguments: int | Returns: none
    RomanTwist(int n = 0)
    {
        num=n;
        setRoman(n);
    }
    //setNum(): to set num variable
    //Arguments: int | Returns: none
    void setNum(int nu){num = nu;setRoman(nu);}
    void setRoman(int);
    //getNum(): to get num value
    //Arguments: none | Returns: int
    int getNum(){return num;}
    //getRoman(): to get the roman
    //Arguments: none | Returns: string
    string getRoman(){return ro;}
    void print();
};

#endif /* RomanTwist_h */
