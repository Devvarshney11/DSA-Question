#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class node
{
public:
    char data;
    node *next;
    node(char i)
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
void insert(node *&head, char i)
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
    if (!head && !head->next)
    {
        return;
    }
    node *current = head;
    node *nextnode = head;
    node *prev = 0;
    while (nextnode != 0)
    {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    head = prev;
}
bool check(node *head1, node *head2)
{
    while (head1 && head2)
    {
        if (head1->data != head2->data)
            return false;
        else
        {
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    if (head1 == 0 && head2 == 0)
    {
        return true;
    }
    return false;
}
bool palindrome(node *head)
{
    if (head && head->next)
    {
        node *fast = head;
        node *slow = head;
        node *prev;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = 0;
        node *second = slow;
        reverse(second);
        return check(head, second);
    }
    return true;
}
int main()
{
    node *head = 0;
    insert(head, 'a');
    insert(head, 'b');
    insert(head, 'c');
    insert(head, 'b');
    insert(head, 'a');
    display(head);
    cout << palindrome(head) << endl;
    return 0;
}