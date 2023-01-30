#include<bits/stdc++.h>

/*
 This is the header file containing the basic operations for queue data structure implemented using linked lists.
*/

using namespace std;

struct node_tree
{
    int data;
    node_tree *lchild;
    node_tree *rchild;

    node_tree(int data)
    {
        this->data=data;
        this->lchild=nullptr;
        this->rchild=nullptr;
    }
};

struct node_ll
{
    node_tree *NODE_TREE;
    node_ll *next;

    node_ll()
    {
        NODE_TREE=nullptr;
        next=nullptr;
    }
};

struct QUEUE
{
    node_ll *Front;
    node_ll *Rear;

    QUEUE()
    {
        Front=nullptr;
        Rear=nullptr;
    }

    bool isEmpty()
    {
        if(Front==nullptr && Rear==nullptr)
        return true;

        return false;
    }

    bool isFull()
    {
        node_ll* temp=new node_ll;
        if(!temp)
            return true;

        delete temp;
        return false;
    }

    void Enqueue(node_tree *t)
    {
        if(isFull()==true)
        {
            cout<<"The queue is full.";
            return;
        }

        node_ll* temp=new node_ll;
        temp->NODE_TREE=t;

        if(isEmpty()==true)
        {
            Front=temp;
            Rear=temp;
            return;
        }

        Rear->next=temp;
        Rear=temp;
    }

    node_tree* Dequeue()
    {
        if(isEmpty()==true)
        return -1;

        node_ll *temp=Front;

        node_tree* t=Front->NODE_TREE;

        // Here Front->next can Rear if there is only one element left
        Front=Front->next;

        if(Front==Rear)
        {
            Front=nullptr;
            Rear=nullptr;
        }

        delete temp;

        return t;
    }

    void Display()
    {
        if(isEmpty()==true)
        {
            cout<<"The queue is empty";
            return;
        }

        node_ll* i;

        for(i=Front;i<=Rear;i=i->next)
            cout<<i->NODE_TREE<<"\t";

        /*
         Or should this be *(i->NODE_TREE) ?
         Should we print the addresses or the numbers stored in them when displaying the whole queue?
        */
    }

    void FrontElement()
    {
        if(isEmpty()==true)
        {
            cout<<"The queue is empty";
            return;
        }

        cout<<Front->NODE_TREE;

        // Or *(Front->NODE_TREE) ?
    }

    void RearElement()
    {
        if(isEmpty()==true)
        {
            cout<<"The queue is empty";
            return;
        }

        cout<<Rear->NODE_TREE;

        // Or *(Rear->NODE_TREE) ?
    }
};
