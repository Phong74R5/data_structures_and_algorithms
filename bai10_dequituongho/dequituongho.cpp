#include <iostream>
using namespace std;
bool isEven(int n);
bool isOdd(int n);
bool isEven(int n)
{
    if (n == 0)
    {
        return true;
    }
    else
    {
        return isOdd(n - 1);
    }
}
bool isOdd(int n)
{
    return !isEven(n);
}
int main()
{
    cout << isEven(8) << endl;
}