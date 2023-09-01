#include <iostream>
using namespace std;
#define MAX_OF_STACK 10
int stack[MAX_OF_STACK];
int top = -1;
void push(int value);
int pop();

void push(int value)
{
    if (top < MAX_OF_STACK)
    {
        top++;
        stack[top] = value;
    }
    else
    {
        cout << "stack full!!";
        exit(0);
    }
}

int pop()
{
    int value;
    if (top >= 0)
    {
        value = stack[top];
        top--;
    }
    else
    {
        cout << "Stack is empty!!";
        exit(0);
    }
    return value;
}

int main()
{
    int n = 10;
    int tmp = n;
    while (tmp > 0)
    {
        int sd = tmp % 2;
        push(sd);
        tmp /= 2;
    }
    while (top >= 0)
    {
        int t = pop();
        cout << t;
    }
}