#include <algorithm>
#include <cstring>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

using namespace std;
struct Node
{
    int data;
    Node *pNext;
};
struct SingleList
{
    Node *pHead;
};
void Initialize(SingleList &list)
{
    list.pHead = NULL;
}
Node *CreateNode(int d)
{
    Node *pNode = new Node;
    if (pNode != NULL)
    {
        pNode->data = d;
        pNode->pNext = NULL;
    }
    else
    {
        cout << "Error!!";
    }
    return pNode;
}
void PrintList(SingleList list)
{
    Node *pTmp = list.pHead;
    if (pTmp == NULL)
    {
        cout << "The list is empty";
        return;
    }
    while (pTmp != NULL)
    {
        cout << pTmp->data << "\t";
        pTmp = pTmp->pNext;
    }
}
int SizeOfList(SingleList list)
{
    Node *pTmp = list.pHead;
    int nSize = 0;
    while (pTmp != NULL)
    {
        pTmp = pTmp->pNext;
        nSize++;
    }
    return nSize;
}
void InsertFirst(SingleList &list, int d)
{
    Node *pNode = CreateNode(d);
    if (list.pHead == NULL)
    {
        list.pHead = pNode;
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
        list.pHead = pNode;
    }
    else
    {
        Node *pTmp = list.pHead;
        while (pTmp->pNext != NULL)
        {
            pTmp = pTmp->pNext;
        }
        pTmp->pNext = pNode;
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
    Node *pDel = list.pHead;
    if (pDel == NULL)
    {
        cout << "The list is empty";
        return;
    }
    else
    {
        Node *pPre = NULL;
        int i = 0;
        while (pDel != NULL)
        {
            if (pDel->data == d)
            {
                break;
            }
            pPre = pDel;
            pDel = pDel->pNext;
        }
        if (pDel == list.pHead)
        {
            list.pHead = list.pHead->pNext;
            pDel->pNext = NULL;
            delete pDel;
            pDel = NULL;
        }
        else
        {
            pPre->pNext = pDel->pNext;
            pDel->pNext = NULL;
            delete pDel;
            pDel = NULL;
        }
    }
    
}
Node *SearchNode(SingleList &list, int d)
{
    Node *pTmp = list.pHead;
    while (pTmp != NULL)
    {
        if (pTmp->data == d)
        {
            break;
        }
        pTmp = pTmp->pNext;
    }
    return pTmp;
}
void SortList(SingleList &list)
{
    for (Node *pTmp = list.pHead; pTmp != NULL; pTmp = pTmp->pNext)
    {
        for (Node *pTmp2 = pTmp->pNext; pTmp2 != NULL; pTmp2 = pTmp2->pNext)
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
int main()
{
    system("color 0A");
    srand(time(NULL));
    SingleList list;
    int n;
    Initialize(list);
    for (int i = 0; i < 10; i++)
    {
        InsertLast(list, rand() % 100);
    }
    PrintList(list);
    SortList(list);
    cout <<"\nSort: "<< endl;
    PrintList(list);
}