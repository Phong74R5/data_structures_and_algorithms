#include <algorithm>
#include <cstring>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

using namespace std;

long h10toh2(int n)
{
    int temp = 1;
    long kq = 0;
    while (n > 0)
    {
        int sd = n % 2;
        n /= 2;
        kq += sd * temp;
        temp *= 10;
    }
    return kq;
}

int main()
{
    system("color 0A");
    /*code*/
    cout << h10toh2(123) << endl;
}