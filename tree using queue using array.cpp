/*
 This code is not printing the last line of traversal_levelorder(), then create(), and then main().
*/

#include <bits/stdc++.h>
#include "queue using array (stationary queue).h"

using namespace std;

/*
 This definition is already there in the Queue header file

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
*/

void traversal_preorder(node_tree* root)
{
    // Sequence: Root, Left child, Right child
    if(root) // or 'if(root!=nullptr)'
    {
        cout<<root->data<<"\t";
        traversal_preorder(root->lchild);
        traversal_preorder(root->rchild);
    }
}

void preorder_iterative(node_tree* root)
{
    stack s, queue q;

    node_tree* i;

    for(i=root;i!=nullptr;i=i->lchild)
        s.push(i);

    for(i=root;i!=nullptr;i=i->rchild)
        q.push(i);


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
}

void inorder_iterative(node_tree* root)
{

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
}

void postorder_iterative(node_tree* root)
{

}

void traversal_levelorder(node_tree* root)
{
    node_tree* ptr;
    QUEUE q(10);

    cout<<root->data<<"\t";
    Enqueue(&q,root);

    while(isEmpty(&q)==false)
    {
        ptr=Dequeue(&q);

        if(ptr->lchild!=nullptr)
        {
            Enqueue(&q,ptr->lchild);
            cout<<ptr->lchild->data<<"\t";
        }

        if(ptr->rchild!=nullptr)
        {
            Enqueue(&q,ptr->rchild);
            cout<<ptr->rchild->data<<"\t";
        }
    }

    cout<<"\n\nLast line of traversal_levelorder()";
}

void create()
{
    node_tree *ptr, *root;
    int val;
    QUEUE q(10);

    cout<<"\n\nEnter the root value: ";
    cin>>val;

    root=new node_tree(val);

    Enqueue(&q,root);

    while(isEmpty(&q)==false)
    {
        ptr=Dequeue(&q);

        // For creating the left child:

        cout<<"\nEnter the left child value of "<<ptr->data<<" (Enter -1 for not creating a left child): ";
        cin>>val;

        if(val!=-1)
        {
            node_tree *temp=new node_tree(val);
            ptr->lchild=temp;
            Enqueue(&q,temp);
        }

        // For creating the right child:

        cout<<"Enter the right child value of "<<ptr->data<<" (Enter -1 for not creating a left child): ";
        cin>>val;

        if(val!=-1)
        {
            node_tree *temp=new node_tree(val);
            ptr->rchild=temp;
            Enqueue(&q,temp);
        }
    }

    cout<<"\n\nTraversing the tree:";

    cout<<"\n\nPre Order Traversal:\t";
    preorder_iterative(root);

    cout<<"\n\nIn Order Traversal:\t";
    traversal_inorder(root);

    cout<<"\n\nPost Order Traversal:\t";
    traversal_postorder(root);

    cout<<"\n\nLevel Order Traversal:\t";
    traversal_levelorder(root);

    cout<<"\n\nLast line of create()";
}

int main()
{
    cout<<"\nCreating a binary tree!";

    create();

    cout<<"\n\nLast line of main()";
    return 0;
}
