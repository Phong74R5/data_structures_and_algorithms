#include <iostream>
using namespace std;
void enter_array(float a[], int n);
void exp_array(float a[], int n);
int count_x(float a[], int n, float x);
float max(float a[], int n);
float min(float a[], int n);
int main()
{
    int n;
    float x;
    cout << "Enter n: ";
    cin >> n;
    float a[n];
    enter_array(a, n);
    exp_array(a, n);
    cout << "Enter x: ";
    cin >> x;
    cout << "there are " << count_x(a, n, x) << " times x appears" << endl;
    cout << "MAX: " << max(a, n) << endl;
    cout << "MIN: " << min(a, n);
}
void enter_array(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "A[" << i << "]=";
        cin >> a[i];
    }
}
void exp_array(float a[], int n)
{
    cout << "Array: ";
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << ", ";
    }
    cout << a[n - 1] << ".";
    cout << endl;
}
int count_x(float a[], int n, float x)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (x == a[i])
        {
            count++;
        }
    }
    return count;
}
float max(float a[], int n)
{
    float m = a[0];
    for (int i = 1; i < n; i++)
    {
        if (m < a[i])
        {
            m = a[i];
        }
    }
    return m;
}
float min(float a[], int n)
{
    float m = a[0];
    for (int i = 1; i < n; i++)
    {
        if (m > a[i])
        {
            m = a[i];
        }
    }
    return m;
}