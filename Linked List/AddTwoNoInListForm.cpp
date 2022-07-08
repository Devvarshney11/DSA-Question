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

int length(node *head)
{
    int count = 1;
    node *temp = head;
    while (temp != 0)
    {
        temp = temp->next;
        count++;
    }
}

void addDigits(node *head1, node *head2, int &carry, node *&ans)
{
    if (!head1 && !head2)
    {
        return;
    }
    addDigits(head1->next, head2->next, carry, ans);
    int sum = head1->data + head2->data + carry;
    carry = sum / 10;
    sum = sum % 10;
    node *temp = new node(sum);
    temp->next = ans;
    ans = temp;
}

void addRemaining(node *head1, int &carry, node *&ans, int diff)
{
    if (!head1 || !diff)
    {
        return;
    }
    addRemaining(head1->next, carry, ans, diff--);
    int sum = head1->data + carry;
    carry = sum / 10;
    sum = sum % 10;
    node *temp = new node(sum);
    temp->next = ans;
    ans = temp;
}

node *addNo(node *head1, node *head2)
{
    if (head1 == 0)
    {
        return head2;
    }
    if (head2 == 0)
    {
        return head1;
    }
    int n = length(head1);
    int m = length(head2);
    node *temp = 0;
    if (n < m)
    {
        temp = head1;
        head1 = head2;
        head2 = temp;
    }
    int diff = abs(n - m);
    temp = head1;
    while (diff--)
    {
        temp = temp->next;
    }
    diff = abs(n - m);
    int carry = 0;
    node *ans = 0;
    addDigits(head1, head2, carry, ans);
    addRemaining(head1, carry, ans, diff);
    while (carry)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        node *temp = new node(sum);
        temp->next = ans;
        ans = temp;
    }
    return ans;
}

int main()
{
    node *head1 = 0;
    insert(head1, 9);
    insert(head1, 9);
    insert(head1, 9);
    node *head2 = 0;
    insert(head2, 9);
    insert(head2, 9);
    insert(head2, 9);
    node *ans = addNo(head1, head2);
    display(ans);
    return 0;
}