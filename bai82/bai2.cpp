#include <iostream>
#include <string>

using namespace std;

struct Product
{
    int id;
    string name;
    double price;
};

struct DNode
{
    Product data;
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

DNode *CreateDNode(Product d)
{
    DNode *pNode = new DNode;
    pNode->data = d;
    pNode->pNext = pNode->pPrevious = NULL;
    return pNode;
}

void InsertFirst(DoubleList &list, Product d)
{
    DNode *pNode = CreateDNode(d);
    if (list.pHead == NULL)
    {
        list.pHead = pNode;
    }
    else
    {

        pNode->pNext = list.pHead;
        list.pHead->pPrevious = pNode;
        list.pHead = pNode;
    }
}

void PrintList(DoubleList list)
{
    if (list.pHead == NULL)
    {
        cout << "The list is empty!!";
    }
    else
    {
        DNode *pTmp = list.pHead;
        cout << "\nID\tName\tPrice\n";
        while (pTmp != NULL)
        {
            cout << pTmp->data.id << "\t" << pTmp->data.name << "\t" << pTmp->data.price << endl;
            pTmp = pTmp->pNext;
        }
    }
}

void Swap(Product &a, Product &b)
{
    Product tmp = a;
    a = b;
    b = tmp;
}

void SortDown(DoubleList &list)
{
    DNode *pTmp = list.pHead;
    while (pTmp->pNext != NULL)
    {
        DNode *pTmp1 = pTmp->pNext;
        while (pTmp1->pNext != NULL)
        {
            if (pTmp->data.price < pTmp1->data.price)
            {
                Swap(pTmp->data, pTmp1->data);
            }
            pTmp1 = pTmp1->pNext;
        }
        pTmp = pTmp->pNext;
    }
}

DoubleList Filter500(DoubleList list)
{
    DoubleList list500;
    Initialize(list500);
    if (list.pHead != NULL)
    {
        DNode *pTmp = list.pHead;
        while (pTmp != NULL)
        {
            if (pTmp->data.price >= 500)
            {
                InsertFirst(list500, pTmp->data);
            }
            pTmp = pTmp->pNext;
        }
    }
    return list500;
}

int main()
{
    DoubleList list;
    Initialize(list);
    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Product tmp;
        cout << "Product " << i + 1 << endl;
        cout << "Enter id: ";
        cin >> tmp.id;
        cout << "Enter name: ";
        cin >> tmp.name;
        cout << "Enter price: ";
        cin >> tmp.price;
        InsertFirst(list, tmp);
    }
    PrintList(list);
    cout << "\nSort:";
    SortDown(list);
    PrintList(list);
    cout << "\nList of product with price over 500$:";
    DoubleList list500 = Filter500(list);
    PrintList(list500);
}