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
    node *temp;
    node *newnode = new node(data);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    temp = head;
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
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void meregepoint(node *head2, node *head3)
{
    node *head1=NULL;
    creation(head1,5);
    creation(head1,1);
    creation(head1,3);
    node *temp=head2;
    node *ptr=head3;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    temp->next=head1;
    ptr->next=head1;
    
}
void pointchecker(node *head1, node *head2)
{
    node *temp = head1;
    node *ptr;
    while (temp != NULL)
    {
        ptr = head2;
        while (ptr != NULL)
        {
            if (ptr == temp)
            {
                cout<<"merge point :"<<temp->data;
                return;
            }
            ptr = ptr->next;
        }
        temp=temp->next;
    }
    cout<<"not merge point"<<endl;
}
int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    creation(head1, 10);
    creation(head2, 20);
    creation(head1, 30);
    creation(head2, 40);
    creation(head1, 50);
    creation(head2, 60);
    creation(head1, 70);
    creation(head2, 80);
    //display(head1);
    meregepoint(head1,head2);
     pointchecker(head1,head2);
    return 0;
}