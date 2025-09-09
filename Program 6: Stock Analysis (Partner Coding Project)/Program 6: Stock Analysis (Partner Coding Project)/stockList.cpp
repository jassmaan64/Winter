

#include <stdio.h>
#include "stockList.h"

// operator<<: overload << operator
//Arguments: osObj v(ostream &), s (stock) | Returns: osObj ostream&
ostream& operator<< (ostream & osObj, stockList& s)
{
  double asset=0.0;
  osObj << "********* First Investor's Heaven **********\n********* Financial Report ********** \n" ;
  osObj<< "Stock \t\t\tToday \t\t\tPrevious \t\t\tPercent\n";
  osObj << "Symbol   Open   Close   High   Low     Close   Gain      Volume\n";
 cout << "------  -----  ------  ------  -----   -----    -----    ------\n";
  for(int i= 0; i < s.list.size(); i++)
    osObj << s.list[i];
  for(int l= 0; l < s.list.size(); l++)
    asset+= s.list[l].getAssets();
  cout << "Closing Assets: " << "$" << asset << endl;
  cout << endl;
  return osObj;
}

// print() : print objects method
//Arguments: none | Returns: none
void stockList:: print()
{
  for(int i= 0; i < list.size(); i++)
    list[i].stock::print();
}

// operator>>: overload >> operator
//Arguments: i v(istream &), s (stock) | Returns: i (istream&)
istream& operator>> (istream & inf, stockList & s)
{
  // string sym;
  stock obj;
  for(int i= 0; i < SIZE; i++)
  {
    inf >> obj;
    s.list.push_back(obj);
  }
  return inf;
}

//sortStockList() : sort stock list
//Arguments: none | Returns: none
void stockList::sortStockList()
{
  deque <double> tempGain;
  for(int i =0 ; i < list.size(); i++)
    tempGain.push_back(list[i].stock::getGain());

  sort(tempGain.begin(), tempGain.end());
  reverse(tempGain.begin(), tempGain.end());
  for(int j =0 ; j < list.size(); j++)
  {
    for(int k =0 ; k < list.size(); k++)
    {
      if(tempGain[j]==list[k].stock::getGain())indexByGain.push_back(k);
    }
  }
}

//printBySymbol : sort and printstock list by symbol
//Arguments: none | Returns: none
void stockList::printBySymbol()
{
  cout << "********* First Investor's Heaven **********\n*********** Financial Report *************** \n" ;
  cout<< "Stock \t\t\tToday \t\t\tPrevious \t\t\tPercent\n";
  cout << "Symbol   Open   Close   High   Low     Close   Gain      Volume\n";
  cout << "------  -----  ------  ------  -----   -----    -----    ------\n";
  deque <string> temps;
  double asset=0.0;
  for(int i =0 ; i < list.size(); i++)
  {
    temps.push_back(list[i].stock::getSymbol());
  }
  
  sort(temps.begin(), temps.end());
  for(int j =0 ; j < list.size(); j++)
    for(int k =0 ; k < list.size(); k++)
      if(temps[j]==list[k].stock::getSymbol())indexByName.push_back(k);
  
  for(int l = 0 ; l < list.size(); l++)
  {
   //cout <<   list;
    cout << list[indexByName[l]];
    asset+= list[indexByName[l]].getAssets();
  }
  cout << "Closing Assets: " << "$" << asset << endl;
  cout << endl;
  }

//printByGain : sort and printstock list by gain
//Arguments: none | Returns: none
void stockList::printByGain()
{
  cout << "*********** First Investor's Heaven *************\n********* Stock by Gain/Loss percentage ********** \n" ;
  cout<< "Stock \t\t\tToday \t\t\tPrevious \t\t\tPercent\n";
  cout << "Symbol   Open   Close   High   Low     Close   Gain      Volume\n";
   cout << "------ ------  ------  ------  ------  ------  ------    ------\n";
  deque <double> temps;
  double asset1=0.0;
  for(int i =0 ; i < list.size(); i++)
  {
    temps.push_back(list[i].stock::getGain());
  }
  sort(temps.begin(), temps.end());
  for(int j =0 ; j < list.size(); j++)
    for(int k =0 ; k < list.size(); k++)
      if(temps[j]==list[k].stock::getGain())indexByGain.push_back(k);
  for(int l =0 ; l < list.size(); l++)
  {
    cout << list[indexByGain[l]];
    asset1+= list[indexByGain[l]].getAssets();
  }
  cout << "Closing Assets: " << "$" << asset1 << endl;
  cout << endl;
  }
