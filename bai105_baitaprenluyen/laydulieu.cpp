#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct Node
{
    int data;
    Node *pLink;
};

typedef Node *STACK;

void Initialize(STACK &stack)
{
    stack = NULL;
}

Node *CreateNode(int d)
{
    Node *pNode = new Node;
    pNode->data = d;
    pNode->pLink = NULL;
    return pNode;
}

void Push(STACK &stack, int d)
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

int Pop(STACK &stack)
{
    int d = stack->data;
    Node *pDel = stack;
    stack = stack->pLink;
    pDel->pLink = NULL;
    delete pDel;
    return d;
}

Node *PopUpdate(STACK &stack)
{
    if (stack == NULL)
    {
        return NULL;
    }
    Node *pPop = stack;
    stack = stack->pLink;
    pPop->pLink = NULL;
    return pPop;
}

Node *Top(STACK stack)
{
    return stack;
}

int main()
{
    srand(time(NULL));
    STACK stack;
    int n;
    Initialize(stack);
    cout << "Enter n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Push(stack, 1 + rand() % 100);
    }

    cout << Top(stack)->data << endl;

    for (int i = 0; i < n; i++)
    {
        cout << PopUpdate(stack)->data << "\t";
    }
    cout << endl;
}