#include <iostream>
#include <string.h>
using namespace std;
struct book
{
    int id;
    char name[150];
    int year;
};
typedef struct book book;
void enter_book(book l[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nBook " << i + 1 << endl;
        cout << "ID: ";
        cin >> l[i].id;
        cout << "Name: ";
        getchar();
        gets(l[i].name);
        cout << "Publishing year: ";
        cin >> l[i].year;
    }
}
void exp_book(book l[], int n)
{
    cout << "\n***********************" << endl;
    cout << "\nID\tName\tYear\n";
    for (int i = 0; i < n; i++)
    {
        cout << l[i].id << "\t" << l[i].name << "\t" << l[i].year << endl;
    }
    cout << "\n***********************" << endl;
}
int search(book l[], int n, int fy)
{
    int flag = -1;
    cout << "\nID\tName\tYear\n";
    cout << "\n***********************" << endl;
    for (int i = 0; i < n; i++)
    {
        if (fy == l[i].year)
        {
            cout << l[i].id << "\t" << l[i].name << "\t" << l[i].year << endl;
            flag = 1;
        }
    }
    cout << "\n***********************" << endl;

    return flag;
}
int main()
{
    int n;
    int fy;
    cout << "Enter n: ";
    cin >> n;
    book l[n];
    enter_book(l, n);
    exp_book(l, n);
    cout << "Enter year to find: ";
    cin >> fy;
    if (search(l, n, fy) == -1)
    {
        cout << "\n==>Not found!!";
    }
}
