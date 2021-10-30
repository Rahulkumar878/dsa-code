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
        head->next = newnode;
        return;
    }
    node *temp = head;
    while (temp->next != head)
        temp = temp->next;
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
    cout << "NULL";
}
void split_list(node *&head, node *&head2)
{
    node *temp = head;
    if (head == NULL && head->next == head)
    {
        return;
    }
    int count = 1;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    node *ptr=temp;
    temp=head;
    for(int i=0;i<count/2-1;i++)
    {
        temp=temp->next;
    }
    head2=temp->next;
    ptr->next=head2;
    temp->next=head;

}
int main()
{
    node *head = NULL;
    node *head2 = NULL;
    creation(head, 10);
    creation(head, 20);
    creation(head, 30);
    creation(head, 40);
    split_list(head, head2);
   display(head2);
}