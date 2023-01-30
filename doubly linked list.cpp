#include<bits/stdc++.h>

using namespace std;

struct node
{
    int di;
    string ds;
    node *prev;
    node *next;

    node(int di, string ds)
    {
        //'this' is used as we have the same variable name as the parameters
        this->di=di;
        this->ds.assign(ds);
        this->prev=NULL;
        this->next=NULL;
    }
};

node* append_beg(node* head)
{
    int DI;
    string DS;

    cout<<"\nEnter the integer data: ";
    cin>>DI;
    cout<<"Enter the string data: ";
    cin>>DS;

    node* temp=new node(DI,DS);

    temp->next=head;

    if(head!=NULL)
        head->prev=temp;

    return temp;
}

node* append_end(node* head)
{
    int DI;
    string DS;

    cout<<"\nEnter the integer data: ";
    cin>>DI;
    cout<<"Enter the string data: ";
    cin>>DS;

    node* temp=new node(DI,DS);

    if(head==NULL)
        return temp;

    else
    {
        node* ptr=head;

        while(ptr->next!=NULL)
            ptr=ptr->next;

        ptr->next=temp;

        temp->prev=ptr;

        return head;
    }
}

void traversal_forward_iteration(node* head)
{
    while(head!=NULL)
    {
        cout<<"\n"<<head->di<<"\t"<<head->ds;
        head=head->next;
    }
}

void traversal_backward_iteration(node* head)
{
    node* temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    while(temp!=NULL)
    {
        cout<<"\n"<<temp->di<<"\t"<<temp->ds;
        temp=temp->prev;
    }
}

void traversal_forward_recursion(node* head)
{
    if(head==NULL)
        return;

    cout<<"\n"<<head->di<<"\t"<<head->ds;
    traversal_forward_recursion(head->next);
}

// is backwards traversal of DLL possible using recursion?

node* reverse_ll(node* head)
{
    if(head==NULL || head->next==NULL)
        return head;

    else
    {
        node *cur=head, *prev=NULL;

        while(cur!=NULL)
        {
            //swapping of the links
            prev=cur->prev;
            cur->prev=cur->next;
            cur->next=prev;

            //moving cur to the next pointer (whose address is now in its prev link after the swapping)
            cur=cur->prev;
        }
        //when cur is NULL, the loop discontinues
        //prev holds the address in the prev link of the last cur (before it became NULL)
        //so prev is pointing to the second last node and its prev link points to the last, our new head
        return prev->prev;
    }
}

node* delete_beg(node* head)
{
    if(head==NULL)
        return NULL;

    else if(head->next==NULL)
    {
        delete head;
        return NULL;
    }

    else
    {
        head->next->prev=NULL;
        delete head;

        return head->next;
    }
}

node* delete_end(node* head)
{
    if(head==NULL)
        return NULL;

    else if(head->next==NULL)
    {
        delete head;
        return NULL;
    }

    else
    {
        node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;

        temp->prev->next=NULL;
        delete temp;

        return head;
    }
}

int main()
{
    node* head;
    int n,i;

    cout<<"\nEnter the no. of nodes: ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"\n";
        head=append_end(head);
    }

    cout<<"\n";
    cout<<"\nTraversing the list in the forward direction:\n";
    cout<<"\n";
    traversal_forward_iteration(head);

    cout<<"\n";
    cout<<"\nDeleting from the beginning:";
    head=delete_beg(head);

    cout<<"\n";
    cout<<"\nTraversing the list in the forward direction:\n";
    cout<<"\n";
    traversal_forward_iteration(head);

    /*
    cout<<"\n";
    cout<<"\nTraversing the list in the backward direction:\n";
    cout<<"\n";
    traversal_backward_iteration(head);

    cout<<"\n";
    cout<<"\nReversing the list:";
    head=reverse_ll(head);

    cout<<"\n";
    cout<<"\nTraversing the list in the forward direction:\n";
    cout<<"\n";
    traversal_forward_iteration(head);

    cout<<"\n";
    cout<<"\nTraversing the list in the backward direction:\n";
    cout<<"\n";
    traversal_backward_iteration(head);
    */

    return 0;
}
