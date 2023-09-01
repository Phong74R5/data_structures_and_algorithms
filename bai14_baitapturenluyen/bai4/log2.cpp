#include <iostream>
using namespace std;
int log2(int n)
{
    if (n < 0)
    {
        return -1;
    }
    else
    {
        if (n >= 2)
        {
            return 1 + log2(n / 2);
        }
        else
        {
            return 0;
        }
    }
}
int main()
{
    cout << log2(4);
}