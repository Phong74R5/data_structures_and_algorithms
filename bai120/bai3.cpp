#include <iostream>
#include <string.h>
using namespace std;

struct Node
{
    char data;
    Node *pLink;
};

struct Queue
{
    Node *pRear, *pFront;
};

void Initialize(Queue &queue)
{
    queue.pFront = queue.pRear = NULL;
}

Node *CreateNode(char value)
{
    Node *pNode = new Node;
    pNode->data = value;
    pNode->pLink = NULL;
}

void Enqueue(Queue &queue, char value)
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

Node *Dequeue(Queue &queue)
{
    if (queue.pFront == NULL)
    {
        cout << "Queue is empty!!";
        exit(0);
    }
    Node *pNode = queue.pFront;
    queue.pFront = queue.pFront->pLink;
    pNode->pLink = NULL;
    return pNode;
}
bool isEmpty(Queue queue)
{
    return queue.pFront != NULL;
}

int main()
{
    Queue queue;
    Initialize(queue);
    char str[255];
    cout << "Enter string: ";
    gets(str);
    for (int i = 0; i < strlen(str); i++)
    {
        Enqueue(queue, str[i]);
    }
    for (int i = 0; isEmpty(queue); i++)
    {
        cout << Dequeue(queue)->data;
    }
    cout << endl;
}