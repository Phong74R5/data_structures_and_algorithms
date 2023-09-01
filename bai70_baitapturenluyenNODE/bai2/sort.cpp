#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct Node
{
    /* data */
    int data;
    Node *pNext;
};

struct SingleList
{
    Node *pHead, *pTail;
    int nlist;//Số lượng phần tử trong danh sách liên kết
};

void Initialize(SingleList &list)
{
    list.pHead = list.pTail = NULL;
    list.nlist = 0;
}

Node *CreateNode(int d)
{
    Node *pNode = new Node;
    pNode->data = d;
    pNode->pNext = NULL;
    return pNode;
}

void InsertLast(SingleList &list, int d)
{
    Node *pNode = CreateNode(d);
    if (list.pTail == NULL)
    {
        list.pHead = list.pTail = pNode;
    }
    else
    {
        list.pTail->pNext = pNode;
        list.pTail = pNode;
    }
    list.nlist++; //Cập nhật số lượng phần tử của danh sách liên kết
}

void PrintList(SingleList &list)
{

    if (list.pHead == NULL)
    {
        cout << "The list is empty";
    }
    else
    {
        Node *pTmp = list.pHead;
        while (pTmp != NULL)
        {
            cout << pTmp->data << "  ";
            pTmp = pTmp->pNext;
        }
    }
}
// Sắp xếp giá trị giảm dần
//??sử dụng giải thuật selection sort
void Sort(SingleList &list)
{
    Node *n = list.pHead; // dùng để quản lí phần tử trong list
    Node *pCheck = n;     // tìm phần tử nhỏ nhất
    Node *pPre = NULL;    // tìm phần tử kế bên phần tử bị lấy ra
    int i = 1;
    while (i <= list.nlist)
    {
        while (pCheck != NULL)
        {
            Node *Check = n;
            int s = 0;
            Node *pTmp = NULL;
            pTmp = Check->pNext;
            // tìm phần tử nhỏ nhất
            while (pTmp != NULL)
            {
                if (Check->data < pTmp->data)
                {
                    Check = pTmp;
                }
                pTmp = pTmp->pNext;
            }
            if (pCheck == Check)
            {
                break;
            }
            pPre = pCheck;
            pCheck = pCheck->pNext;
        }
        // Đưa phần tử nhỏ nhất trong khoảng lên đầu danh sách -->
        if (pCheck == list.pTail)
        {
            list.pTail = pPre;
            pPre->pNext = NULL;
            pCheck->pNext = list.pHead;
            list.pHead = pCheck;
        }
        else if (pCheck != list.pHead)
        {
            pPre->pNext = pCheck->pNext;
            pCheck->pNext = list.pHead;
            list.pHead = pCheck;
        }
        //<--Đưa phần tử nhỏ nhất trong khoảng lên đầu danh sách
        //!!giới hạn lại danh sách phần tử cần xét
        //??Do những phần tử đã sắp xếp đã được sắp xếp
        int f = 0;
        n = list.pHead;
        while (f < i)
        {
            n = n->pNext;
            f++;
        }
        i++;
    }
}
int main()
{
    srand(time(NULL));
    SingleList list;
    int n;
    Initialize(list);
    for (int i = 0; i < 20; i++)
    {
        InsertLast(list, rand() % 100);
    }
    PrintList(list);
    cout << "\nSort:" << endl;
    Sort(list);
    PrintList(list);
    // cout << MIN(list)->data;
}