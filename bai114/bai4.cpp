#include <iostream>
#include <string.h>
#define MAX_OF_QUEUE 10

using namespace std;

struct Node
{
    int data;
    int priority;
};

Node queue[MAX_OF_QUEUE];
int rear = -1;
int front = -1;

void enqueue(Node *value)
{
    if (rear < MAX_OF_QUEUE - 1)
    {
        rear++;
        queue[rear] = *value;
    }
    else
    {
        cout << "Queue is full!!";
        exit(0);
    }
}

Node *dequeue()
{
    if (front == rear)
    {
        cout << "Queue is empty!!";
        exit(0);
    }
    front++;
    return &queue[front];
}

bool isEmpty()
{
    return front == rear;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Node *d = new Node;
        cin >> d->data >> d->priority;
        enqueue(d);
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        Node *d = dequeue();
        cout << d->data << "\t" << d->priority << endl;
    }
}