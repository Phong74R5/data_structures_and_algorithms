#include <iostream>
using namespace std;

int Sn(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + Sn(n - 1);
}

int main()
{
    cout << Sn(6);
}