//*****************
//Program Name: Lab 7-1: Simple Cryptography
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: program that does simple encryption and decryption
//*****************

#include <iostream>
using namespace std;
#include <map>
#include <fstream>
#include <cctype>
#include <cstring>
const int SIZE = 26;

int main() {
    char alpha[SIZE] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char alphaTemp[SIZE] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
    map <char,char> seq, seq2;//map declaration
    for(int i=0; i <SIZE; i++)//for loop to fill the map
        seq.emplace(alpha[i],alphaTemp[i]);
    for(int k=0; k <SIZE; k++)//for loop to fill the map
        seq2.emplace(alphaTemp[k],alpha[k]);
    ifstream fin("/Users/jassmaan/Documents/CS20 Spring 2021/Lab 7-1: Simple Cryptography/Lab 7-1: Simple Cryptography/input.txt");//to read file
    ofstream fout("/Users/jassmaan/Documents/CS20 Spring 2021/Lab 7-1: Simple Cryptography/Lab 7-1: Simple Cryptography/output.txt");//to create file
    if(!fin)cout << "no file";//if file not found
    else//if file is found
    {
        string sen="", temp="";
        while(fin>> sen)
        {
            for(int i = 0; i < sen.size(); i++)//to splitt apart the string
            {
                if(isalpha(sen[i]))
                {
                    sen[i]= toupper(sen[i]);
                    auto it = seq.find(sen[i]);
                    temp[i] = it->second;
                    fout << temp[i];
                }
                else
                {
                    temp[i] = sen[i];
                    fout << temp[i];
                }
            }
            fout << " ";
        }
        fout.close();
        fin.close();
    }
    
    ifstream fin2("/Users/jassmaan/Documents/CS20 Spring 2021/Lab 7-1: Simple Cryptography/Lab 7-1: Simple Cryptography/output.txt");//to read file
    if(!fin2)cout << "no file";// if file 
    else
    {
        string sen2="", temp2="";
        while(fin2>> sen2)
        {
            for(int j = 0; j < sen2.size(); j++)//to splitt apart the string
            {
                if(isalpha(sen2[j]))
                {
                    auto it2 = seq2.find(sen2[j]);
                    temp2[j] = it2->second;
                    cout << temp2[j];
                }
                else
                {
                    temp2[j] = sen2[j];
                    cout << temp2[j];
                }
            }
            cout << " ";
            temp2 = "";
        }
        fin2.close();
    }
    return 0;
}
