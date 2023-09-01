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

void PrintList(SingleList &list)
{
    Node *pTmp = list.pHead;
    if (pTmp == NULL)
    {
        cout << "The list is empty";
    }
    else
    {
        cout << pTmp->data << "  ";
        pTmp = pTmp->pNext;
    }
}

int SizeofList(SingleList &list)
{
    int n = 0;
    Node *pTmp = list.pHead;
    if (pTmp == NULL)
    {
        return n;
    }
    else
    {
        while (pTmp != NULL)
        {
            n++;
            pTmp = pTmp->pNext;
        }
    }
    return n;
}
void InsertFirst(SingleList &list, int d)
{
    Node *pNode = CreateNode(d);
    if (list.pHead == NULL)
    {
        list.pHead = list.pTail = pNode;
    }
    else
    {
        pNode->pNext = list.pHead;
        list.pHead = pNode;
    }
}

void InsertLast(SingleList &list, int d)
{
    Node *pNode = CreateNode(d);
    if (list.pHead == NULL)
    {
        list.pHead = list.pTail = pNode;
    }
    else
    {
        list.pTail->pNext = pNode;
        list.pTail = pNode;
    }
}