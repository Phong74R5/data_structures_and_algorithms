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
        cout << "error!!\n";
    }
}

void deleteK(SingleList &list, int k)
{
    Node *pDel = list.pHead;
    if (pDel == NULL)
    {
        cout << "The list is empty\n";
        return;
    }
    else
    {
        Node *pPre = NULL;
        int i = 0;
        while (pDel != NULL)
        {
            if (pDel->data == k)
            {

                if (pDel == list.pHead)
                {
                    list.pHead = list.pHead->pNext;
                }
                else
                {
                    pPre->pNext = pDel->pNext;
                }
            }
            pPre = pDel;
            pDel = pDel->pNext;
        }
    }
}

void PrintList(SingleList &list)
{
    Node *pTmp = list.pHead;
    if (pTmp == NULL)
    {
        cout << "The list is empty";
        return;
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

int main()
{
    SingleList list;
    Initialize(list);
    for (int i = 0; i < 10; i++)
    {
        int d;
        cin >> d;
        InsertLast(list, d);
    }
    PrintList(list);
    cout << endl;
    int k;
    cin >> k;
    cout << endl;
    deleteK(list, k);
    PrintList(list);
}