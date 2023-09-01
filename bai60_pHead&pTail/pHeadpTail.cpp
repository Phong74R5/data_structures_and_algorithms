#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *pNext;
};

struct SingleList
{
    Node *pHead;
    Node *pTail;
};

void Initialize(SingleList &list)
{
    list.pHead = list.pTail = NULL;
}

Node *CreateNode(int d)
{
    Node *pNode = new Node;
    if (pNode != NULL)
    {
        pNode->data = d;
        pNode->pNext = NULL;
        return pNode;
    }
    else
    {
        cout << "Error!!";
    }
}
