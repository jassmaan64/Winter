//*****************
//Program Name: Lab 11: Recursion
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: program to Output your reversed string/story to a file
//*****************
#include <iostream>
#include <fstream>
using namespace std;
void findPunct(string);
void printRev(string, string&);
int find_Puncts(string, int, int);

int main() {
    string story, temp, temps;
    ifstream fin("/Users/jassmaan/Documents/CS20 Spring 2021/ant.txt");
    while(getline(fin, temp))
    {
        story+= "@";
        story+=temp;
    }
    fin.close();
    int choice;
    cout << "Enter\n";
    cout << "[1] to find the number of punctuation marks in the story\n";
    cout << "[2] to print the story in reverse\n";
    cout << "[3] for both\n";
    cin>>choice;
    while(choice <1 or choice >3)
    {
        cout << "Please enter a number 1-3 inclusive only: ";
        cin>>choice;
    }
    int length=story.size(), count=0;
    //switch between 3 scenarios
    switch(choice)
    {
        case 1://only punct case
            count=find_Puncts(story, 0, length);
            cout << "This story has " << count << " number of Punctuation marks.\n";
            break;
        case 2://only print revarraycase
            printRev(story, temps);
            break;
        case 3://case with both options
            count=find_Puncts(story, 0, length);
            cout << "This story has " << count << " number of Punctuation marks.\n";
            printRev(story, temps);
            break;
        default://just incase
            cout << "Invalid Selection.\n";
    }
    if(choice == 2 or choice == 3)
    {
        cout << "\n\n\n\n";
        cout << temps;
        ofstream fout("/Users/jassmaan/Documents/CS20 Spring 2021/revant.txt");
        fout << temps;
        fout.close();
    }
    
    return 0;
}
//findPunct(): to find the number of punctutaions in a string
//Arguments: string | Returns: none
void findPunct(string story)
{
    int punc=0;
    for(int i=0; i<story.size();i++)
    {
        if(story[i]!= '@')
        {
            if(ispunct(story[i]))punc++;
        }
    }
    cout << "This story has " << punc << " number of Punctuation marks.\n";
}

//printRev(): to print a reversed string both in console and an external file
//Arguments: string | Returns: none
void printRev(string story, string &temps)
{
    if(story.size()==0)
    {
        return;
    }
    else
    {
        if(story[story.size()-1]!='@')
        {
            cout << story[story.size()-1];
            temps+=story[story.size()-1];
            story.resize(story.size()-1);
            printRev(story, temps);
        }
        else
        {
            story.resize(story.size()-1);
            printRev(story, temps);
        }
    }
}
//find_Puncts(): to find the number of punctutaions in a string
//Arguments: string, int, int | Returns: int
int find_Puncts(string str, int pos, int length)
{
    if(pos >= length)
        return 0;
    else if(ispunct(str[pos]))
    {
        if(str[pos]!= '@')
            return 1 + find_Puncts(str, pos+ 1, length);
        else
            return find_Puncts(str, pos + 1, length);
    }
    else
        return find_Puncts(str, pos+ 1, length);
}
