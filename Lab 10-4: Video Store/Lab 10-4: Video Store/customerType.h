//
//  customerType.h
//  Lab 10-4: Video Store
//
//  Created by Jass Maan on 3/22/21.
//

#ifndef customerType_h
#define customerType_h
#include <iostream>
using namespace std;
#include <vector>
#include "personType.h"
#include "videoListType.h"
#include "videoType.h"

class customerType: public personType
{
private:
    int idNum;
    vector <string> videos;
    personType per;
public:
    //constructor
    customerType()
    {
        idNum=0;
    }
    //setCustomerInfo(): to set customer info
    //Arguments: string, string, int | Returns: none
    void setCustomerInfo(string fn, string ln, int iD)
    {
        personType::setName(fn, ln);
        idNum=iD;
    }
    //checkId(): to check id
    //Arguments: int | Returns: bool
    bool checkId(int title)
    {
        return(idNum == title);
    }
    //getVideos(): to get videos
    //Arguments: none | Returns: vector<string>
    vector<string> getVideos()
    {
        return videos;
    }
    //rentVideo(): to get videos
    //Arguments: string, videoListType | Returns: none
    void rentVideo(string title, videoListType& vid)
    {
        if(vid.videoSearch(title))
        {
            vid.videoCheckOut(title);
            videos.push_back(title);
        }
        else{
            cout << "The title you are looking for is not in stock, "
                << "thank you for your time.\n";
        }
    }
    //checkIns(): to check in videos
    //Arguments: string, videoListType | Returns: none
    void checkIns(string num, videoListType& vid)
    {
        bool found = false;
        for(int it=0;it< videos.size();it++)
        {
            if(videos[it] == num)
            {
                videos.erase(videos.begin()+it);
                vid.videoCheckIn(num);
                found=true;
            }
        }
        if(found == false)
        {
            cout <<"The title you are looking for is not checked, "
            << "out by this person.\n";
        }
    }
    //constructor
    customerType(int i, personType pt):personType(pt)
    {
        idNum = i;
        videos.clear();
    }
    int getId(){return idNum;}
    void setId(int i)
    {
        if(i<0)
        {
            cout << "Id number can not be negative, setting the default to 0";
            i =0;
        }
        idNum=i;
    }
    //getNumRentals(): to see the no of videos rented
    //Arguments: none | Returns: int
    int getNumRentals()
    {
        return videos.size();
    }
    //print(): to print some data
    //Arguments: none | Returns: none
    void print()
    {
        personType::print();
        cout << "\nAccount number: " << idNum << endl;
        cout << "List of Movies rented: ";
        for(auto it: videos)cout << it<< endl;
        cout << endl;
        cout << "The number of videos rented: " << videos.size() << endl;
        cout << endl;
    }
    //printRentMov(): to print some data
    //Arguments: none | Returns: none
    void printRentMov()
    {
        int i =0;
        for(auto it: videos)cout << "[" << ++i << "] " << it << endl;
    }
    //printName(): to print some data
    //Arguments: none | Returns: none
    void printName()
    {
        personType::print();
    }
};


#endif /* customerType_h */
