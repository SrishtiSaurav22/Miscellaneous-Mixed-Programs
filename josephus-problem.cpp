<<<<<<< HEAD
#include<bits/stdc++.h>

using namespace std;

class node
{
    public:

    int val;
    node* next;

    node(int val)
    {
        this->val=val;
        this->next=nullptr;
    }
};

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
node* victim_circle(int n, int arr[])
{
    node* head=new node(arr[0]);
    node* curr=head;

    for(int i=1;i<n;i++)
    {
        node* temp=new node(arr[i]);
        curr->next=temp;

        curr=curr->next;
    }

    curr->next=head;

    return head;
}

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
void print_list(node* head)
{
    node* temp=head;

    while(temp->next!=head)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    
    cout<<temp->val<<endl;
}

/*
Below is 

Time complexity:  theta(n * k) or theta(n) if k is constant

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
int josephus_problem_naive(node* head, int n, int k)
{
    node* prev=nullptr;
    node* curr=head;

    while(curr->next!=curr) // more than one node
    {
        for(int i=1;i<k;i++)
        {
            prev=curr;
            curr=curr->next;
        }

        // curr is the k-th node to delete
        prev->next=curr->next;

        node* temp=curr;
        curr=curr->next;
        delete temp;
    }

    int survivor=curr->val;
    delete curr;

    return survivor;
}

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
int josephus_problem_optimized_iterative(int n, int k)
{
    int res=0;
    
    for(int i=2;i<=n;i++)
        res=(res+k)%i;

    return res;
}

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int josephus_problem_optimized_recursive(int n, int k)
{
    if(n==1)
        return 0;

    return ( josephus_problem_optimized_recursive(n-1, k) + k ) % n;
}

int main()
{
    int arr[]={0,1,2,3,4,5,6,7};
    int size=8;

    node* temp=victim_circle(size,arr);
    print_list(temp);
    cout<<endl;

    cout<<josephus_problem_naive(temp, size, 3)<<endl;
    cout<<josephus_problem_optimized_iterative(8,3)<<endl;
    cout<<josephus_problem_optimized_recursive(8,3)<<endl;
    
    return 0;
=======
#include<bits/stdc++.h>

using namespace std;

class node
{
    public:

    int val;
    node* next;

    node(int val)
    {
        this->val=val;
        this->next=nullptr;
    }
};

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
node* victim_circle(int n, int arr[])
{
    node* head=new node(arr[0]);
    node* curr=head;

    for(int i=1;i<n;i++)
    {
        node* temp=new node(arr[i]);
        curr->next=temp;

        curr=curr->next;
    }

    curr->next=head;

    return head;
}

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
void print_list(node* head)
{
    node* temp=head;

    while(temp->next!=head)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    
    cout<<temp->val<<endl;
}

/*
Below is 

Time complexity:  theta(n * k) or theta(n) if k is constant

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
int josephus_problem_naive(node* head, int n, int k)
{
    node* prev=nullptr;
    node* curr=head;

    while(curr->next!=curr) // more than one node
    {
        for(int i=1;i<k;i++)
        {
            prev=curr;
            curr=curr->next;
        }

        // curr is the k-th node to delete
        prev->next=curr->next;

        node* temp=curr;
        curr=curr->next;
        delete temp;
    }

    int survivor=curr->val;
    delete curr;

    return survivor;
}

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
int josephus_problem_optimized_iterative(int n, int k)
{
    int res=0;
    
    for(int i=2;i<=n;i++)
        res=(res+k)%i;

    return res;
}

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int josephus_problem_optimized_recursive(int n, int k)
{
    if(n==1)
        return 0;

    return ( josephus_problem_optimized_recursive(n-1, k) + k ) % n;
}

int main()
{
    int arr[]={0,1,2,3,4,5,6,7};
    int size=8;

    node* temp=victim_circle(size,arr);
    print_list(temp);
    cout<<endl;

    cout<<josephus_problem_naive(temp, size, 3)<<endl;
    cout<<josephus_problem_optimized_iterative(8,3)<<endl;
    cout<<josephus_problem_optimized_recursive(8,3)<<endl;
    
    return 0;
>>>>>>> 95a289d2b2620083357fcb405d7b9ac99fd960cb
}