O#include<bits/stdc++.h>

/*
 Find the unique element in the array of form: 2m+1,
 where m is the no. of elements appearing twice, and
 1 is the unique element to be found.

 Use set functions: count(const g) and erase(const g)
*/

using namespace std;

int find_unique_element(int *arr, int n)
{
    set<int> s;

    int i;

    for(i=0;i<n;i++)
    {
        if(s.count(arr[i])==0)
            s.insert(arr[i]);

        else
            s.erase(arr[i]);
    }

    return *(s.begin());
    //s.begin() returns the iterator, not the value, so use '*'
    // anyhow there's only the unique element left in the set
}

int main()
{
    int arr[]={2,4,1,2,3,1,3};
    int *ptr=arr;

    cout<<"The unique element of the array is: "<<find_unique_element(ptr,7);

    cout<<endl;
    return 0;
}
