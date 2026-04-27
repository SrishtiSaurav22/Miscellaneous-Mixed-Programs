// middle_element_naive is not working
// void nth_node_from_end_naive(node* head, int n, int length) complete it later....seems useless to me.....
// reverse_recursion_1 i do not understand yet
// reverse_recursion_2 i do not understand yet
// write a function to detect a loop in a linked list
// write a function to get the intersection point of two linked lists
// write a function to concatenate two lists
// write a function to merge two lists


#include<bits/stdc++.h>

using namespace std;

struct node
{
    int di;
    string ds;
    node *next;

    node(int di, string ds)
    {
        //'this' is used as we have the same variable name as the parameters
        this->di=di;
        this->ds.assign(ds);
        this->next=NULL;
    }
};

node* append_end(node *head)
{
    int DI;
    string DS;

    cout<<"\nEnter integer data: ";
    cin>>DI;
    cout<<"Enter string data: ";
    cin>>DS;

    node* ptr=new node(DI,DS);

    if(head==NULL)
    head=ptr;

    else
    {
        node *temp=head;

        while(temp->next!=NULL)
        //we cannot have temp=NULL as the condition as then temp won't be connected to the previous node
        //(NULL is a non-valid memory address)
            temp=temp->next;

        temp->next=ptr;
    }

    return head;
}

node* append_beg(node *head)
{
    int DI;
    string DS;

    cout<<"\nEnter integer data: ";
    cin>>DI;
    cout<<"Enter string data: ";
    cin>>DS;

    node* ptr=new node(DI,DS);

    if(head==NULL)
    head=ptr;

    else
    {
        ptr->next=head;
        head=ptr;
    }

    return head;
}

node* append_in_sorted_list(node* head)
{
    int DI;
    string DS;

    cout<<"\nEnter integer data: ";
    cin>>DI;
    cout<<"Enter string data: ";
    cin>>DS;

    node* ptr=new node(DI,DS);

    if(head==NULL)
    head=ptr;

    else
    {
        if(head->di>DI)
        {
            ptr->next=head;
            head=ptr;
        }

        else
        {
            node *temp=head;

            while(temp->next!=NULL && temp->next->di<DI)
                temp=temp->next;

            ptr->next=temp->next;
            temp->next=ptr;
        }
    }

    return head;
}

/*
In traversal functions we do not need an extra variable temp as pointer variables, like other variables, are copied
into the parameters of a function. So the head from main, passed into these functions, is not the same as the head in them.
So there's no change in head.
*/

void traverse_iteration(node *head)
{
    if(head==NULL)
    {
        cout<<"The list is empty!";
        return;
    }

    while(head!=NULL)
    {
        cout<<"\n"<<head->di<<"\t"<<head->ds;
        head=head->next;
    }
}

void traverse_recursion(node *temp)
{
    if(temp==NULL)
        return;

    cout<<"\n"<<temp->di<<"\t"<<temp->ds;
    traverse_recursion(temp->next);
}

void search_iteration(node *head)
{
    char ch;
    int f=0;

    cout<<"\nWould you like to search the list by integer (press 'i' or \"I\") or string (press 's' pr \"S\")?\nEnter your choice: ";
    cin>>ch;

    if(ch=='i' || ch=='I')
    {
        int DI;

        cout<<"Enter the integer key: ";
        cin>>DI;

        node* temp=head;

        while(temp!=NULL)
        {
            if(temp->di==DI)
            {
                cout<<"\nFound it!\n\n"<<temp->di<<"\t"<<temp->ds;
                f++;
            }
            temp=temp->next;
        }

        if(f==0)
            cout<<"\nSorry data not found....";
    }

    else if(ch=='s' || ch=='S')
    {
        string DS;

        cout<<"Enter the string key: ";
        cin>>DS;

        node* temp=head;

        while(temp!=NULL)
        {
            if(temp->ds.compare(DS)==0)
            {
                cout<<"\nFound it!\n\n"<<temp->di<<"\t"<<temp->ds;
                f++;
            }
            temp=temp->next;
        }

        if(f==0)
            cout<<"\nSorry data not found....";
    }
}

void search_recursion_i(node *head, int DI)
{
    if(head==NULL)
    //either the list is empty or the data was not found
    {
        cout<<"Could not find the data....";
        return;
    }

    if(head->di==DI)
    {
        cout<<"\nFound it!\n\n"<<head->di<<"\t"<<head->ds;
        return;
    }
    search_recursion_i(head->next, DI);
}

void search_recursion_s(node *head, string DS)
{
    if(head==NULL)
    //either the list is empty or the data was not found
    {
        cout<<"Could not find the data....";
        return;
    }

    if(head->ds.compare(DS)==0)
    {
        cout<<"\nFound it!\n\n"<<head->di<<"\t"<<head->ds;
        return;
    }
    search_recursion_s(head->next, DS);
}

void search_recursion(node *head)
{
    char ch;

    cout<<"\nWould you like to search the list by integer (press 'i' or \"I\") or string (press 's' pr \"S\")?\nEnter your choice: ";
    cin>>ch;

    if(ch=='i' || ch=='I')
    {
        int DI;

        cout<<"Enter the integer key: ";
        cin>>DI;

        search_recursion_i(head,DI);
    }

    else if(ch=='s' || ch=='S')
    {
        string DS;

        cout<<"Enter the string key: ";
        cin>>DS;

        search_recursion_s(head,DS);
    }
}

node* delete_beg(node* head)
{
    if(head==NULL)
    {
        cout<<"The list is empty!";
        return head;
    }


    node* ptr=head;
    head=head->next;
    delete ptr;
    return head;

    /*
    node* temp=head->next;
    delete head;
    return temp;
    */
}

node* delete_end(node* head)
{
    if(head==NULL)
    {
        cout<<"The list is empty!";
        return head; //OR return NULL;
    }


    else if(head->next==NULL)
    {
        delete head;
        return NULL;
    }

    else
    {
        node* temp=head;

        while(temp->next->next!=NULL)
            temp=temp->next;

        delete temp->next;

        temp->next=NULL;

        return head;
    }
}

//write delete_specific_node(node* head) as well

void middle_element_naive(node* head)
{
    if(head==NULL)
    {
        cout<<"The list is empty!";
        return;
    }

    node* temp=head;
    int c=0, i;

    while(temp!=NULL)
    {
        ++c;
        temp=temp->next;
    }

    temp=head;
    if(c%2==0)
    {
        for(i=1;i<=c;i++)
            temp=temp->next;

        cout<<"\nMiddle Elements:\n"<<temp->di<<"\t"<<temp->ds;
        temp=temp->next;
        cout<<"\n"<<temp->di<<"\t"<<temp->ds;
    }
    else
    {
        for(i=1;i<=c+1;i++)
            temp=temp->next;

        cout<<"\nMiddle Element:\n"<<temp->di<<"\t"<<temp->ds;
    }
}

void middle_element_pointers(node* head)
//best for odd number of nodes
//for even number of nodes the second one of the two middle nodes is displayed
{
    if(head==NULL)
    {
        cout<<"The list is empty!";
        return;
    }

    node *fast=head, *slow=head;

    while(fast!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    cout<<"\nMiddle element:\n"<<slow->di<<"\t"<<slow->ds;
}

void nth_node_from_end_naive(node* head, int n)
{
    node* temp=head;
    int c=0, i;

    while(temp!=NULL)
    {
        ++c;
        temp=temp->next;
    }

    temp=head;
    for(i=1;i<=(c-n);i++)
        temp=temp->next;

    cout<<"\n"<<n<<"th node from the end:\n"<<temp->di<<"\t"<<temp->ds;
}

//write void nth_node_from_end_naive(node* head, int n, int length) as well

node* reverse_iteration_1(node* head) //GFG
{
    node *prev, *next, *cur;

    prev=NULL;
    cur=head;

    while(cur!=NULL)
    {
        next=cur->next; //cur->next held by next, then cur->next is changed
        cur->next=prev; //orev held by cur->next, then prev is changed
        prev=cur;       //cur held by prev, then cur is changed
        cur=next;
    }
    return prev;
}

node* reverse_iteration_2(node* head) //in Abdul Bari video
{
    node *p, *q, *r;

    p=head;
    q=NULL;
    r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }

    return q;
}

node* reverse_recursion_1(node* head) //GFG
{
    if(head==NULL || head->next==NULL)
        return head;

    node *r_head=reverse_recursion_1(head->next);
    node *r_tail=head->next;
    r_tail->next=head;
    head->next=NULL;

    return r_head;
}

node *reverse_recursion_2(node *cur, node *prev) //GFG
{
    if(cur==NULL)
        return prev;

    node *next=cur->next;
    cur->next=prev;

    return reverse_recursion_2(next,cur);
}

node* remove_duplicates_sorted_ll(node* head)
{
    node *temp=head, *ptr;

    while(temp->next!=NULL)
    {
        // We only move to the next node when all consecutive duplicates have been removed.
        if(temp->di==temp->next->di)
        {
            ptr=temp->next;
            temp->next=temp->next->next;
            delete ptr;
        }

        else
            temp=temp->next;
    }
    return head;
}

bool circular_ll_check(node *head)
{
    if(head==NULL)
    return true;

    else
    {
        node *temp=head;

        //do while so that it does not check for the head itself
        do
        {
            if(temp->next==head)
            return true;

            temp=temp->next;
        }
        while(temp!=NULL);

    return false;
    }
}

int main()
{
    int i,n, ch, pos;

    cout<<"\nEnter the no. of nodes: ";
    cin>>n;

    if(n>0)
    {
        node *head=NULL;

        for(i=0;i<n;i++)
        {
            cout<<"\n\nAppend at?\n1. Beginning\n2. End\nEnter your choice: ";
            cin>>ch;

            switch(ch)
            {
                case 1:
                    head=append_beg(head);
                    break;

                case 2:
                    head=append_end(head);
                    break;
            }
        }

        cout<<"\nBefore reversing;\n";
        traverse_iteration(head);

        cout<<"\nReversing the linked list:\n";
        head=reverse_iteration_1(head);

        /*
        cout<<"\n";
        cout<<"Checking if a list is circular or not:\n";

        if(circular_ll_check(head)==true)
            cout<<"Yes, the list is circular!";
        else
            cout<<"No, the list is not circular!";

        cout<<"\n";
        traverse_iteration(head);
        cout<<"\n";
        traverse_recursion(head);

        cout<<"\n";
        cout<<"\nRemoving duplicate integer elements from the list:\n";
        head=remove_duplicates_sorted_ll(head);

        cout<<"\n";
        traverse_iteration(head);
        cout<<"\n";
        traverse_recursion(head);

        cout<<"\n";
        cout<<"\nReversing the linked list:\n";
        head=reverse_iteration_1(head);

        cout<<"\n";
        traverse_iteration(head);
        cout<<"\n";
        traverse_recursion(head);

        cout<<"\n";
        cout<<"\nEnter the position of the node to be checked from the end: ";
        cin>>pos;
        nth_node_from_end_naive(head,pos);
        */

        cout<<"\n";
        middle_element_pointers(head);

        /*
        cout<<"\n\nTime to append the list while keeping it sorted!\n";
        head=append_in_sorted_list(head);

        cout<<"\n";
        search_iteration(head);
        cout<<"\n";
        search_recursion(head);

        for(i=0;i<n;i++)
        {
            cout<<"\n\nDelete from the?\n1. Beginning\n2. End\nEnter your choice: ";
            cin>>ch;

            switch(ch)
            {
                case 1:
                    head=delete_beg(head);
                    cout<<"\n";
                    traverse_iteration(head);
                    break;

                case 2:
                    head=delete_end(head);
                    cout<<"\n";
                    traverse_iteration(head);
                    break;
            }
        }

        cout<<"\n";
        traverse_iteration(head);
        cout<<"\n";
        traverse_recursion(head);

        */
    }

    return 0;
}
