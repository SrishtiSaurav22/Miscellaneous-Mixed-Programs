#include<bits/stdc++.h>

using namespace std;

/*
Below is a further optimized implementation of a iterative function to check if an input number is prime 

Time complexity:  theta( sq. root(n) ) 

Space complexity: theta(1)   
Auxiliary space:  theta(1)    
*/

bool prime_number_check(int n) 
{
    if(n==1)
        return false;

    if(n==2 || n==3)
        return true;

    if(n%2==0 || n%3==0)
        return false;

    for(int i=5;i*i<=n;i=i+6)
    {
        if( n%i==0 || n%(i+2)==0 )
            return false;
    }

    return true;
}

/*
Below is a function to print all the primes till a given input 

Time complexity:  theta( n * sq. root(n) ) or theta( n^(3/2) )

Space complexity: theta(1)   
Auxiliary space:  theta(1)    
*/

void print_all_primes_till_input_naive(int n)
{
    for(int i=2;i<=n;i++)
        if(prime_number_check(i)==true)
            cout<<i<<" ";
}

/*
Below is a function to print all the primes till a given input using the Sieve of Eratosthenes algorithm

Time complexity:  theta(n log log n)

Space complexity: theta(n)   
Auxiliary space:  theta(n)    
*/

void sieve_of_eratosthenes_simple(int n)
{
    vector<bool> isPrime(n+1, true);

    // We don't care about the values stored in isPrime[0] and isPrime[1]
    for(int i=2;i*i<=n;i++)
    {
        if(isPrime[i]==true)
            for(int j=2*i;j<=n;j=j+i)
                isPrime[j]=false;
    }

    // Now that only the prime indices of the vector are marked true, we can print them
    // The composite indices of the vector are marked false
    for(int i=2;i<=n;i++)
        if(isPrime[i]==true)
            cout<<i<<" ";
}

/*
Below is a function to print all the primes till a given input using the Sieve of Eratosthenes algorithm

Time complexity:  theta(n log log n)

Space complexity: theta(n)   
Auxiliary space:  theta(n)    
*/

void sieve_of_eratosthenes_optimized(int n)
{
    vector<bool> isPrime(n+1, true);

    // We don't care about the values stored in isPrime[0] and isPrime[1]
    for(int i=2;i*i<=n;i++)
    {
        if(isPrime[i]==true)
            for(int j=i*i;j<=n;j=j+i)
                isPrime[j]=false;
    }

    // Now that only the prime indices of the vector are marked true, we can print them
    // The composite indices of the vector are marked false
    for(int i=2;i<=n;i++)
        if(isPrime[i]==true)
            cout<<i<<" ";
}

/*
Below is a function to print all the primes till a given input using the Sieve of Eratosthenes algorithm

Time complexity:  theta(n log log n)

Space complexity: theta(n)   
Auxiliary space:  theta(n)    
*/

void sieve_of_eratosthenes_optimized_shorter(int n)
{
    vector<bool> isPrime(n+1, true);

    // We don't care about the values stored in isPrime[0] and isPrime[1]
    for(int i=2;i<=n;i++)
    {
        if(isPrime[i]==true)
        {
            cout<<i<<" ";
            for(int j=i*i;j<=n;j=j+i)
                isPrime[j]=false;
        }
    }
}

int main()
{
    int n;

    cout<<"Enter a natural number: ";
    cin>>n;

    sieve_of_eratosthenes_optimized_shorter(n);

    return 0;
}