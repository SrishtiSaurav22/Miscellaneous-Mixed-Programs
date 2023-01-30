/*
 traversal_levelorder() is printing
 1 2 3
 when it should print
 1 2 3 4 5 6 7

 postorder_iterative is also printing partially and that too incorrectly.
*/

/*
 You do not have to show the user how one is implementing the tree.
 So you can directly use an array or linked list to implement the various operations on trees.
*/

#include<bits/stdc++.h>

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

    node_ll(node_tree *address)
    {
        this->address=address;
        this->next=nullptr;
    }
};

node_ll *enqueue(node_ll *head, node_tree *addr)
{
    node_ll *temp=new node_ll(addr);

    if(head==nullptr)
        head=temp;

    else
    {
        node_ll *ptr=head;

        while(ptr->next!=nullptr)
            ptr=ptr->next;

        ptr->next=temp;
    }

    return head;
}

node_ll *dequeue(node_ll *head)
{
    /* While it is good practice, in exams you can skip deletion of
       the memory which head was initially pointing to.
    */

    node_ll* ptr=head;

    head=head->next;

    delete ptr;

    return head;
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
     Here we are not writing any else condition as
     that will be implemented every time we reach a leaf node
    */
}

void preorder_iterative(node_tree* root)
{
    // Sequence: Root, Left child, Right child

    node_ll *head=nullptr;

    node_tree *ptr=root;

    while(ptr!=nullptr || head!=nullptr)
    // both the conditions have to be false for the loop to stop
    {
        if(ptr!=nullptr)
        {
            cout<<ptr->data<<"\t";

            // push into the stack
            node_ll* temp=new node_ll(ptr);

            temp->next=head;
            head=temp;

            ptr=ptr->lchild;
        }

        else
        {
            node_ll* temp=head;
            head=head->next;

            ptr=temp->address;

            delete temp;

            ptr=ptr->rchild;
        }
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

    /*
     Here we are not writing any else condition as
     that will be implemented every time we reach a leaf node
    */
}

void inorder_iterative(node_tree* root)
{
    // Sequence: Left child, Root, Right child

    node_tree* ptr=root;
    node_ll* head=nullptr;

    while(ptr!=nullptr || head!=nullptr)
    {
        if(ptr!=nullptr)
        {
            // pushing ptr into the stack

            node_ll* temp=new node_ll(ptr);
            temp->next=head;
            head=temp;

            ptr=ptr->lchild;
        }

        else
        {
            /*
             This is to stop the loop
             when it reaches the last node of the tree (on the right side)
            */

            if(head==nullptr)
                ptr=nullptr;

            else
            {
                // pop the top element from the stack

                node_ll* temp=head;
                head=head->next;

                ptr=temp->address;

                delete temp;

                cout<<ptr->data<<"\t";

                ptr=ptr->rchild;
            }
        }
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

    /*
     Here we are not writing any else condition as
     that will be implemented every time we reach a leaf node
    */
}

void postorder_iterative(node_tree* root)
{
    // Sequence: Left child, Right child, Root

    node_ll *head=nullptr;

    node_tree *ptr=root, *temp_addr=nullptr;

    int condition=0;

    while(ptr!=nullptr || head!=nullptr)
    // both the conditions have to be false for the loop to stop
    {
        if(ptr!=nullptr)
        {
            // push ptr into the stack

            node_ll* temp=new node_ll(ptr);
            temp->next=head;
            head=temp;

            if(condition!=0)
            {
                ptr=ptr->rchild;
                condition=0;
            }

            else
                ptr=ptr->lchild;
        }

        else
        {
            node_ll* temp=head;
            head=head->next;

            temp_addr=temp->address;

            delete temp;

            /*
             If the variable 'condition' is:

             Zero: Move ptr to its right child
             Not zero: Print the data in ptr and then move to its parent
            */

            if(condition==0)
            {
                 // We will go to the rchild of the current node

                 node_ll* temp=new node_ll(temp_addr);

                 temp->next=head;
                 head=temp;

                 ptr=temp_addr->rchild;

                 condition++;
            }

            else
            {
                cout<<temp_addr->data<<"\t";

                /*
                 ptr needs to point to the parent node of the current node in the next loop iteration
                 So, it is made nullptr to fit in the else condition in the while loop
                */

                ptr=nullptr;
            }
        }
    }
}

void traversal_levelorder(node_tree* root)
{
    node_tree *ptr=nullptr;
    node_ll *head=nullptr;

    head=enqueue(head,root);
    cout<<root->data<<"\t";

    while(head!=nullptr || ptr!=nullptr)
    {
        if(head==nullptr)
            ptr=nullptr;

        ptr=head->address;
        head=dequeue(head);

        if(ptr->lchild!=nullptr)
        {
            enqueue(head,ptr->lchild);
            cout<<ptr->lchild->data<<"\t";
        }

        if(ptr->rchild!=nullptr)
        {
            enqueue(head,ptr->rchild);
            cout<<ptr->rchild->data<<"\t";
        }
    }
}

void generate_tree(node_ll* pre_head, node_ll* in_head);



int main()
{
    node_ll *head=nullptr;

    // data_by_user holds the value to be put into a node of the tree
    int data_by_user;

    cout<<"\nEnter the data for the root node of the tree: ";
    cin>>data_by_user;

    node_tree *root=new node_tree(data_by_user);

    head=enqueue(head,root);

    while(head!=nullptr)
    {
        // Here current_node is the one at the beginning of the queue (which really is just a linked list here).

        node_tree *current_node=head->address;

        head=dequeue(head);

        cout<<"\nEnter the data for the left child of "<<current_node->data<<": ";
        cin>>data_by_user;

        // temp_node holds the node (of type node_tree) to be linked to the current_node as its left and then right child.
        node_tree *temp_node=nullptr;

        if(data_by_user>=0) // This is just a condition for knowing when a node is not to be created
        {
            temp_node=new node_tree(data_by_user);

            current_node->lchild=temp_node;
            head=enqueue(head,temp_node);

            /* We can write

               q=enqueue(q,current_node->lchild);

               as well but writing 'temp_node' in place of 'current_node->lchild'
               makes the code segment reusable.
            */
        }

        cout<<"Enter the data for the right child of "<<current_node->data<<": ";
        cin>>data_by_user;

        if(data_by_user>=0) // This is just a condition for knowing when a node is not to be created
        {
            temp_node=new node_tree(data_by_user);

            current_node->rchild=temp_node;
            head=enqueue(head,temp_node);
        }
    }

    cout<<"\nTraversing tree:\n\nPREORDER:\t";
    traversal_preorder(root);
    cout<<endl;
    preorder_iterative(root);
    cout<<"\nINORDER:\t";
    inorder_iterative(root);
    cout<<"\nPOSTORDER:\t";
    postorder_iterative(root);
    cout<<"\nLEVEL ORDER:\t";
    traversal_levelorder(root);

    cout<<endl;
    return 0;
}
