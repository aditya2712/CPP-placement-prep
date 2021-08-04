#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* next;
};
void push(node** head,int newdata)
{
    node *newnode=new node();
    newnode->data=newdata;
    newnode->next=(*head);

    *head=newnode;
}
void print(node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}
void delnode(node **head,int key)
{
    node *temp=*head,*prev;
    if(temp!=NULL && temp->data==key)
    {
        *head=temp->next;
        free(temp);
        return ;
    }
    while(temp!=NULL && temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
        return;
    prev->next=temp->next;
    free(temp);
    return;
}
int main(){
    node* head=NULL;
    push(&head,4);
    push(&head,6);
    push(&head,8);
    delnode(&head,6);
    print(head);
}
