//


#include <stdio.h>
#include "CashRegister.h"
//getCurrentBalance(): to get the amount of money left
//Arguments: none | Returns: int
int cashRegister::getCurrentBalance() const
{
    return cashOnHand;
}
//acceptAmount(): to accept money
//Arguments: int | Returns: none
void cashRegister::acceptAmount(int amountIn)
{
    cashOnHand = cashOnHand + amountIn;
}
//cashRegister(): default constructor
//Arguments: none | Returns:none
cashRegister::cashRegister()
{
    cashOnHand = 500;
}
//cashRegister(): developed contrctor
//Arguments: int | Returns: none
cashRegister::cashRegister(int cashIn)
{
    if (cashIn >= 0)
        cashOnHand = cashIn;
    else
        cashOnHand = 500;
}
