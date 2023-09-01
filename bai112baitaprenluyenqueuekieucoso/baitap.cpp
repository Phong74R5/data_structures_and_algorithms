#include <iostream>
using namespace std;

#define MAX_OF_QUEUE 10

double queue[MAX_OF_QUEUE];
int rear = -1;
int front = -1;

void enqueue(double value)
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

double dequeue()
{
    if (front == rear)
    {
        cout << "Queue is empty!!";
        exit(0);
    }
    front++;
    double value = queue[front];
    return value;
}

int main()
{
    double d;
    cin >> d;
    enqueue(d);
    cout << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
}