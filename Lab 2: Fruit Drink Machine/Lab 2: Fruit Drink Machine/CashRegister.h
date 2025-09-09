//---------------------------
//      cashRegister
//---------------------------
//–cashOnHand: int
//---------------------------
//+getCurrentBalance const(): int
//+acceptAmount(int): void
//+cashRegister()
//+cashRegister(int)
//---------------------------

#ifndef CashRegister_h
#define CashRegister_h
#include <iostream>
using namespace std;


class cashRegister
{
private:
    int cashOnHand;
public:
    int getCurrentBalance() const;
    //Function to show the current amount in the cash register. //Postcondition: The value of cashOnHand is returned.
    void acceptAmount(int amountIn);
    //Function to receive the amount deposited by
    //the customer and update the amount in the register. //Postcondition: cashOnHand = cashOnHand + amountIn;
        cashRegister();
           //Default constructor
           //Sets the cash in the register to 500 cents.
           //Postcondition: cashOnHand = 500.
    cashRegister(int cashIn);
    //Constructor with a parameter.
    //Sets the cash in the register to a specific amount. //Postcondition: cashOnHand = cashIn;
     //variable to store the cash in the register
 
};

#endif /* CashRegister_h */
