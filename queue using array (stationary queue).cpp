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

struct QUEUE
{
    int Size;
    int Front;
    int Rear;
    int *Arr;

    QUEUE(int s)
    {
        Size=s;
        Front=-1;
        Rear=-1;
        Arr=new int[Size];
    }

    bool isFull()
    {
        if(Rear==Size-1)
            return true;

        return false;
    }

    bool isEmpty()
    {
        if(Front==-1 || Front>Rear)
            return true;

        return false;
    }

    void Enqueue(int x)
    {
        if(isFull()==true)
        {
            cout<<"The queue is full!";
            return;
        }
        Arr[++Rear]=x;

        // When a new element is added to the empty queue, both Front and Rear are at the same location
        if(Rear==0)
            Front++;
    }

    int Dequeue()
    {
        if(isEmpty()==true)
            return -1;

        int res=Arr[Front++];

        if(isEmpty()==true)
        {
            Front=-1;
            Rear=-1;
        }

        return res;
    }

    void Display()
    {
        if(isEmpty()==true)
        {
            cout<<"The queue is empty!";
            return;
        }

        int i;

        for(i=Front;i<=Rear;i++)
            cout<<Arr[i]<<"\t";
    }

    void FirstElement()
    {
        if(isEmpty()==true)
        {
            cout<<"The queue is empty!";
            return;
        }

        cout<<Arr[Front];
    }

    void LastElement()
    {
        if(isEmpty()==true)
        {
            cout<<"The queue is empty!";
            return;
        }

        cout<<Arr[Rear];
    }
};

int main()
{
    int n,i;

    cout<<"Enter the size of the queue: ";
    cin>>n;

    QUEUE q(n);

    cout<<"\n\nDisplaying the queue:\n";
    q.Display();

    cout<<"\n\nPushing elements into the queue:\n";
    for(i=1;i<=n;i++)
    {
        cout<<"\nPushing "<<i<<" into the queue.";
        q.Enqueue(i);
    }

    cout<<"\n\nDisplaying the queue:\n";
    q.Display();

    cout<<"\n\nPopping elements from the queue:\n";
    for(i=1;i<=n;i++)
    {
        cout<<"\nPopping "<<q.Dequeue()<<" from the queue.";
    }

    cout<<"\n\nDisplaying the queue:\n";
    q.Display();

    cout<<"\n";
    return 0;
}
