/*
 Since stack DS follows LIFO principle.
 (Both insertion and deletion take place at the same end).
 (OR elements are added to the top and also removed from the top).
 So, the time complexity of the push and pop operations is O(1).

 Otherwise we can push or pop elements from the front and back resp. as well but that function will take O(n) time.

 This 'stack' is just an array (HERE) where we add and delete elements from the same end so that the operation takes O(1) time
 And group it together with variables to hold its maximum capacity as well the index of the top most element.

 These are grouped together in a structure, and named as 'stack'.
*/

#include<bits/stdc++.h>

using namespace std;

struct STACK
{
    int cap;
    int top;
    int *arr; // we declared a pointer so that we can assign the size of the array which it is pointing to at runtime (or dynamically)

    STACK(int c)
    {
        cap=c;
        arr=new int[cap]; // a new array is created in the heap
        top=-1;
    }

    bool isEmpty()
    {
        if(top==-1) return true;

        return false;
    }

    bool isFull()
    {
        if(top==cap-1) return true;

        return false;
    }

    void push(int x)
    {
        if(top==cap-1)
            cout<<"\nOverflow condition!";

        // We can also call isFull() here

        arr[++top]=x;
    }

    int pop()
    {
        if(top==-1)
            cout<<"\nUnderflow condition!";

        // We can also call isEmpty() here

        return arr[top--];
    }

    int sizeOfStack()
    {
        return (top+1);
    }

    void topElement()
    // peek() can also be used to display an element at a given position using a formula (as per the sequencing) in O(1) time.
    {
        if(isEmpty()==true)
            cout<<"\nThe stack is empty";

        cout<<"\n"<<arr[top];
    }

    void peek(int pos) // pos is considered starting from the top
    {
        if(isEmpty()==true)
            cout<<"\nThe stack is empty";

        cout<<"\n"<<arr[cap-pos];
    }

    void display()
    {
        int i;

        for(i=top;i>=0;i--)
            cout<<"\n"<<arr[i];
    }
};

int main()
{
    int i,n;

    cout<<"\nEnter the capacity of the stack: ";
    cin>>n;

    STACK s(n);

    cout<<"\n";
    cout<<"\nPushing elements into the stack:\n";
    for(i=1;i<=n;i++)
    {
        cout<<"\nPushing "<<i<<" into the stack.";
        s.push(i);
    }

    cout<<"\n";
    if(s.isFull()==true)
        cout<<"\nThe stack is full!";

    cout<<"\n";
    cout<<"\nDisplaying the stack:\n";
    s.display();

    cout<<"\n";
    cout<<"\nPoping elements from the stack:\n";
    for(i=0;i<n;i++)
    {
        cout<<"\n";
        s.topElement();
        cout<<"\n"<<s.pop();
    }


    cout<<"\n";
    if(s.isEmpty()==true)
        cout<<"\nThe stack is empty!";

    cout<<"\n";
    return 0;
}
