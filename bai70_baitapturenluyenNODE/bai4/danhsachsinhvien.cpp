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

struct Date
{
    int day;
    int month;
    int year;
};

struct Student
{
    int id;
    char name[20];
    Date age;
};

struct Node
{
    Student data;
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
            cout << pTmp->data.id << "\t"
                 << pTmp->data.name << "\t"
                 << pTmp->data.age.day << "/"
                 << pTmp->data.age.month << "/"
                 << pTmp->data.age.year << endl;
            pTmp = pTmp->pNext;
        }
    }
}

void InsertLast(SingleList &list, Student d)
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

void SortList(SingleList &list)
{
    for (Node *pTmp = list.pHead; pTmp != NULL; pTmp = pTmp->pNext)
    {
        for (Node *pTmp2 = pTmp->pNext; pTmp2 != NULL; pTmp2 = pTmp2->pNext)
        {
            if (pTmp->data.age.year > pTmp2->data.age.year)
            {
                Student tmp = pTmp->data;
                pTmp->data = pTmp2->data;
                pTmp2->data = tmp;
            }
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
         << "| 4. Exit                                    |\n"
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
                    cout << "Enter birthday: ";
                    cin >> list[i].age.day >> list[i].age.month >> list[i].age.year;

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