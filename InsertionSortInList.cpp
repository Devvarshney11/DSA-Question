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
void sorted(node *&s, node *temp)
{
    if (s == 0 || s->data >= temp->data)
    {
        temp->next = s;
        s = temp;
    }
    else
    {
        node *itr = s;
        while (itr->next && itr->next->data < temp->data)
        {
            itr = itr->next;
        }
        temp->next = itr->next;
        itr->next = temp;
    }
}
void insertionSort(node *&head)
{
    if (!head && !head->next)
    {
        return;
    }
    node *temp = head;
    node *s = 0;
    while (temp != 0)
    {
        node *n = temp->next;
        sorted(s, temp);
        temp = n;
    }
    head = s;
}
int main()
{
    node *head = 0;
    insert(head, 5);
    insert(head, 1);
    insert(head, 3);
    insert(head, 2);
    insert(head, 6);
    insert(head, 4);
    display(head);
    insertionSort(head);
    display(head);
    return 0;
}