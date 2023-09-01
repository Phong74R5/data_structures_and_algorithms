#include <iostream>
#include <string.h>
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
    DNode *pTail;
};

void Initialize(DoubleList &list)
{
    list.pHead = list.pTail = NULL;
}

DNode *CreateDNode(int d)
{
    DNode *pNode = new DNode;
    pNode->data = d;
    pNode->pNext = pNode->pPrevious = NULL;
    return pNode;
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

DoubleList Sum2BigInteger(DoubleList list1, DoubleList list2)
{
    DoubleList Sum;
    Initialize(Sum);
    DNode *tail1 = list1.pTail;
    DNode *tail2 = list2.pTail;
    int v2 = 0;
    while (tail1 != NULL || tail2 != NULL)
    {
        int v1 = 0;
        if (tail1 != NULL && tail2 != NULL)
        {
            v1 = tail1->data + tail2->data;
        }
        else if (tail1 != NULL)
        {
            v1 = tail1->data;
        }
        else if (tail2 != NULL)
        {
            v1 = tail2->data;
        }
        v1 = v1 + v2;
        if (v1 >= 10)
        {
            v2 = v1 / 10;
            v1 = v1 % 10;
        }
        else
        {
            v2 = 0;
        }
        InsertFirst(Sum, v1);
        if (tail1 != NULL)
        {
            tail1 = tail1->pPrevious;
        }
        if (tail2 != NULL)
        {
            tail2 = tail2->pPrevious;
        }
    }
    if (v2 != 0)
    {
        InsertFirst(Sum, v2);
    }
    return Sum;
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
        cout << pTmp->data;
        pTmp = pTmp->pNext;
    }
}

int main()
{
    DoubleList list = Sum2BigInteger(CreateBigInteger("213132"), CreateBigInteger("6566555555555555546544444444442"));
    PrintList(list);
}