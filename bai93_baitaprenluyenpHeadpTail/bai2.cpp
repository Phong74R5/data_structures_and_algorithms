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
    DNode *pHead, *pTail;
};

void Initialize(DoubleList &list)
{
    list.pHead = list.pTail = NULL;
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
        list.pHead = list.pTail = pNode;
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
    while (pTmp!= NULL)
    {
        DNode *pTmp1 = pTmp->pNext;
        while (pTmp1 != NULL)
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

void ReMoveNode(DoubleList &list, int id)
{
    if (list.pHead == NULL)
    {
        cout << "The list is empty!!";
        return;
    }
    DNode *pPre = NULL;
    DNode *pDel = list.pHead;
    while (pDel != NULL)
    {
        if (pDel->data.id == id)
        {
            break;
        }
        pPre = pDel;
        pDel = pDel->pNext;
    }
    if (pDel == NULL)
    {
        cout << "Could not found number!!";
    }
    else if (pDel == list.pHead)
    {
        list.pHead = pDel->pNext;
    }
    else if (pDel = list.pTail)
    {
        pPre->pNext = NULL;
    }
    else
    {
        pPre->pNext = pDel->pNext;
        pDel->pNext->pPrevious = pPre;
    }
    pDel = NULL;
    delete pDel;
}

DoubleList Filter(DoubleList list, double a, double b)
{
    DoubleList listAB;
    Initialize(listAB);
    if (b < a)
    {
        cout << "Error!!";
        return listAB;
    }

    if (list.pHead != NULL)
    {
        DNode *pTmp = list.pHead;
        while (pTmp != NULL)
        {
            if (pTmp->data.price >= a && pTmp->data.price <= b)
            {
                InsertFirst(listAB, pTmp->data);
            }
            pTmp = pTmp->pNext;
        }
        SortDown(listAB);
    }
    return listAB;
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
    int id, a, b;
    cout << "\nEnter ID to delete: ";
    cin >> id;
    ReMoveNode(list, id);
    PrintList(list);
    cout << "\nEnter a, b: ";
    cin >> a >> b;
    PrintList(Filter(list, a, b));
}