//*****************
//Program Name: Program 14: Searching Analysis
//Author: Jaspreet Singh
//IDE Used: X-code
//Program description: program will analyze the efficiency of search algorithms
//*****************

#include <iostream>
using namespace std;
#include <vector>
#include "Hash.h"

const int TIMES=13, SEARCHES=1000;

int Proced_linear_Search(vector<int>, int, int&);
int Proced_binary_Search(vector<int>, int, int&);
int rec_linear_Search(vector<int> , int ,int , int, int &);
int rec_binarySearch(vector <int>, int, int, int, int &);
void Print(vector<int>, vector <double>);
int main() {
    int num_sea=0;
    vector <int> arr, sises;
    vector <double> arr2, arr3, arr4, arr5, arr6;
    srand(time(0));
    int avg=0, temp, prev=0;
    Hash myhash(2);
    for(int l=0;l<2;l++)arr.push_back(rand()%100);
    for(int n=0;n<2;n++)myhash.insert_element(rand()%100);
//    arr.resize(4);
    prev=arr.size();
    for(int i =0; i <5;i++)
    {
        arr.resize(2);
        for(int j =0;j <TIMES;j++)
        {
            switch(i)
            {
                case 0:
                    for(int l=0;l<arr.size();l++)arr[l]=rand()%100;
                    num_sea=0;
                    for(int k=0;k<SEARCHES;k++)
                    {
                        temp= rand() % arr.size();
                        Proced_linear_Search(arr, arr[temp], num_sea);
                    }
                    sises.push_back(arr.size());
                    avg=num_sea/SEARCHES;
                    arr2.push_back(double(avg)/arr.size());
                    arr.resize(arr.size()*2);
                    break;
                case 1:
                    for(int l=0;l<arr.size();l++)arr[l]=rand()%100;
                    num_sea=0;
                    for(int k=0;k<SEARCHES;k++)
                    {
                        Proced_binary_Search(arr, arr[rand()%arr.size()], num_sea);
                    }
                    avg=num_sea/SEARCHES;
                    arr3.push_back(double(avg)/arr.size());
                    arr.resize(arr.size()*2);
                    break;
                case 2:
                    for(int l=0;l<arr.size();l++)arr[l]=rand()%100;
                    num_sea=0;
                    for(int k=0;k<SEARCHES;k++)
                    {
                        rec_linear_Search(arr,0, arr.size()-1 , arr[rand()%arr.size()], num_sea);
                    }
                    avg=num_sea/SEARCHES;
                    arr4.push_back(double(avg)/arr.size());
                    arr.resize(arr.size()*2);
                    break;
                case 3:
                    for(int l=0;l<arr.size();l++)arr[l]=rand()%100;
                    num_sea=0;
                    for(int k=0;k<SEARCHES;k++)
                    {
                        rec_binarySearch(arr,0, arr.size()-1 , arr[rand()%arr.size()], num_sea);
                    }
                    avg=num_sea/SEARCHES;
                    arr5.push_back(double(avg)/arr.size());
                    arr.resize(arr.size()*2);
                    break;
                case 4:
                    for(int l=0;l<(arr.size()-prev);l++)myhash.insert_element(rand()%100);
                    num_sea=0;
                    for(int k=0;k<SEARCHES;k++)
                    {
                        rec_binarySearch(arr,0, arr.size()-1 , arr[rand()%arr.size()], num_sea);
                    }
                    avg=num_sea/SEARCHES;
                    arr6.push_back(double(avg)/arr.size());
                    prev=arr.size();
                    arr.resize(arr.size()*2);
                    break;
                default:
                    break;
            }
        }
    }
    cout << "Procedural Sequential Search\n";
    Print(sises, arr2);
    cout << "\nProcedural Binary Search\n";
    Print(sises, arr3);
    cout << "\nRecursive sequential search\n";
    Print(sises, arr4);
    cout << "\nRecursive Binary Search\n";
    Print(sises, arr5);
    cout << "\nHashing\n";
    Print(sises, arr6);
    cout<< "This is my original work; apart from standard tutoring or class collaboration,"
    << " I neither received help nor copied this code from another source.\n";
    return 0;
}
//Proced_linear_Search(): to run Procedural linear search
//Arguments: vector<int>, value, int | Returns: int
int Proced_linear_Search(vector<int>arr, int value, int &num_sea)
{
    int SIZE=arr.size();
    int position = -1;
        int index = 0;
        bool found = false;

        while (index < SIZE and !found)
        {
            if (arr[index] == value)
            {
                found = true;
                position = index;
                num_sea++;
            }
            index++;
            num_sea++;
        }
        return position;
}
//Proced_binary_Search(): to run Procedural binary search
//Arguments: vector<int>, value, int | Returns: int
int Proced_binary_Search(vector<int>arr, int value, int &num_sea)
{
    int SIZE=arr.size();
    int position = -1, first = 0, last = SIZE - 1, middle;
       bool found = false;

       while (first <= last and !found)
       {
           middle = (first + last) / 2;
           if (arr[middle] == value)
           {
               found = true;
               position = middle;
               num_sea++;
           }
           else if (arr[middle] > value)
           {
               last = middle - 1;
               num_sea++;
           }
           else
           {
               first = middle + 1;
               num_sea++;
           }
               
       }
       return position;
}
//Print(): to print some data
//Arguments: vector<int>, vector <double> | Returns: void
void Print(vector<int> SIZE, vector <double> percentage)
{
    for(int i=0;i<SIZE.size();i++)
    {
        cout << "n = " << SIZE[i] << " | pct = " << percentage[i] << endl;
    }
}
//rec_linear_Search(): Recursive linear search
//Arguments: vector<int>, int, int, int, int | Returns: int
int rec_linear_Search(vector<int> arr, int l,int r, int x, int &num_sea)
{
    if (r < l)
        return -1;
    if (arr[l] == x)
    {
        num_sea++;
        return l;
    }
    if (arr[r] == x)
    {
        num_sea++;
        return r;
    }
    num_sea++;
    return rec_linear_Search(arr, l + 1,r - 1, x, num_sea);
}
//rec_binarySearch(): Recursive binary search
//Arguments: vector<int>, int, int, int, int | Returns: int
int rec_binarySearch(vector <int> arr, int l, int r, int x, int &num_sea)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
        {
            num_sea++;
            return mid;
        }
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
        {
            num_sea++;
            return rec_binarySearch(arr, l, mid - 1, x, num_sea);
        }
     
            // Else the element can only be present
            // in right subarray
        num_sea++;
        return rec_binarySearch(arr, mid + 1, r, x, num_sea);
        }
     
        // We reach here when element is not
        // present in array
    return -1;
}
