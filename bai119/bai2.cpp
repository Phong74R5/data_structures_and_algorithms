#include <iostream>
#include <string.h>
using namespace std;

struct Customer
{
    int id;
    string name;
};

struct Node
{
    Customer data;
    Node *pLink;
};
struct Queue
{
    Node *pRear, *pFront;
};

void Initialize(Queue &Queue)
{
    Queue.pFront = Queue.pRear = NULL;
}

Node *CreateNode(Customer d)
{
    Node *pNode = new Node;
    pNode->data = d;
    pNode->pLink = NULL;
    return pNode;
}

void Enqueue(Queue &Queue, Customer d)
{
    Node *pNode = CreateNode(d);
    if (Queue.pFront == NULL)
    {
        Queue.pFront = Queue.pRear = pNode;
    }
    else
    {
        Queue.pRear->pLink = pNode;
        Queue.pRear = pNode;
    }
}

Customer Dequeue(Queue &Queue)
{
    if (Queue.pFront == NULL)
    {
        cout << "Queue is empty!!";
        exit(0);
    }
    Customer d = Queue.pFront->data;
    Node *pDel = Queue.pFront;
    Queue.pFront = Queue.pFront->pLink;
    pDel->pLink = NULL;
    delete pDel;
    return d;
}

int main()
{
    Queue Queue;
    Initialize(Queue);
    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Customer " << i + 1 << ":" << endl;
        Customer tmp;
        cout << "Enter id: ";
        cin >> tmp.id;
        cout << "Enter name: ";
        cin >> tmp.name;
        Enqueue(Queue, tmp);
    }
    cout << "ID\tName\n";
    for (int i = 0; i < n; i++)
    {
        Customer tmp = Dequeue(Queue);
        cout << tmp.id << "\t" << tmp.name << endl;
    }
}