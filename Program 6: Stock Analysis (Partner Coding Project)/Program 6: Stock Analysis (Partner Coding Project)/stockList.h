
#include <iostream>
#include <algorithm>
#include <fstream>
#include <deque>
#include <iomanip>
#include "stock.h"
using namespace std;

#ifndef stockList_h
#define stockList_h

/*
---------------------------------------
             stockList
---------------------------------------
-indexByGain:  deque<int>
-indexByName :  deque<int>
- list:  deque<stock>
---------------------------------------
+ friend ostream& operator<< (ostream &, stockList&)
+ friend istream& operator>> (istream &, stockList &)
+insert(const stock&) : void
+sortStockList() : void
+ printBySymbol(): void
+ printByGain(): void
+getList(): deque <stock>
+ print() : void
---------------------------------------
 */
class stockList
{
public:
  void insert(const stock& item){list.push_back(item);};
  void sortStockList();
  void printBySymbol();
  void printByGain();
  //Function to insert a stock in the list.
  deque<stock> getList(){return list;}
  friend ostream& operator<< (ostream &, stockList&);
  friend istream& operator>> (istream &, stockList &);
  void print();
private:
  deque<int> indexByGain;
  deque<int> indexByName;
  deque<stock> list; //vector to store the list //of stocks
};



#endif /* stockList_h */
