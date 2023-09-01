#include <iostream>
#define MAX 10

using namespace std;

double stack[MAX];
int top = -1;

void push(double value)
{
    if (top < MAX)
    {
        top++;
        stack[top] = value;
    }
    else
    {
        cout << "Stack full!!";
        exit(0);
    }
}

double pop()
{
    double value;
    if (top >= 0)
    {
        value = stack[top];
        top--;
    }
    else
    {
        cout << "Stack is empty";
        exit(0);
    }
    return value;
}

int main()
{
    cout << "Push:" << endl;
    for (double i = 0; i < MAX; i++)
    {
        double n;
        cin >> n;
        push(n);
    }
    cout << "Pop: ";
    for (double i = 0; i < MAX; i++)
    {
        double t = pop();
        cout << t << "\t";
    }
}