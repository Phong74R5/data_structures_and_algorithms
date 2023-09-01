#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void bubble_sort(int a[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
            }
        }
    }
}

int main()
{
    int n = 9;
    int a[n] = {3, 5, 1, 6, 12, 7, 4, 10, 2};
    bubble_sort(a, n);
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << ", ";
    }
    cout << a[n - 1] << ".";
    cout << endl;
}
