#include <iostream>
using namespace std;

struct Node
{
    int data;
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

Node *CreateNode(int d)
{
    Node *pNode = new Node;
    if (pNode != NULL)
    {
        pNode->data = d;
        pNode->pNext = NULL;
        return pNode;
    }
    else
    {
        cout << "Error!!";
    }
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
            cout << pTmp->data << "\t";
            pTmp = pTmp->pNext;
        }
    }
}

int SizeOfList(SingleList &list)
{
    int n = 0;
    Node *pTmp = list.pHead;
    if (pTmp == NULL)
    {
        return n;
    }
    else
    {
        while (pTmp != NULL)
        {
            n++;
            pTmp = pTmp->pNext;
        }
    }
    return n;
}
void InsertFirst(SingleList &list, int d)
{
    Node *pNode = CreateNode(d);
    if (list.pHead == NULL)
    {
        list.pHead = list.pTail = pNode;
    }
    else
    {
        pNode->pNext = list.pHead;
        list.pHead = pNode;
    }
}

void InsertLast(SingleList &list, int d)
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
}

void InsertMid(SingleList &list, int pos, int d)
{
    int n = SizeOfList(list);
    if (pos < 0 || pos > n)
    {
        cout << "Invalid value!!\n";
    }
    else
    {
        if (pos == 0)
        {
            InsertFirst(list, d);
        }
        else
        {
            if (pos == n)
            {
                InsertLast(list, d);
            }
            else
            {
                Node *pNode = CreateNode(d);
                Node *pPre = NULL;
                Node *pIns = list.pHead;
                int i = 0;
                while (pIns != NULL)
                {
                    if (pos == i)
                        break;
                    pPre = pIns;
                    pIns = pIns->pNext;
                    i++;
                }
                pPre->pNext = pNode;
                pNode->pNext = pIns;
            }
        }
    }
}

void RemoveNode(SingleList &list, int d)
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
            if (pDel->data == d)
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
    }
}

Node *SearchNode(SingleList &list, int d)
{
    Node *pTmp = list.pHead;
    while (pTmp != NULL)
    {
        if (pTmp->data == d)
        {
            break;
        }
        pTmp = pTmp->pNext;
    }
    return pTmp;
}
int main()
{
    system("color 0A");
    SingleList list;
    int n;
    Initialize(list);
    for (int i = 0; i < 10; i++)
    {
        InsertLast(list, i);
    }
    PrintList(list);
    cout << "\nEnter n: ";
    cin >> n;
    Node *pSearch = SearchNode(list, n);
    if (pSearch == NULL)
    {

        cout << "Not found " << n << " !!" << endl;
    }
    else
    {
        cout << "Found " << pSearch->data << " in list" << endl;
    }
}