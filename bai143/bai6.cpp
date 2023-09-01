#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
struct TNode
{
    int data;
    TNode *pLeft;
    TNode *pRight;
};

typedef TNode *BTree;

TNode *CreateNode(int v)
{
    TNode *pNode = new TNode;
    pNode->data = v;
    pNode->pLeft = pNode->pRight = NULL;
    return pNode;
}

void InsertNode(BTree &root, int v)
{
    TNode *pNode = CreateNode(v);
    if (root == NULL)
    {
        root = pNode;
    }
    else
    {
        BTree Tmp = root;
        BTree Parent = NULL;
        while (Tmp != NULL)
        {
            Parent = Tmp;
            if (Tmp->data > pNode->data)
            {
                Tmp = Tmp->pLeft;
            }
            else
            {
                Tmp = Tmp->pRight;
            }
        }
        if (Parent->data > pNode->data)
        {
            Parent->pLeft = pNode;
        }
        else
        {
            Parent->pRight = pNode;
        }
    }
}

void InOrder(BTree root)
{
    while (root)
    {
        if (root->pLeft == NULL)
        {
            cout << root->data << " ";
            root = root->pRight;
        }
        else
        {
            TNode *p = root->pLeft;
            while (p->pRight && p->pRight != root)
            {
                p = p->pRight;
            }
            if (p->pRight == NULL)
            {
                p->pRight = root;
                root = root->pLeft;
            }
            else
            {
                p->pRight = NULL;
                cout << root->data << " ";
                root = root->pRight;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    BTree root = NULL;
    for (int i = 0; i < 10; i++)
    {
        InsertNode(root, rand() % 100);
    }
    InOrder(root);
}
