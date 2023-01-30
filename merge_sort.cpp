#include<bits/stdc++.h>

using namespace std;

// merge function can be void since we are dealing with arrays
void merge_arrays(int *arr, int si, int ei, int mid)
{
    int i=si,j=mid+1,k=si;

    /*
     You could do this, but here the value of n will be
     incorrect because here arr is simply an integer
     pointer, not an array (if treated as a pointer,
     then sizeof(arr) would be 8 units and not the
     appropriate size.

     int n=sizeof(arr)/sizeof(arr[0]);

     Also, you can't use a pointer here. Because its
     size is not specified then. Might be the cause of
     segmentation fault.
    */

    int arr1[ei+1];
    int *p_arr1=arr1;

    /*
     Here, if I directly returned arr1, I got a warning
     that I'm returning the address of a local variable
     but if I return a pointer pointing to it, then
     there's no warning. Why? The pointer is still
     pointing to a local variable right...? We use this
     with constructors as well. How does that work?
    */

    while(i<=mid && j<=ei)
    {
        if(arr[i]<=arr[j])
            arr1[k++]=arr[i++];

        else
            arr1[k++]=arr[j++];
    }

    for(;i<=mid;)
        arr1[k++]=arr[i++];

    for(;j<=ei;)
        arr1[k++]=arr[j++];

    for(i=si;i<=ei;i++)
        arr[i]=arr1[i];
}

// si is start index
// ei is end index
void merge_sort(int *arr, int si, int ei)
{
    if(si>=ei)
        return;

    int mid=(si+ei)/2;

    merge_sort(arr,si,mid);
    merge_sort(arr,mid+1,ei);

    merge_arrays(arr,si,ei,mid);
}

void print_array(int *arr, int n)
{
    int i;

    for(i=0;i<n;i++)
        cout<<arr[i]<<"\t";
}

int main()
{
    int arr[9]={8,7,2,5,4,1,9,3,6};

    cout<<"Before sorting: "<<endl;
    print_array(arr,9);

    merge_sort(arr,0,9);

    cout<<"\nAfter sorting: "<<endl;
    print_array(arr,9);

    cout<<endl;
    return 0;
}
