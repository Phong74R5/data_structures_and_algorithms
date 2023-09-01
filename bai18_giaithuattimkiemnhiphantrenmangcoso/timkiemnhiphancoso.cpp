#include <iostream>
using namespace std;
int binary_search(int a[], int n, int x)
{
    int l = 0;
    int r = n - 1;
    int mid = (l + r) / 2;
    do
    {
        mid = (l + r) / 2;
        if (x == a[mid])
        {
            return mid;
        }
        else
        {
            if (x < a[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    } while (l <= r);
    return -1;
}
int main()
{
    int a[8] = {1, 2, 3, 6, 7, 778, 3242345, 44444444};
    int x = 778;
    cout << binary_search(a, 8, x);
}