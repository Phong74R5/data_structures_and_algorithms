#include <iostream>

using namespace std;

struct DNode
{
    /* data */
    int data;
    DNode *pNext;
    DNode *pPrevious;
};

struct DLink
{
    /* data */
    DNode *pHead;
};

void Initialize(DLink &list)
{
    list.pHead = NULL;
}

DNode *CreateDNode(int d)
{
    DNode *pNode = new DNode;
    pNode->data = d;
    pNode->pNext = NULL;
    pNode->pPrevious = NULL;
    return pNode;
}

void InsertLast(DLink &list, int d)
{
    DNode *pNode = CreateDNode(d);
    if (list.pHead == NULL)
    {
        list.pHead = pNode;
        return;
    }
    DNode *pTmp = list.pHead;
    while (pTmp->pNext != NULL)
    {
        pTmp = pTmp->pNext;
    }
    pTmp->pNext = pNode;
    pNode->pPrevious = pTmp;
}

void RemoveNode(DLink &list, int d)
{
    if (list.pHead == NULL)
    {
        cout << "The list is empty!!";
        return;
    }
    DNode *pPre = NULL;
    DNode *pDel = list.pHead;
    while (pDel != NULL)
    {
        if (pDel->data == d)
        {
            break;
        }
        pPre = pDel;
        pDel = pDel->pNext;
    }
    if (pDel == NULL)
    {
        cout << "Could not found number!!";
    }
    else if (pDel == list.pHead)
    {
        list.pHead = pDel->pNext;
    }
    else if (pDel->pNext == NULL)
    {
        pPre->pNext = NULL;
    }
    else
    {
        pPre->pNext = pDel->pNext;
        pDel->pNext->pPrevious = pPre;
    }
    pDel = NULL;
    delete pDel;
}

void RemoveSame(DLink &list)
{
    DNode *pTmp1 = list.pHead;

    while (pTmp1 != NULL)
    {
        DNode *pTmp2 = pTmp1->pNext;
        while (pTmp2 != NULL)
        {
            if (pTmp1->data == pTmp2->data)
            {
                RemoveNode(list, pTmp1->data);
            }
            pTmp2 = pTmp2->pNext;
        }
        pTmp1 = pTmp1->pNext;
    }
}

void PrintList(DLink list)
{
    DNode *pTmp = list.pHead;
    if (pTmp == NULL)
    {
        cout << "The list is empty";
    }
    else
    {
        while (pTmp != NULL)
        {
            cout << pTmp->data << "  ";
            pTmp = pTmp->pNext;
        }
    }
}

int main()
{
    int n;
    DLink list;
    Initialize(list);
    cout << "Enter n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cout << "Enter number " << i + 1 << ": ";
        cin >> tmp;
        InsertLast(list, tmp);
    }
    PrintList(list);
    cout << "\nAfter filtering the list:\n";
    RemoveSame(list);
    PrintList(list);
}