/*
 There are two possible approaches in recursion problems with arrays:

 1)
 Programmer handles the first element
 Recursion handles the remaining (n-1) elements

 2)
 Recursion handles the first (n-1) elements
 Programmer handles the remaining n-th element

 Find all the indices of a value in an array, using recursion
 the array is not sorted or anything, it just has elements that
 occur multiple times in different arbitrary places

 See the time taken by both the functions

 Implement this by:
 returning the array of the positions of the value
 returning only the size of that array (or the frequency of the value)
*/

#include<bits/stdc++.h>

using namespace std;

int all_indice_1(int *arr, int n, int val)
{
    if(n==0)
        return 0;

    if(arr[0]==val)
        return 1+all_indice_1(arr+1,n-1,val);

    else
        return 0+all_indice_1(arr+1,n-1,val);
}

int all_indice_2(int *arr, int n, int val)
{
    if(n==0)
        return 0;

    if(arr[n-1]==val)
        return 1+all_indice_1(arr,n-1,val);

    else
        return 0+all_indice_1(arr,n-1,val);
}

int main()
{
    int arr[]={2,2,5,4,5,5};
    int val1=3,val2=5,val3=2,pos1,pos2,pos3;

    pos1=all_indice_2(arr,6,val1);

    if(pos1!=-1)
        cout<<"All indice of "<<val1<<" in the array: "<<pos1<<endl;

    else
        cout<<"Sorry, "<<val1<<" not found in the array!"<<endl;

    pos2=all_indice_2(arr,6,val2);

    if(pos2!=-1)
        cout<<"All indice of "<<val2<<" in the array: "<<pos2<<endl;

    else
        cout<<"Sorry, "<<val2<<" not found in the array!"<<endl;

    pos3=all_indice_2(arr,6,val3);

    if(pos3!=-1)
        cout<<"All indice of "<<val3<<" in the array: "<<pos3<<endl;

    else
        cout<<"Sorry, "<<val3<<" not found in the array!"<<endl;

    cout<<endl;
    return 0;
}
