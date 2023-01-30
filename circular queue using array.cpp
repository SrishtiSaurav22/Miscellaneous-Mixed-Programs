#include<bits/stdc++.h>

using namespace std;

struct CQUEUE
{
    int Size;
    int Front;
    int Rear;
    int *Arr;

    CQUEUE(int s)
    {
        Size=s; // Size-1 elements will be stored in the circular queue since Front must always be behind Rear
        Front=0;
        Rear=0;
        Arr=new int[Size];
    }

    bool isEmpty()
    {
        // this is different from the condition that you used in the other two files where Front did not need to be behind Rear
        if(Front==Rear)
            return true;

        return false;
    }

    bool isFull()
    {
        // The space held by Front has to be empty so the circular queue holds Size-1 elements
        if( ( (Rear+1)%Size ) == Front )
            return true;

        return false;
    }

    void Enqueue(int x)
    {
        if(isFull()==true)
        {
            cout<<"The circular queue is full.";
            return;
        }

        Rear=(Rear+1)%Size;
        Arr[Rear]=x;

        /*
        By writing this, you are not changing the value of Rear, only the position after it
        Arr[ (Rear+1)%Size ]=x;

        Here's why:
        num++ and ++num are expressions, num+1 is not
        */
    }

    int Dequeue()
    {
        if(isEmpty()==true)
            return -1;

        // Front is moved forward as the position held by Front is empty.
        // The element is held in the position right after it.
        Front=(Front+1)%Size;
        int res=Arr[Front];

        return res;
    }

    void Display()
    {
        if(isEmpty()==true)
        {
            cout<<"The circular queue is empty.";
            return;
        }

        int i;

        /*
        for( i=Front+1 ; i!=(Rear+1)%Size ; i=(i+1)%Size)
            cout<<Arr[i]<<"\t";
        */

        i=Front+1;

        do
        {
            cout<<Arr[i]<<"\t";
            i=(i+1)%Size;
        }
        while(i!=( (Rear+1)%Size) ) ;
    }
};

int main()
{
    int n,i;

    cout<<"\nEnter the size of the queue: ";
    cin>>n;

    CQUEUE q(n);

    cout<<"\n\nDisplaying the queue:\n";
    q.Display();

    cout<<"\n\nPushing elements into the queue:\n";
    for(i=1;i<=n-1;i++)
    {
        cout<<"\nPushing "<<i<<" into the queue";
        q.Enqueue(i);
    }

    cout<<"\n\nDisplaying the queue:\n";
    q.Display();

    cout<<"\n\nPopping elements from the queue:\n";
    for(i=1;i<=n-1;i++)
        cout<<"\nPopping "<<q.Dequeue()<<" from the stack.";

    cout<<"\n\nDisplaying the queue:\n";
    q.Display();


    cout<<"\n";
    return 0;
}
