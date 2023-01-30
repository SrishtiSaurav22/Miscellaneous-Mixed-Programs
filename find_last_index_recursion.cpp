/*
There are two possible approaches in recursion problems with arrays:

 1)
 Programmer handles the first element
 Recursion handles the remaining (n-1) elements

 2)
 Recursion handles the first (n-1) elements
 Programmer handles the remaining n-th element

 Find the last index of a value in an array, using recursion
 the array is not sorted or anything, it just has elements that
 occur multiple times in different arbitrary places

 see the time taken by both the functions
*/

#include<bits/stdc++.h>

using namespace std;

int last_index_1(int *arr, int n, int val)
{
    if(n==0)
        return -1;

    if(arr[n-1]==val)
        return n-1;

    return last_index_1(arr,n-1,val);
}

/*
 Can you start the traversal of the array from 0,
 instead of (n-1)? This is a medium level problem.

 Both the approaches in 'find_first_index' and the
 first approach of this problem are easy level problems.
 Just saying.
*/

//int last_index_2(int *arr, int n, int val)

int main()
{
    int arr[]={2,2,5,4,5,5};
    int val1=3,val2=5,val3=2,pos1,pos2,pos3;

    pos1=last_index_1(arr,6,val1);

    if(pos1!=-1)
        cout<<"Last index of "<<val1<<" in the array: "<<pos1<<endl;

    else
        cout<<"Sorry, "<<val1<<" not found in the array!"<<endl;

    pos2=last_index_1(arr,6,val2);

    if(pos2!=-1)
        cout<<"Last index of "<<val2<<" in the array: "<<pos2<<endl;

    else
        cout<<"Sorry, "<<val2<<" not found in the array!"<<endl;

    pos3=last_index_1(arr,6,val3);

    if(pos3!=-1)
        cout<<"Last index of "<<val3<<" in the array: "<<pos3<<endl;

    else
        cout<<"Sorry, "<<val3<<" not found in the array!"<<endl;

    cout<<endl;
    return 0;
}
