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
    node()
    {
        cout << "Enter the value : ";
        cin >> data;
        next = 0;
    }
};
class list
{
    int count;
    node *head;

public:
    list()
    {
        head = 0;
        count = 0;
    }
    void insert(int i)
    {
        count++;
        node *n = new node(i);
        if (head == 0)
        {
            head = n;
            return;
        }
        node *temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    void insertAtBeginning(int i)
    {
        count++;
        node *n = new node(i);
        n->next = head;
        head = n;
    }
    void insertAtEnd(int i)
    {
        count++;
        node *n = new node(i);
        if (head == 0)
        {
            head = n;
            return;
        }
        node *temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    void insertAtposition(int i, int pos)
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
            node *n = new node(i);
            node *temp = head;
            for (int j = 1; j < pos - 1; j++)
            {
                temp = temp->next;
            }
            n->next = temp->next;
            temp->next = n;
        }
    }
    void deleteAtBeginning()
    {
        count--;
        if (head == 0)
        {
            cout << "List underflow" << endl;
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;
    }
    void deleteAtEnd()
    {
        count--;
        if (head == 0)
        {
            cout << "List underflow" << endl;
            return;
        }
        node *temp = head;
        node *prev = 0;
        while (temp->next != 0)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = 0;
        delete temp;
    }
    void deleteAtPosition(int pos)
    {
        if (pos < 1 || pos > count)
        {
            cout << "Invalid position" << endl;
            return;
        }
        if (head == 0)
        {
            cout << "List underflow" << endl;
            return;
        }
        else if (pos == 1)
        {
            deleteAtBeginning();
        }
        else if (pos == count)
        {
            deleteAtEnd();
        }
        else
        {
            count--;
            node *temp = head;
            node *prev;
            for (int j = 1; j < pos; j++)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
        }
    }
    bool isEmpty()
    {
        if (head == 0)
            return true;
        else
            return false;
    }
    void reverse()
    {
        if (head == 0)
        {
            return;
        }
        node *currnode = head;
        node *nextnode = head;
        node *prevnode = 0;
        while (nextnode != 0)
        {
            nextnode = currnode->next;
            currnode->next = prevnode;
            prevnode = currnode;
            currnode = nextnode;
        }
        head = prevnode;
    }
    void display()
    {
        node *temp = head;
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
    node *head = 0;
    list l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.display();
    // l.insertAtposition(0, 1);
    // l.display();
    // l.insertAtposition(6, 6);
    // l.insertAtposition(3, 4);
    // l.deleteAtPosition(1);
    // l.display();
    // l.deleteAtPosition(4);
    // l.display();
    // l.deleteAtPosition(2);
    l.reverse();
    l.display();
    return 0;
}