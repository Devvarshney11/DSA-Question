#include <iostream>

using namespace std;

class kQueue
{
private:
    int n;
    int k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freespot;

public:
    kQueue(int N, int K)
    {
        n = N;
        k = K;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        
        for(int i = 0;i<k;i++)
        {
            front[i] = rear[i] = -1;
        }
        next = new int[n];
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        freespot = 0;
    }
    void enqueue(int data, int q)
    {
        // overflow condition
        if (freespot == -1)
        {
            cout << "Queue overflow" << endl;
            return;
        }
        // Intitalize index
        int index = freespot;

        // update freespot

        freespot = next[index];

        if (front[q - 1] == -1)
        {
            front[q - 1] = index;
        }
        else
        {
            // link new element with previous one
            next[rear[q - 1]] = index;
        }
        // update next
        next[index] = -1;

        // update rear
        rear[q - 1] = index;

        // insert element in main array
        arr[index] = data;
    }
    int dequeue(int q)
    {
        if (front[q - 1] == -1)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }
        // intialize index
        int index = front[q - 1];

        // update front
        front[q - 1] = next[index];

        // update next[index] with next free spot
        next[index] = freespot;

        // update freespot with index;
        freespot = index;
        return arr[index];
    }
};
int main()
{
    kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    return 0;
}