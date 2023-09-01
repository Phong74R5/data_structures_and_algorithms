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

int Compare2BigInteger(DoubleList list1, DoubleList list2)
{
    int n1 = SizeOfList(list1);
    int n2 = SizeOfList(list2);

    if (n1 > n2)
    {
        return 1;
    }
    else if (n1 < n2)
    {
        return -1;
    }
    else
    {
        DNode *pTmp1 = list1.pHead;
        DNode *pTmp2 = list2.pHead;
        while (pTmp1 != NULL && pTmp2 != NULL)
        {
            if (pTmp1->data < pTmp2->data)
                return -1;
            if (pTmp1->data > pTmp2->data)
                return 1;
            pTmp1 = pTmp1->pNext;
            pTmp2 = pTmp2->pNext;
        }
        return 0;
    }
}

DoubleList Sub2BigInteger(DoubleList list1, DoubleList list2)
{
    DoubleList Sub;
    Initialize(Sub);

    int n1 = SizeOfList(list1);
    int n2 = SizeOfList(list2);

    if (Compare2BigInteger(list1, list2) == 0)
    {
        InsertFirst(Sub, 0);
        return Sub;
    }
    else if (Compare2BigInteger(list1, list2) == -1)
    {
        return Sub;
    }
    else
    {

        DNode *tail1 = list1.pTail;
        DNode *tail2 = list2.pTail;
        int v2 = 0;
        while (tail1 != NULL)
        {
            int v1 = 0;
            if (tail1 != NULL && tail2 != NULL)
            {
                if (tail1->data >= (tail2->data + v2))
                {
                    v1 = tail1->data - (tail2->data + v2);
                    v2 = 0;
                }
                else
                {
                    v1 = tail1->data + 10 - (tail2->data + v2);
                    v2 = 1;
                }
                tail1 = tail1->pPrevious;
                tail2 = tail2->pPrevious;
            }
            else if (tail1 != NULL)
            {

                v1 = tail1->data - v2;
                v2 = 0;
                tail1 = tail1->pPrevious;
            }

            InsertFirst(Sub, v1);
        }
        while (Sub.pHead->data == 0)
        {
            DNode *pDel = Sub.pHead;
            Sub.pHead = pDel->pNext;
            Sub.pHead->pPrevious = NULL;
            pDel->pNext = NULL;
            pDel->pPrevious = NULL;
        }
        return Sub;
    }
}

void PrintList(DoubleList list)
{
    if (list.pHead == NULL)
    {
        cout << "Error!!";
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
    DoubleList list = Sub2BigInteger(CreateBigInteger("125544242290"), CreateBigInteger("12554424222"));
    PrintList(list);
}