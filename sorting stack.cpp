/*
 Stack, here, it is a STL data structure that holds values of a type, here, it is int
 So we need to write stack<int>
*/

// It won't be even print the whole stack....before sorting

#include<bits/stdc++.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

void print_stack(stack<int> s)
{
    int i;

    for(i=0;i<s.size();i++)
    {
        cout<<s.top()<<"\t";
        s.pop();
    }
}

void sort_stack(stack<int> s)
{
    queue<int> q1,q2;

    while(!s.empty())
    {
        if(q1.empty())
        {
            q1.push(s.top());
            s.pop();
        }


        else
        {
            if(s.top()>=q1.front())
                q1.push(s.top());

            else
                q2.push(s.top());

            s.pop();
        }
    }

    // one of the queues will end before the other, or they'll end together
    while(!q1.empty() && !q2.empty())
    {
        if(q1.front()<q2.front())
            s.push(q1.front());

        else
            s.push(q2.front());
    }

    // pushing all the elements of the non-empty queue to the stack (now sorted)
    while(!q1.empty())
        s.push(q1.front());

    while(!q2.empty())
        s.push(q2.front());

    print_stack(s);
}

int main()
{
    stack<int> s;

    s.push(12);
    s.push(32);
    s.push(-9);
    s.push(67);
    s.push(21);
    s.push(5);

    cout<<"Before sorting:\n";
    print_stack(s);

    cout<<"After sorting:\n";
    sort_stack(s);


    cout<<endl<<endl;
    return 0;
}
