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
        cout << "error!!\n";
    }
}

int SizeOfList(SingleList &list)
{
    Node *pTmp = list.pHead;
    int n = 0;
    while (pTmp != NULL)
    {
        n++;
        pTmp = pTmp->pNext;
    }
    return n;
}

void PrintList(SingleList &list)
{
    Node *pTmp = list.pHead;
    if (pTmp == NULL)
    {
        cout << "The list is empty";
        return;
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

void InsertLast(SingleList &list, int d)
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
        cout << "The list is empty\n";
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
int SumList(SingleList &list)
{
    int S = 0;
    Node *pTmp = list.pHead;
    if (pTmp == NULL)
    {
        delete pTmp;
        return S;
    }
    else
    {

        while (pTmp != NULL)
        {
            S += pTmp->data;
            pTmp = pTmp->pNext;
        }
        delete pTmp;
        return S;
    }
}
void SortList(SingleList &list)
{
    for (Node *pTmp = list.pHead; pTmp != NULL; pTmp = pTmp->pNext)
    {
        for (Node *pTmp2 = pTmp->pNext; pTmp2 != NULL; pTmp2 = pTmp2->pNext)
        {
            if (pTmp->data > pTmp2->data)
            {
                int tmp = pTmp->data;
                pTmp->data = pTmp2->data;
                pTmp2->data = tmp;
            }
        }
    }
}

void FreeMemory(SingleList &list)
{
    cout << "\nStarting to delete. . .";
    while (list.pHead != NULL)
    {
        Node *pTmp = list.pHead;
        list.pHead = pTmp->pNext;
        pTmp->pNext = NULL;
        cout << pTmp->data << " is deleted\n";
        delete pTmp;
        pTmp = NULL;
    }
    cout << "\nDeleted is complete!!\n";
}

void Menu()
{
    cout << "\n+--------------------Menu--------------------+\n"
         << "| 1. List initialization                     |\n"
         << "| 2. Add node                                |\n"
         << "| 3. Total value of nodes                    |\n"
         << "| 4. Search                                  |\n"
         << "| 5. Sort                                    |\n"
         << "| 6. Delete                                  |\n"
         << "| 7. Exit                                    |\n"
         << "+--------------------------------------------+\n";
}

void MenuAddNode()
{
    cout << "\n+--------------------Menu--------------------+\n"
         << "| 1. Insert First                            |\n"
         << "| 2. Insert Mid                              |\n"
         << "| 3. Insert Last                             |\n"
         << "| 4. exit                                    |\n"
         << "+--------------------------------------------+\n";
}

int main()
{
    int key1, key2, setup = 0, flag1 = 1, flag2;
    SingleList list;
    while (flag1)
    {
        Menu();
        cout << "You choose: ";
        cin >> key1;
        switch (key1)
        {
        case 1:
            cout << "\n1. List initialization\n";
            Initialize(list);
            setup = 1;
            cout << "...........Complete!!...........\n";
            break;
        case 2:

            if (setup)
            {
                flag2 = 1;
                cout << "\n2. Add node\n";
                while (flag2)
                {
                    MenuAddNode();
                    cout << "You choose: ";
                    cin >> key2;
                    int d;
                    switch (key2)
                    {
                    case 1:
                        cout << "List: ";
                        PrintList(list);
                        cout << "\nEnter d: ";
                        cin >> d;
                        InsertFirst(list, d);
                        cout << "...........Complete!!...........\nList: ";
                        PrintList(list);
                        break;

                    case 2:
                        cout << "\nList: ";
                        PrintList(list);
                        int pos;
                        cout << "\nPos = ";
                        cin >> pos;
                        cout << "Enter d: ";
                        cin >> d;
                        InsertMid(list, pos, d);

                        cout << "...........Complete!!...........\nList: ";
                        PrintList(list);
                        break;

                    case 3:
                        cout << "\nList: ";
                        PrintList(list);
                        cout << "\nEnter d: ";
                        cin >> d;
                        InsertLast(list, d);
                        cout << "...........Complete!!...........\nList: ";
                        PrintList(list);
                        break;
                    case 4:
                        flag2 = 0;
                    }
                }
            }
            else
            {
                system("color 04");
                cout << "You must initialize the list first\n";
                getch();
                system("color 07");
            }
        case 3:
            if (setup)
            {
                cout << "\n3. Total value of nodes: " << SumList(list) << endl;
                cout << "...........Complete!!...........\n";
                break;
            }

        case 4:
            if (setup)
            {
                cout << "4. Search\n";
                int x;
                cout << "Enter x: ";
                cin >> x;
                Node *pSearch = SearchNode(list, x);
                if (pSearch == NULL)
                {

                    cout << "Not found " << x << " !!" << endl;
                }
                else
                {
                    cout << "Found " << pSearch->data << " in list" << endl;
                }
                delete pSearch;
            }
            else
            {
                system("color 04");
                cout << "You must initialize the list first\n";
                getch();
                system("color 07");
            }
            break;

        case 5:
            if (setup)
            {
                cout << "5. Sort\n";
                SortList(list);
                cout << "List: ";
                PrintList(list);
            }
            else
            {
                system("color 04");
                cout << "You must initialize the list first\n";
                getch();
                system("color 07");
            }
            break;
        case 6:
            if (setup)
            {
                cout << "6. Delete\n";
                int x;
                cout << "Enter x: ";
                cin >> x;
                RemoveNode(list, x);
                cout << "List: ";
                PrintList(list);
            }
            else
            {
                system("color 04");
                cout << "You must initialize the list first\n";
                getch();
                system("color 07");
            }
            break;

        case 7:
            flag1 = 0;
            FreeMemory(list);
            PrintList(list);
            break;
        }
    }
}