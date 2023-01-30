/*
 Here, we can see three approaches to get the maximum value:
 1) normal if/else
 2) ternary operator
 3) using a function

 Advantages/Disadvantages of all:
 1) if/else is readable but that's a lot to type
 2) little to write, but will take the coder a second to understand
 3) readable, little to write (after writing the function definition)
    but reduces the performance (due to function calls, copying of variables, etc.)

 Read about inline functions:
 https://www.geeksforgeeks.org/inline-functions-cpp/

 use the clock function (from c) to see the time difference between
 the usage of normal and inline functions.

*/

#include<bits/stdc++.h>

using namespace std;

int max_value(int a,int b)
{
    return (a>b)?a:b;
}

inline int max_value_inline(int a,int b)
{
    return (a>b)?a:b;
}

int main()
{
    int a=1,b=2,c;

    if(a>b)
        c=a;

    else
        c=b;

    cout<<"Using normal if/else:\nc: "<<c<<endl;

    // c=(a>b)?a:b;
    // we can also write this:
    c=max_value(a,b);

    cout<<"Using ternary operator:\nc: "<<c<<endl;

    // compare 3 numbers using ternary operator:

    a=2;
    b=3;
    c=4;

    int MAX=(a>b)?(a>c?a:c):(b>c?b:c);
    cout<<"Maximum of three numbers: "<<MAX;

    cout<<endl;
    return 0;
}
