#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
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
void menu_sort()
{
    cout << "\n==========MENU==========\n"
         << "1. Bubble Sort\n"
         << "2. Selection Sort\n"
         << "3. Insertion Sort\n"
         << "4. Interchange Sort\n"
         << "5. Quick Sort\n"
         << "6. Merge Sort\n"
         << "7. Reset array\n"
         << "0. Exit"
         << "\n========================\n";
}
void bubble_sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
void selection_sort(int a[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
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
void quick_sort(int a[], int left, int right)
{
    if (left >= right)
        return;
    int pivot = a[(left + right) / 2];
    int i = left, j = right;
    do
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i < j);
    quick_sort(a, left, j);
    quick_sort(a, i, right);
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
void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Tìm điểm chính giữa
        int m = (l + r) / 2;
        // Hàm đệ quy tiếp tục chia đôi
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
int main()
{
    srand(time(NULL));
    int n, key;
    clock_t start, end;
    double time_use;
    cout << "Enter n: ";
    cin >> n;
    int a[n];
    enter_array(a, n);
    int flag = 1;
    while (flag)
    {
        cout << "Do you want the array to appear on the screen?(y/n): ";
        char q;
        cin >> q;
        switch (q)
        {
        case 'y':
            exp_array(a, n);
            flag = 0;
            break;
        case 'n':
            flag = 0;
            break;
        default:
            break;
        }
    }
    while (1)
    {
        int temp[n];
        for (int i = 0; i < n; i++)
        {
            temp[i] = a[i];
        }
        menu_sort();
        cout << "Choose: ";
        cin >> key;
        switch (key)
        {
        case 1:
        {
            cout << "1. Bubble Sort\n";
            start = clock();
            bubble_sort(temp, n);
            end = clock();
            time_use = (double)(end - start);
            cout << "\n==> Time: " << time_use << "ms" << endl;
            int flag = 1;
            while (flag)
            {
                cout << "Do you want the sorted array to appear on the screen?(y/n): ";
                char q;
                cin >> q;
                switch (q)
                {
                case 'y':
                    exp_array(temp, n);
                    flag = 0;
                    break;
                case 'n':
                    flag = 0;
                    break;
                default:
                    break;
                }
            }
        }
        break;

        case 2:
        {
            cout << "2. Selection Sort\n";
            start = clock();
            selection_sort(temp, n);
            end = clock();
            time_use = (double)(end - start);
            cout << "\n==> Time: " << time_use << "ms" << endl;
            int flag = 1;
            while (flag)
            {
                cout << "Do you want the sorted array to appear on the screen?(y/n): ";
                char q;
                cin >> q;
                switch (q)
                {
                case 'y':
                    exp_array(temp, n);
                    flag = 0;
                    break;
                case 'n':
                    flag = 0;
                    break;
                default:
                    break;
                }
            }
        }
        break;

        case 3:
        {
            cout << "3. Insertion Sort\n";
            start = clock();
            insert_sort(temp, n);
            end = clock();
            time_use = (double)(end - start);
            cout << "\n==> Time: " << time_use << "ms" << endl;
            int flag = 1;
            while (flag)
            {
                cout << "Do you want the sorted array to appear on the screen?(y/n): ";
                char q;
                cin >> q;
                switch (q)
                {
                case 'y':
                    exp_array(temp, n);
                    flag = 0;
                    break;
                case 'n':
                    flag = 0;
                    break;
                default:
                    break;
                }
            }
        }
        break;

        case 4:
        {
            cout << "4. Interchange Sort\n";
            start = clock();
            interchange_sort(temp, n);
            end = clock();
            time_use = (double)(end - start);
            cout << "\n==> Time: " << time_use << "ms" << endl;
            int flag = 1;
            while (flag)
            {
                cout << "Do you want the sorted array to appear on the screen?(y/n): ";
                char q;
                cin >> q;
                switch (q)
                {
                case 'y':
                    exp_array(temp, n);
                    flag = 0;
                    break;
                case 'n':
                    flag = 0;
                    break;
                default:
                    break;
                }
            }
        }
        break;

        case 5:
        {
            cout << "5. Quick Sort\n";
            start = clock();
            quick_sort(temp, 0, n - 1);
            end = clock();
            time_use = (double)(end - start);
            cout << "\n==> Time: " << time_use << "ms" << endl;
            int flag = 1;
            while (flag)
            {
                cout << "Do you want the sorted array to appear on the screen?(y/n): ";
                char q;
                cin >> q;
                switch (q)
                {
                case 'y':
                    exp_array(temp, n);
                    flag = 0;
                    break;
                case 'n':
                    flag = 0;
                    break;
                default:
                    break;
                }
            }
        }
        break;

        case 6:
        {
            cout << "6. Merge Sort\n";
            start = clock();
            merge_sort(temp, 0, n - 1);
            end = clock();
            time_use = (double)(end - start);
            cout << "\n==> Time: " << time_use << "ms" << endl;
            int flag = 1;
            while (flag)
            {
                cout << "Do you want the sorted array to appear on the screen?(y/n): ";
                char q;
                cin >> q;
                switch (q)
                {
                case 'y':
                    exp_array(temp, n);
                    flag = 0;
                    break;
                case 'n':
                    flag = 0;
                    break;
                default:
                    break;
                }
            }
        }
        break;

        case 7:
        {
            cout << "Enter n: ";
            cin >> n;
            int a[n];
            enter_array(a, n);
            int flag = 1;
            while (flag)
            {
                cout << "Do you want the array to appear on the screen?(y/n): ";
                char q;
                cin >> q;
                switch (q)
                {
                case 'y':
                    exp_array(a, n);
                    flag = 0;
                    break;
                case 'n':
                    flag = 0;
                    break;
                default:
                    break;
                }
            }
        }
        break;

        case 0:
            return 0;
            break;

        default:
            break;
        }
    }
    getch();
}