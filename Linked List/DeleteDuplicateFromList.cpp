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
void insert(node *&head, int i)
{
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
void RemoveDuplicate(node *&head)
{
    node *temp = head;
    while(temp->next)
    {
        if(temp->data == temp->next->data)
        {
            node *next_itr = temp->next->next;
            delete temp->next;
            temp->next= next_itr;
        }
        else
        temp = temp->next;
    }
}
int main()
{
    node *head = 0;
    insert(head,1);
    insert(head,1);
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    RemoveDuplicate(head);
    display(head);
    return 0;
}