#include <iostream>
using namespace std;
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
void swap(float &a, float &b)
{
    float temp = a;
    a = b;
    b = temp;
}
void sort_down(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}
int search_binary_down(float a[], int n, float x)
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
int main()
{
    int n;
    float x;
    cout << "Enter n: ";
    cin >> n;
    float a[n];
    enter_array(a, n);
    sort_down(a,n);
    exp_array(a, n);
    cout << "Enter x: ";
    cin >> x;
    if (search_binary_down(a,n,x)==-1)
    {
        cout << "Not found!!!";
    }
    else
    {
        cout <<"There is x in the array";
    }

}