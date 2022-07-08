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
node *reverseInPair(node *&head, int n, int k)
{
    if (head == 0 && n < k)
    {
        return head;
    }
    else
    {
        node *current = head;
        node *nextnode = head;
        node *prev = 0;
        for (int i = 1; i <= k; i++)
        {
            nextnode = current->next;
            current->next = prev;
            prev = current;
            current = nextnode;
        }
        head->next = reverseInPair(current, n - k, k);
        return prev;
    }
}
int main()
{
    node *head = 0;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    node *ans = reverseInPair(head,5,4);
    display(ans);
    return 0;
}