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
void interchange_sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int a[n];
    enter_array(a, n);
    exp_array(a, n);
    interchange_sort(a, n);
    cout << "==>Sort!!\n";
    exp_array(a, n);
}