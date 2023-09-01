#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
    int data_x;
    int data_n;
    Node *pNext;
};

struct SingleList
{
    Node *pHead;
    Node *pTail;
};

void Initialize(SingleList &list)
{
    list.pHead = list.pTail = NULL;
}

Node *CreateNode(int x, int n)
{
    Node *pNode = new Node;
    if (pNode != NULL)
    {
        pNode->data_x = x;
        pNode->data_n = n;
        pNode->pNext = NULL;
    }
    else
    {
        cout << "Error!!";
    }
    return pNode;
}

void InsertLast(SingleList &list, int x, int n)
{
    Node *pNode = CreateNode(x, n);
    if (list.pHead == NULL)
    {
        list.pHead = list.pTail = pNode;
    }
    else
    {
        list.pTail->pNext = pNode;
        list.pTail = pNode;
    }
}

int S(SingleList &list, int x, int n)
{
    int S = 0;
    for (int i = 0; i < n; i++)
    {
        InsertLast(list, x, i + 1);
        S += pow(x, i + 1);
    }
    return S;
}

void PrintList(SingleList &list)
{
    Node *pTmp = list.pHead;
    if (pTmp == NULL)
    {
        cout << "The list is empty";
    }
    else
    {
        while (pTmp != NULL)
        {
            cout << pTmp->data_x << "^" << pTmp->data_n << "\t";
            pTmp = pTmp->pNext;
        }
    }
}

int main()
{
    SingleList list;
    Initialize(list);
    int x, n;
    cout << "Enter x, n: ";
    cin >> x >> n;
    int Sxn = S(list, x, n);
    cout << "S(" << x << ", " << n << ") = " << Sxn << endl;
    cout << "List: " << endl;
    PrintList(list);
}