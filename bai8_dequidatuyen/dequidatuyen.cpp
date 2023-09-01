#include <iostream>
using namespace std;

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void print_permutation(int arr[], int n, int i)
{
    int j;
    print_array(arr, n);
    for (j = i + 1; j < n; j++)
    {
        if (arr[i] > arr[j])
        {
            swap(arr[i], arr[j]);
        }
        print_permutation(arr, n, i + 1);
    }
}
int main()
{
    int M[3] = {10, 2, 5};
    print_permutation(M, 3, 0);
}