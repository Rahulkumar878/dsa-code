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
void creation(node *&head, int data)
{
    node *n = new node(data);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void insertion_at_first(node *head, int data)
{
    node *newnode = new node(data);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}
void insert_at_last(node *head, int data)
{
    node *newnode = new node(data);
    node *temp;
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}
void insert_at_position(node *head, int position, int data)
{
    node *newnode = new node(data);
    node *temp;
    node *ptr;
    if (position == 1)
    {
        insertion_at_first(head, data);
        return;
    }
    temp = head;
    while (position != 1 && temp != NULL)
    {
        ptr=temp;
        temp = temp->next;
        position--;
    }
   ptr->next=newnode;
   newnode->next=temp;
}
int main()
{
    node *head = NULL;
    creation(head, 10);
    creation(head, 20);
    creation(head, 30);
    creation(head, 40);
    insertion_at_first(head, 0);
    insert_at_last(head, 50);
    insert_at_position(head, 3, 80);
   display(head);
   return 0;
}