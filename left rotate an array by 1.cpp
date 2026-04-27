#include<bits/stdc++.h>

using namespace std;

void swap_method(int a[], int n)
{
    int i, t;

    for(i=0;(i+1)<n;i++)
    {
        t=a[i];
        a[i]=a[i+1];
        a[i+1]=t;
    }
}

void assignment_method(int a[], int n)
{
    int i, t;

    t=a[0];
    for(i=1;i<n;i++)
        a[i-1]=a[i];
    a[n-1]=t;
}

int main()
{
    int a[]={1,2,3,4,5}, i;

    cout<<"Before changes:\n";
    for(i=0;i<5;i++)
        cout<<a[i]<<" ";

    //use anyone

    swap_method(a,5);
    //assignment_method(a,5);

    cout<<"\nAfter changes:\n";
    for(i=0;i<5;i++)
        cout<<a[i]<<" ";
}
