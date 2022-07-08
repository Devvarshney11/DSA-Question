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
void reverse(node *&head)
{
    if (!head || !head->next)
    {
        return;
    }
    node *current = head;
    node *nextnode = head;
    node *prev = 0;
    while (nextnode)
    {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    head = prev;
}
node *addOne(node *head)
{
    if (!head)
    {
        return 0;
    }
    reverse(head);
    node *temp = head;
    int sum = 0;
    int carry = 1;
    node *ans = new node(0);
    node *itr = ans;
    while (temp != 0)
    {
        sum = temp->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        itr->next = new node(sum);
        itr = itr->next;
        temp = temp->next;
    }
    while (carry)
    {
        sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        itr->next = new node(sum);
        itr = itr->next;
    }
    temp = ans->next;
    reverse(temp);
    return temp;
}
int main()
{

    node *head = 0;
    insert(head, 9);
    insert(head, 9);
    insert(head, 8);
    node *ans = addOne(head);
    display(ans);
    return 0;
}