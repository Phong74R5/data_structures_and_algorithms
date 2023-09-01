#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void enter_array(int a[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = -50 + rand() % 100;
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
void quick_sort(int a[], int left, int right)
{
    if (left >= right)
        return;
    int pivot = a[(left + right) / 2];
    int i = left, j = right;
    do
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i < j);
    quick_sort(a, left, j);
    quick_sort(a, i, right);
}
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int a[n];
    enter_array(a, n);
    exp_array(a, n);
    quick_sort(a, 0, n - 1);
    cout << "==>Sort!!\n";
    exp_array(a, n);
}