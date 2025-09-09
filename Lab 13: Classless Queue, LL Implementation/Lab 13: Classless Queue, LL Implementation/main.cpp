//*****************
//Program Name: Lab 13: Classless Queue, LL Implementation
//Author: Jaspreet Singh
//IDE Used: X-Code
//Program description: implement a queue using a linked list
//*****************

#include <iostream>
using namespace std;

static int queue_size=0;
const int RUNS=15;
struct Node
{
    int val;
    Node *next;
};

int front(Node *);
int back(Node *);
void print(Node *);
Node* addQueue(int, Node*);
Node* deleteQueue(Node *);

int main() {
    int num=0, rando;
    Node *queues = new Node;
    srand(time(0));
    for(int i=0;i<RUNS;i++)
    {
        cout << "Operation #" << i+1 << " : \n";
        
        rando=rand()%101;
        if(rando < 51)
        {
            num=rand()%100;
            cout << "addQueue operation in progress: " << num << endl;
            queues=addQueue(num, queues);
            print(queues);
        }
        else
        {
            if(queue_size > 0)
            {
                cout << "deleteQueue operation in progress: " << front(queues) << endl;
                queues=deleteQueue(queues);
                print(queues);
            }
            else
                cout << "Can not delete from an empty queue.\n";
        }
        cout << endl;
    }
    cout << "This is my original work; apart from standard tutoring or class collaboration,"
         << "I neither received help nor copied this code from another source.\n";
    return 0;
}
//front(): to find the front element
//Arguments: Node* | Returns: int
int front(Node *head)
{
    if(head)
    {
        return head->val;
    }
   else
       return -1;
}
//back(): to find the last element
//Arguments: Node* | Returns: int
int back(Node * head)
{
    if(!head)
    {
        Node *temp=head;
        while(!temp)temp=temp->next;
        return temp->val;
    }
    else return -1;
}
//print(): to print some data
//Arguments: Node* | Returns: none
void print(Node *head)
{
    Node *temp=head;
    if(temp)
    {
        cout << "Current queue: ";
        while(temp)
        {
            cout << temp->val << " ";
            temp=temp->next;
        }
        cout << "\nQueue size: " << queue_size << endl;
    }
    else
        cout << "The Queue is empty.\n";
}
//addQueue(): to add data
//Arguments: int, Node* | Returns: Node*
Node* addQueue(int valu, Node* head)
{
    Node *temp= new Node;
    Node *ptr;
    temp->val=valu;
    temp->next=nullptr;
    if(queue_size==0)
    {
        head= temp;
    }
    else
    {
        ptr = head;
        while(ptr->next)
            ptr=ptr->next;
        ptr->next= temp;
    }
    queue_size++;
    return head;
}
//deleteQueue(): to delete an element from queue
//Arguments: Node* | Returns: Node*
Node* deleteQueue(Node * head)
{
    if(head)
    {
        Node *temp=new Node;
        temp=head;
        head=head->next;
        delete temp;
        queue_size--;
    }
   else
       cout << "Error! Queue Empty.\n";
    return head;
}
