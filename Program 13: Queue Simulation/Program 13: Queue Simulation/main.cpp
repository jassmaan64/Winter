//*****************
//Program Name: Program 13: Queue Simulation
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: program will simulate a queue
//*****************

#include <iostream>
using namespace std;
#include "queueType.h"

static int queue_size=0;
const int RUNS=10;

int main() {
    queueType<int> myqueue;
    myqueue.addQueue(5);
    queue_size++;
    myqueue.addQueue(19);
    queue_size++;
    myqueue.addQueue(97);
    queue_size++;
    myqueue.addQueue(53);
    queue_size++;
    myqueue.addQueue(68);
    queue_size++;
    myqueue.addQueue(30);
    queue_size++;
    myqueue.addQueue(58);
    queue_size++;
    myqueue.addQueue(5);
    queue_size++;
    myqueue.addQueue(31);
    queue_size++;
    myqueue.addQueue(77);
    queue_size++;
    int num=0, rando;
    srand(time(0));
    for(int i=0;i<RUNS;i++)
    {
        cout << "Operation #"<< i+1 << ": ";
        rando=rand()%101;
        if(rando < 45)
        {
            num=rand()%50;
            cout << "Add random number to the queue (" <<num << ")\n";
            myqueue.addQueue(num);
            queue_size++;
            myqueue.printQueue();
        }
        else if(rando < 90)
        {
            if(queue_size > 0)
            {
                cout << "Delete queue front (" <<myqueue.front() << ")\n";
                myqueue.deleteQueue();
                queue_size--;
                myqueue.printQueue();
            }
            else
                cout << "Queue empty.\n";
        }
        else
        {
            if(queue_size == 0)
                cout << "Error!Queue empty.\n";
            else if(queue_size==1)
                cout << "Error! only one element in the queue.\n";
            else
            {
                cout << "Move random element to front\n";
                num=rand()%(queue_size-2+1)+2;
                cout << "Randomly selected element " << num
                     << " (" << myqueue.get_element_at(num)
                << ") to move to front.\n";
                myqueue.moveToFront(num);
                myqueue.printQueue();
            }
        }
        cout << endl;
    }
    cout << "This is my original work; apart from standard tutoring or class collaboration,"
         << " I neither received help nor copied this code from another source.\n";
    return 0;
}
