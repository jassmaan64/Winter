
//*****************
//Program Name: Lab 10-4: Video Store
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: program that shows the working of a video store
//*****************
#include <iostream>
using namespace std;
#include <fstream>
#include <list>
#include "videoType.h"
#include "videoListType.h"
#include "customerType.h"
#include "customerListType.h"


//template <class Type>
void createVideoList(ifstream& infile, videoListType& videoList);
void createCustomerList(ifstream& infile, customerListType& videoList);
void displayMenu();


int main() {
    videoListType videoList;
    int choice, custId;
    char ch;
    string title;
    ifstream infile;
    infile.open("/Users/jassmaan/Documents/CS20 Spring 2021/videoData.txt");
    //open the input file infile.open("videoDat.txt");
    if (!infile)
    {
        cout << "The input file does not exist. "
             << "The program terminates!!!" << endl;
        return 1;
    }
    //create the video list
    createVideoList(infile, videoList);
    infile.close();
        //show the menu
    customerListType custList;
    ifstream infile2;
    infile2.open("/Users/jassmaan/Documents/CS20 Spring 2021/customerData.txt");
    //open the input file infile.open("videoDat.txt");
    if (!infile2)
    {
        cout << "The input file does not exist. "
             << "The program terminates !!!" << endl;
        return 1;
    }
    //create the video list
    createCustomerList(infile2, custList);
    infile2.close();
    displayMenu();
    cout << "Enter your choice: ";
    cin >> choice;    //get the request
    cin.get(ch);
    cout << endl;
    //process the requests while (choice != 9)
    while (choice != 9)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;
                
            if (videoList.videoSearch(title))
                cout << "The store carries " << title
                << endl;
            else
                cout << "The store does not carry "
                     << title << endl;
            break;
        case 2:
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;
            cin.ignore();
            if (videoList.videoSearch(title))
            {
                if (videoList.isVideoAvailable(title))
                {
                    
                    cout << "Please enter the customer Id of the one checking out the movie: \n";
                    custList.printCust();
                    cin>>custId;
                    if(custList.custSearchId(custId))
                    {
                        custList.custRentVideo(custId, title, videoList);
                        cout << "Enjoy your movie: "
                                 << title << endl;
                    }
                    else cout <<"Customer id not found in the system.\n";
                    cout << endl;
                    
                }
                else
                    cout << "Currently " << title
                << " is out of stock." << endl;
            }
                else
                        cout << "The store does not carry "
                             << title << endl;
                break;
        case 3:
                custId=0;
                cout << "Enter the Id of the person turning in the video: ";
                custList.printCust();
                cin>>custId;
                if(custList.custSearchId(custId))
                {
                    cin.ignore();
                    cout << "Enter the title: ";
                    getline(cin, title);
                    if (videoList.videoSearch(title))
                    {
                        custList.custReturnVideo(custId, title, videoList);
                    }
                    else cout << "Video not from this store.\n";
                }
                else cout << "The Id is not valid.\n";
                
        break;
        case 4:
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;
        if (videoList.videoSearch(title))
        {
            if (videoList.isVideoAvailable(title)) cout << title << " is currently in "
                             << "stock." << endl;
            else
            cout << title << " is currently out "
                             << "of stock." << endl;
        }
        else
            cout << "The store does not carry "
                 << title << endl;
        break;
        case 5:
            videoList.videoPrintTitle();
            break;
        case 6:
            videoList.print();
            break;
        case 7:
                custList.printCustomer();
                break;
        default:
        cout << "Invalid selection." << endl;
        }//end switch
        displayMenu();     //display menu
        cout << "Enter your choice: ";
            cin >> choice;
            cin.get(ch);
            cout << endl;
        }//end while

    return 0;
}

void createVideoList(ifstream& infile, videoListType& videoList)
{
    string title;
    string star1;
    string star2;
    string producer;
    string director;
    string productionCo;
    char ch;
    int inStock;
    videoType newVideo;
    getline(infile, title);
    while (infile)
    {
        getline(infile, star1);
        getline(infile, star2);
        getline(infile, producer);
        getline(infile, director);
        getline(infile, productionCo);
        infile >> inStock;
        infile.get(ch);
        newVideo.setVideoInfo(title, star1, star2, producer,
        director, productionCo, inStock);
        videoList.insertFirst(newVideo);
        getline(infile, title);
    }//end while
}//end createVideoList

void createCustomerList(ifstream& infile, customerListType& videoList)
{
    
    string first;
    string last;
    int ids;
    customerType newVideo;
    while (infile>>first)
    {
        infile>>last;
        infile>>ids;
        newVideo.setCustomerInfo(first, last, ids);
        videoList.insertFirst(newVideo);
    }//end while
}


void displayMenu()
{
    cout << "Select one of the following:" << endl;
    cout << "1: To check whether the store carries a "
    << "particular video." << endl;
    cout << "2: To check out a video." << endl;
    cout << "3: To check in a video." << endl;
    cout << "4: To check whether a particular video is " << "in stock." << endl;
    cout << "5: To print only the titles of all the videos." << endl;
    cout << "6: To print a list of all the videos." << endl;
    cout << "7: TO print a detail of customers." << endl;
    cout << "9: To exit" << endl;
} //end createVideoList
