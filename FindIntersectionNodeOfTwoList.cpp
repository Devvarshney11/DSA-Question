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
int length(node *head)
{
    node *temp = head;
    int count = 1;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
node *findIntersection(node *head1, node *head2)
{
    int n = length(head1);
    int m = length(head2);

    int diff = abs(n-m);

    if(n>m)
    {
        while(diff--)
        {
            head1 = head1->next;
        }
    }
    else
    {
        while(diff--)
        {
            head2 = head2->next;
        }
    }
    while(head1 && head2 && head1 != head2)
    {
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1;
}
int main()
{
    node *head1 = new node(1);
    head1->next = new node(2);
    head1->next->next = new node(3);
    node *n1 = new node(4);
    head1->next->next = n1;
    node *head2 = new node(2);
    head2->next = n1;
    n1->next = new node(6);
    n1->next->next = new node(8);
    n1->next->next->next = new node(10);
    cout << findIntersection(head1,head2)->data << endl;

    return 0;
}