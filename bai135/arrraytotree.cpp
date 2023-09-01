#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct TNode
{
    int value;
    TNode *pLeft;
    TNode *pRight;
};

typedef TNode *BTree;

TNode *CreateTNode(int v)
{
    TNode *pNew = new TNode;
    pNew->value = v;
    pNew->pLeft = pNew->pRight = NULL;
    return pNew;
}

void EnterArray(int array[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 100;
    }
}

void ExpArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << "\t";
    }
}

void InsertNode(BTree &root, int v)
{
    TNode *pNode = CreateTNode(v);
    if (root == NULL)
    {
        root = pNode;
    }
    else
    {
        BTree tmp = root;
        BTree parent = NULL;
        while (tmp != NULL)
        {
            parent = tmp;
            if (tmp->value > pNode->value)
            {
                tmp = tmp->pLeft;
            }
            else
            {
                tmp = tmp->pRight;
            }
        }
        if (parent->value > pNode->value)
        {
            parent->pLeft = pNode;
        }
        else
        {
            parent->pRight = pNode;
        }
    }
}

void ArrayToTree(BTree &root, int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        InsertNode(root, array[i]);
    }
}

void InOrder(BTree root)
{
    if (root != NULL)
    {
        InOrder(root->pLeft);
        cout << root->value << "\t";
        InOrder(root->pRight);
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int A[n];
    EnterArray(A, n);
    cout << "Array: ";
    ExpArray(A, n);
    BTree root = NULL;
    ArrayToTree(root, A, n);
    cout << "\nTree: ";
    InOrder(root);
}
