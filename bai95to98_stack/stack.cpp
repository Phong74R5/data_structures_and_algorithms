#include <iostream>
using namespace std;
#define MAX_OF_STACK 10
int stack[MAX_OF_STACK];
int top = -1;
void push(int value);
int pop();

int main()
{
    push(12);
    push(3);
    push(5);
    int t = pop(); // Lấy phần tử trên cùng stack
    cout << t << endl;
}

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