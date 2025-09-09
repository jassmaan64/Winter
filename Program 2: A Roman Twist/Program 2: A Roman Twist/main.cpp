//*****************
//Program Name: Program 2: A Roman Twist
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: A roman representation of integers
//*****************

#include <iostream>
using namespace std;
#include "RomanTwist.h"
const int RUNS = 1;

int main() {
    int num, numb, numb1;
    char sign;
    RomanTwist num1, num2, num3, num4;
    cout << "Please enter a number between 1-1500:-";
    cin >> num;
    while(num < 1 or num > 1500)
    {
        cout << "Please enter a number between 1-1500:-";
        cin >> num;
    }
    num1.setNum(num);//to set an object
    num1.print();//to print data
    int run = RUNS;
    while(run !=0)// to scale the number of runs
    {
        cout << "\nNow enter two number and a + or - to add or subtract integers and represent them in roman numerical.\n";
        cin >> num;
        while(num < 1 or num > 1500)//input validation
        {
            cout << "Please enter a number between 1-1500:-";
            cin >> num;
        }
        cin >> numb;
        while(numb < 1 or numb > 1500)//input validation
        {
            cout << "Please enter a number between 1-1500:-";
            cin >> numb;
        }
        num4.setNum(num);
        num2.setNum(numb);
        cin >>sign;
        while(sign!= '+' and sign!= '-')//input validation
        {
            cout << "Please enter a + or - :-";
            cin >> sign;
        }
        if(sign == '+')// for addition
        {
            numb1= num+numb;
            num3.setNum(numb1);
            cout << num << " + " << numb << " = " << numb1 << "\n";
            cout << num4.getRoman() << " + " << num2.getRoman() << " = " << num3.getRoman();
        }
        else// to subtract
        {
            if(num >= numb)// if clause for just in case
            {
                numb1= num-numb;
                num3.setNum(numb1);
                cout << num << " - " << numb << " = " << numb1 << "\n";
                cout << num4.getRoman() << " - " << num2.getRoman() << " = " << num3.getRoman();
            }
            else// else clause for just in case
            {
                numb1= numb-num;
                cout << numb << " - " << num << " = " << numb1 << "\n";
                cout << num2.getRoman() << " - " << num4.getRoman() << " = " << num3.getRoman();
            }
        }
        run--;//to decrement the runs to stop the code eventually
    }
    cout << "I attest that this code is my original work, I received no help creating it,and that I did not copy this code nor any portion of it from any source.";
    return 0;
}
