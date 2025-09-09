//*****************
//Program Name: Lab 7-3: Count Those Words
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: program that will use an STL::Map to count the appearance of words in a story
//*****************

#include <iostream>
#include <fstream>
#include <map>
#include <cctype>
#include <iomanip>
using namespace std;
const int W1= 14;

int main() {
    map<string, int> freq;
    string temp, temps;
    ifstream fin("/Users/jassmaan/Documents/CS20 Spring 2021/Lab 7-3: Count Those Words/Lab 7-3: Count Those Words/story.txt");//to read file
    while(fin >> temp)//to read strings
    {
        temps ="";// to empty temps every time
        for(int i =0; i < temp.size(); i++)//to split a string nto chars
        {
            if(isalpha(temp[i]))
            {
                temp[i]=tolower(temp[i]);
                temps+= temp[i];
            }
        }
        //to point at string
        auto it= freq.find(temps);
        //if the string is not already in map
        if(it->first != temps)freq.emplace(temps, 1);
        //if the string is already in map
        else
            it->second++;
            
    }
    for(auto it2: freq)//to display the contents of map
    {
        cout << setw(W1) << left << it2.first << " : " << it2.second <<endl;
    }
    fin.close();
    cout << "This is my original work; apart from standard tutoring or class collaboration,"
    << "I neither received help nor copied this code from another source.\n";
    return 0;
}
