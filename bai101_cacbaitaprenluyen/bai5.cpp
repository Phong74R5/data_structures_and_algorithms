#include <iostream>
using namespace std;
#define MAX_OF_STACK 10

struct Block
{
    int id;
    int Data;
};

Block stack[MAX_OF_STACK];
int top = -1;
void push(Block value);
Block pop();

int main()
{
    push({02, 03202032});
    push({01, 12121212});
    cout << "ID"
         << "\t"
         << "Data" << endl;
    while (top >= 0)
    {
        Block t = pop(); // Lấy phần tử trên cùng stack
        cout << t.id << "\t" << t.Data << endl;
    }
}

void push(Block value)
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

Block pop()
{
    Block value;
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