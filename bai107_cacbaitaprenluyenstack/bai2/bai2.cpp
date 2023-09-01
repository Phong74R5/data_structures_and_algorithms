#include <iostream>
using namespace std;

struct Block
{
    int id;
    int data;
};

struct Node
{
    Block data;
    Node *pLink;
};

typedef Node *STACK;

void Initialize(STACK &stack)
{
    stack = NULL;
}

Node *CreateNode(Block d)
{
    Node *pNode = new Node;
    pNode->data = d;
    pNode->pLink = NULL;
    return pNode;
}

void Push(STACK &stack, Block d)
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

Block Pop(STACK &stack)
{
    if (stack == NULL)
    {
        cout << "Stack is empty!!";
        exit(0);
    }
    Block d = stack->data;
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
        cout << "Block " << i + 1 << ":" << endl;
        Block tmp;
        cout << "Enter id: ";
        cin >> tmp.id;
        cout << "Enter data: ";
        cin >> tmp.data;
        Push(stack, tmp);
    }
    cout << "ID\tdata\n";
    for (int i = 0; i < n; i++)
    {
        Block tmp = Pop(stack);
        cout << tmp.id << "\t" << tmp.data << endl;
    }
}