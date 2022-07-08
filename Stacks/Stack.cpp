#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
template <class t>
class Stack
{
    int ptr;
    int cap;
    t *stck;

public:
    Stack(int cap)
    {
        this->cap = cap;
        ptr = -1;
        stck = new t[cap];
    }
    ~Stack()
    {
        delete[] stck;
    }
    void push(t data)
    {
        if (ptr == cap - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        ptr++;
        stck[ptr] = data;
        return;
    }
    void pop()
    {
        if (ptr == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        ptr--;
    }
    t top()
    {
        return stck[ptr];
    }
    bool empty()
    {
        if (ptr == -1)
        {
            return true;
        }
        return false;
    }
    void display()
    {
        for (int i = ptr; i >= 0; i--)
        {
            cout << stck[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Stack<int> s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.display();
    return 0;
}