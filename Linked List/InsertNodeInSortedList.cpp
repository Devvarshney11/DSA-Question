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
void insertAtCorrectPostion(node *&head, int i)
{
    node *n = new node(i);
    node *temp = head;
    while(temp->next && temp->next->data<n->data)
    {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}
int main()
{
    node *head = 0;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,7);
    insert(head,8);
    display(head);
    insertAtCorrectPostion(head,6);
    display(head);
    return 0;
}