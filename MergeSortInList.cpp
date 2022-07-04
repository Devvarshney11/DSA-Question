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
node *merge(node *head1, node *head2)
{
    if (head1 == 0)
    {
        return head2;
    }
    if (head2 == 0)
    {
        return head1;
    }
    node *ans = 0;
    if (head1->data <= head2->data)
    {
        ans = head1;
        ans->next = merge(head1->next, head2);
    }
    else
    {
        ans = head2;
        ans->next = merge(head1, head2->next);
    }
    return ans;
}
node *middle(node *head)
{
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}
node *mergeSort(node *head)
{   
    if (!head || !head->next)
    {
        return head;
    }
    node *mid = middle(head);
    node *temp = mid->next;
    mid->next = 0;
    node *left = mergeSort(head);
    node *right = mergeSort(temp);
    node *ans = merge(left,right);
    return ans;
}
int main()
{
    node *head = 0;
    insert(head, 5);
    insert(head, 10);
    insert(head, 8);
    insert(head, 1);
    insert(head, 4);
    insert(head, 3);
    node *ans = mergeSort(head);
    display(ans);
    return 0;
}