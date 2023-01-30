/*
 Here the stack is truly nothing but a vector. Internally the stack (class in C++) is implemented using vectors.

 This 'stack' is just a vector (HERE).

 We don't need to group this vector with a size variable as the size of a vector can be dynamically changed.

 And we don't need a variable to hold the index of the top most element (updated during insertion and deletion) since
 vectors already follow the LIFO principle.

 These are grouped together in a structure, and named as 'stack'.
*/

#include<bits/stdc++.h>

using namespace std;

struct STACK
{
    vector<int> vec;

    void push(int x)
    {
        vec.push_back(x);
    }

    int pop()
    {
        int res=vec.back(); // displaying the element to be deleted
        vec.pop_back();
        return res;
    }

    int peek()
    {
        return vec.back();
    }

    bool isEmpty()
    {
        return vec.empty();
    }

    int sizeOfStack()
    {
        return vec.size();
    }
};

int main()
{
    int i,n;

    cout<<"Enter the no. of elements that you wish to enter into the stack: ";
    cin>>n;

    STACK s;

    cout<<"\n\nPushing elements into the stack:\n";
    for(i=1;i<=n;i++)
    {
        cout<<"\nPushing "<<i<<" into the stack.";
        s.push(i);
    }

    cout<<"\n\nPoping elements from the stack:\n";
    for(i=0;i<n;i++)
    {
        cout<<"\n\n"<<s.peek();
        cout<<"\n"<<s.pop();
    }

    cout<<"\n";
    return 0;
}

