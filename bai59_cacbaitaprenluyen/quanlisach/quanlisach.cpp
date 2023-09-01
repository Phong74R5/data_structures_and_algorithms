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

struct Book
{
    int id;
    char name[20];
    int npage;
};

struct Node
{
    Book data;
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

Node *CreateNode(Book d)
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
            cout << pTmp->data.id << "\t" << pTmp->data.name << "\t" << pTmp->data.npage << endl;
            pTmp = pTmp->pNext;
        }
    }
}

void InsertLast(SingleList &list, Book d)
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

void SortList(SingleList &list)
{
    for (Node *pTmp = list.pHead; pTmp != NULL; pTmp = pTmp->pNext)
    {
        for (Node *pTmp2 = pTmp->pNext; pTmp2 != NULL; pTmp2 = pTmp2->pNext)
        {
            if (pTmp->data.npage < pTmp2->data.npage)
            {
                Book tmp = pTmp->data;
                pTmp->data = pTmp2->data;
                pTmp2->data = tmp;
            }
        }
    }
}

void RemoveNode(SingleList &list, char x[])
{
    int find = 1;
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
            if (strcmp(pDel->data.name, x) == 0)
            {
                find = 0;
                break;
            }

            pPre = pDel;
            pDel = pDel->pNext;
        }
        if (find)
        {
            cout << "\nNot found!!\n";
            return;
        }
        else if (pDel == list.pHead)
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

void FreeMemory(SingleList &list)
{
    cout << "\nStarting to delete. . .\n";
    while (list.pHead != NULL)
    {
        Node *pTmp = list.pHead;
        list.pHead = pTmp->pNext;
        pTmp->pNext = NULL;
        cout << "Data Book" << pTmp->data.id << " is deleted\n";
        delete pTmp;
        pTmp = NULL;
    }
    cout << "\nDeleted is complete!!\n";
}

void Menu()
{
    cout << "\n+--------------------Menu--------------------+\n"
         << "| 1. List initialization                     |\n"
         << "| 2. Add list Books                          |\n"
         << "| 3. Sort Books                              |\n"
         << "| 4. Delete Books                            |\n"
         << "| 5. Exit                                    |\n"
         << "+--------------------------------------------+\n";
}

int main()
{
    int key, flag = 1, setup = 0;
    SingleList listBooks;
    while (flag)
    {
        Menu();
        cout << "You choose: ";
        cin >> key;
        switch (key)
        {
        case 1:
            cout << "\n1. List initialization\n";
            Initialize(listBooks);
            setup = 1;
            cout << "...........Complete!!...........\n";
            break;

        case 2:
            if (setup)
            {
                cout << "\n2. Add Book\n";
                int n;
                cout << "Enter n: ";
                cin >> n;
                Book list[n];
                for (int i = 0; i < n; i++)
                {
                    cout << "Book " << i + 1 << ":\n";
                    cout << "ID: ";
                    cin >> list[i].id;
                    cout << "Name: ";
                    cin >> list[i].name;
                    cout << "Page: ";
                    cin >> list[i].npage;

                    InsertLast(listBooks, list[i]);
                }
                cout << "...........Complete!!...........\n";
                cout << "List Books:\n";
                PrintList(listBooks);
            }
            else
            {
                system("color 04");
                cout << "You must initialize the list first\n";
                getch();
                system("color 07");
            }
            break;

        case 3:
            if (setup)
            {
                cout << "\n3. Sort list Books\n";
                SortList(listBooks);
                cout << "List Books:\n";
                PrintList(listBooks);
            }
            else
            {
                system("color 04");
                cout << "You must initialize the list first\n";
                getch();
                system("color 07");
            }
            break;

        case 4:
            if (setup)
            {
                cout << "6. Delete Book\n";
                char x[20];
                cout << "Enter name to delete: ";
                cin >> x;
                RemoveNode(listBooks, x);
                cout << "List Books:\n";
                PrintList(listBooks);
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
            flag = 0;
            if (setup)
            {
                FreeMemory(listBooks);
                PrintList(listBooks);
            }
            break;
        }
    }
}