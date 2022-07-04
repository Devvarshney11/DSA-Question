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
node *middle(node *head)
{
    node *fast, *slow;
    fast = slow = head;
    while (fast && fast->next)
    {
        fast = fast->next;
        if(fast != 0)
        {
           fast = fast->next;
           slow = slow->next;
        }
    }
    return slow;
}
int main()
{
    node *head = 0;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    cout<<middle(head)->data<<endl;
    return 0;
}