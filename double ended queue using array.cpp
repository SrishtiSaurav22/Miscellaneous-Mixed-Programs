/*
 Here insertion to the Front is possible only after at least one deletion from it
 Deletion from the Rear is possible only after at least one insertion from it

 There are two types of double ended queues:
 Input Restricted (no insertion to Front, all other operations are possible)
 Output Restricted (no deletion from Rear, all other operations are possible)
*/

#include<bits/stdc++.h>

using namespace std;

struct DE_QUEUE
{
    int Size;
    int Front;
    int Rear;
    int *Arr;

    DE_QUEUE(int s)
    {
        Size=s;
        Front=-1;
        Rear=-1;
        Arr=new int[Size];
    }

    bool isEmpty()
    {
        if(Front==Rear)
        /*
         This condition includes both:
         Front = Rear = -1
         Front = Rear = Size-1 (There can be no element at Front's position)
        */
        return true;

        return false;
    }

    bool isFull()
    {
        if(Front==-1 && Rear==Size-1) // Full from both sides
            return true;

        return false;
    }

    void Enqueue(int x)
    {
        if(isFull()==true)
        {
            cout<<"The queue is full.";
            return;
        }

        char ch;

        cout<<"\n\nWould you like to push an element to the FRONT (enter 'f') or the REAR (enter 'r')?\nEnter your choice: ";
        choice:
        fflush(stdin);
        cin>>ch;

        switch(ch)
        {
            case 'f':

                if(Front==-1)
                {
                    cout<<"Sorry, can't push to the Front";
                    return;
                }
                Arr[Front--]=x;

            break;

            case 'r':

                if(Rear==Size-1)
                {
                    cout<<"Sorry, can't push to the Rear";
                    return;
                }
                Arr[++Rear]=x;

            break;

            default:

                cout<<"\nInvalid input. Enter your choice again: ";
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

        char ch;

        cout<<"\n\nWould you like to pop an element from the FRONT (enter 'f') or the REAR (enter 'r')?\nEnter your choice: ";
        choice:
        fflush(stdin);
        cin>>ch;

        switch(ch)
        {
            case 'f':

                cout<<Arr[++Front];

                // As soon as Front & Rear become equal (holding any value) set them back to -1
                if(Front==Rear)
                {
                    Front=-1;
                    Rear=-1;
                }
                break;

            /*
             When declaring variables in a switch case,
             enclose the code in a scope using curly brackets

             OR

             You can declare res outside the switch statement

             otherwise you'll get the error:
             error: jump to case label [-fpermissive]
            */
            case 'r':

                cout<<Arr[Rear--];

                // As soon as Front & Rear become equal (holding any value) set them back to -1
                if(Front==Rear)
                {
                    Front=-1;
                    Rear=-1;
                }
            break;

            default:

                cout<<"\nInvalid input. Enter your choice again: ";
                goto choice;
        }
    }

    void FrontElement()
    {
        if(isEmpty()==true)
        {
            cout<<"The queue is empty";
            return;
        }

        cout<<Arr[Front+1];
    }

    void RearElement()
    {
        if(isEmpty()==true)
        {
            cout<<"The queue is empty";
            return;
        }

        cout<<Arr[Rear];
    }

    void Display()
    {
        if(isEmpty()==true)
        {
            cout<<"The queue is empty";
            return;
        }

        int i;

        for(i=Front+1;i<=Rear;i++)
            cout<<Arr[i]<<"\t";
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
