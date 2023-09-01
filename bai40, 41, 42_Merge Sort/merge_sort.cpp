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
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int a[n];
    enter_array(a, n);
    exp_array(a, n);
    sort(a, 0, n - 1);
    cout << "==>Sort!!\n";
    exp_array(a, n);
}