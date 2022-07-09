#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class cqueue
{
    int *q;
    int front;
    int rear;
    int size;

public:
    cqueue(int s)
    {
        size = s;
        q = new int[s];
        front = rear = -1;
    }
    void enqueue(int data)
    {
        if (rear == size - 1 && (rear + 1) % size == front)
        {
            cout << "Queue overflow" << endl;
            return;
        }
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            q[rear] = data;
            return;
        }
        rear = (rear + 1) % size;
        q[rear] = data;
    }
    void dequeue()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue underflow" << endl;
            return;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }
    int getFront()
    {
        if (front == -1)
        {
            return -1;
        }
        else
        {
            return q[front];
        }
    }
    int getrear()
    {
        if (rear == -1)
        {
            return -1;
        }
        else
        {
            return q[rear];
        }
    }
    bool empty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void display()
    {
        int i = front;
        while (i != rear)
        {
            cout << q[i] << " ";
            i = (i + 1) % size;
        }
        cout << q[rear] << endl;
    }
};
int main()
{
    cqueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}