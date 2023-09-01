#include <iostream>
#include <string.h>
using namespace std;

struct Product
{
    int id;
    string name;
    float price;
};

struct TNode
{
    Product data;
    TNode *pLeft, *pRight;
};

typedef TNode *BTree;

TNode *CreateNode(Product d)
{
    TNode *pNode = new TNode;
    pNode->data = d;
    pNode->pLeft = pNode->pRight = NULL;
    return pNode;
}

void EnterProduct(Product a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Product " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> a[i].id;
        cout << "Name: ";
        cin >> a[i].name;
        cout << "Price: ";
        cin >> a[i].price;
    }
}

void ExpProduct(Product d)
{
    cout << d.id << "\t" << d.name << "\t" << d.price << endl;
}

void InsertNode(BTree &root, Product d)
{
    TNode *pNode = CreateNode(d);
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
            if (tmp->data.id > pNode->data.id)
            {
                tmp = tmp->pLeft;
            }
            else
            {
                tmp = tmp->pRight;
            }
        }
        if (parent->data.id > pNode->data.id)
        {
            parent->pLeft = pNode;
        }
        else
        {
            parent->pRight = pNode;
        }
    }
}

void PostOrder(BTree root)
{
    if (root != NULL)
    {
        PostOrder(root->pLeft);
        PostOrder(root->pRight);
        ExpProduct(root->data);
    }
}

TNode *SearchNode(BTree root, int d)
{
    if (root == NULL || root->data.id == d)
    {
        return root;
    }
    else
    {
        if (d < root->data.id)
        {
            return SearchNode(root->pLeft, d);
        }
        else if (d > root->data.id)
        {
            return SearchNode(root->pRight, d);
        }
    }
}
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    Product a[n];
    EnterProduct(a, n);
    BTree root = NULL;
    for (int i = 0; i < n; i++)
    {
        InsertNode(root, a[i]);
    }
    PostOrder(root);
    int x;
    cout << "Enter x: ";
    cin >> x;
    TNode *pTmp = SearchNode(root, x);
    if (pTmp == NULL)
    {
        cout << "Not found!!\n";
    }
    else
    {
        cout << "Found: ";
        ExpProduct(pTmp->data);
    }
}