#include <iostream>
#include <stdlib.h>
#include <time.h>
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
int OddEven(int a[], int n, int c)
{
    int o = 0, e = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            e++;
        }
        else
        {
            o++;
        }
    }
    return c ? e : o;
}
void insert_sort(int a[], int n)
{
    int pos = 0;
    int x;
    for (int i = 1; i < n; i++)
    {
        x = a[i];
        for (pos = i; (pos > 0) && (a[pos - 1] > x); pos--)
        {
            a[pos] = a[pos - 1];
        }
        a[pos] = x;
    }
}
void merge(int arr[], int l, int m, int r)
{
    // Tìm kích thước của 2 mảng con để merged
    int n1 = m - l + 1;
    int n2 = r - m;
    // Tạo mảng tạm
    int L[n1];
    int R[n2];
    // Copy dữ liệu vào mảng tạm
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];
    // Merge các mảng tạm lại
    // Chỉ mục ban đầu của 2 mảng con
    int i = 0, j = 0;
    // Chỉ mục ban đầu của mảng phụ được hợp nhất
    int k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Sao chép các phần tử còn lại của L[] nếu có
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Sao chép các phần tử còn lại của R[] nếu có
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void sort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Tìm điểm chính giữa
        int m = (l + r) / 2;
        // Hàm đệ quy tiếp tục chia đôi
        sort(arr, l, m);
        sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
void SplitArray(int a[], int b[], int c[], int n)
{
    int o = 0, e = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            b[e] = a[i];
            e++;
        }
        else
        {
            c[o] = a[i];
            o++;
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
    int n1 = OddEven(a, n, 1);
    int n2 = OddEven(a, n, 0);
    int b[n1];
    int c[n2];

    SplitArray(a, b, c, n);
    sort(b, 0, n1 - 1);
    insert_sort(c, n2);
    cout << "==>Split:\n";
    exp_array(b, n1);
    exp_array(c, n2);
}