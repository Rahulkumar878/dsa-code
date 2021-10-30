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
void first_at_index(node *&head, int data)
{
    node *newnode = new node(data);
    if (head == NULL)
    {
        head = newnode;
        newnode->next = newnode;
        return;
    }
    node *temp = head;
    while (temp != head)
    {
        temp = temp->next;
    }
    newnode->next = head;
    head = newnode;
    temp->next = head;
}
void creation(node *&head, int data)
{
    node *newnode = new node(data);
    if (head == NULL)
    {
        first_at_index(head, data);
        return;
    }
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
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
}
void loopchecker(node *&head)
{
    node *slow = head;
    node *first = head;
    while (first != NULL && first->next != NULL)
    {
        slow = slow->next;
        first = first->next->next;
        if(first==slow)
        {
            cout<<"loop exit!"<<endl;
            return;
        }
    }
    cout<<"not exit"<<endl;
}
int main()
{
    node *head = NULL;
    creation(head, 10);
    creation(head, 20);
    creation(head, 30);
    creation(head, 40);
    creation(head, 50);
   // display(head);
   loopchecker(head);
}