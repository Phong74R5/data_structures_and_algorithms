#include <iostream>
#include <string.h>
using namespace std;
struct student
{
    char ID[10];
    char name[150];
    bool sex;
};
typedef struct student student;
void enter_stu(student l[], int n);
void exp_stu(student l[], int n);
student *find_student(student l[], int n, char find_ID[10]);
int main()
{
    int n = 3;
    char find_ID[10];
    student l[n];
    enter_stu(l, n);
    exp_stu(l, n);
    cout << "Enter ID to find: ";
    gets(find_ID);
    student *p = find_student(l, n, find_ID);
    if (p == NULL)
    {
        cout << "Student not found!!";
    }
    else
    {
        cout << "ID: ";
        cout << p->ID << endl;
        cout << "Name: ";
        cout << p->name << endl;
        cout << "Sex: ";
        if (p->sex)
            cout << "Female" << endl;
        else
            cout << "Male" << endl;
    }
}
void enter_stu(student l[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "ID: ";
        gets(l[i].ID);
        cout << "Name: ";
        gets(l[i].name);
        cout << "Sex (m/f): ";
        char sex[2];
        gets(sex);
        if (strcmp(sex, "m") == 0)
            l[i].sex = false;
        else
            l[i].sex = true;
    }
}
void exp_stu(student l[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "ID: ";
        puts(l[i].ID);
        cout << "Name: ";
        puts(l[i].name);
        cout << "Sex: ";
        if (l[i].sex)
            cout << "Female" << endl;
        else
            cout << "Male" << endl;
    }
}
student *find_student(student l[], int n, char find_ID[10])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(l[i].ID, find_ID) == 0)
        {
            return &l[i];
        }
    }
    return NULL;
}
