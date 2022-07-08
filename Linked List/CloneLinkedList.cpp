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
    node *random;
    node(int i)
    {
        data = i;
        next = 0;
        random = 0;
    }
    node()
    {
        cout << "Enter the value : ";
        cin >> data;
        next = 0;
        random = 0;
    }
};
void display(node *head)
{
    node *temp = head;
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *clone(node *head)
{
    if(head == 0 && head->next == 0)
    {
        return head;
    }
    node *temp = head;
    while(temp != 0)
    {
        node *n = new node(temp->data);
        n->next = temp->next;
        temp->next = n;
        temp = n->next;
    }
    temp = head;
    while(temp != 0)
    {
        if(temp->next != 0)
        {
            temp->next->random = (temp->random)?temp->random->next:0;
        }
        temp = temp->next->next;
    }
    temp = head;
    node *clone = head->next;
    node *copy = clone;
    while(copy != 0 && temp != 0)
    {
        temp->next = temp->next->next;
        if(copy->next != 0)
        {
            copy->next = copy->next->next;
        }
        else
        {
            copy->next = 0;
        }
        copy = copy->next;
        temp = temp->next;
    }
    return clone;
}
int main()
{
    return 0;
}