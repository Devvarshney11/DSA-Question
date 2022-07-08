// There are Three Apparoch to solve this
// i - By taking one node and check duplicate in rest of the list
// ii - By Sorting and check in sorted linked list
// iii - By Hash Map
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

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
void RemoveDuplicate(node *&head)
{
    set<int> s;
    node *temp = head;
    node *prev = 0;
    while (temp != 0)
    {
        if (!s.count(temp->data))
        {
            s.insert(temp->data);
            prev = temp;
            temp = temp->next;
        }
        else
        {
            prev->next = temp->next;
            delete temp;
            temp = prev->next;
        }
    }
}
int main()
{
    node *head = 0;
    insert(head, 4);
    insert(head, 2);
    insert(head, 5);
    insert(head, 10);
    insert(head, 5);
    insert(head, 2);
    insert(head, 1);
    insert(head, 2);
    insert(head, 1);
    RemoveDuplicate(head);
    display(head);
    return 0;
}