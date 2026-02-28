#include<bits/stdc++.h>

using namespace std;

/*
Below is a naive and iterative approach to calculate the power of x raised to n:

Time complexity:  theta(n)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/

int power_iterative_naive(int x, int n)
{
    int prod=1;
    for(int i=0;i<n;i++)
        prod=prod*x;

    return prod;
}

/*
Below is a naive and recursive approach to calculate the power of x raised to n:

Time complexity:  theta(n)

Space complexity: theta(n)   
Auxiliary space:  theta(n)
*/

int power_recursive_naive(int x, int n)
{
    if(n==0)
        return 1;
    
    return x * power_recursive_naive(x,n-1);
}

/*
Below is an efficient and recursive approach to calculate the power of x raised to n:

Time complexity:   theta(log n)

Space complexity:  theta(log n) 
Auxiliary space:   theta(log n)
*/

int power_recursive_efficient(int x, int n)
{
    if(n==0)
        return 1;

    int temp=power_recursive_efficient(x, n/2);

    temp=temp*temp;

    if(n%2==0)
        return temp;

    else
        return temp*x;
}

/*
Below is an efficient and iterative approach to calculate the power of x raised to n:

Time complexity:   theta(log n)

Space complexity:  theta(1) 
Auxiliary space:   theta(1)

NOTE: This is the best method to solve the given problem
*/

int power_iterative_efficient(int x, int n)
{
    int res=1;

    while(n>0)
    {
        if(n%2==1)
            res=res*x;
        
        x=x*x;
        n=n/2;
    }

    return res;
}

int main()
{
    int x, n;

    cout<<"Enter x=";
    cin>>x;

    cout<<"Enter n=";
    cin>>n;

    cout<<"\n"<<x<<" raised to the power of "<<n<<" is "<<power_iterative_efficient(x,n);

    return 0;
}