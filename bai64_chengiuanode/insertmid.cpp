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
        while (pTmp != NULL)
        {
            cout << pTmp->data << "\t";
            pTmp = pTmp->pNext;
        }
    }
}

int SizeOfList(SingleList &list)
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
    if (list.pTail == NULL)
    {
        list.pHead = list.pTail = pNode;
    }
    else
    {
        list.pTail->pNext = pNode;
        list.pTail = pNode;
    }
}

void InsertMid(SingleList &list, int pos, int d)
{
    int n = SizeOfList(list);
    if (pos < 0 || pos > n)
    {
        cout << "Invalid value!!\n";
    }
    else
    {
        if (pos == 0)
        {
            InsertFirst(list, d);
        }
        else
        {
            if (pos == n)
            {
                InsertLast(list, d);
            }
            else
            {
                Node *pNode = CreateNode(d);
                Node *pPre = NULL;
                Node *pIns = list.pHead;
                int i = 0;
                while (pIns != NULL)
                {
                    if (pos == i)
                        break;
                    pPre = pIns;
                    pIns = pIns->pNext;
                    i++;
                }
                pPre->pNext = pNode;
                pNode->pNext = pIns;
            }
        }
    }
}

void RemoveNode(SingleList &list, int d)
{
    
}

int main()
{
    SingleList list;
    Initialize(list);
    for (int i = 0; i < 10; i++)
    {
        InsertLast(list, i);
    }
    InsertMid(list, 3, 12);
    PrintList(list);
}