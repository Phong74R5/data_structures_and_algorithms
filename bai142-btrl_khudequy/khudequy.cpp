#include <iostream>
using namespace std;
int fib(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    int f = 1;
    int tmp = 1;
    for (int i = 2; i < n; i++)
    {
        f = f + tmp;
        tmp = f - tmp;
    }
    return f;
}

int main()
{
    cout << fib(10);
}