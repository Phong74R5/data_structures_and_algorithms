#include <iostream>
using namespace std;
void enter_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "A[" << i << "]=";
        cin >> a[i];
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
void sortdown(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void exp_array_no_x(int a[], int n)
{
    cout << "Array: ";
    for (int i = 1; i < n - 1; i++)
    {
        cout << a[i] << ", ";
    }
    cout << a[n - 1] << ".";
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int a[n];
    enter_array(a, n);
    exp_array(a, n);
    cout << "==>Larger number than smallest number:";
    sortup(a, n);
    exp_array_no_x(a, n);
    cout << "==>Smaller number than the largest:";
    sortdown(a, n);
    exp_array_no_x(a, n);
}