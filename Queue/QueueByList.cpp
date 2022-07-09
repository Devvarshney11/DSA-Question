#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = 0;
    }
};

class queue
{
    node *front;
    node *rear;

public:
    queue()
    {
        front = 0;
        rear = 0;
    }
    void enqueue(int data)
    {
        node *n = new node(data);
        if (front == 0 && rear == 0)
        {
            front = rear = n;
            return;
        }
        rear->next = n;
        rear = n;
    }
    void dequeue()
    {
        if (front == 0 && rear == 0)
        {
            cout << "Queue underflow" << endl;
            return;
        }
        if(front == rear)
        {
           node *temp = front;
           front = rear = 0;
        }
        node *temp = front;
        front = front->next;
        delete temp;
    }
    int getFront()
    {
        if (front == 0)
        {
            return -1;
        }
        return front->data;
    }
    int getRear()
    {
        if (rear == 0)
        {
            return -1;
        }
        return rear->data;
    }
    bool empty()
    {
        if (front == 0 && rear == 0)
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
        node *temp = front;

        while (temp != 0)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    queue q;
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