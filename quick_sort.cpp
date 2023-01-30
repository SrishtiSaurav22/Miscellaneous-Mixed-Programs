#include<bits/stdc++.h>

using namespace std;

int partition_(int *arr, int si, int ei)
{
    int i=si;
    int j=ei;
    int pivot=si;
    int t;

    do
    {
        do{i++;} while(arr[i]<=arr[pivot]);
        do{j--;} while(arr[j]>arr[pivot]);

        if(i<j)
        {
            t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }

    } while(i<j);

    t=arr[j];
    arr[j]=arr[si];
    arr[si]=t;

    return j;
}

void quick_sort(int *arr, int si, int ei)
{
    if(si>=ei)
        return;

    int pivot=partition_(arr,si,ei);

    quick_sort(arr,si,pivot);
    quick_sort(arr,pivot+1,ei);
}

void print_array(int *arr, int n)
{
    int i;

    for(i=0;i<n;i++)
        cout<<arr[i]<<"\t";
}

int main()
{
    int arr[]={5,2,1,4,3};

    cout<<"Before sorting: "<<endl;
    print_array(arr,5);

    quick_sort(arr,0,5); // pass (n-1) for ei

    cout<<"\nAfter sorting: "<<endl;
    print_array(arr,5);

    cout<<endl;
    return 0;
}
