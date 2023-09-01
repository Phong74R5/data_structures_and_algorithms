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
int CountNode(BTree root);
int SumNode(BTree root);
void writeNodeToFile(BTree root, fstream &file);
void writeTreeToFile(BTree root, string filename);
void readFile(BTree &root, string filename);
int Height(BTree root);
int max(BTree root);
int min(BTree root);
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

int SumNode(BTree root)
{
    if (root == NULL)
    {
        return (0);
    }
    else
    {
        return (root->data + (SumNode(root->pLeft) + SumNode(root->pRight)));
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

int max(BTree root)
{
    int m = 0;
    while (root != NULL)
    {
        m = root->data;
        root = root->pRight;
    }
    return m;
}

int min(BTree root)
{
    int m = 0;
    while (root != NULL)
    {
        m = root->data;
        root = root->pLeft;
    }
    return m;
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

void Menu()
{
    cout << "+--------------------Menu--------------------+\n"
         << "| 1. Them Node                               |\n"
         << "| 2. Tim gia tri trung binh cua danh sach    |\n"
         << "| 3. Xuat danh sach                          |\n"
         << "| 4. Luu toan bo cay ve file                 |\n"
         << "| 5. Nap cay tu file                         |\n"
         << "| 6. Tinh so luong node cua cay              |\n"
         << "| 7. Tinh chieu cao cua cay                  |\n"
         << "| 8. Tim gia tri nho nhat                    |\n"
         << "| 9. Tim gia tri lon nhat                    |\n"
         << "|10. Tim node theo gia tri nhap              |\n"
         << "|11. Hien thi gia tri tang dan cua cay       |\n"
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

int main()
{
    BTree root = NULL;
    readFile(root, "data.txt");
    int flag1 = 1;
    while (flag1)
    {
        system("cls");
        int key;
        Menu();
        cin >> key;
        switch (key)
        {
        case 1:
            system("cls");
            cout << "+--------------------Menu--------------------+\n"
                 << "| 1. Them Node                               |\n"
                 << "+--------------------------------------------+\n";
            int n;
            cout << "Enter n: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int tmp;
                cout << "Enter \"" << i + 1 << "\": ";
                cin >> tmp;
                InsertNode(root, tmp);
            }
            cout << "Done!! ";
            system("pause");
            break;

        case 2:
        {
            system("cls");
            cout << "+--------------------Menu--------------------+\n"
                 << "| 2. Tim gia tri trung binh cua danh sach    |\n"
                 << "+--------------------------------------------+\n";
            int m = CountNode(root);
            int s = SumNode(root);
            if (m == 0)
            {
                cout << "Avg: " << 0 << endl;
            }
            else
            {
                cout << "Avg: " << double(s) / m << endl;
            }
            cout << "Done!! ";
            system("pause");
        }
        break;

        case 3:
        {
            int flag = 1;
            while (flag)
            {
                system("cls");
                cout << "+--------------------Menu--------------------+\n"
                     << "| 3. Xuat danh sach                          |\n"
                     << "+--------------------------------------------+\n";
                MenuExp();
                int keyExp;
                cin >> keyExp;
                switch (keyExp)
                {
                case /* constant-expression */ 1:
                    /* code */
                    system("cls");
                    cout << "PreOrder: ";
                    PreOrder_NLR(root);
                    cout << "Done!! ";
                    system("pause");
                    break;

                case 2:
                    system("cls");
                    cout << "\nInOrder: ";
                    InOrder_LNR(root);
                    cout << "Done!! ";
                    system("pause");
                    break;

                case 3:
                    system("cls");
                    cout << "\nPostOrder: ";
                    PostOrder_LRN(root);
                    cout << "Done!! ";
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    cout << "Exit!!";
                    flag = 0;
                    system("pause");
                default:
                    break;
                }
            }
        }
        break;

        case 4:
            system("cls");
            cout << "+--------------------Menu--------------------+\n"
                 << "| 4. Luu toan bo cay ve file                 |\n"
                 << "+--------------------------------------------+\n";
            writeTreeToFile(root, "data.txt");
            cout << "Done!! ";
            system("pause");
            break;

        case 5:
            system("cls");
            cout << "+--------------------Menu--------------------+\n"
                 << "| 5. Nap cay tu file                         |\n"
                 << "+--------------------------------------------+\n";
            readFile(root, "data.txt");
            cout << "Done!! ";
            system("pause");
            break;

        case 6:
        {
            system("cls");
            cout << "+--------------------Menu--------------------+\n"
                 << "| 6. Tinh so luong node cua cay              |\n"
                 << "+--------------------------------------------+\n";
            int m = CountNode(root);

            cout << "Node: " << m << endl;

            cout << "Done!! ";
            system("pause");
        }
        break;

        case 7:
        {
            system("cls");
            cout << "+--------------------Menu--------------------+\n"
                 << "| 7. Tinh chieu cao cua cay                  |\n"
                 << "+--------------------------------------------+\n";
            int m = Height(root);

            cout << "Height: " << m << endl;

            cout << "Done!! ";
            system("pause");
        }
        break;

        case 8:
        {
            system("cls");
            cout << "+--------------------Menu--------------------+\n"
                 << "| 8. Tim gia tri nho nhat                    |\n"
                 << "+--------------------------------------------+\n";
            int m = min(root);

            cout << "MIn: " << m << endl;

            cout << "Done!! ";
            system("pause");
        }
        break;

        case 9:
        {
            system("cls");
            cout << "+--------------------Menu--------------------+\n"
                 << "| 9. Tim gia tri lon nhat                    |\n"
                 << "+--------------------------------------------+\n";
            int m1 = max(root);

            cout << "Node: " << m1 << endl;

            cout << "Done!! ";
            system("pause");
        }
        break;

        case 10:
        {
            system("cls");
            cout << "+--------------------Menu--------------------+\n"
                 << "|10. Tim node theo gia tri nhap              |\n"
                 << "+--------------------------------------------+\n";
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
            cout << "Done!! ";
            system("pause");
        }
        break;

        case 11:
        {
            system("cls");
            cout << "+--------------------Menu--------------------+\n"
                 << "|11. Hien thi gia tri tang dan cua cay       |\n"
                 << "+--------------------------------------------+\n";

            cout << "Tree: ";
            InOrder_LNR(root);
            cout << endl;

            cout << "Done!! ";
            system("pause");
        }
        break;

        case 0:
            system("cls");
            writeTreeToFile(root, "data.txt");
            cout << "Exit!!";
            flag1 = 0;
        }
    }
}