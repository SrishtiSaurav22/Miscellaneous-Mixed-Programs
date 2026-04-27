/*
 this code stops after "biensurrrrrrrrrrrrrrrrrrrrrrrrr.............."
*/

#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *next;

    node()
    {
        next=NULL;
    }
};

struct DE_QUEUE
{
    int Size;
    node* Front;
    node* Rear;

    DE_QUEUE(int s)
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
        cout<<"ouaiiiiiiiiiiiiiiiiiiiiiiiiiiiissssssssssssssss\n\n";

        node* temp=new node;
        if(!temp)
            return true;

        return false;
    }

    void Enqueue(int x)
    {
        cout<<"yyyyyyyyyyyyyyyyyyyy\n\n";

        if(isFull()==true)
        {
            cout<<"The queue is full";
            return;
        }

        cout<<"bababababababa....\n\n";

        node* temp;

        if(temp==nullptr)
            cout<<"Jenkins this is terrible!\n\n";

        cout<<"biensurrrrrrrrrrrrrrrrrrrrrrrrr.....\n\n";

        temp->data=x;

        cout<<"You egg!\n\n";

        if(isEmpty()==true)
        {
            cout<<"The queue is empty so there are no two ends!";
            Front=temp;
            Rear=temp;
            return;
        }

        char ch;

        cout<<"Push to Front (press 'f') or Rear (press 'r')?\nEnter your choice: ";
        choice:
        fflush(stdin);
        cin>>ch;

        switch(ch)
        {
            case 'f':

                temp->next=Front;
                Front=temp;

            break;

            case 'r':

                Rear->next=temp;
                Rear=temp;

            break;

            default:

                cout<<"Invalid input. Enter your choice again: ";
                goto choice;
        }
    }

    void Dequeue()
    {
        if(isEmpty()==true)
        {
            cout<<"The queue is empty";
            return;
        }

        node* temp;

        if(Front==Rear)
        {
            cout<<"There is only one element here, so there are no two ends!";

            temp=Front; // or node* temp=Rear;
            delete temp;

            Front=nullptr;
            Rear=nullptr;

            return;
        }

        char ch;

        cout<<"Pop from Front (press 'f') or Rear (press 'r')?\nEnter your choice: ";
        choice:
        fflush(stdin);
        cin>>ch;

        switch(ch)
        {
            case 'f':

                temp=Front;
                Front=Front->next;
                delete temp;

            break;

            case 'r':

                temp=Rear;
                Rear=nullptr;
                delete temp;

            break;

            default:

                cout<<"Invalid input. Enter your choice again: ";
                goto choice;
        }
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
            cout<<i<<"\t";
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

    DE_QUEUE q(n);

    cout<<"\n\nDisplaying the queue:\n";
    q.Display();

    cout<<"\n\nPushing elements into the queue:\n";
    for(i=1;i<=n;i++)
    {
        cout<<"\nPushing "<<i<<" into the queue";
        q.Enqueue(i);
    }

    cout<<"\n\nDisplaying the queue:\n";
    q.Display();

    cout<<"\n\nPopping elements from the queue:\n";
    for(i=1;i<=n;i++)
    {
        cout<<"\nPopping "<<i<<" from the stack.";
        q.Dequeue();
    }

    cout<<"\n\nDisplaying the queue:\n";
    q.Display();


    cout<<"\n";
    return 0;
}
