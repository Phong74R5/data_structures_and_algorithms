#include <iostream>
#include <string.h>
using namespace std;

struct Device
{
    int id;
    string name;
};

struct Node
{
    Device data;
    Node *pLink;
};

typedef Node *STACK;

void Initialize(STACK &stack)
{
    stack = NULL;
}

Node *CreateNode(Device d)
{
    Node *pNode = new Node;
    pNode->data = d;
    pNode->pLink = NULL;
    return pNode;
}

void Push(STACK &stack, Device d)
{
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

Device Pop(STACK &stack)
{
    Device d = stack->data;
    Node *pDel = stack;
    stack = stack->pLink;
    pDel->pLink = NULL;
    delete pDel;
    return d;
}

int main()
{
    STACK stack;
    Initialize(stack);
    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Device " << i + 1 << ":" << endl;
        Device tmp;
        cout << "Enter id: ";
        cin >> tmp.id;
        cout << "Enter name: ";
        cin >> tmp.name;
        Push(stack, tmp);
    }
    cout << "ID\tName\n";
    for (int i = 0; i < n; i++)
    {
        Device tmp = Pop(stack);
        cout << tmp.id << "\t" << tmp.name << endl;
    }
}