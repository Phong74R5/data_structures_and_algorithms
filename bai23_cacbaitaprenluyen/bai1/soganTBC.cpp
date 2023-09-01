#include <iostream>
using namespace std;
float abs_float(float n)
{
    if (n < 0)
    {
        return n * -1.0;
    }
    return n;
}
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
int search_near_avg(int a[], int n)
{
    float avg;
    int S = 0;
    for (int i = 0; i < n; i++)
    {
        S += a[i];
    }
    avg = S * 1.0 / n;
    int idsearch = 0;
    float near = abs_float(a[0] - avg);
    for (int i = 0; i < n; i++)
    {
        if (abs_float(a[i] - avg) <= near)
        {
            near = abs_float(a[i] - avg);
            idsearch = i;
        }
    }
    return idsearch;
}
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int a[n];
    enter_array(a, n);
    exp_array(a, n);
    cout << "==>Near AVG: " << a[search_near_avg(a, n)];
}