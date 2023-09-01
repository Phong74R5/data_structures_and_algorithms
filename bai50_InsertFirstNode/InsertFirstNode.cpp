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
int main()
{
    system("color 0A");

    SingleList list;
    Initialize(list);
    for (int i = 3; i > 0; i--)
    {
        InsertFirst(list, i);
    }
    PrintList(list);
    cout << "\nHave " << SizeOfList(list) << " Node\n";

    system("pause");
}