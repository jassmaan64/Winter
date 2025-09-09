

#include <stdio.h>
#include "DispenserType.h"
//getNoOfItems(): to get the no of items
//Arguments: none | Returns: int
int dispenserType::getNoOfItems() const
{
    return numberOfItems;
}
//getCost(): to obtain cost
//Arguments: none | Returns: int
int dispenserType::getCost() const
{
    return cost;
}
//makeSale(): to make a sale
//Arguments: none | Returns: none
void dispenserType::makeSale()
{
    numberOfItems--;
}
//dispenserType(): default constructor
//Arguments: none | Returns: none
dispenserType::dispenserType()
{
    numberOfItems = 50;
    cost = 50;
}
//dispenserType(): develped constructor
//Arguments: int, int | Returns: none
dispenserType::dispenserType(int setNoOfItems, int setCost)
{
    if (setNoOfItems >= 0)
        numberOfItems = setNoOfItems;
    else
        numberOfItems = 50;
    if (setCost >= 0)
        cost = setCost;
    else
        cost = 50;
}
