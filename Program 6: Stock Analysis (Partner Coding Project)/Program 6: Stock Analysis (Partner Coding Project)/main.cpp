//*****************
//Program Name: Program 6
//Author: Jaspreet Singh and Riyya Ahmed
//IDE Used: X-Code
//Program description: program to do stock analysis
//*****************

#include <iostream>
#include "stock.h"
#include "stockList.h"
#include <deque>
using namespace std;

void getData(stockList &);

int main()
{
  stockList stockList;
  freopen("error.txt", "w", stderr);
  cout << fixed << setprecision(2) << showpoint;
  getData(stockList); //read external file data into stockList
  stockList.sortStockList(); //sorts stockList and generates indexByGain
  stockList.printBySymbol(); //prints alphabetically by symbol
  stockList.printByGain();   //prints high-to-low low by gain /*

  cout << "\nThis is my original work; apart from standard tutoring or class collaboration, I neither received help nor copied this code from another source.";

  /* Partner attestation: We planned the whole thing together and divided the classes to code seperately. Then, we implemented
  the classes together adn debugged issues colaboratively.
  It is fair to conclude that it was a 50/50 collaboration.
  */
  return 0;
}
void getData(stockList &obj)
{
  ofstream fout("stockData.txt");
    fout << "ABC 123.45 130.95 132.00 125.00 120.50 10000\n"
         <<  "MSET 120.00 140.00 145.00 140.00 115.00 30920\n"
         <<  "AOLK 80.00 75.00 82.00 74.00 83.00 5000\n"
         <<  "CSO 100.00 102.00 105.00 98.00 101.00 25000\n"
    <<  "IBD 68.00 71.00 72.00 67.00 75.00 15000\n";
    fout.close();
    stock temp;
      ifstream fin ("stockData.txt");
      string name;
      deque <double> price1;
      double temps;
      int vol;
      if(!fin) cout << "Error reading the external file!\n";
      
      while(fin >> name )
      {
        for(int i = 0 ; i < 5; i++)
        {
          fin >> temps;
          price1.push_back(temps);
        }
        fin >> vol;
        temp.setStockInfo(name, price1, vol);
        obj.insert(temp);
        for(int j = 0 ; j < 5; j++) price1.pop_back();
      }
}









foo(A[0...n-1])
{
    if n < 2:
        return 1
    i = 1
    while i <= n:
    {
        boo(A[0...i])
        i = i * 2           //logn
    }

    a = foo(A[0...n/4])     // n/4
    b = foo(A[n/4+1...n/2])   
    c = foo(A[n/2+1...n-1])
    return a + b + c
}
