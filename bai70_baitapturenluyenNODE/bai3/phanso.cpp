#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

struct phanso
{
    int tu;
    int mau;
};

struct Node
{
    phanso data;
    Node *pNext;
};

struct SingleList
{
    Node *pHead;
    Node *pTail;
    int nList;
};

void Initialize(SingleList &list)
{
    list.pHead = list.pTail = NULL;
    list.nList = 0;
}

int USCLN(int a, int b)
{
    if (a == 0)
        return b;
    return USCLN(b % a, a);
}
void toigian(int &TS, int &MS)
{
    int temp = USCLN(TS, MS);
    TS /= temp;
    MS /= temp;
    if (TS < 0 && MS < 0)
    {
        TS = abs(TS);
        MS = abs(MS);
    }
    else
    {
        if (TS < 0 || MS < 0)
        {
            TS = -1 * abs(TS);
            MS = abs(MS);
        }
    }
}

Node *CreateNode(phanso d)
{
    toigian(d.tu, d.mau);
    Node *pNode = new Node;
    if (pNode != NULL)
    {
        pNode->data.tu = d.tu;
        pNode->data.mau = d.mau;
        pNode->pNext = NULL;
    }
    else
    {
        cout << "Error!!";
    }
    return pNode;
}

void InsertLast(SingleList &list, phanso d)
{
    Node *pNode = CreateNode(d);
    if (list.pTail == NULL)
    {
        list.pHead = list.pTail = pNode;
    }
    else
    {
        list.pTail->pNext = pNode;
        list.pTail = pNode;
    }
    list.nList++; // Cập nhật số lượng phần tử của danh sách liên kết
}

void RemoveNode(SingleList &list, phanso d)
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
            if (pDel->data.tu == d.tu && pDel->data.mau == d.mau)
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
        else if (pDel == list.pTail)
        {
            list.pTail = pPre;
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
        list.nList--;
    }
}

void RemoveSame(SingleList &list)
{
    Node *pTmp1 = list.pHead;

    while (pTmp1 != NULL)
    {
        Node *pTmp2 = pTmp1;
        while (pTmp2 != NULL)
        {
            if (pTmp1->data.tu = pTmp2->data.tu)
            {
                RemoveNode(list, pTmp1->data);
            }
            pTmp2 = pTmp2->pNext;
        }
        pTmp1 = pTmp1->pNext;
    }
}

void PrintNode(SingleList &list)
{
    Node *pTmp = list.pHead;
    if (pTmp == NULL)
    {
        cout << "The list is empty!!";
    }
    else
    {
        while (pTmp != NULL)
        {
            cout << pTmp->data.tu << "/" << pTmp->data.mau << "  ";
            pTmp = pTmp->pNext;
        }
    }
}

int main()
{
    SingleList list;
    Initialize(list);
    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        phanso d;
        cout << "\nPhan so thu " << i + 1 << ": ";
        cin >> d.tu >> d.mau;
        InsertLast(list, d);
    }
    PrintNode(list);
    cout << endl;
    RemoveSame(list);
    PrintNode(list);
}