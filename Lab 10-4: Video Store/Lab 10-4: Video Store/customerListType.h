//
//  customerListTyp.h
//  Lab 10-4: Video Store
//
//  Created by Jass Maan on 3/22/21.
//

#ifndef customerListTyp_h
#define customerListTyp_h
#include <iostream>
#include <string>
#include <list>
#include "LinkedListType.h"
#include "customerType.h"
#include "videoListType.h"

using namespace std;

class customerListType:public linkedListType<customerType>
{
private:
    list <customerType> cust;
    videoListType vid;
public:
    //printCust(): to print some data
    //Arguments: none | Returns: none
    void printCust()
    {
        nodeType <customerType> *current=first;
        while(current!= NULL)
        {
            current->info.printName();
            cout << " ";
            cout << current->info.getId();
            current=current->link;
            cout << endl;
        }
    }
    //printCustomer(): to print some data
    //Arguments: none | Returns: none
    void printCustomer()
    {
        nodeType <customerType> *current=first;
        while(current!= NULL)
        {
            current->info.print();
            current = current->link;
        }
    }
    //custSearchId(): to search for an id
    //Arguments: int | Returns: bool
    bool custSearchId(int id)
    {
        bool found = false;
        nodeType<customerType> *current = first;
        while(current != NULL)
        {
            if(current->info.getId()== id)found = true;
            current = current->link;
        }
        return found;
    }
    //custReturnVideo(): to return a video
    //Arguments: int, string, videoListType | Returns: none
    void custReturnVideo(int id, string title, videoListType& vid)
    {
        bool found = false;
        nodeType<customerType> *current = first;
        while(current != NULL)
        {
            if(current->info.getId()== id)
            {
                current->info.checkIns(title, vid);
                found = true;
            }
            current =current->link;
        }
        if(!found)cout << "The requested Id was not found, "
            << "please return using the rented ID.\n";
    }
    //custRentVideo(): to rent a video
    //Arguments: int, string, videoListType | Returns: none
    void custRentVideo(int id, string title, videoListType& vid)
    {
        bool found = false;
        nodeType<customerType> *current = first;
        while(current != NULL)
        {
            if(current->info.getId()== id)
            {
                current->info.rentVideo(title, vid);
                found = true;
            }
            current =current->link;
        }
        if(!found)cout << "The requested Id was not found, "
            << "therefore video can not be rented.\n";
    }
    //custGetNoOfRentals(): to get thw number of rented videos
    //Arguments: int | Returns: int
    int  custGetNoOfRentals(int id)
    {
        int num=0;
        nodeType<customerType> *current = first;
        while(current != NULL)
        {
            if(current->info.getId()== id)
            {
                num=current->info.getNumRentals();
            }
            current = current-> link;
        }
        return num;
    }
    //rentedVideosInfo(): to print rented videos data
    //Arguments: int | Returns: int
    void rentedVideosInfo()
    {
        nodeType<customerType> *current = first;
        while(current != NULL)
        {
            current->info.print();
        }
    }
};


#endif /* customerListTyp_h */
