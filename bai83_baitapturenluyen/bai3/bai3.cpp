#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct DNode
{
    int data;
    DNode *pNext;
    DNode *pPrevious;
};

struct DLink
{
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

void SplitNode(DLink &list, DNode *&pA)
{
    //?tách node ra khỏi danh sách liên kết
    if (pA == list.pHead)
    {
        list.pHead = pA->pNext;
    }
    else if (pA->pNext == NULL)
    {
        pA->pPrevious->pNext = pA->pNext;
    }
    else
    {
        pA->pPrevious->pNext = pA->pNext;
        pA->pNext->pPrevious = pA->pPrevious;
    }
    pA->pNext = pA->pPrevious = NULL;
    //?? kết thúc tách node
}

void SortList(DLink &list)
{
    DNode *Check = list.pHead;
    int n = 0;
    while (Check != NULL)
    {

        DNode *Result = Check;
        DNode *pTmp = Result->pNext;
        // tìm phần tử nhỏ nhất
        while (pTmp != NULL)
        {
            if (Result->data < pTmp->data)
            {
                Result = pTmp;
            }
            pTmp = pTmp->pNext;
        }
        // Tách phần tử nhỏ nhất ra khỏi danh sách liên kết
        SplitNode(list, Result);
        // Gắn lại vào đầu danh sách danh sách liên kết
        Result->pNext = list.pHead;
        list.pHead->pPrevious = Result;
        list.pHead = Result;

        n++;
        Check = list.pHead;
        // Giới hạn kiểm tra danh sách 1 Node
        for (int i = 0; i < n; i++)
        {
            Check = Check->pNext;
        }
    }
}

int main()
{
    srand(time(NULL));
    DLink list;
    Initialize(list);
    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        InsertLast(list, 1 + rand() % 100);
    }
    PrintList(list);
    cout << "\nSort:\n";
    SortList(list);
    PrintList(list);
}