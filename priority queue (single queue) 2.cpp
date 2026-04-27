#include<bits/stdc++.h>

using namespace std;

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

void sort_before_q_insertion(int *arr, int Size)
{
    int i,j,temp;

    for(i=0;i<Size;i++)
        for(j=i+1;j<Size;j++)
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
}

int main()
{
    int n,i,val;

    cout<<"\nEnter the no. of data: ";
    cin>>n;

    QUEUE q(n);
    int temp[n];

    cout<<"\n\nEntering the values into the queue:\n";

    for(i=0;i<n;i++)
    {
        cout<<"\nEnter the value: ";
        cin>>temp[i];
    }

    sort_before_q_insertion(temp,n);

    for(i=0;i<n;i++)
        q.Enqueue(temp[i]);

    cout<<"\n\nDisplaying the queue:\n";
    q.Display();

    cout<<"\n\nDeleting the values as per priority:\n";

    for(i=0;i<n;i++)
        cout<<q.Dequeue()<<"\t";

    cout<<"\n\nDisplaying the queue:\n";
    q.Display();

    cout<<"\n\n";
    return 0;
}
