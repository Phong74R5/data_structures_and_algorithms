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

float AVG_check_k_array(int a[], int n, int k)
{
    int S = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= k)
        {
            S += a[i];
            count ++;
        }
    }
    return S * 1.0 / count;
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
    cout << "Enter k: ";
    cin >> k;
    cout << "AVG: " << AVG_check_k_array(a, n, k);
}