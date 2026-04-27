#include<bits/stdc++.h>

using namespace std;

int return_pair_sums(int *arr, int n, int sum)
{
    int i,j,cnt=0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i]+arr[j]==sum)
                ++cnt;
        }
    }

    return cnt/2;
}

int main()
{
    int arr[]={2,8,10,5,-2,5};
    int n=6;
    int sum=10;

    cout<<"Number of element pairs with the sum of "<<sum<<" is "<<return_pair_sums(arr,n,sum);

    cout<<endl;
    return 0;
}
