//*****************
//Program Name: Extra Credit Program 1: STL::Set in STL::Map
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: program that reads a story and generates a word index
//*****************

#include <iostream>
#include <map>
#include <set>
#include <fstream>
using namespace std;

int main() {
    map<string, set<int>> index;
    string tempWord, temp;
    set <int> tempss;
    int lineNumber=0;
    ifstream fin("/Users/jassmaan/Documents/CS20 Spring 2021/Extra Credit Program 1: STL::Set in STL::Map/Extra Credit Program 1: STL::Set in STL::Map/input.txt");
    while(getline(fin,temp))
    {
        tempWord="";
        lineNumber++;
        for(int i=0;i<temp.size();i++)
        {
            if(isalpha(temp[i])or temp[i]=='\'')tempWord+=tolower(temp[i]);
            else
            {
                if(!index.count(tempWord))index.emplace(tempWord, set<int> {lineNumber});
                else
                {
                    auto it=index.find(tempWord);
                    it->second.insert(lineNumber);
                }
                tempWord="";
            }
        }
        temp="";
    }
    cout << "*****WORD INDEX:*****\n";
    for(auto it2:index)
    {
        cout << it2.first << ": ";
        for(auto i =it2.second.begin(); i!= it2.second.end();i++)
            cout << *i << " ";
        cout << endl;
    }
    cout << "This is my original work; apart from standard tutoring or class collaboration,"
    << "I neither received help nor copied this code from another source.\n";
    return 0;
}
