/*
 Here the elements themselves represent priorities.
 So, the number and type of priorities are determined by the user.
*/

#include<bits/stdc++.h>

using namespace std;

struct data
{
    int e;
    int p;
};

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

    bool isEmpty()
    {
        if(Front==Rear)
            return true;

        return false;
    }

    bool isFull()
    {
        if(Rear==Size-1)
            return true;

        return false;
    }

    void Enqueue(int x)
    {
        if(isFull()==true)
        {
            cout<<"\nThe queue is full.";
            return;
        }

        Arr[++Rear]=x;
    }

    int Dequeue() // original dequeue
    {
        if(isEmpty()==true)
            return -1;

        return Arr[++Front];
    }

    int Priority_Dequeue()
    {
        if(isEmpty()==true)
            return -1;

        int MIN=INT_MAX, i, pos;

        for(i=Front+1;i<=Rear;i++)
        {
            if(Arr[i]<MIN)
            {
                MIN=Arr[i];
                pos=i;
            }
        }

        for(i=pos;i<Rear;i++)
                Arr[i]=Arr[i+1];

        --Rear;

        return MIN;
    }

    void Display()
    {
        if(isEmpty()==true)
        {
            cout<<"\nThe queue is empty.";
            return;
        }

        int i;

        for(i=Front+1;i<=Rear;i++)
            cout<<Arr[i]<<"\t";
    }
};

int main()
{
    int n,i,val;

    cout<<"\nEnter the no. of data: ";
    cin>>n;

    QUEUE q(n);

    cout<<"\n\nEntering the values into the queue:\n";

    for(i=0;i<n;i++)
    {
        cout<<"\nEnter the value: ";
        cin>>val;
        q.Enqueue(val);
    }

    cout<<"\n\nDisplaying the queue:\n";
    q.Display();

    cout<<"\n\nDeleting the values as per priority:\n";

    for(i=0;i<n;i++)
        cout<<q.Priority_Dequeue()<<"\t";

    cout<<"\n\nDisplaying the queue:\n";
    q.Display();

    cout<<"\n\n";
    return 0;
}
