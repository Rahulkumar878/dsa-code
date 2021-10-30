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
    node *newnode = new node(data);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
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
void deletion(node *&head, int pos)
{
    node *temp, *ptr;
    if (pos == 1)
    {
        temp = head;
        head = head->next;
        delete (temp);
        return;
    }
    temp = head;
    while (pos != 1 && temp != NULL)
    {
        pos--;
        ptr = temp;
        temp = temp->next;
    }
    ptr->next = temp->next;
    delete (temp);
}
int main()
{
    node *head = NULL;
    creation(head, 10);
    creation(head, 20);
    creation(head, 30);
    creation(head, 40);
    creation(head, 50);
    deletion(head, 4);
    display(head);
}