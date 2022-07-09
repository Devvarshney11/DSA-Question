#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
class queue
{
    int size;
    int *q;
    int front;
    int rear;

    public:

    queue(int size)
    {
        this->size = size;
        q = new int[size];
        front = -1;
        rear = -1;
    }
    void enqueue(int data)
    {
        if(front == -1 && rear == -1)
        {
            front = rear = 0;
            q[rear] = data;
        }
        else if(rear == size-1)
        {
            cout<<"Queue overflow"<<endl;
            return;
        }
        else{
            rear++;
            q[rear] = data;
        }
    }
    void dequeue()
    {
        if(front == -1 && rear == -1)
        {
            cout<<"Queue underflow"<<endl;
            return;
        }
        else if(front == rear) 
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
    int getFront()
    {
        if(front == -1)
        {
            return -1;
        }
        else
        {
            return q[front];
        }
    }
    int getRear()
    {
        if(rear == -1)
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
        if(front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }
    void display()
    {
        int i = front;
        while(i<=rear)
        {
             cout<<q[i]<<" ";
             i++;
        }
        cout<<endl;
    }
};
int main()
{
    queue q(5);
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