/*
 There are two possible approaches in recursion problems with arrays:

 1)
 Programmer handles the first element
 Recursion handles the remaining (n-1) elements

 2)
 Recursion handles the first (n-1) elements
 Programmer handles the remaining n-th element

 Find the first index of a value in an array, using recursion
 the array is not sorted or anything, it just has elements that
 occur multiple times in different arbitrary places

 See the time taken by both the functions
*/

#include<bits/stdc++.h>

using namespace std;

int first_index_1(int *arr, int n, int pos, int val)
{
    if(pos==n)
        return -1;

    if(arr[pos]==val)
        return pos;

    // in the function call, pos will start from zero
    return first_index_1(arr,n,pos+1,val);
}

// Can you break the array one by one? YES!

/*
 Here,there is an issue that the index returned will be 0
 if the value is found, as we are only checking the beginning
 of the new cut array every time

 In order to resolve this, we need to add 1 to every recursive
 as we are basically moving to the next element in the array
 every recursive call

 Since the array indexes start from zero, we don't have to
 add an extra plus one to mark the position, as the number of
 of moves is the position of the array
*/

int first_index_2(int* arr, int n, int val)
{
    int ans;

    if(n==0)
        return -1;

    if(arr[0]==val)
        return 0;

    ans=first_index_2(arr+1,n-1,val)+1;
    return ans;
}

int main()
{
    int arr[]={2,2,5,4,5,5};
    int val1=3,val2=5,val3=2,pos1,pos2,pos3;

    pos1=first_index_2(arr,6,val1);

    if(pos1!=-1)
        cout<<"First index of "<<val1<<" in the array: "<<pos1<<endl;

    else
        cout<<"Sorry, "<<val1<<" not found in the array!"<<endl;

    pos2=first_index_2(arr,6,val2);

    if(pos2!=-1)
        cout<<"First index of "<<val2<<" in the array: "<<pos2<<endl;

    else
        cout<<"Sorry, "<<val2<<" not found in the array!"<<endl;

    pos3=first_index_2(arr,6,val3);

    if(pos3!=-1)
        cout<<"First index of "<<val3<<" in the array: "<<pos3<<endl;

    else
        cout<<"Sorry, "<<val3<<" not found in the array!"<<endl;

    cout<<endl;
    return 0;
}
