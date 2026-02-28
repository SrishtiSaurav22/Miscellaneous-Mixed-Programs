#include<bits/stdc++.h>

using namespace std;

/*
Below is an iterative function to print all the divisors of an input natural number

Time complexity:  theta(n) 

Space complexity: theta(1)   
Auxiliary space:  theta(1)
*/

void print_all_divisors_of_number_naive_and_sorted(int n)
{
    cout<<"\nAll the divisors of this number are:\n";
    for(int i=1 ; i<=(n/2) ; i++)
    {
        if(n%i==0)
            cout<<i<<" ";
    }

    cout<<n<<"\n";
}

/*
Below is an iterative function to print all the divisors of an input natural number

Time complexity:  theta( sq. root(n) ) 

Space complexity: theta(1)   
Auxiliary space:  theta(1)
*/

void print_all_divisors_of_number_optimized(int n)
{
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
            cout<<i<<" ";

        if(i!=(n/i))
            cout<<(n/i)<<" ";
    }   
        
}

/*
Below is an iterative function to print all the divisors of an input natural number

Time complexity:  theta( sq. root(n) ) 

Space complexity: theta(1)   
Auxiliary space:  theta(1)
*/

void print_all_divisors_of_number_optimized_and_sorted(int n)
{
    int i;

    // print divisors from 1 to sq. root(n) (inclusive range)
    for(i=1;i*i<=n;i++)
        if(n%i==0)
            cout<<i<<" ";
    
    // print divisors from sq. root(n) to n (inclusive range)
    for( ;i>=1;i--)
        if(n%i==0 && i!=(n/i))
            cout<<(n/i)<<" ";   
}

int main()
{
    int n;

    cout<<"Enter a natural number: ";
    cin>>n;
    print_all_divisors_of_number_optimized_and_sorted(n);
    
    return 0;
}