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
    node *prev;
    node(int data)
    {
        this->data = data;
        next = 0;
        prev = 0;
    }
};
class list
{
    int count;
    node *head;
    node *tail;

public:
    list()
    {
        count = 0;
        head = 0;
        tail = 0;
    }
    void insert(int i)
    {
        count++;
        node *n = new node(i);
        if (head == 0 && tail == 0)
        {
            head = tail = n;
            return;
        }
        n->prev = tail;
        tail->next = n;
        tail = n;
    }
    void insertAtBeginning(int i)
    {
        count++;
        node *n = new node(i);
        head->prev = n;
        n->next = head;
        head = n;
    }
    void insertAtEnd(int i)
    {
        count++;
        node *n = new node(i);
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
    void insertAtPosition(int i, int pos)
    {
        if(pos<1 || pos>count+1)
        {
            cout<<"Invalid position"<<endl;
            return;
        }
        if(pos == 1)
        {
            insertAtBeginning(i);
        }
        else if(pos == count+1)
        {
            insertAtEnd(i);
        }
        else
        {
            node *temp = head;
            node *n = new node(i);
            for(int j = 1;j<pos-1;j++)
            {
                temp = temp->next;
            }
            n->prev = temp;
            n->next = temp->next;
            temp->next->prev = n;
            temp->next = n;
        }
    }
    void deleteAtBeginning()
    {
        if(head == 0)
        {
            cout<<"List underflow"<<endl;
            return;
        }
        node *temp = head;
        head = head->next;
        head->prev = 0;
        delete temp;
    }
    void deleteAtEnd()
    {
        if(head == 0)
        {
            cout<<"List underflow"<<endl;
            return;
        }
        node *temp = tail;
        tail = tail->prev;
        tail->next = 0;
        delete temp;
    }
    void deleteAtPosition(int pos)
    {
        if(pos<1 || pos>count)
        {
            cout<<"Invalid position"<<endl;
            return;
        }
        if(head == 0)
        {
            cout<<"List underflow"<<endl;
            return;
        }
        if(pos == 1)
        {
            deleteAtBeginning();
        }
        else if(pos == count)
        {
            deleteAtEnd();
        }
        else
        {
            count--;
            node*temp = head;
            for(int i = 1;i<pos;i++)
            {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }
    void reverse()
    {
        if(head == 0)
        {
            return;
        }
        node *currnode = head;
        node *nextnode = head;
        while(nextnode != 0)
        {
            nextnode = currnode->next;
            currnode->next = currnode->prev;
            currnode->prev = nextnode;
            currnode = nextnode;
        }
        currnode = head;
        head = tail;
        tail = currnode;
    }
    bool isEmpty()
    {
        if(head == 0)
        return true;
        return false;
    }
    void display()
    {
        node *temp = head;
        while(temp != 0)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
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
    l.display();
    // l.insertAtPosition(0,1);
    // l.display();
    // l.insertAtPosition(6,6);
    // l.display();
    // l.insertAtPosition(3,4);
    // l.display();
    //l.deleteAtPosition(2);
    l.reverse();
    l.display();
    return 0;
}