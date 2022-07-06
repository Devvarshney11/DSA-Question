// You are given a Singly Linked List of integers and an integer array 'B' of size 'N'.
// Each element in the array 'B' represents a block size.
// Modify the linked list by reversing the nodes in each block whose sizes are given by the array 'B'.
// Note:
// 1. If you encounter a situation when 'B[i]' is greater than the number of remaining nodes in the list,
//    then simply reverse the remaining nodes as a block and ignore all the block sizes from 'B[i]'.

// 2. All block sizes are contiguous i.e. suppose that block 'B[i]' ends at a node cur,
//    then the block 'B[i+1]' starts from the node just after the node cur.

// Example
// Linked list: 1->2->3->4->5
// Array B: 3 3 5
// Output: 3->2->1->5->4

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

node *getListAfterReverseOperation(node *head, int n, int b[])
{
    if (head == 0 || n == 0)
    {
        return head;
    }
    node *current = head;
    node *nextnode = head;
    node *prev = 0;
    int k = b[0];
    if (k == 0)
    {
        head = getListAfterReverseOperation(current, n - 1, b + 1);
        return head;
    }
    else
    {
        for (int i = 1; nextnode != 0 && i <= k; i++)
        {
            nextnode = current->next;
            current->next = prev;
            prev = current;
            current = nextnode;
        }
        head->next = getListAfterReverseOperation(current, n - 1, b + 1);
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
    insert(head,6);
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    head = getListAfterReverseOperation(head,n,arr);
    display(head);
    return 0;
}