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
node *sortEvenOdd(node *head)
{
    node *evenH = 0;
    node *evenT = 0;
    node *oddH = 0;
    node *oddT = 0;
    node *temp = head;
    while (temp != 0)
    {
        if (temp->data & 1)
        {
            if (oddH == 0)
            {
                oddH = oddT = temp;
                temp = temp->next;
            }
            else
            {
                oddT->next = temp;
                temp = temp->next;
                oddT = oddT->next;
            }
        }
        else
        {
            if (evenH == 0)
            {
                evenH = evenT = temp;
                temp = temp->next;
            }
            else
            {
                evenT->next = temp;
                temp = temp->next;
                evenT = evenT->next;
            }
        }
    }
    evenT->next = oddH;
    oddT->next = 0;
    return evenH;
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
int main()
{
    node *head = 0;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    node *ans = sortEvenOdd(head);
    display(ans);
    return 0;
}