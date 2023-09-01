#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;
void enter_array(int a[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = 1 + rand() % 100;
    }
}
void exp_array(int a[], int n)
{
    cout << "Array:\n";
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << ", ";
    }
    cout << a[n - 1] << ".";
    cout << endl;
}
bool CheckSortUp(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                return false;
            }
        }
    }
    return true;
}
int BinarySearch(int a[], int n, int x)
{
    int l = 0;
    int r = n - 1;
    do
    {
        int mid = (l + r) / 2;
        if (x == a[mid])
            return mid;
        else if (x > a[mid])
            r = mid - 1;
        else
            l = mid + 1;
    } while (l <= r);
    return -1;
}
int LinearSearch(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (x == a[i])
            return i;
    return -1;
}
int main()
{
    int n, x, k;
    cout << "Enter n: ";
    cin >> n;
    int a[n];
    enter_array(a, n);
    exp_array(a, n);
    cout << "Enter x: ";
    cin >> x;
    if (CheckSortUp(a, n))
    {
        k = BinarySearch(a, n, x);
    }
    else
    {
        k = LinearSearch(a, n, x);
    }
    if (k == -1)
    {
        cout << "search x: false";
    }
    else
    {

        cout << "Search x: a[" << k << "]";
    }
    getch();
}