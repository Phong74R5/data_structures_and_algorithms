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

struct Student
{
    int id;
    char name[20];
};

struct Node
{
    Student data;
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

Node *CreateNode(Student d)
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
            cout << pTmp->data.id << "\t" << pTmp->data.name << endl;
            pTmp = pTmp->pNext;
        }
    }
}

void InsertLast(SingleList &list, Student d)
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
            if (pTmp->data.id > pTmp2->data.id)
            {
                Student tmp = pTmp->data;
                pTmp->data = pTmp2->data;
                pTmp2->data = tmp;
            }
        }
    }
}

void RemoveNode(SingleList &list, int ID)
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
            if (pDel->data.id == ID)
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
        cout << "Data student" << pTmp->data.id << " is deleted\n";
        delete pTmp;
        pTmp = NULL;
    }
    cout << "\nDeleted is complete!!\n";
}

void Menu()
{
    cout << "\n+--------------------Menu--------------------+\n"
         << "| 1. List initialization                     |\n"
         << "| 2. Add list students                       |\n"
         << "| 3. Sort student                            |\n"
         << "| 4. Delete student                          |\n"
         << "| 5. Exit                                    |\n"
         << "+--------------------------------------------+\n";
}

int main()
{
    int key, flag = 1, setup = 0;
    SingleList listStudents;
    while (flag)
    {
        Menu();
        cout << "You choose: ";
        cin >> key;
        switch (key)
        {
        case 1:
            cout << "\n1. List initialization\n";
            Initialize(listStudents);
            setup = 1;
            cout << "...........Complete!!...........\n";
            break;

        case 2:
            if (setup)
            {
                cout << "\n2. Add student\n";
                int n;
                cout << "Enter n: ";
                cin >> n;
                Student list[n];
                for (int i = 0; i < n; i++)
                {
                    cout << "Student " << i + 1 << ":\n";
                    cout << "ID: ";
                    cin >> list[i].id;
                    cout << "Name: ";
                    cin >> list[i].name;

                    InsertLast(listStudents, list[i]);
                }
                cout << "...........Complete!!...........\n";
                cout << "List students:\n";
                PrintList(listStudents);
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
                cout << "\n3. Sort list students\n";
                SortList(listStudents);
                cout << "List students:\n";
                PrintList(listStudents);
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
                cout << "6. Delete student\n";
                int x;
                cout << "Enter id to delete: ";
                cin >> x;
                RemoveNode(listStudents, x);
                cout << "List students:\n";
                PrintList(listStudents);
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
                FreeMemory(listStudents);
                PrintList(listStudents);
            }
            break;
        }
    }
}