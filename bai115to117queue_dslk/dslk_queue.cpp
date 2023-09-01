#include <iostream>
using namespace std;

struct Node
{
    int data;
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

Node *CreateNode(int d)
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

void Enqueue(Queue &queue, int value)
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

int Dequeue(Queue &queue)
{
    if (queue.pFront == NULL)
    {
        cout << "Queue is empty!!";
        exit(0);
    }
    else
    {
        int d = queue.pFront->data;
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
    Enqueue(queue, 5);
    Enqueue(queue, 3);
    Enqueue(queue, 4);
    cout << Dequeue(queue);
    cout << Dequeue(queue);
    cout << Dequeue(queue);
}