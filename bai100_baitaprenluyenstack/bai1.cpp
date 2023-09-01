#include <iostream>
#include <string.h>
using namespace std;
#define MAX_OF_STACK 10

struct device
{
    int id;
    string name;
};

device stack[MAX_OF_STACK];
int top = -1;
void push(device data);
device pop();

int main()
{
    push({02, "HP"});
    push({01, "Lenevo"});
    cout << "ID"
         << "\t"
         << "Name" << endl;
    while (top >= 0)
    {
        device t = pop(); // Lấy phần tử trên cùng stack
        cout << t.id << "\t" << t.name << endl;
    }
}

void push(device data)
{
    if (top < MAX_OF_STACK)
    {
        top++;
        stack[top] = data;
    }
    else
    {
        cout << "stack full!!";
        exit(0);
    }
}

device pop()
{
    device value;
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