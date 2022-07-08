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
node *findCyclic(node *head)
{
    node*fast,*slow;
    fast = slow = head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast)
        {
            break;
        }
    }
    slow = head;
    while(slow != fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
int main()
{
    node *head = new node(1);
    head->next = new node(2);
    node *n1 = new node(3);
    head->next->next = n1;
    head->next->next->next = new node(4);
    head->next->next->next->next = n1;
    cout<<findCyclic(head)->data<<endl;
    return 0;
}