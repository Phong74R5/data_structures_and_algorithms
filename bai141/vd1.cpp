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

int giaithua(int n)
{
    int gt = 1;
    for (int i = 1; i <= n; i++)
    {
        gt *= i;
    }
    return gt;
}

int main()
{
    system("color 0A");
    /*code*/
    cout << giaithua(5) << endl;
}