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
};

void Initialize(SingleList &list)
{
    list.pHead = NULL;
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

phanso SumNode(SingleList &list)
{
    phanso TONG;
    TONG.tu = 0, TONG.mau = 1;
    Node *pTmp = list.pHead;
    if (pTmp == NULL)
    {
        return TONG;
    }
    else
    {
        while (pTmp != NULL)
        {
            TONG.tu = TONG.tu * pTmp->data.mau + pTmp->data.tu * TONG.mau;
            TONG.mau = TONG.mau * pTmp->data.mau;
            pTmp = pTmp->pNext;
        }
        toigian(TONG.tu, TONG.mau);
        return TONG;
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
    phanso sum = SumNode(list);
    if (sum.tu == 0)
    {
        cout << "Tong cua cac phan so la: 0";
    }
    else
    {
        cout << "Tong cua cac phan so la: " << sum.tu << "/" << sum.mau << endl;
    }
}