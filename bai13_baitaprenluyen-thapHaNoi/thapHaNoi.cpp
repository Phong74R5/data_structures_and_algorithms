#include <iostream>
using namespace std;
void move(int n, char A, char B, char C)
{
    if (n == 1)
        cout << A << "==>" << C << endl;
    else
    {
        move(n - 1, A, C, B);
        cout << A << "==>" << C << endl;
        move(n - 1, B, A, C);
    }
}
int main()
{
    int n = 3;
    move(n, 'A', 'B', 'C');
}