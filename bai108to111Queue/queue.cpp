#include <iostream>
#define MAX_OF_QUEUE 100
using namespace std;

int queue[100];
int rear = -1;
int front = -1;
void enqueue(int value);
int dequeue();
int main()
{
    enqueue(1);
    enqueue(9);
    enqueue(7);
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
}

void enqueue(int value)
{
    if (rear < MAX_OF_QUEUE - 1)
    {
        rear++;
        queue[rear] = value;
    }
    else
    {
        cout << "Queue is full";
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