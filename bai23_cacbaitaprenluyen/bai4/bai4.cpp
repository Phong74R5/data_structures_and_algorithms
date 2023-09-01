#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void enter_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
}
void exp_array(int a[], int n)
{
    cout << "Array: ";
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << ", ";
    }
    cout << a[n - 1] << ".";
    cout << endl;
}
void sortup(int a[], int n)
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
int min_near(int a[], int n)
{
    int M = a[0];
    for (int i = 0; i < n; i++)
    {
        if (M < a[i])
        {
            return a[i];
        }
    }
}

int main()
{
    srand(time(NULL));
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    int a[n];
    enter_array(a, n);
    exp_array(a, n);
    sortup(a, n);
    cout << "Min 2st: " << min_near(a, n);
}
