#include <iostream>
#include <string.h>
using namespace std;

struct student
{
    int id;
    char name[250];
};

struct NodeStu
{
    student *data;
    NodeStu *pLeft;
    NodeStu *pRight;
};

typedef NodeStu *BST;

struct Class
{
    int id;
    char name[250];
};

struct NodeCls
{
    Class *data;
    NodeCls *pPre, *pNext;
    BST root;
};

struct DLink
{
    NodeCls *pHead, *pTail;
};
// sinh viên
NodeStu *CreateNodeStu(student *sv);
void InitBST(BST &root);
void InsertStu(BST &root, student *sv);
void InOrder(BST root);

// lớp học

NodeCls *CreateNodeCls(Class *cla);
void InitDLink(DLink &link);
void InsertCls(DLink &link, NodeCls *cls);
void PrintCls(DLink link);
NodeCls *SNCls(DLink link, int ml);

int main()
{
    DLink link;
    InitDLink(link);

    Class *lop1 = new Class;
    lop1->id = 1;
    strcpy(lop1->name, "K22119");
    NodeCls *node1 = CreateNodeCls(lop1);
    InsertCls(link, node1);

    Class *lop2 = new Class;
    lop2->id = 2;
    strcpy(lop2->name, "K2229");
    NodeCls *node2 = CreateNodeCls(lop2);
    InsertCls(link, node2);

    Class *lop3 = new Class;
    lop3->id = 3;
    strcpy(lop3->name, "K2239");
    NodeCls *node3 = CreateNodeCls(lop3);
    InsertCls(link, node3);

    Class *lop4 = new Class;
    lop4->id = 4;
    strcpy(lop4->name, "K2249");
    NodeCls *node4 = CreateNodeCls(lop4);
    InsertCls(link, node4);

    cout << "danh sach lop hoc:\n";
    PrintCls(link);

    BST dssv1;
    InitBST(dssv1);
    student *sv1 = new student;
    sv1->id = 20;
    strcpy(sv1->name, "a");
    InsertStu(dssv1, sv1);

    student *sv2 = new student;
    sv2->id = 30;
    strcpy(sv2->name, "b");
    InsertStu(dssv1, sv2);

    student *sv3 = new student;
    sv3->id = 40;
    strcpy(sv3->name, "c");
    InsertStu(dssv1, sv3);

    node1->root = dssv1;
    int ml;
    cout << "Nhap ma lop can tim: ";
    cin >> ml;
    NodeCls *result = SNCls(link, ml);
    if (result != NULL)
    {
        cout << "tim thay " << result->data->name << "!\n";
        InOrder(result->root);
    }
    else
    {
        cout << "Khong tim thay\n!";
    }
}

NodeStu *CreateNodeStu(student *sv)
{
    NodeStu *node = new NodeStu;
    node->data = sv;
    node->pLeft = node->pRight = NULL;
    return node;
}
void InitBST(BST &root)
{
    root = NULL;
}
void InsertStu(BST &root, student *sv)
{
    NodeStu *node = CreateNodeStu(sv);
    if (root == NULL)
    {
        root = node;
    }
    else
    {
        NodeStu *tmp = root;
        NodeStu *p = NULL;
        while (tmp != NULL)
        {
            p = tmp;
            if (tmp->data->id > node->data->id)
            {
                tmp = tmp->pLeft;
            }
            else
            {
                tmp = tmp->pRight;
            }
        }
        if (p->data->id > node->data->id)
        {
            p->pLeft = node;
        }
        else
        {
            p->pRight = node;
        }
    }
}
void InOrder(BST root)
{
    if (root != NULL)
    {
        InOrder(root->pLeft);
        cout << root->data->id << "\t" << root->data->name << endl;
        InOrder(root->pRight);
    }
}

NodeCls *CreateNodeCls(Class *cla)
{
    NodeCls *node = new NodeCls;
    node->data = cla;
    node->pNext = node->pPre = NULL;
    node->root = NULL;
    return node;
}
void InitDLink(DLink &link)
{
    link.pHead = link.pTail = NULL;
}
void InsertCls(DLink &link, NodeCls *cls)
{
    if (link.pHead == NULL)
    {
        link.pHead = link.pTail = cls;
    }
    else
    {
        link.pTail->pNext = cls;
        cls->pPre = link.pTail;
        link.pTail = cls;
    }
}
void PrintCls(DLink link)
{
    NodeCls *node = link.pHead;
    while (node != NULL)
    {
        /* code */
        Class *cls = node->data;
        cout << cls->id << "\t" << cls->name << endl;
        node = node->pNext;
    }
}
NodeCls *SNCls(DLink link, int ml)
{
    NodeCls *node = link.pHead;
    while (node != NULL)
    {
        /* code */
        Class *cls = node->data;
        if (cls->id == ml)
        {
            break;
        }
        node = node->pNext;
    }
    return node;
}