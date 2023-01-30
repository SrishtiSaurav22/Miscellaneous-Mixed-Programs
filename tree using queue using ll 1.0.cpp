/*
 The while loop runs once and then stops in the second run at the Dequeue function call.
 Need to use double pointer but I am not able to make the required modifications.

 In this code, we return the queue every time it is modified but the code stops at Enqueue function call.
*/

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
    node_tree *address;
    node_ll *next;

    node_ll()
        {
        address=nullptr;
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
};

    bool isEmpty(QUEUE *q)
    {
        if(q->Front==nullptr && q->Rear==nullptr)
        return true;

        return false;
    }

    bool isFull(QUEUE *q)
    {
        node_ll* temp=new node_ll;
        if(!temp)
            return true;

        delete temp;
        return false;
    }

    QUEUE* Enqueue(QUEUE *q, node_tree *t)
    {
        if(isFull(q)==true)
        {
            cout<<"The queue is full.";
            return nullptr;
        }

        node_ll* temp=new node_ll;
        temp->address=t;

        if(isEmpty(q)==true)
        {
            q->Front=temp;
            q->Rear=temp;
            return nullptr;
        }

        q->Rear->next=temp;
        q->Rear=temp;

        return q;
    }

    QUEUE* Dequeue(QUEUE *q)
    {
        if(isEmpty(q)==true)
        return nullptr;

        node_ll *temp=q->Front;

        // Here Front->next can point to Rear if there is only one element left
        q->Front=q->Front->next;

        if(q->Front==q->Rear)
        {
            q->Front=nullptr;
            q->Rear=nullptr;
        }

        delete temp;

        return q;
    }

    node_tree* FrontElement(QUEUE *q)
    {
        if(isEmpty(q)==true)
        return nullptr;

        return q->Front->address;
    }

void traversal_preorder(node_tree* root)
{
    // Sequence: Root, Left child, Right child
    if(root) // or 'if(root!=nullptr)'
    {
        cout<<root->data<<"\t";
        traversal_preorder(root->lchild);
        traversal_preorder(root->rchild);
    }

    /*
     Here we are not writing any else condition as that will be implemented every time we reach a leaf node
    */
}

void traversal_inorder(node_tree* root)
{
    // Sequence: Left child, Root, Right child
    if(root) // or 'if(root!=nullptr)'
    {
        traversal_inorder(root->lchild);
        cout<<root->data<<"\t";
        traversal_inorder(root->rchild);
    }

    /*
     Here we are not writing any else condition as that will be implemented every time we reach a leaf node
    */
}

void traversal_postorder(node_tree* root)
{
    // Sequence: Left child, Right child, Root
    if(root) // or 'if(root!=nullptr)'
    {
        traversal_postorder(root->lchild);
        traversal_postorder(root->rchild);
        cout<<root->data<<"\t";
    }

    /*
     Here we are not writing any else condition as that will be implemented every time we reach a leaf node
    */
}

void create()
{
    node_tree *ptr, *root;
    int val;
    QUEUE *q=nullptr;

    cout<<"\n\nEnter the root value: ";
    cin>>val;

    root=new node_tree(val);

    /*
     The code is running till here after changing the return type of Enqueue and Dequeue
     from void and node_tree respectively to QUEUE* type.
    */

    q=Enqueue(q,root);

    while(isEmpty(q)==false)
    {
        cout<<"\n\nChecking if this loop begins...\n";

        ptr=FrontElement(q);
        q=Dequeue(q);

        cout<<"\n\nWe have the address of the new root node!\n\n";

        // For creating the left child:

        cout<<"\nEnter the left child value of "<<ptr->data<<" (Enter -1 for not creating a left child): ";
        cin>>val;

        if(val!=-1)
        {
            node_tree *temp=new node_tree(val);
            ptr->lchild=temp;
            q=Enqueue(q,temp);
        }

        // For creating the right child:

        cout<<"\nEnter the right child value of "<<ptr->data<<" (Enter -1 for not creating a left child): ";
        cin>>val;

        if(val!=-1)
        {
            node_tree *temp=new node_tree(val);
            ptr->rchild=temp;
            q=Enqueue(q,temp);
        }

        cout<<"\n\tChecking if this segment is working!\n";
    }

    cout<<"\n\nTraversing the tree:";

    cout<<"\n\n";
    traversal_preorder(root);

    cout<<"\n\n";
    traversal_inorder(root);

    cout<<"\n\n";
    traversal_postorder(root);
}

int main()
{
    cout<<"\nCreating a binary tree!";

    create();

    cout<<"\n";
    return 0;
}
