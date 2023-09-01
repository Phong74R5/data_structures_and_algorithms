#include <iostream>
#include <math.h>
using namespace std;

struct FracSxn
{
    int numerator;
    int denominator;
};

struct Node
{
    FracSxn data;
    Node *pNext;
};

struct SingleList
{
    Node *pHead, *pTail;
};

void Initialize(SingleList &list)
{
    list.pHead = list.pTail = NULL;
}

Node *CreateNode(FracSxn d)
{
    Node *pNode = new Node;
    pNode->data = d;
    pNode->pNext = NULL;
}

void InsertLast(SingleList &list, FracSxn d)
{
    Node *pNode = CreateNode(d);
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

double factorial(int n)
{
    double fac = 1;
    for (int i = 1; i <= n; i++)
    {
        fac *= i;
    }
    return fac;
}

void InsertListFrac(SingleList &list, int x, int n)
{

    for (int i = 1; i <= n; i++)
    {
        FracSxn tmp = {x, i};
        InsertLast(list, tmp);
    }
}

void PrintListFrac(SingleList &list, int n)
{
    Node *pTmp = list.pHead;
    if (pTmp == NULL)
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        int i = 1;
        while (pTmp != NULL)
        {
            if (i != n)
                cout << "(" << pTmp->data.numerator << "^" << i << ")"
                     << "/(" << pTmp->data.denominator << "!)"
                     << "+";
            else
                cout << "(" << pTmp->data.numerator << "^" << i << ")"
                     << "/(" << pTmp->data.denominator << "!)";
            pTmp = pTmp->pNext;
            i++;
        }
    }
}

double Sxn(SingleList &list)
{
    Node *pTmp = list.pHead;
    double S = 0;
    if (list.pHead == NULL)
    {
        return 0;
    }
    else
    {
        int i = 1;
        while (pTmp != NULL)
        {
            S += pow(pTmp->data.numerator, i) / factorial(pTmp->data.denominator);
            pTmp = pTmp->pNext;
            i++;
        }
    }
    return S;
}

int main()
{
    SingleList list;
    int x, n;
    cout << "Enter x, n: ";
    cin >> x >> n;
    Initialize(list);
    InsertListFrac(list, x, n);
    cout << "S(" << x << ", " << n << ") = ";
    PrintListFrac(list, n);
    cout << " = " << Sxn(list) << endl;
}