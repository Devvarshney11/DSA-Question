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

// By count method
// node *sortList(node *head)
// {
//     int count0 = 0;
//     int count1 = 0;
//     int count2 = 0;
//     node *temp = head;
//     while (temp != 0)
//     {
//         if (temp->data == 0)
//             count0++;
//         else if (temp->data == 1)
//             count1++;
//         else
//             count2++;
//         temp = temp->next;
//     }
//     temp = head;
//     while (temp && count0)
//     {
//         temp->data = 0;
//         temp = temp->next;
//         count0--;
//     }
//     while (temp && count1)
//     {
//         temp->data = 1;
//         temp = temp->next;
//         count1--;
//     }
//     while (temp && count2)
//     {
//         temp->data = 2;
//         temp = temp->next;
//         count2--;
//     }
//     return head;
// }

// By seprate list method
node *sortList(node *head)
{
    node *oneHead = new node(-1);
    node *oneTail = oneHead;
    node *zeroHead = new node(-1);
    node *zeroTail = zeroHead;
    node *twoHead = new node(-1);
    node *twoTail = twoHead;

    node *temp = head;
    while (temp != 0)
    {
        int value = temp->data;
        if (value == 0)
        {
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if (value == 1)
        {
            oneTail->next = temp;
            oneTail = temp;
        }
        else
        {
            twoTail->next = temp;
            twoTail = temp;
        }
        temp = temp->next;
    }
    twoTail->next = 0;
    twoHead = twoHead->next;
    oneTail->next = twoHead;
    oneHead = oneHead->next;
    zeroTail->next = oneHead;
    zeroHead = zeroHead->next;

    return zeroHead;
}

int main()
{
    node *head = 0;
    insert(head ,1);
    insert(head ,1);
    insert(head ,0);
    insert(head ,2);
    insert(head ,2);
    insert(head ,0);
    head = sortList(head);
    display(head);
    return 0;
}