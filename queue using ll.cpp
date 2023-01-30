#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *next;

    node()
    {
        next=nullptr;
    }
};

struct QUEUE
{
    int Size;
    node *Front;
    node *Rear;

    QUEUE(int s)
    {
        Size=s;
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
        node* temp=new node;
        if(!temp)
            return true;

        delete temp;
        return false;
    }

    void Enqueue(int x)
    {
        if(isFull()==true)
        {
            cout<<"The queue is full.";
            return;
        }

        node* temp=new node;
        temp->data=x;

        if(isEmpty()==true)
        {
            Front=temp;
            Rear=temp;
            return;
        }

        Rear->next=temp;
        Rear=temp;
    }

    int Dequeue()
    {
        if(isEmpty()==true)
        return -1;

        node *temp=Front;

        int t=Front->data;

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

        node* i;

        for(i=Front;i<=Rear;i=i->next)
            cout<<i->data<<"\t";
    }

    void FrontElement()
    {
        if(isEmpty()==true)
        {
            cout<<"The queue is empty";
            return;
        }

        cout<<Front->data;
    }

    void RearElement()
    {
        if(isEmpty()==true)
        {
            cout<<"The queue is empty";
            return;
        }

        cout<<Rear->data;
    }
};

int main()
{
    int n,i;

    cout<<"Enter the size of the queue: ";
    cin>>n;

    QUEUE q(n);

    cout<<"\n\nDisplaying elements in the queue:\n";
    q.Display();

    cout<<"\n\nPushing elements into the queue:\n";
    for(i=1;i<=n;i++)
    {
        cout<<"\nPushing "<<i<<" into the queue";
        q.Enqueue(i);
    }

    cout<<"\n\nDisplaying elements in the queue:\n";
    q.Display();

    for(i=1;i<=n;i++)
    {
        cout<<"\n\nPopping "<<q.Dequeue()<<" from the queue:\n";
    }

    cout<<"\n\nDisplaying elements in the queue:\n";
    q.Display();

    cout<<"\n";
    return 0;
}
