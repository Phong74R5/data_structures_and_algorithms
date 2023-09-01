#include <iostream>
#include <string.h>
using namespace std;
struct staff
{
    int ID;
    char name[150];
    int age;
};
void enter_staff(staff l[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "+++++++++++++++++++\n";
        cout << "Staff " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> l[i].ID;
        getchar();
        cout << "Name: ";
        gets(l[i].name);
        cout << "Age: ";
        cin >> l[i].age;
        cout << "+++++++++++++++++++\n";
    }
}
void exp_staff(staff d[], int n)
{
    cout << "\nID\tName\tAge\n";
    for (int i = 0; i < n; i++)
    {
        cout << d[i].ID << "\t" << d[i].name << "\t" << d[i].age << endl;
    }
}
void SortAge(staff d[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (d[i].age > d[j].age)
            {
                staff temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
}
void SortName(staff d[], int l, int r)
{
    if (l >= r)
        return;
    staff pivot = d[(l + r) / 2];
    int i = l, j = r;
    do
    {
        while (stricmp(d[i].name, pivot.name) < 0)
        {
            i++;
        }
        while (stricmp(d[j].name, pivot.name) > 0)
        {
            j--;
        }
        if (i <= j)
        {
            staff temp = d[i];
            d[i] = d[j];
            d[j] = temp;
            i++, j--;
        }
    } while (i < j);
    SortName(d, l, j);
    SortName(d, i, r);
}
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    staff a[n];
    enter_staff(a, n);
    exp_staff(a, n);
    SortAge(a, n);
    cout << endl;
    cout << "==> Sort age:";
    exp_staff(a, n);
    SortName(a, 0, n - 1);
    cout << endl;
    cout << "==> Sort name:";
    exp_staff(a, n);
}