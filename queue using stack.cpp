#include<bits/stdc++.h>

using namespace std;

struct STACK
{
    int Top;
    int Size;
    int *Arr;

    STACK(int s)
    {
        Size=s;
        Top=-1;
        Arr=new int[Size];
    }

    bool isEmpty()
    {
        if(Top==-1)
            return true;

        return false;
    }

    bool isFull()
    {
        if(Top==Size-1)
            return true;

        return false;
    }

    void push(int x)
    {
        if(isFull()==true)
        {
            cout<<"The stack is full!";
            return;
        }

        Arr[++Top]=x;
    }

    int pop()
    {
        if(isEmpty()==true)
            return -1;

        return Arr[Top--];
    }

    void Display()
    {
        if(isEmpty()==true)
        {
            cout<<"The stack is empty";
            return;
        }

        int i;

        for(i=0;i<=Top;i++)
            cout<<Arr[i]<<"\t";
    }
};

int main()
{
    int n, i, val;

    cout<<"\nEnter the number of elements: ";
    cin>>n;

    STACK s1(n), s2(n);

    cout<<"\n\nPushing elements to the queue:\n\n";

    for(i=0;i<n;i++)
    {
        cout<<"Enter the element: ";
        cin>>val;
        s1.push(val);
    }

    cout<<"\n\nDisplaying stack s1:\n";
    s1.Display();

    cout<<"\n\nDisplaying stack s2:\n";
    s2.Display();

    for(i=0;i<n;i++)
        s2.push(s1.pop());

    cout<<"\n\nDisplaying stack s1:\n";
    s1.Display();

    cout<<"\n\nDisplaying stack s2:\n";
    s2.Display();

    cout<<"\n\nPopping elements from the queue:\n";

    for(i=0;i<n;i++)
        cout<<s2.pop()<<"\t";

    cout<<"\n\nDisplaying stack s1:\n";
    s1.Display();

    cout<<"\n\nDisplaying stack s2:\n";
    s2.Display();

    cout<<"\n\n";
    return 0;
}
