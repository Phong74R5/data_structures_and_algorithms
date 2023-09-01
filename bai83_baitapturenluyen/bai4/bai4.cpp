#include <iostream>
#include <string>

using namespace std;

struct Subject
{
    int id;
    string name;
    int credit;
};

struct DNode
{
    Subject data;
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

DNode *CreateDNode(Subject d)
{
    DNode *pNode = new DNode;
    pNode->data = d;
    pNode->pNext = pNode->pPrevious = NULL;
    return pNode;
}

void InsertFirst(DoubleList &list, Subject d)
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
        cout << "\nID\tName\tCredits\n";
        while (pTmp != NULL)
        {
            cout << pTmp->data.id << "\t" << pTmp->data.name << "\t" << pTmp->data.credit << endl;
            pTmp = pTmp->pNext;
        }
    }
}


DoubleList Filter4(DoubleList list)
{
    DoubleList list4;
    Initialize(list4);
    if (list.pHead != NULL)
    {
        DNode *pTmp = list.pHead;
        while (pTmp != NULL)
        {
            if (pTmp->data.credit == 4)
            {
                InsertFirst(list4, pTmp->data);
            }
            pTmp = pTmp->pNext;
        }
    }
    return list4;
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
        Subject tmp;
        cout << "Subject " << i + 1 << endl;
        cout << "Enter id: ";
        cin >> tmp.id;
        cout << "Enter name: ";
        cin >> tmp.name;
        cout << "Enter credit: ";
        cin >> tmp.credit;
        InsertFirst(list, tmp);
    }
    PrintList(list);
    cout << "\nList of Subjects with 4 credit:";
    DoubleList list4 = Filter4(list);
    PrintList(list4);
}