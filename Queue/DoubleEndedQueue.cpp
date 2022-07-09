#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Deque
{
    int *q;
    int front;
    int rear;
    int size;

public:
    Deque(int n)
    {
        size = n;
        q = new int[n];
        front = rear = -1;
    }

    void pushFront(int value)
    {
        if ((front + size - 1) % size == rear)
        {
            cout<<"Queue overflow"<<endl;
            return;
        }
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            q[front] = value;
            return;
        }
        front = (front + size - 1) % size;
        q[front] = value;
    }

    void pushRear(int value)
    {
        if ((rear + 1) % size == front)
        {
            cout<<"Queue overlfow"<<endl;
            return ;
        }
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            q[rear] = value;
            return;
        }
        rear = (rear + 1) % size;
        q[rear] = value;
    }

    void popFront()
    {
        if (front == -1 && rear == -1)
        {
           cout<<"Queue underflow"<<endl;
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

    void popRear()
    {
        if (front == -1 && rear == -1)
        {
           cout<<"Oueue underflow"<<endl;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            rear = (rear + size - 1) % size;
        }
    }

    int getFront()
    {
        if (front == -1 && rear == -1)
        {
            return -1;
        }
        return q[front];
    }

    int getRear()
    {
        if (rear == -1 && front == -1)
        {
            return -1;
        }
        return q[rear];
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if ((front + size - 1) % size == rear)
        {
            return true;
        }
        return false;
    }
    void display()
    {
        int i = front;
        while(i != rear)
        {
            cout<<q[i]<<" ";
            i = (i+1)%size;
        }
        cout<<q[rear]<<endl;
    }
};
int main()
{
    Deque d(5);
    d.pushFront(1);
    d.pushRear(5);
    d.pushFront(2);
    d.pushRear(4);
    d.pushFront(3);
    d.pushRear(6);
    d.display();
    return 0;
}