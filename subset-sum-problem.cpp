<<<<<<< HEAD
#include<bits/stdc++.h>

using namespace std;

int sum_subset_count=0;

/*
Below is 

Time complexity:  theta(2^n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
void check_subset_sum(int* arr, int size, int key_sum, int sum=0, int index=0)
{
    if(index==size)
    {
        if(sum==key_sum)
            ++sum_subset_count;

        return;
    }

    check_subset_sum(arr, size, key_sum, sum+arr[index], index+1);
    check_subset_sum(arr, size, key_sum, sum, index+1);
}

/*
Below is 

Time complexity:  theta(2^n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int count_subsets(int arr[], int n, int sum)
{
    if(n==0)
        return (sum==0)?1:0;
    
    return count_subsets(arr, n-1, sum) + count_subsets(arr, n-1, sum-arr[n-1]);
}

/*
Below is 

Time complexity:  theta(n * sum)

Space complexity: theta(n * sum)
Auxiliary space:  theta(n * sum)
*/
int count_subsets_dp(int arr[], int n, int sum)
{
    int dp[n+1][sum+1];

    //dp[0][0] is 1
    for(int i=0;i<=n;i++)
        dp[i][0]=1;

    for(int j=1;j<=sum;j++)
        dp[0][j]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];

            else
                dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][sum];
}

/*
Below is 

Time complexity:  theta(n * sum)

Space complexity: theta(sum)
Auxiliary space:  theta(sum)
*/
int count_subsets_dp_space_optimized(int arr[], int n, int sum)
{
    vector<int> dp(sum+1,0);
    
    dp[0]=1;

    for(int i=0;i<n;i++)
        for(int j=sum;j>=arr[i];j--)
            dp[j]+=dp[j-arr[i]];

    return dp[sum];
}

int main()
{
    int arr[]={2,3,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key_sum=7;

    check_subset_sum(arr,size,key_sum);
    cout<<"The number of subsets in the given array whose elements add up to "<<key_sum<<" are "<<sum_subset_count<<endl;
    cout<<"Via an alternate method: "<<count_subsets(arr,size,key_sum)<<endl;

    cout<<"\nUsing the Dynamic Programming appproaches:\n";
    cout<<"Using the classic DP approach: "<<count_subsets_dp(arr,size,key_sum)<<endl;
    cout<<"Using the space optimized DP approach: "<<count_subsets_dp_space_optimized(arr,size,key_sum)<<endl;
    
    return 0;
=======
#include<bits/stdc++.h>

using namespace std;

int sum_subset_count=0;

/*
Below is 

Time complexity:  theta(2^n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
void check_subset_sum(int* arr, int size, int key_sum, int sum=0, int index=0)
{
    if(index==size)
    {
        if(sum==key_sum)
            ++sum_subset_count;

        return;
    }

    check_subset_sum(arr, size, key_sum, sum+arr[index], index+1);
    check_subset_sum(arr, size, key_sum, sum, index+1);
}

/*
Below is 

Time complexity:  theta(2^n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int count_subsets(int arr[], int n, int sum)
{
    if(n==0)
        return (sum==0)?1:0;
    
    return count_subsets(arr, n-1, sum) + count_subsets(arr, n-1, sum-arr[n-1]);
}

/*
Below is 

Time complexity:  theta(n * sum)

Space complexity: theta(n * sum)
Auxiliary space:  theta(n * sum)
*/
int count_subsets_dp(int arr[], int n, int sum)
{
    int dp[n+1][sum+1];

    //dp[0][0] is 1
    for(int i=0;i<=n;i++)
        dp[i][0]=1;

    for(int j=1;j<=sum;j++)
        dp[0][j]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];

            else
                dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][sum];
}

/*
Below is 

Time complexity:  theta(n * sum)

Space complexity: theta(sum)
Auxiliary space:  theta(sum)
*/
int count_subsets_dp_space_optimized(int arr[], int n, int sum)
{
    vector<int> dp(sum+1,0);
    
    dp[0]=1;

    for(int i=0;i<n;i++)
        for(int j=sum;j>=arr[i];j--)
            dp[j]+=dp[j-arr[i]];

    return dp[sum];
}

int main()
{
    int arr[]={2,3,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key_sum=7;

    check_subset_sum(arr,size,key_sum);
    cout<<"The number of subsets in the given array whose elements add up to "<<key_sum<<" are "<<sum_subset_count<<endl;
    cout<<"Via an alternate method: "<<count_subsets(arr,size,key_sum)<<endl;

    cout<<"\nUsing the Dynamic Programming appproaches:\n";
    cout<<"Using the classic DP approach: "<<count_subsets_dp(arr,size,key_sum)<<endl;
    cout<<"Using the space optimized DP approach: "<<count_subsets_dp_space_optimized(arr,size,key_sum)<<endl;
    
    return 0;
>>>>>>> 95a289d2b2620083357fcb405d7b9ac99fd960cb
}