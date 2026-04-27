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

void traversal_levelorder(node_tree* root)
{

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

        cout<<"\n\nEnter the left child value of "<<ptr->data<<" (Enter -1 for not creating a left child): ";
        cin>>val;

        if(val!=-1)
        {
            node_tree *temp=new node_tree(val);
            ptr->lchild=temp;
            Enqueue(&q,temp);
        }

        // For creating the right child:

        cout<<"\n\nEnter the right child value of "<<ptr->data<<" (Enter -1 for not creating a left child): ";
        cin>>val;

        if(val!=-1)
        {
            node_tree *temp=new node_tree(val);
            ptr->rchild=temp;
            Enqueue(&q,temp);
        }
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
