#include <iostream>
using namespace std;

int choose(int n, int k)
{
    if (k == 0 || n == k)
        return 1;
    return choose(n - 1, k) + choose(n - 1, k - 1);
}

int main()
{
    cout << choose(5, 3);
}