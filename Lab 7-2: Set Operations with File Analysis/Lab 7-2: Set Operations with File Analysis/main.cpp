//*****************
//Program Name: Lab 7-2: Set Operations with File Analysis
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: program that will read two text files that contain words and/or a story
//*****************

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;

int main() {
    set<string> fl1, fl2;//, f3,f4, f5,f6
    string temp, temps;
    ifstream fin("/Users/jassmaan/Documents/CS20 Spring 2021/Lab 7-2: Set Operations with File Analysis/Lab 7-2: Set Operations with File Analysis/File1.txt");//to read file
    ifstream fin2("/Users/jassmaan/Documents/CS20 Spring 2021/Lab 7-2: Set Operations with File Analysis/Lab 7-2: Set Operations with File Analysis/File2.txt");//to read file
    if(!fin)cout<<"File 1 does not exist.\n";//if file not found
    else
    {
        while(fin>>temp)//reading a string at a time
        {
            for(int i =0; i< temp.size();i++)//to split a string into char
                if(isalpha(temp[i]))
                    temps += tolower(temp[i]);
            fl1.insert(temps);
            temps="";
        }
    }
    if(!fin2)cout<<"File 2 does not exist.\n";//if file not found
    else//if file is found
    {
        while(fin2>>temp)
        {
            for(int i =0; i< temp.size();i++)
                if(isalpha(temp[i]))
                {
                    temp[i] = tolower(temp[i]);
                    temps+= temp[i];
                }
            fl2.insert(temps);
            temps="";
        }
    }
    cout << "Unique words in file 1 :\n";
    for(auto it: fl1)cout << it << endl;//displaying set1
    cout << "\nUnique words in file 2 :\n";
    for(auto it: fl2)cout << it << endl;//displaying set2
    vector <string> f3(fl1.size()+fl2.size());
    //to code the set union
    auto it=set_union(fl1.begin(), fl1.end(), fl2.begin(), fl2.end(), f3.begin());
    cout << "\nWords that appear in both files :\n";
    //to resize the set union
    f3.resize(it-f3.begin());
    //to display the set union
    for(auto it: f3)cout << it << endl;
    vector <string> f4(fl1.size()+fl2.size());
    //to code the set difference
    auto it2 = set_difference(fl1.begin(),fl1.end(),fl2.begin(),fl2.end(),f4.begin());
    cout << "\nWords that appear in the first file, but not the second :\n";
    //to resize the set difference
    f4.resize(it2-f4.begin());
    //to display the set difference
    for(auto it: f4)cout << it << endl;
    vector <string> f5(fl1.size()+fl2.size());
    //to code the set difference
    auto it3 = set_difference(fl2.begin(),fl2.end(),fl1.begin(),fl1.end(),f5.begin());
    cout << "\nWords that appear in the second file, but not the first :\n";
    //to resize the set difference
    f5.resize(it3-f5.begin());
    //to display the set difference
    for(auto it: f5)cout << it << endl;
    vector <string> f6(fl1.size()+fl2.size());
    auto it4 = set_symmetric_difference(fl1.begin(),fl1.end(),fl2.begin(),fl2.end(),f6.begin());
    cout << "\nWords that appear in either the first or second file, but not both :\n";
    f6.resize(it4-f6.begin());
    for(auto it: f6)cout << it << endl;
    fin.close();
    fin2.close();
    cout << "This is my original work; apart from standard tutoring or class collaboration,"
    << "I neither received help nor copied this code from another source.\n";
    return 0;
}
