#include <iostream>
using namespace std;

struct Node
{
    double data;
    Node *pLink;
};

struct Queue
{
    Node *pRear, *pFront;
};

void Initialize(Queue &q)
{
    q.pRear = q.pFront = NULL;
}

Node *CreateNode(double d)
{
    Node *pNode = new Node;
    if (pNode == NULL)
    {
        cout << "Error!!";
        exit(0);
    }
    pNode->data = d;
    pNode->pLink = NULL;
}

void Enqueue(Queue &queue, double value)
{
    Node *pNode = CreateNode(value);
    if (queue.pFront == NULL)
    {
        queue.pFront = queue.pRear = pNode;
    }
    else
    {
        queue.pRear->pLink = pNode;
        queue.pRear = pNode;
    }
}

double Dequeue(Queue &queue)
{
    if (queue.pFront == NULL)
    {
        cout << "Queue is empty!!";
        exit(0);
    }
    else
    {
        double d = queue.pFront->data;
        Node *pDel = queue.pFront;
        queue.pFront = queue.pFront->pLink;
        pDel->pLink = NULL;
        delete pDel;
        return d;
    }
}

int main()
{
    Queue queue;
    Initialize(queue);
    Enqueue(queue, 5.2);
    Enqueue(queue, 0.3);
    Enqueue(queue, 0.4);
    cout << Dequeue(queue) << endl;
    cout << Dequeue(queue) << endl;
    cout << Dequeue(queue) << endl;
}