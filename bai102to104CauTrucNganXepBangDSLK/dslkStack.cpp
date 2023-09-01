#include <iostream>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *pNext;
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
    pNode->pNext = NULL;
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
        pNode->pNext = stack;
        stack = pNode;
    }
}

int Pop(STACK &stack)
{
    int d = stack->data;
    Node *pDel = stack;
    stack = stack->pNext;
    pDel->pNext = NULL;
    delete pDel;
    return d;
}

int main()
{
    STACK stack;
    Initialize(stack);
    Push(stack, 12);
    Push(stack, 123);
    cout << Pop(stack) << endl;
    cout << Pop(stack) << endl;
}
