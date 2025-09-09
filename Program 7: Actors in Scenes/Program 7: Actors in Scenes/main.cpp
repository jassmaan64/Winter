//*****************
//Program Name: Program 7: Actors in Scenes
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: program will read a text file that a producer might have on the set of a movie
//*****************

#include <iostream>
using namespace std;
#include <map>
#include <set>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <vector>

int main() {
    set <int> scenes;
    map <string, set<int> > bluh;
    string s1,s2,s3;
    int num, count=0;
    ifstream fin("/Users/jassmaan/Documents/CS20 Spring 2021/Program 7: Actors in Scenes/Program 7: Actors in Scenes/actors.txt");//directory needed for x-code
    while(fin>>s1)// to read file
    {
        if(isdigit(s1[0]))count++;
        for(int i =0; i < s1.size();i++)
        {
            if(isdigit(s1[i]))num = atoi("s1[i]");
        }
        if(!isdigit(s1[0]) and s1 !="SCENE")
        {
            if (bluh.count(s1) == 0) //if the count of "actor" appearing in the map is 0
                bluh.emplace(s1, set<int> {count}); //emplace the actor and the set (containing scene nr)
            else
                {
                    auto it = bluh.find(s1);  //point iterator to that map element
                    it->second.insert(count);   //insert that scene into that map element's set
                }
        }
    }
    cout << "Actors and the scenes they are in: \n";
    for(auto it2: bluh)
    {
        cout << it2.first << " : " ;
        for(auto it3 : it2.second)cout << it3 << " ";
        cout << endl;
    }
    fin.close();
    return 0;
}
