#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct DNode
{
    int data;
    DNode *pNext, *pPrevious;
};

struct DoubleList
{
    /* data */
    DNode *pHead, *pTail;
};

void Initialize(DoubleList &list)
{
    list.pHead = list.pTail = NULL;
}

void PrintList(DoubleList list)
{
    if (list.pHead == NULL)
    {
        cout << "The list is empty!!";
        return;
    }
    DNode *pTmp = list.pHead;
    while (pTmp != NULL)
    {
        cout << pTmp->data << "  ";
        pTmp = pTmp->pNext;
    }
}

int SizeOfList(DoubleList list)
{
    if (list.pHead == NULL)
    {
        return 0;
    }
    int n = 0;
    DNode *pTmp = list.pHead;
    while (pTmp == NULL)
    {
        n++;
        pTmp = pTmp->pNext;
    }
    return n;
}

DNode *CreateDNode(int d)
{
    DNode *pNode = new DNode;
    pNode->data = d;
    pNode->pNext = pNode->pPrevious = NULL;
    return pNode;
}

void InsertFirst(DoubleList &list, int d)
{
    DNode *pNode = CreateDNode(d);
    if (list.pHead == NULL)
    {
        list.pHead = list.pTail = pNode;
    }
    else
    {
        pNode->pNext = list.pHead;
        list.pHead->pPrevious = pNode;
        list.pHead = pNode;
    }
}

void InsertLast(DoubleList &list, int d)
{
    DNode *pNode = CreateDNode(d);
    if (list.pHead == NULL)
    {
        list.pHead = list.pTail = pNode;
    }
    else
    {
        list.pTail->pNext = pNode;
        pNode->pPrevious = list.pTail;
        list.pTail = pNode;
    }
}

void InsertMid(DoubleList &list, int d, int pos)
{
    int n = SizeOfList(list);
    if (pos < 0 || pos > n)
    {
        cout << "Invalid value!!\n";
        return;
    }
    else if (pos == 0)
    {
        InsertFirst(list, d);
    }
    else if (pos == n - 1)
    {
        InsertLast(list, d);
    }
    else
    {
        DNode *pNode = CreateDNode(d);
        DNode *pTmp = list.pHead;
        DNode *pPre = NULL;
        int i = 0;
        while (pTmp != NULL)
        {
            if (i == pos)
            {
                break;
            }
            pPre = pTmp;
            pTmp = pTmp->pNext;
            i++;
        }
        pNode->pNext = pTmp;
        pTmp->pPrevious = pNode;
        pPre->pNext = pNode;
        pNode->pPrevious = pPre;
    }
}

void ReMoveNode(DoubleList &list, int d)
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
    else if (pDel = list.pTail)
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

DNode *Search(DoubleList list, int d)
{
    DNode *pTmp = list.pHead;
    while (pTmp != NULL)
    {
        /* code */
        if (pTmp->data == d)
        {
            break;
        }
        pTmp = pTmp->pNext;
    }
    return pTmp;
}

void SortList(DoubleList &list)
{
    for (DNode *pTmp = list.pHead; pTmp != NULL; pTmp = pTmp->pNext)
    {
        for (DNode *pTmp2 = pTmp->pNext; pTmp2 != NULL; pTmp2 = pTmp2->pNext)
        {
            if (pTmp->data > pTmp2->data)
            {
                int tmp = pTmp->data;
                pTmp->data = pTmp2->data;
                pTmp2->data = tmp;
            }
        }
    }
}

void FreeMemory(DoubleList &list)
{
    cout << "\nStarting to delete. . .\n";
    while (list.pHead != NULL)
    {
        DNode *pTmp = list.pHead;
        list.pHead = pTmp->pNext;
        pTmp->pNext = NULL;
        pTmp->pPrevious = NULL;
        cout << pTmp->data << " is deleted\n";
        delete pTmp;
        pTmp = NULL;
    }
    cout << "\nDeleted is complete!!\n";
}

int main()
{
    srand(time(NULL));
    DoubleList list;
    Initialize(list);
    InsertFirst(list, 3);
    InsertLast(list, 1000);
    InsertMid(list, 0, 0);
    InsertMid(list, 1, 0);

    PrintList(list);
    cout << endl;
    int n = 1000;
    DNode *pSearch = Search(list, n);
    if (pSearch == NULL)
    {

        cout << "\nNot found " << n << " !!" << endl;
    }
    else
    {
        cout << "Found " << pSearch->data << " in list" << endl;
    }
    ReMoveNode(list, 1);
    SortList(list);
    cout << "\rSort\n";
    PrintList(list);
    FreeMemory(list);
}