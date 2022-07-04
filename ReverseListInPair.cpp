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

// By recursion

// node *reverseInPair(node *&head)
// {
//     //base case
//     if(head && head->next)
//     {
//         return head;
//     }
//     node *temp = head->next;
//     head->next = temp->next;
//     temp->next = head;
//     head = temp;
//     head->next->next = reverseInPair(head->next->next);
//     return head;
// }

// By Iteration

// node *reverseInPair(node *&head)
// {
//     if (head || head->next)
//     {
//         return head;
//     }
//     node *current = head;
//     node *temp1 = 0;
//     node *temp2 = 0;
//     while(current)
//     {
//         if(temp1 != 0)
//         {
//             //for substituting the use of prev pointer
//             temp1->next->next = current->next;
//         }
//         temp1 = current->next;
//         current->next = current->next->next;
//         temp1->next  = current;
//         if(temp2 == 0)
//         {
//             temp2 = temp1;
//         }
//         current = current->next;
//     }
//     return temp2;
// }

// By another method

node *reverseInPair(node *&head, int n)
{
    if (head && n < 2)
    {
        return head;
    }
    else
    {
        node *current = head;
        node *nextnode = head;
        node *prev = 0;
        for (int i = 1; i <= 2; i++)
        {
            nextnode = current->next;
            current->next = prev;
            prev = current;
            current = nextnode;
        }
        head->next = reverseInPair(current, n - 2);
        return prev;
    }
}
int main()
{
    node *head = 0;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    node *ans = reverseInPair(head, 5);
    display(ans);
    return 0;
}