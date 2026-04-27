/*
 Here, the queue does not shift i.e. during deletion from the front, all elements will be moved a step back.
 Also there will be two variables: size and capacity, rather than just one.
*/

#include<bits/stdc++.h>

using namespace std;

struct QUEUE
{
    int *Arr;
    int Front;
    int Rear;
    int Cap;
    int Size;

    QUEUE(int c)
    {
        Cap=c;
        Size=0;
        Front=-1;
        Rear=-1;
        Arr=new int[Cap];
    }

    bool isFull()
    {
        if(Size==Cap)
            return true;

        return false;
    }

    bool isEmpty()
    {
        if(Front==-1 && Rear==-1)
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

        // Front will remain as zero until the queue is empty
        if(Front==-1)
        ++Front;
    }

    int Dequeue()
    {
        if(isEmpty()==true)
            return -1;

        int res=Arr[Front], i;

        for(i=0;i<Size;i++)
            Arr[i]=Arr[i+1];

        Rear--;

        // If Rear reaches -1 then so does Front and the queue is empty as Front = Rear = -1 now.
        if(Rear==-1)
            Front=-1;

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

    int FirstElement()
    {
        if(isEmpty()==true)
            return -1;

        return Arr[Front];
    }

    int LastElement()
    {
        if(isEmpty()==true)
            return -1;

        return Arr[Rear];
    }

    int SizeOfQueue()
    {
        return Size;
    }
};

int main()
{
    int m,n,i;

    cout<<"Enter the capacity of the queue: ";
    cin>>m;

    cout<<"Enter the size of the queue: ";
    cin>>n;

    QUEUE q(m);

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
        cout<<"\nPopping "<<q.Dequeue()<<" from the stack.";

    cout<<"\n\nDisplaying the queue:\n";
    q.Display();


    cout<<"\n";
    return 0;
}
