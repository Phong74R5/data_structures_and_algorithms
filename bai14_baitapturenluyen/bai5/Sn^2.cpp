#include <iostream>
using namespace std;

int Sn_2(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * n + Sn_2(n - 1);
}

int main()
{
    cout << Sn_2(3);
}