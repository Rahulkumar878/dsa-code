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
void reverse(node *&head)
{
    node *current=head;
    node *nextnode=head;
    node *prevnode=NULL;
    while(nextnode!=NULL)
    {
        nextnode=nextnode->next;
        current->next=prevnode;
        prevnode=current;
        current=nextnode;
    }
    head=prevnode;
}
int main()
{
    node *head = NULL;
    creation(head, 10);
    creation(head, 20);
    creation(head, 30);
    creation(head, 40);
     display(head);
     cout<<endl;
     cout<<"after the reversing node are"<<endl;
     reverse(head);
     display(head);
}