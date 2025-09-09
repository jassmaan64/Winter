
#include <stdio.h>
#include "stock.h"


// operator<<: overload << operator
//Arguments: osObject v(ostream &), s (stock) | Returns: osObject ostream&
ostream& operator<< (ostream & osObject, const stock& s)
{
  osObject<< setw(7) << left << s.symbol ;
  for(int i=0; i < s.price.size(); i++)
    osObject<< setw(7) << left << s.price[i] << " ";
  osObject << setw(5) << right << fixed << setprecision(2) << ((s.price[1]/s.price[4]) -1 ) *100 << "%";
  osObject << "\t " << s.share << endl;
  return osObject;
}

// operator>>: overload >> operator
//Arguments: isObject v(istream &), s (stock) | Returns: isObject (istream&)
istream& operator>> (istream & isObject, stock& s)
{
  s.price.clear();
  double pr;
  cout << "Please enter the symbol: ";
  isObject >> s.symbol;
  cout << "Please enter stock prices(Today's(Open, close, High), Previous(Low, Close)) :";
  for(int i =0; i < SIZE; i++)
  {
    isObject >> pr ;
    while(pr<0 or pr >10000)
    {
      cerr << "Error!Invalid number entered.";
      isObject >> pr;
    }
    s.price.push_back(pr);
  }

  cout << "Please enter the number of shares in " << s.getSymbol() << " : ";
  isObject >> s.share;
  while(s.share < 0 or s.share > 100000)
  {
    cerr << "Error!Invalid number entered.";
    isObject >> s.share;
  }
  cin.ignore();
  return isObject;
}

// setStockInfo: set stock info
//Arguments: s (String), p (deque <double>), sh(int) | Returns: nothing
void stock:: setStockInfo(string s, deque <double> p, int sh)
{
  symbol = s;
  price= p;
  share = sh;
}

// print() : print objects method
//Arguments: none | Returns: none
void stock::print()
{
  cout << setw(7) << left << symbol ;
    // cin.ignore();
  for(int i =0; i < price.size(); i++)
    cout << setw(7) << left <<price[i] << " ";
  cout << setw(5) << right << ((price[1]/price[4]) -1 ) *100 << "%";
  cout << "\t " << share << endl;
}
