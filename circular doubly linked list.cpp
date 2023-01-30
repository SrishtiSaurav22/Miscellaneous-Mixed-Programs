// The functions in this code do not seem to be working. The code is causing segmentation fault.

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

    if(head==NULL)
    {
        temp->prev=temp;
        temp->next=temp;
    }

    else if(head->next==head)
    {
        temp->prev=head;
        temp->next=head;

        head->prev=temp;
        head->next=temp;
    }

    else
    {   temp->prev=head->prev;
        temp->next=head;

        head->prev->next=temp;
        head->prev=temp;
    }

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
    {
        temp->prev=temp;
        temp->next=temp;
    }

    else if(head->next==head)
    {
        temp->prev=head;
        temp->next=head;

        head->prev=temp;
        head->next=temp;
    }

    else
    {   temp->prev=head->prev;
        temp->next=head;

        node* last=head->prev;

        head->prev->next=temp;
        head->prev=temp;
    }

    return head;
}

void traversal_forward_iteration(node* head)
{
    if(head==NULL)
    {
        cout<<"The list is empty!";
        return;
    }

    while(head->next!=head)
    {
        cout<<"\n"<<head->di<<"\t"<<head->ds;
        head=head->next;
    }
    cout<<"\n"<<head->di<<"\t"<<head->ds;
}

void traversal_backward_iteration(node* head)
{
    if(head==NULL)
    {
        cout<<"The list is empty!";
        return;
    }

    node* temp=head->prev;

    while(temp!=head)
    {
        cout<<"\n"<<temp->di<<"\t"<<temp->ds;
        temp=temp->prev;
    }
    cout<<"\n"<<temp->di<<"\t"<<temp->ds;
}

void traversal_forward_recursion(node* temp, const node* head)
{
    if(head==NULL)
    {
        cout<<"The list is empty!";
        return;
    }

    if(temp->next==head)
    {
        cout<<"\n"<<temp->di<<"\t"<<temp->ds;
        return;
    }

    cout<<"\n"<<temp->di<<"\t"<<temp->ds;
    traversal_forward_recursion(temp->next, head);
}

node* delete_beg(node* head)
{
    if(head==NULL)
    {
        cout<<"The list is empty!";
        return NULL;
    }

    else if(head->next==NULL)
    {
        delete head;
        return NULL;
    }

    else
    {
        head->prev->next=head->next;
        head->next->prev=head->prev;
        delete head;

        return head->next;
    }
}

node* delete_end(node* head)
{
    if(head==NULL)
    {
        cout<<"The list is empty!";
        return NULL;
    }

    else if(head->next==NULL)
    {
        delete head;
        return NULL;
    }

    else
    {
        head->prev->prev->next=head;
        head->prev=head->prev->prev;
        delete head->prev;

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
    cout<<"\nTraversing the list in the backward direction:\n";
    cout<<"\n";
    traversal_backward_iteration(head);

    cout<<"\n";
    cout<<"\nDeleting a node from the beginning:\n";
    cout<<"\n";
    head=delete_beg(head);

    cout<<"\n";
    cout<<"\nDeleting a node from the end:\n";
    cout<<"\n";
    head=delete_end(head);

    cout<<"\n";
    cout<<"\nTraversing the list in the forward direction:\n";
    cout<<"\n";
    traversal_forward_iteration(head);

    cout<<"\n";
    cout<<"\nTraversing the list in the backward direction:\n";
    cout<<"\n";
    traversal_backward_iteration(head);

    return 0;
}
