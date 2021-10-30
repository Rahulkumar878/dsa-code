#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
void insertion_at_head(node *&head, int data)
{
    node *newnode = new node(data);
    if (head == NULL)
    {
        newnode->next = newnode;
        head = newnode;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    newnode->next = head;
    head = newnode;
    temp->next = newnode;
}
void creation(node *&head, int data)
{
    if (head == NULL)
    {
        insertion_at_head(head, data);
        return;
    }
    node *newnode = new node(data);
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
}
void display(node *head)
{
    node *temp = head;
    do
    {
        /* code */
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout<<"NULL";
}
int main()
{
    node *head = NULL;
    creation(head, 10);
    creation(head, 20);
    creation(head, 30);
    creation(head, 40);
    insertion_at_head(head,0);
    display(head);
    return 0;
}