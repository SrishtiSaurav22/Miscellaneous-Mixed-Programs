#include<bits/stdc++.h>

using namespace std;

struct node
{
    int di;
    string ds;
    node *next;

    node(int di, string ds)
    {
        this->di=di;
        this->ds=ds;
        this->next=NULL;
    }
};

void traverse_ll_iterative(node* head)
{
    if(head==NULL)
    {
        cout<<"\nThe list is empty!";
        return;
    }

    else if(head->next==head)
    {
        cout<<"\n"<<head->di<<"\t"<<head->ds;
        return;
    }

    else
    {
        node* temp=head;
        while(temp->next!=head)
        {
            cout<<"\n"<<temp->di<<"\t"<<temp->ds;
            temp=temp->next;
        }
        cout<<"\n"<<temp->di<<"\t"<<temp->ds<<"\n";
        //since the last node does not meet the condition and is not printed
    }
}

void traverse_ll_for(node* head)
{
    if(head==NULL)
    {
        cout<<"\nThe list is empty!";
        return;
    }

    else
    {
        cout<<"\n"<<head->di<<"\t"<<head->ds;

        node *temp;

        for(temp=head->next; temp!=head; temp=temp->next)
            cout<<"\n"<<temp->di<<"\t"<<temp->ds;
    }
}

void traverse_ll_do_while(node* head)
{
    if(head==NULL)
    {
        cout<<"\nThe list is empty!";
        return;
    }

    else
    {
        node* temp=head;

        do
        {
            cout<<"\n"<<temp->di<<"\t"<<temp->ds;
            temp=temp->next;
        }
        while(temp!=head);
    }
}

void traverse_ll_recursive(node *temp, const node *head)
// instead of holding the address of head, we can also use a static variable to avoid running the recursion infinitely
{
    // static flag=0;
    if(temp->next==head) // if(temp!=head || flag==0)
    {
       // ++flag;
       cout<<"\n"<<temp->di<<"\t"<<temp->ds;
       return;
    }

    cout<<"\n"<<temp->di<<"\t"<<temp->ds;
    traverse_ll_recursive(temp->next, head);
}

/*
 The procedures for inserting a node at the end and at the beginning are the same.
 We only need to return the node which is to be the new head, without actually changing the head
*/

/*
 The efficient methods of insertion and deletion involve swapping of data of one with another.
 These take O(1) time while the naive solutions take O(n) time.

 But keep in mind that the efficient solutions have some drawbacks too.
 Analyze the individual functions for different cases and you will find the drawbacks.

 The efficient methods are also asked as trick questions in interviews.
*/

node* insert_beg_naive(node* head)
// here we change the linking
{
    int DI;
    string DS;

    cout<<"\nEnter the integer data: ";
    cin>>DI;
    cout<<"Enter the string data: ";
    cin>>DS;

    node* temp=new node(DI,DS);

    if(head==NULL)
        temp->next=temp;

    else if(head->next==head)
    {
        head->next=temp;
        temp->next=head;
    }

    else
    {
        node* ptr=head->next;

        while(ptr->next!=head)
            ptr=ptr->next;

        temp->next=head;
        ptr->next=temp;
    }

    return temp;
}

node* insert_beg_efficient(node* head)
// here we add the new node after head and swap the data of head and the new node
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
        temp->next=temp;
        return temp;
    }

    else
    {
        temp->next=head->next;
        head->next=temp;

        //swap data of head and temp
        int DI_=head->di;
        string DS_=head->ds;

        head->di=temp->di;
        head->ds=temp->ds;

        temp->di=DI_;
        temp->ds=DS_;;

        return head;
    }
}

node* insert_end_naive(node* head)
//another solution besides this is to maintain a tail pointer besides head as the part of the 'node' structure
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
        temp->next=temp;
        return temp;
    }

    else if(head->next==head)
    {
        head->next=temp;
        temp->next=head;
    }

    else
    {
        node* ptr=head;

        while(ptr->next!=head)
            ptr=ptr->next;

        ptr->next=temp;
        temp->next=head;
    }

    return head;
}

node* insert_end_efficient(node* head)
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
        temp->next=temp;
        return temp;
    }

    else if(head->next==head)
    {
        head->next=temp;
        temp->next=head;

        return head;
    }

    else
    {
        //insert temp right after head, as the second node
        temp->next=head->next;
        head->next=temp;

        //swap the data of head and temp
        int DI_=head->di;
        string DS_=head->ds;

        head->di=temp->di;
        head->ds=temp->ds;

        temp->di=DI_;
        temp->ds=DS_;

        return temp;
        //now temp is 'the head' and the previous head node is now the last node holding temp's data.
        //no traversal required in this.
    }
}

node* delete_beg_naive(node* head)
{
    if(head==NULL)
    {
        cout<<"\nThe list is empty!";
        return NULL;
    }

    else if(head->next==head)
    {
        delete head;
        return NULL;
    }

    else
    {
        node *temp=head;

        while(temp->next!=head)
            temp=temp->next;

        temp->next=head->next;
        delete head;

        return temp->next;
    }
}

node* delete_beg_efficient(node* head)
{
    if(head==NULL)
    {
        cout<<"\nThe list is empty!";
        return NULL;
    }

    else if(head->next==head)
    {
        delete head;
        return NULL;
    }

    else
    {
        //head now holds the data of its next node
        head->di=head->next->di;
        head->ds=head->next->ds;

        //temp holds the data of the second node
        node* temp=head->next;

        //head now points to the third node, while holding the data of the second
        head->next=head->next->next;

        //deleting the second node
        delete temp;

        //the head is as it is only its data has been changed
        return head;
    }
}

node* delete_k_th_node(node* head, int k)
{
    if(head==NULL)
    {
        cout<<"\nThe list is empty!";
        return NULL;
    }

    if(head->next=head)
    {
        cout<<"\nThere is only node which is being deleted:\n";
        cout<<head->di<<"\t"<<head->ds;
        delete head;
        return NULL;
    }

    else
    {
        node* temp=head;
        int i=1;

        while(i<k-1)
        {
            temp=temp->next;
            i++;
        }
        node* ptr=temp->next;
        temp->next=temp->next->next;
        delete ptr;

        return head;
    }
}

bool circular_ll_check(node *head)
{
    if(head==NULL)
    return true;

    else
    {
        node *temp=head;

        do
        {
            if(temp->next==head)
            return true;

            temp=temp->next;
        }
        while(temp!=NULL || temp!=head);

    return false;
    }
}

int main()
{
    node* head;
    int n,i,k;

    cout<<"\nEnter the number of nodes: ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"\n";
        head=insert_end_naive(head);
    }

    cout<<"\n";
    cout<<"Checking if a list is circular or not:\n";

    if(circular_ll_check(head)==true)
        cout<<"Yes, the list is circular!";
    else
        cout<<"No, the list is not circular!";

    /*
    cout<<"\nTraversing the linked list:\n";
    traverse_ll_recursive(head, head);

    cout<<"\nEnter the position of the node to be deleted: ";
    cin>>k;
    cout<<"\nDeleting the "<<k<<"th node of the list:\n";
    head=delete_k_th_node(head,k);

    cout<<"\nTraversing the linked list:\n";
    traverse_ll_iterative(head);

    cout<<"\n";
    cout<<"\nDeleting all the elements of the list:\n";
    for(i=0;i<n;i++)
    {
        cout<<"\n";
        head=delete_beg_naive(head);
        cout<<"\n";
        traverse_ll_iterative(head);
    }
    */

    return 0;
}
