/*
 We can implement stack using linked lists, using all the 'at front' operations i.e. :
 push: insert at front
 pop: delete from front
 peek: display top
 isEmpty: check if top is NULL

 Why only 'at front' operations? Because in stack all the operations are to be implemented in O(1) as per LIFO principle.

 This 'stack' is just a linked list (HERE) where we add and delete elements from the same end so that the operation takes O(1) time
 And group it together with 'ssize' and 'top' variables to hold its maximum capacity and the address of the top most element, resp.

 These are grouped together in a structure, and named as 'stack'.
*/

#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *next;

    node(int x)
    {
        data=x;
        next=NULL;
    }
};

struct STACK
{
    node *top;
    int ssize;

    STACK()
    {
        top=NULL;
        ssize=0;
    }

    bool isEmpty()
    {
        return (top==NULL);
    }

    bool isFull_1()
    // While an array would have a fixed size, a linked list does not.
    // The only limit is when the heap is full. Then we cannot extend the linked list further and so our 'stack' is full.
    {
        node* temp=new node(0);

        if(temp==NULL)
        {
            delete temp;
            return true;
        }
        else
            return false;
    }

    // Another approach
    int isFull_2()
    {
        node *temp=new node(0);

        int r = temp ? 1 : 0;
        delete temp;

        return r;
    }

    void push(int x)
    {
        if(isFull_1()==true)
        {
            cout<<"The stack is full!";
            return;
        }

        node* temp=new node(x);

        ssize++;

        temp->next=top;
        top=temp;
    }

    int pop()
    {
        // empty stack condition
        // we can also call isEmpty()
        if(top==NULL)
            return INT_MAX;

        int res=top->data;

        node* temp=top;
        top=top->next;
        delete temp;
        ssize--;

        return res;
    }

    void display()
    {
        if(isEmpty()==true)
        {
            cout<<"\nThe stack is empty!";
            return;
        }

        node *temp=top;

        while(temp!=NULL)
        {
            cout<<"\n"<<temp->data;
            temp=temp->next;
        }
    }

    int topElement()
    {
        if(top==NULL)
            return INT_MAX;

        return top->data;
    }

    int sizeOfStack()
    {
        return ssize;
    }
};

int main()
{
    STACK s;
    int i;

    cout<<"\nPushing into the stack:";
    for(i=0;i<5;i++)
    {
        cout<<"\nPushing "<<i<<" into the stack.";
        s.push(i);
    }

    cout<<"\n\nPopping elements from the stack:";
    for(i=0;i<5;i++)
    {
        cout<<"\n\n";
        cout<<s.topElement();
        cout<<"\n"<<s.pop();
    }

    cout<<"\n\n"<<s.isEmpty();

    return 0;
}
