#include<bits/stdc++.h>

using namespace std;

int find_duplicate_element(int *arr, int n)
{
    set<int> s;
    int i;

    for(i=0;i<n;i++)
    {
        /*
         There is this insert signature in std::set
         pair<iterator,bool> insert ( const value_type& x );
         Test the second of the returned pair, should be set to true if inserted successfully.

         https://stackoverflow.com/questions/9586281/set-detect-insertion-failure
        */

        if(s.insert(arr[i]).second==false)
            return arr[i];
    }

    return -1;
}

int main()
{
    int arr[]={0,7,2,5,4,7,1,3,6};
    int *ptr=arr;

    cout<<"Duplicate element of the array: "<<find_duplicate_element(arr,9);

    cout<<endl;
    return 0;
}
