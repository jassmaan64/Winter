
#ifndef stock_h
#define stock_h

#include <iostream>
#include <algorithm>
#include <fstream>
#include <deque>
#include <iomanip>
using namespace std;

const int SIZE=5;
/*
---------------------------------------
              stock
---------------------------------------
-symbol : string
- price: deque <double>
- share: int
---------------------------------------
+stock()
+ stock(string, double, int)
+ setSymbol(string s) : void
+ setPrice(deque <double> p) : void
+ setShare(int s) : void
+ getSymbol(): string
+ getPrice() : double
+  getShare() : int
+ getGain() : double
+ getGain(): double
+ getAssets() : double
+ friend ostream& operator<< (ostream &, const stock&)
+ friend istream& operator>> (istream &, stock&)
---------------------------------------
 */
class stock {
private:
  string symbol;
  deque <double> price;
  int share;
public:
  stock() {symbol =" "; share =0;};
  stock(string s, deque <double> p, int sh)
  {symbol = s; for(int i=0; i < 4;i++)price[i]= p[i];share = sh;}
  void setStockInfo( string, deque <double>, int);
  void setSymbol(string s){symbol = s;};
  void setPrice(deque <double> p){price=p;};
  void setShare(int s){share = s;};
  string getSymbol(){return symbol;};
  deque <double> getPrice(){return price;}
  int getShare(){return share;};
  double getGain(){return (((price[1]/price[4]) -1 ) *100);}
  double getAssets(){return (price[1]*share);}
  void print();
  friend ostream& operator<< (ostream &, const stock&);
  friend istream& operator>> (istream &, stock&);
};

#endif /* stock_h */
