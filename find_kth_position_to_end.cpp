#include<iostream>
using namespace std;
#include<algorithm>
#include<string>

class node
{
public :
int data;
node *next;
node (int x)
{
    data=x;
    next=NULL;
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
int length(node *head)
{
    node *temp=head;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}
node *kthnode(node *head,int k)
{
    node *temp=head,*ptr=head;
if(k>length(head))
{
    return NULL;
}
for(int i=0;i<k-1;i++)
{
temp=temp->next;
}
while(temp->next!=NULL)
{
    temp=temp->next;
    ptr=ptr->next;
}
return ptr;
}
int main()
{
node *head=NULL;
creation(head,10);
creation(head,20);
creation(head,30);
creation(head,40);
node *result=kthnode(head,3);
cout<<"data is : "<<result->data;
return 0;
}