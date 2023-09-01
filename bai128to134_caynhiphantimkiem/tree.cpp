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

void PreOrder_NLR(BTree root)
{
    if (root != NULL)
    {
        cout << root->data << "\t";
        PreOrder_NLR(root->pLeft);
        PreOrder_NLR(root->pRight);
    }
}

void PostOrder_LRN(BTree root)
{
    if (root != NULL)
    {
        PostOrder_LRN(root->pLeft);
        PostOrder_LRN(root->pRight);
        cout << root->data << "\t";
    }
}

void InOrder_LNR(BTree root)
{
    if (root != NULL)
    {
        InOrder_LNR(root->pLeft);
        cout << root->data << "\t";
        InOrder_LNR(root->pRight);
    }
}

int CountNode(BTree root)
{
    if (root == NULL)
    {
        return (0);
    }
    else
    {
        return (1 + (CountNode(root->pLeft) + CountNode(root->pRight)));
    }
}

int CountLeaf(BTree root)
{
    if (root != NULL)
    {
        if (root->pLeft == NULL && root->pRight == NULL)
        {
            return 1;
        }
        else
        {
            return CountLeaf(root->pLeft) + CountLeaf(root->pRight);
        }
    }
    else
    {
        return 0;
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int Height(BTree root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + max(Height(root->pLeft), Height(root->pRight));
    }
}

TNode *Search(BTree root, int v)
{
    if (root == NULL || root->data == v)
    {
        return root;
    }
    else
    {
        if (v < root->data)
        {
            return Search(root->pLeft, v);
        }
        else if (v > root->data)
        {
            return Search(root->pRight, v);
        }
    }
}

void RemoveNode(BTree &root, int v)
{
    if (root == NULL)
    {
        cout << "Tree is empty!!";
        return;
    }
    TNode *pParent = NULL;
    TNode *pDel = NULL;
    TNode *pTmp = root;
    while (pTmp != NULL)
    {
        pParent = pTmp;
        if (pTmp->data > v)
        {
            pTmp = pTmp->pLeft;
        }
        else if (pTmp->data < v)
        {
            pTmp = pTmp->pRight;
        }
        if (pTmp->data == v)
        {
            pDel = pTmp;
            break;
        }
    }
    if (pDel == NULL)
    {
        cout << "Not found!!";
        return;
    }
    if (pDel->pLeft == NULL && pDel->pRight == NULL)
    {
        if (pParent->data > pDel->data)
        {
            pParent->pLeft = NULL;
        }
        else
        {
            pParent->pRight = NULL;
        }
        delete pDel;
        pDel = NULL;
    }
    else if (pDel->pLeft != NULL && pDel->pRight == NULL)
    {
        if (pParent->data > pDel->data)
        {
            pParent->pLeft = pDel->pLeft;
        }
        else
        {
            pParent->pRight = pDel->pRight;
        }
        pDel->pLeft = NULL;
        delete pDel;
        pDel = NULL;
    }
    else if (pDel->pLeft == NULL && pDel->pRight != NULL)
    {
        if (pParent->data > pDel->data)
        {
            pParent->pLeft = pDel->pRight;
            pDel->pRight = NULL;
        }
        else
        {
            pParent->pRight = pDel->pRight;
            pDel->pRight = NULL;
        }
        delete pDel;
        pDel = NULL;
    }
    else
    {
        // tìm trái nhất của cây con phải
        TNode *pMinOfRight = pDel->pRight;
        TNode *pParentMinOfRight = NULL;
        while (pMinOfRight->pLeft != NULL)
        {
            pParentMinOfRight = pMinOfRight;
            pMinOfRight = pMinOfRight->pLeft;
        }
        pDel->data = pMinOfRight->data;
        if (pParentMinOfRight == NULL)
        {
            pDel->pRight = NULL;
        }
        else if (pParentMinOfRight->data > pMinOfRight->data)
        {
            pParentMinOfRight->pLeft = pMinOfRight->pRight;
        }
        delete pMinOfRight;
        pMinOfRight = NULL;
    }
}
int main()
{
    srand(time(NULL));
    BTree root;
    root = NULL;
    for (int i = 0; i < 10; i++)
    {
        InsertNode(root, 1 + rand() % 100);
    }
    cout << "PreOrder: ";
    PreOrder_NLR(root);
    cout << "\nPostOrder: ";
    PostOrder_LRN(root);
    cout << "\nInOrder: ";
    InOrder_LNR(root);
    // cout << "\nNode: " << CountNode(root) << endl;
    // cout << "Leaf: " << CountLeaf(root) << endl;
    // cout << "Height: " << Height(root) << endl;
    int x;
    cout << "Enter x: ";
    cin >> x;
    TNode *pS = Search(root, x);
    if (pS == NULL)
    {
        cout << "Not found!!" << endl;
    }
    else
    {
        cout << "Found " << pS->data << "in tree!!" << endl;
    }
    int del;
    cout << "\nNhap so can xoa: ";
    cin >> del;
    RemoveNode(root, del);
    cout << "\nInOrder: ";
    InOrder_LNR(root);
}