
#include <stdio.h>
#include "RomanTwist.h"

//setRoman(): to set the roman variable
//Arguments: none | Returns: int
void RomanTwist:: setRoman(int nu)
{
    ro = "";
    int numbers[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string roman[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int temp=nu;
    for(int i =12; i >=0; i--)
    {
        while((temp/numbers[i])!=0)
        {
            ro += roman[i];
            temp -= numbers[i];
        }
    }
}
//print(): to pint some data
//Arguments: none | Returns: none
void RomanTwist:: print()
{
    cout << "Roman representation of " << num << " is " << ro << endl;
}

