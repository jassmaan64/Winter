//*****************
//Program Name: Lab 2: Fruit Drink Machine
//Author: Jaspreet SIngh
//IDE Used: X-Code
//Program description: Program to replicate the functionality of a dispensing machine
//*****************

#include <iostream>
using namespace std;
#include "CashRegister.h"
#include "DispenserType.h"

static int moneyColl;

void showSelection()
{
    cout << "*** Welcome to Shelly's Fruit Juice Shop ***" << endl; cout << "To select an item, enter " << endl;
    cout << "1 for apple juice" << endl;
    cout << "2 for orange juice" << endl;
    cout << "3 for mango lassi" << endl;
    cout << "4 for fruit punch" << endl;
    cout << "5 for Pomegranate juice" << endl;
    cout << "6 for Carrot Orange juice" << endl;
    cout << "9 to exit" << endl;
}//end showSelection
void sellProduct(dispenserType& product, cashRegister& pCounter)
{
    int amount; //variable to hold the amount entered
    int amount2; //variable to hold the extra amount needed
    int amount3 = 0;//to tell the change that is due
    if (product.getNoOfItems() > 0) //if the dispenser is not empty
    {
        cout << "Please deposit " << product.getCost()
             << " cents" << endl;
        cin >> amount;
    if (amount < product.getCost())
    {
        cout << "Please deposit another "
        << product.getCost()- amount << " cents" << endl;
        cin >> amount2;
        amount = amount + amount2;
    }
         if (amount >= product.getCost())
         {
             pCounter.acceptAmount(amount);
             product.makeSale();
             if(amount > product.getCost())
             {
                 amount3 = amount - product.getCost();
                 cout << "Please collect " << amount3 << " from the change bin.\n";
             }
             cout << "Collect your item at the bottom and enjoy."
             << endl;
             moneyColl += product.getCost();
             
         }
         else
            cout << "The amount is not enough. "
             << "Collect what you deposited." << endl;
            cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
    }
    else
        cout << "Sorry, this item is sold out." << endl;
}//end sellProduct

int main() {
    // insert code here...
    cashRegister counter;
    dispenserType appleJuice(100, 50);
    dispenserType orangeJuice(100, 65);
    dispenserType mangoLassi(75, 45);
    dispenserType fruitPunch(100, 85);
    dispenserType pomegranateJuice(100, 70);
    dispenserType carrotOrangeJuice(125, 55);
    int choice; //variable to hold the selection
    showSelection();
    cin >> choice;
    while (choice != 9)
    {
        switch(choice)
        {
            case 1:
            sellProduct(appleJuice, counter); break;
            case 2:
            sellProduct(orangeJuice, counter); break;
            case 3:
            sellProduct(mangoLassi, counter); break;
            case 4:
            sellProduct(fruitPunch, counter); break;
            case 5:
            sellProduct(pomegranateJuice, counter); break;
            case 6:
            sellProduct(carrotOrangeJuice, counter); break;
            default:
            cout << "Invalid selection." << endl;
        } //end switch
        showSelection();
        cin >> choice;
    }//end while
    cout << "Money Collected in the machine is " << moneyColl << " cents.\n";
    if(moneyColl > 0)cout << "We is getting rich.\n";
    cout << "I attest that this code is my original work, I received some help creating it from textbook,and some portion of the code has been taken from the textbook of the course.";
    return 0;
}
