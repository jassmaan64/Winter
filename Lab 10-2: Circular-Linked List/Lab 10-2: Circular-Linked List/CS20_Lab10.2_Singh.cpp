//*****************
//Program Name: Lab 10-2: Circular-Linked List
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: menu-driven program for circular linked list operations
//*****************

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct nodeType
{
    int value;
    nodeType *next;
};

//function prototypes
nodeType* buildList();
int menu();
void outputList(nodeType*);
nodeType* addNode(nodeType*);
nodeType* deleteNode(nodeType*);

int main()
{
    //housekeeping
    srand(time(0));

    //build the LL, return a pointer to it, assign pointer to myList
    nodeType *myList = buildList();

    //main menu and processing
    int choice = menu();
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:    outputList(myList);          break;
    case 2: myList = addNode(myList);    break;
    case 3: myList = deleteNode(myList); break;
    case 4: cout << "Program ending.";
        }
        choice = menu();
    }
    return 0;
}

//deleteNode(): deletes the user-specified LL node
//Arguments: pointer to the LL head | Returns: pointer to the LL head
nodeType* deleteNode(nodeType *head)
{
    nodeType *p,       //p will point to the node prior to the one to be deleted
             *current; //to traverse the list

    //traverse *head and have p point to the node to be deleted
    cout << "Enter the node number to be deleted:\n";
    int index = 1;
    current = head;
    while (current->next != head)
    {
        cout << "\t[" << index++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "\t[" << index++ << "] " << current->value << endl;
    current = current->next;
    int choice;
    cin >> choice;
    //make p point to the node just prior to that choice
    if (choice == 1)
    {
        p = head;
        head = head->next;
        delete p;
    }
    else
    {
        choice--;
        current = head;
        for (int i = 1; i <= choice; i++)
        {
            p = current;
            current = current->next;
        }
        p->next = current->next;
        delete current;
    }
    return head;
}

//addNode(): adds a LL node in a user-specified location
//Arguments: pointer to the LL head | Returns: pointer to the LL head
nodeType* addNode(nodeType *head)
{
    nodeType *p,        //p will point to the node prior to the insertion point
             *newNode,  //newNode points to the newly-created memory
             *current;  //used to traverse the LL
    cout << "Enter the new node's value: ";
    int num;
    cin >> num;
    newNode = new nodeType;
    newNode->value = num;
    newNode->next = nullptr; // initialize this

    //traverse LL and have p point to the node just prior to
    //the intended insertion
    cout << "Enter the node number just prior to your insertion point:\n";
    int index = 1;
    current = head;
    cout << "\t[0] New node at beginning\n";
//    while (current != nullptr)
    while (current->next != head)
    {
        cout << "\t[" << index++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "\t[" << index++ << "] " << current->value << endl;
    current = current->next;
    int choice;
    cin >> choice;
    //make p point to that choice's node
    current = head;
    if (choice == 0) // insert node at beginning
    {
        newNode->next = head;
        head = newNode;
    }
    else // insert node somewhere else
    {
        for (int i = 1; i <= choice; i++)
        {
            p = current;
            current = current->next;
        }
        cout << "Inserting after element: " << p->value << endl;
        newNode->next = current;
        p->next = newNode;
    }
    return head;
}

//buildList(): builds a LL
//Arguments: none | Returns: pointer to the LL head
nodeType* buildList()
{
    nodeType *first,    //points to the LL head
             *newNode,  //points to a new node
             *last;     //points to the LL tail
    int num;
    first = nullptr;       //initialize the LL head

    //obtain & validate the user input for # of nodes
    cout << "How many nodes to generate [10-50]: ";
    cin >> num;
    while (num < 10 or num > 50 or cin.fail())
    {
        cout << "ERROR: 10-50 only: ";
        cin >> num;
    }

    for (int i = 1; i <= num; i++)
    {
        int rando = rand() % 100;
        newNode = new nodeType;
        newNode->value = rando;
        newNode->next = nullptr;

        if (first == nullptr)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
        last->next=first;
    }
    return first;
}

//outputList(): outputs the LL to the console
//Arguments: pointer to the LL head | Returns: void
void outputList(nodeType *current)
{
//    cin.ignore();
    int count = 0, disp;
    cout << "Please enter the number of elements to be printed: ";
    cin>>disp;
    while(disp<1)
    {
        cout << "Please enter a number greater than 0: ";
        cin>>disp;
    }
    cout << "Current nexted List: ";

//    while (current != NULL)
    for(int i=0;i<disp;i++)
    {
        cout << current->value << " ";
        current = current->next;
        count++;
        if (count % 25 == 0) cout << endl;
    }
    cout << endl;
}

//menu(): presents menu, returns a validated user choice
//Arguments: none | Returns: validated user choice (int)
int menu()
{
    cout << "Enter:\t[1] Output LL\n";
    cout << "\t[2] Insert node\n";
    cout << "\t[3] Delete node\n";
    cout << "\t[4] Quit\n";
    cout << "\nYour choice: ";
    int num;
    cin >> num;
    while (num < 1 or num > 4 or cin.fail())
    {
        cout << "ERROR; 1-4 only: ";
        cin >> num;
    }
    return num;
}
