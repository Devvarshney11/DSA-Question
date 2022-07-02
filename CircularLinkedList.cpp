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
    node(int i)
    {
        data = i;
        next = 0;
    }
};
class list
{
    int count;
    node *tail;

public:
    list()
    {
        count = 0;
        tail = 0;
    }
    void insert(int i)
    {
        count++;
        node *n = new node(i);
        if (tail == 0)
        {
            tail = n;
            n->next = tail;
            return;
        }
        n->next = tail->next;
        tail->next = n;
        tail = n;
    }
    void insertAtBeginning(int i)
    {
        count++;
        node *n = new node(i);
        n->next = tail->next;
        tail->next = n;
    }
    void insertAtEnd(int i)
    {
        count++;
        node *n = new node(i);
        n->next = tail->next;
        tail->next = n;
        tail = n;
    }
    void insertAtPosition(int i, int pos)
    {
        if (pos < 1 || pos > count + 1)
        {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 1)
        {
            insertAtBeginning(i);
        }
        else if (pos == count + 1)
        {
            insertAtEnd(i);
        }
        else
        {
            count++;
            node *temp = tail->next;
            node *n = new node(i);
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            n->next = temp->next;
            temp->next = n;
        }
    }
    void deleteAtBeginning()
    {
        if (tail == 0)
        {
            cout << "list underflow" << endl;
            return;
        }
        node *temp = tail->next;
        tail->next = temp->next;
        delete temp;
    }
    void deleteAtEnd()
    {
        if (tail == 0)
        {
            cout << "List underflow" << endl;
            return;
        }
        node *temp = tail->next;
        node *prev;
        while (temp->next != tail->next)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        tail = prev;
        delete temp;
    }
    void deleteAtPosition(int pos)
    {
        if (pos < 1 && pos > count)
        {
            cout << "Invalid position" << endl;
            return;
        }
        if (tail == 0)
        {
            cout << "List Underflow" << endl;
            return;
        }
        if (pos == 1)
        {
            deleteAtBeginning();
        }
        else if (pos == count)
        {
            deleteAtEnd();
        }
        else
        {
            node *temp = tail->next;
            node *prev;
            for (int i = 1; i < pos; i++)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
        }
    }
    void reverse()
    {
        if (tail == 0)
        {
            return;
        }
        node *currnode = tail->next;
        node *nextnode = tail->next;
        node *prevnode = tail;
        while (nextnode != tail)
        {
            nextnode = currnode->next;
            currnode->next = prevnode;
            prevnode = currnode;
            currnode = nextnode;
        }
        tail = currnode->next;
        currnode->next = prevnode;
    }
    void display()
    {
        node *temp = tail->next;
        while (temp->next != tail->next)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
};
int main()
{
    list l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.reverse();
    l.display();
    return 0;
}