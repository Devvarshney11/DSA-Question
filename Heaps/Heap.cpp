#include <bits/stdc++.h>

using namespace std;

//Insertion and Deletion 
//T.C : O(log n)
//S.C : O(log n)
class Heap
{
public:
    int *hp;
    int size;
    int capacity;
    int parent(int &i)
    {
        return (i - 1) / 2;
    }
    int leftChild(int &i)
    {
        return 2 * i + 1;
    }
    int rightChild(int &i)
    {
        return 2 * i + 2;
    }
    Heap(int c)
    {
        capacity = c;
        size = 0;
        hp = new int[c];
    }
    void insert(int value)
    {
        if (size == capacity)
        {
            cout << "Heap Overflow" << endl;
        }
        int i = size;
        size++;
        hp[i] = value;
        while (i >= 0 && hp[parent(i)] < hp[i])
        {
            swap(hp[parent(i)], hp[i]);
            i = parent(i);
        }
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << hp[i] << " ";
        }
        cout << endl;
    }
    void heapify(int i)
    {
        int l = leftChild(i);
        int r = rightChild(i);
        int s = i;
        if (l < size && hp[l] > hp[s])
            s = l;
        if (r < size && hp[r] > hp[s])
            s = r;
        if (s != i)
        {
            swap(hp[s], hp[i]);
            heapify(s);
        }
    }
    void deleteNode()
    {
        if(size == 0)
        {
            cout<<"Nothing to delete"<<endl;
            return;
        }
        hp[0] = hp[size-1];
        size--;
        heapify(0);
    }
};
int main()
{
    Heap h(10);
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.display();
    h.deleteNode();
    h.display(); 
}