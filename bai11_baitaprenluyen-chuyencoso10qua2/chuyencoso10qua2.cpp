#include <iostream>
using namespace std;

void h10toh2(int n)
{
    if (n > 0)
    {
        int h2 = n % 2;
        n /= 2;
        h10toh2(n);
        cout << h2;
    }
}

int main()
{
    h10toh2(12);
}