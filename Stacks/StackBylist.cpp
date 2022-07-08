#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
template <class t>
class node
{
public:
    t data;
    node *next;

    node(t data)
    {
        this->data = data;
        next = 0;
    }
};
template <class t>
class Stack
{
    node<t> *head;

public:
    Stack()
    {
        head = 0;
    }
    void push(t data)
    {
        node<t> *n = new node<t>(data);
        if (head == 0)
        {
            head = n;
            return;
        }
        n->next = head;
        head = n;
    }
    void pop()
    {
        if (head == 0)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        node<t> *temp = head;
        head = head->next;
        delete temp;
    }
    t top()
    {
        if (head == 0)
        {
            return -1;
        }
        return head->data;
    }
    bool empty()
    {
        if (head == 0)
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
        node<t> *temp = head;
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
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.display();
    return 0;
}