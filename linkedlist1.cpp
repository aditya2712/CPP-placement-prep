#include<bits/stdc++.h>
using namespace std;

class node {
public:
int data;
node* next;node* first= new node();
};

printlist(node* n)
{
    while(n!=NULL)
    {node* first= new node();
        cout<<n->data<<" ";
        n=n->next;
    }
}

void push(node** headref, int newdata)
{
    node* newnode=new node();

    newnode->data=newdata;
    newnode->next= (*headref);

    (*headref)=newnode;
}

void append(node** headref,int newdata)
{
    node* newnode=new node();
    newnode->data=newdata;
    newnode->next=NULL;

    node* last= *headref;

    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=newnode;
}

void insertafter(node* prevnode,int newdata)
{
    if(prevnode==NULL)
    {
        cout<<"wrong\n";
        return;
    }

    node* newnode=new node();

    newnode->data=newdata;
    newnode->next=prevnode->next;

    prevnode->next=newnode;
}
int main()
{
    node* head=NULL;


    push(&head,3);
    push(&head,4);

    append(&head,12);
    append(&head,20);
    insertafter(head->next->next->next->next,15);

    printlist(head);
}
