#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
};

void Initialize(DoubleList &list)
{
    list.pHead = NULL;
}

DNode *CreateDNode(int d)
{
    DNode *pDNode = new DNode;
    pDNode->data = d;
    pDNode->pNext = pDNode->pPrevious = NULL;
    return pDNode;
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
            cout << pTmp->data << "";
            pTmp = pTmp->pNext;
        }
    }
}

DoubleList CreateBigInteger(char *str)
{
    DoubleList list;
    Initialize(list);
    for (int i = 0; i < strlen(str); i++)
    {
        char strTmp[1];
        strTmp[0] = str[i];
        int d = atoi(strTmp);
        InsertLast(list, d);
    }
    return list;
}

int main()
{
    DoubleList list = CreateBigInteger("1425252525252525252542544546");
    cout << "Big Integer: ";
    PrintList(list);    
    cout << endl;
}