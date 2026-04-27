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

    int Dequeue()
    {
        if(isEmpty()==true)
            return -1;

        return Arr[++Front];
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
            cout<<"\n"<<Arr[i];
    }
};

int main()
{
    int n,i;

    cout<<"\nEnter the no. of data: ";
    cin>>n;

    data d[n];

    int c0=0, c1=0, c2=0;

    // the different priorities: 0,1,2

    cout<<"\n\nEntering the values into the array of data:\n";

    for(i=0;i<n;i++)
    {
        cout<<"\nElement: ";
        cin>>d[i].e;
        cout<<"Priority: ";
        cin>>d[i].p;

        if(d[i].p==0)
            c0++;

        else if(d[i].p==1)
            c1++;

        else if(d[i].p==2)
            c2++;
    }

    QUEUE q0(c0), q1(c1), q2(c2);

    for(i=0;i<n;i++)
    {
        if(d[i].p==0)
            q0.Enqueue(d[i].e);

        else if(d[i].p==1)
            q1.Enqueue(d[i].e);

        else if(d[i].p==2)
            q2.Enqueue(d[i].e);
    }

    cout<<"\n\nRemoving all the data according to priority:";

    cout<<"\n";
    for(i=0;i<c0;i++)
        cout<<q0.Dequeue()<<"\t";

    cout<<"\n";
    for(i=0;i<c1;i++)
        cout<<q1.Dequeue()<<"\t";

   cout<<"\n";
    for(i=0;i<c2;i++)
        cout<<q2.Dequeue()<<"\t";

    cout<<"\n\n";
    return 0;
}
