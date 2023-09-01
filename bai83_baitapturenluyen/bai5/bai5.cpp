#include <iostream>
using namespace std;

struct DNode
{
    int data;
    DNode *pNext;
    DNode *pPrevious;
};

struct DoubleList
{
    DNode *pHead;
    int nList;
};

void Initialize(DoubleList &list)
{
    list.pHead = NULL;
    list.nList = 0;
}

void PrintList(DoubleList list)
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

DNode *CreateDNode(int d)
{
    DNode *pNode = new DNode;
    pNode->data = d;
    pNode->pNext = NULL;
    pNode->pPrevious = NULL;
    return pNode;
}

void InsertFirst(DoubleList &list, int d)
{
    DNode *pNode = CreateDNode(d);
    if (list.pHead == NULL)
    {
        list.pHead = pNode;
    }
    else
    {

        pNode->pNext = list.pHead;
        list.pHead->pPrevious = pNode;
        list.pHead = pNode;
    }
    list.nList++;
}

void InsertLast(DoubleList &list, int d)
{
    DNode *pNode = CreateDNode(d);

    if (list.pHead == NULL)
    {
        list.pHead = pNode;
    }
    else
    {
        DNode *pTmp = list.pHead;
        while (pTmp->pNext != NULL)
        {
            pTmp = pTmp->pNext;
        }
        pTmp->pNext = pNode;
        pNode->pPrevious = pTmp;
    }
    list.nList++;
}

void InsertMid(DoubleList &list, int d, int pos)
{
    int n = list.nList;
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
    }
    list.nList++;
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
    else if (pDel->pNext == NULL)
    {
        pPre->pNext = NULL;
    }
    else
    {
        pPre->pNext = pDel->pNext;
        pDel->pNext->pPrevious = pPre;
    }
    list.nList--;
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
    DoubleList list;
    Initialize(list);
    InsertFirst(list, 10);
    InsertFirst(list, 12);
    PrintList(list);
    InsertLast(list, 100);
    cout << endl;
    PrintList(list);
    cout << endl;
    InsertMid(list, 12, 12);
    PrintList(list);
    cout << endl;
    ReMoveNode(list, 1212);
    cout << endl;
    PrintList(list);
    ReMoveNode(list, 100);
    cout << endl;
    InsertMid(list, 1, 2);
    PrintList(list);
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

    for (int i = 0; i < 10; i++)
    {
        InsertLast(list, 1 + rand() % 100);
    }
    PrintList(list);
    cout << "\nSort:\n";
    SortList(list);
    PrintList(list);
    FreeMemory(list);
}