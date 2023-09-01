#include <iostream>
#include <string.h>
#define MAX_OF_QUEUE 10

using namespace std;

struct Customer
{
    int id;
    string name;
};

Customer queue[MAX_OF_QUEUE];
int rear = -1;
int front = -1;

void enqueue(Customer *value)
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

Customer *dequeue()
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
    Customer *c1 = new Customer;
    c1->id = 1;
    c1->name = "Phong";

    Customer *c2 = new Customer;
    c2->id = 2;
    c2->name = "An";

    Customer *c3 = new Customer;
    c3->id = 3;
    c3->name = "Truong";

    Customer *c4 = new Customer;
    c4->id = 4;
    c4->name = "Duy";

    enqueue(c1);
    enqueue(c2);
    enqueue(c3);
    enqueue(c4);

    while (isEmpty() == false)
    {
        Customer *d = new Customer;
        d = dequeue();
        cout << d->id << "\t" << d->name << endl;
    }
}