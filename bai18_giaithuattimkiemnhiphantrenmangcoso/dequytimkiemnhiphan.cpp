#include <iostream>
using namespace std;
int binary_search(int a[], int x, int l, int r)
{
    if (l > r)
    {
        return -1;
    }
    int mid = (l + r) / 2;
    if (x == a[mid])
    {
        return mid;
    }
    if (x < a[mid])
    {
        return binary_search(a, x, l, mid - 1);
    }
    return binary_search(a, x, mid + 1, r);
}
int main()
{
    int a[6] = {1, 2, 3, 6, 7, 778};
    int x = 7;
    cout << binary_search(a,x,0,5);
}