#include <iostream>
using namespace std;

#define MAX_OF_QUEUE 10

int queue[MAX_OF_QUEUE];
int rear = -1;
int front = -1;

void enqueue(int value)
{
    if (rear < MAX_OF_QUEUE - 1)
    {
        rear++;
        queue[rear] = value;
    }
    else
    {
        cout << "Queue is full!!";
        exit(0);
    }
}

int dequeue()
{
    if (front == rear)
    {
        cout << "Queue is empty!!";
        exit(0);
    }
    front++;
    int value = queue[front];
    return value;
}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;
    int temp1 = n;
    int count = 0;
    while (temp1 > 0)
    {
        count++;
        int temp2 = temp1 % 10;
        if (temp1 < 10)
        {
            enqueue(temp1);
        }
        temp1 /= 10;
        enqueue(temp2);
    }
    cout << endl;
    for (int i = 0; i < count; i++)
    {
        cout << dequeue();
    }
    cout << endl;
}