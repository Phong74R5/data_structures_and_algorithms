#include <iostream>
using namespace std;

int Stn(int n)
{
    if (n < 10)
    {
        return n;
    }
    return n % 10 + Stn(n / 10);
}

int main()
{
    cout << Stn(35613) << endl;
}