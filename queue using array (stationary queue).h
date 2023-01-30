/* queue using array (stationary queue).h */

#include<bits/stdc++.h>

using namespace std;

/*
 Here, the queue will move so dequeue takes O(1) time.
 Also there will not be two variables i.e size and capacity. There will only be size.

 Front & Rear are equal in 2 cases:
 Front = Rear = -1 (Queue is empty (Queue is also empty when Front > Rear) )
 Front = Rear = 0 (There is only one element in the queue)

 To make this queue reusable,
 As soon as Front exceeds Rear, make then both -1, thus becoming empty as it was in the first program run.

 Here you can push and pop all the elements only in one go. Not alternatively or in a staggered manner.

*/

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

struct QUEUE
{
    int Size;
    int Front;
    int Rear;
    node_tree **Arr;

    QUEUE(int s)
    {
        Size=s;
        Front=-1;
        Rear=-1;
        Arr=new node_tree*[Size];
    }
};

    bool isFull(QUEUE *q)
    {
        if(q->Rear==q->Size-1)
            return true;

        return false;
    }

    bool isEmpty(QUEUE *q)
    {
        if(q->Front==-1 || q->Front>q->Rear)
            return true;

        return false;
    }



    void Enqueue(QUEUE *q, node_tree *t)
    {
        if(isFull(q)==true)
        {
            cout<<"The queue is full!";
            return;
        }
        q->Arr[++q->Rear]=t;

        // When a new element is added to the empty queue, both Front and Rear are at the same location
        if(q->Rear==0)
            q->Front++;
    }

    node_tree* Dequeue(QUEUE *q)
    {
        if(isEmpty(q)==true)
            return nullptr;

        node_tree* res=q->Arr[(q->Front)++];

        if(isEmpty(q)==true)
        {
            q->Front=-1;
            q->Rear=-1;
        }

        return res;
    }

    void Display(QUEUE *q)
    {
        if(isEmpty(q)==true)
        {
            cout<<"The queue is empty!";
            return;
        }

        int i;

        for(i=q->Front;i<=q->Rear;i++)
            cout<<q->Arr[i]<<"\t";
    }

    void FirstElement(QUEUE *q)
    {
        if(isEmpty(q)==true)
        {
            cout<<"The queue is empty!";
            return;
        }

        cout<<q->Arr[q->Front];
    }

    void LastElement(QUEUE *q)
    {
        if(isEmpty(q)==true)
        {
            cout<<"The queue is empty!";
            return;
        }

        cout<<q->Arr[q->Rear];
    }

/* queue using array (stationary queue).h */
