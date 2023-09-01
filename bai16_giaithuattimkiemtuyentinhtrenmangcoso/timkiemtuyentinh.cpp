#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;
int lsearch(int M[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (x == M[i])
            return i;
    return -1;
}
int main()
{
    srand(time(NULL));
    int n = 5, x = 74;
    int M[n];

    for (int i = 0; i < n; i++)
    {
        M[i] = rand() % 100;
        cout << M[i] << " ";
    }
    cout << endl;

    cout << lsearch(M, n, x);
    getch();
}