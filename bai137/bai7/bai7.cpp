#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

struct TNode
{
    int data;
    TNode *pLeft;
    TNode *pRight;
};
typedef TNode *BTree;

TNode *CreateNode(int v);
void InsertNode(BTree &root, int v);
void PreOrder_NLR(BTree root);
void PostOrder_LRN(BTree root);
void InOrder_LNR(BTree root);
void writeNodeToFile(BTree root, fstream &file);
void writeTreeToFile(BTree root, string filename);
void readFile(BTree &root, string filename);
TNode *Search(BTree root, int v);
void Menu();
void MenuExp();

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
            else if (Tmp->data < pNode->data)
            {
                Tmp = Tmp->pRight;
            }
            else
            {
                cout << "Same!!\n";
                return;
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
void writeNodeToFile(BTree root, fstream &file)
{
    if (root == NULL)
    {
        return;
    }
    file << root->data << endl;
    writeNodeToFile(root->pLeft, file);
    writeNodeToFile(root->pRight, file);
}
void writeTreeToFile(BTree root, string filename)
{
    fstream f;
    f.open(filename, ios::out);
    writeNodeToFile(root, f);
    f.close();
}

void readFile(BTree &root, string filename)
{
    fstream f;
    f.open(filename, ios::in);
    char content[20];
    while (!f.eof())
    {
        f.getline(content, 20);
        InsertNode(root, atoi(content));
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

void Menu()
{
    cout << "+--------------------Menu--------------------+\n"
         << "| 1. Them Node                               |\n"
         << "| 2. Tim gia tri trung binh cua danh sach    |\n"
         << "| 3. Xuat danh sach                          |\n"
         << "| 4. Luu toan bo cay ve file                 |\n"
         << "| 5. Nap cay tu file                         |\n"
         << "|10. Tim node theo gia tri nhap              |\n"
         << "| 0. Thoat                                   |\n"
         << "+--------------------------------------------+\n"
         << "Nhap tuy chon: ";
}
void MenuExp()
{
    cout << "+--------------------Menu--------------------+\n"
         << "| 1. PreOrder                                |\n"
         << "| 2. InOrder                                 |\n"
         << "| 3. PostOrder                               |\n"
         << "| 4. Thoat                                   |\n"
         << "+--------------------------------------------+\n"
         << "Nhap tuy chon: ";
}
