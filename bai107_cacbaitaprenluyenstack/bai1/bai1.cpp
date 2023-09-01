#include <iostream>
using namespace std;

struct Node
{
    double data;
    Node *pLink;
};

typedef Node *STACK;

void Initialize(STACK &stack)
{
    stack = NULL;
}

Node *CreateNode(double d)
{
    Node *pNode = new Node;
    pNode->data = d;
    pNode->pLink = NULL;
}

void Push(STACK &stack, double d)
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

double Pop(STACK &stack)
{
    if (stack == NULL)
    {
        cout << "Stack is empty!!";
        exit(0);
    }
    double d = stack->data;
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
    cout << "Push:\n";
    for (int i = 0; i < n; i++)
    {
        double d;
        cin >> d;
        Push(stack, d);
    }
    cout << "Pop: ";
    for (int i = 0; i < n; i++)
    {
        cout << Pop(stack) << "\t";
    }
    cout << endl;
}