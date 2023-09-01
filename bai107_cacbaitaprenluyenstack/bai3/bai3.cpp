#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct Info
{
    char className[20];
    int number;
};

struct Node
{
    Info data;
    Node *pLink;
};

typedef Node *STACK;

void Initialize(STACK &stack)
{
    stack = NULL;
}

Node *CreateNode(Info d)
{
    Node *pNode = new Node;
    pNode->data = d;
    pNode->pLink = NULL;
    return pNode;
}

void Push(STACK &stack, Info d)
{
    Node *pTmp = stack;
    while (pTmp != NULL)
    {
        if (strcmp(d.className, pTmp->data.className) == 0)
        {
            pTmp->data.number += d.number;
            return;
        }
        pTmp = pTmp->pLink;
    }
    Node *pNode = CreateNode(d);
    if (stack == NULL)
    {
        stack = pNode;
    }
    else
    {
        pNode->pLink = stack;
        stack = pNode;
    }
}

Info Pop(STACK &stack)
{
    if (stack == NULL)
    {
        cout << "Stack is empty!!";
        exit(0);
    }
    Info d = stack->data;
    Node *pDel = stack;
    stack = stack->pLink;
    pDel->pLink = NULL;
    delete pDel;
    return d;
}

void expStackNotDel(STACK stack)
{
    Node *pTmp = stack;
    cout << "\nName\tNumber\n";
    while (pTmp != NULL)
    {
        cout << pTmp->data.className << "\t" << pTmp->data.number << endl;
        pTmp = pTmp->pLink;
    }
}

Info Input()
{
    Info temp;
    cout << "Enter class name: ";
    fflush(stdin);
    gets(temp.className);
    cout << "Enter number: ";
    cin >> temp.number;
    return temp;
}

void saveStackToFile(STACK stack, string nameFile)
{
    fstream f;
    f.open(nameFile, ios::out);
    Node *temp = stack;
    while (temp != NULL)
    {
        f << temp->data.className << endl;
        f << temp->data.number << endl;
        temp = temp->pLink;
    }
    delete temp;
    f.close();
}

void expFileToStack(STACK &stack, string nameFile)
{
    fstream f;
    f.open(nameFile, ios::in);
    int count = 1;
    Info temp;
    char content[20];
    while (!f.eof())
    {

        f.getline(content, 20);
        if (count == 1)
        {
            strcpy(temp.className, content);
        }
        if (count == 2)
        {
            temp.number = atoi(content);
            count = 1;
            Push(stack, temp);
            Info temp;
            continue;
        }
        count++;
    }
}

void Menu()
{
    cout << "\n+--------------------Menu--------------------+\n"
         << "| 1. Luu stack vao file                      |\n"
         << "| 2. Push phan tu moi (lop moi)              |\n"
         << "| 3. Pop phan tu vao stack                   |\n"
         << "| 4. Hien thi danh sach cua stack            |\n"
         << "| 5. Nap stack tu file                       |\n"
         << "| 0.Exit                                     |\n"
         << "+--------------------------------------------+\n"
         << "Nhap tuy chon: ";
}

int main()
{
    STACK stack;
    Initialize(stack);
    while (1)
    {
        Menu();
        int key;
        cin >> key;
        switch (key)
        {
        case 1:
        { /* code */
            saveStackToFile(stack, "data.txt");
            cout << "Done!!";
        }
        break;

        case 2:
        { /* code */
            int n;
            cout << "Enter n: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "\n-----" << i + 1 << "-----\n";
                Info d = Input();
                Push(stack, d);
            }
        }
        break;

        case 3:
        { /* code */
            Info d = Pop(stack);
            cout << "Pop: " << d.className << "\t" << d.number << endl;
        }
        break;

        case 4:
        { /* code */
            expStackNotDel(stack);
        }
        break;

        case 5:
        {
            Initialize(stack);
            expFileToStack(stack, "data.txt");
            cout << "Done!!";
        }
        break;

        case 0:
            exit(0);
            break;
        }
    }
}
