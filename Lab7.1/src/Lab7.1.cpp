//============================================================================
// Name        : Lab7.1.cpp
// Author      : Jaspreet Singh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <map>
#include <fstream>
//#include <algorithm>
const int SIZE = 26;

int main() {
    char alpha[SIZE] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char alphaTemp[SIZE] = {'1','2','3','4','5','6','7','8','9','0','!','@','#','$','%','^','&','*','(',')','-','_','=','+',',','.'};
    map<char,char> sequ;
    for(int i=0; i <SIZE; i++)
        sequ.emplace(alphaTemp[i],alpha[i]);
//    ifstream fin("input.txt");
//    while(!fin)cout << "no file";
//    string sen;
//    while(getline(fin,sen));
//    cout << sen;
//    fin.close();
//    cout << "hello";
    return 0;
}
