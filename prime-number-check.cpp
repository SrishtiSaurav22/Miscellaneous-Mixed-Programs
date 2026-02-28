// check the notes

#include<bits/stdc++.h>

using namespace std;

/*
Below is a naive implementation of a iterative function to check if an input number is prime 

Time complexity:  theta(n) 

Space complexity: theta(1)   
Auxiliary space:  theta(1)    
*/

bool prime_number_check_naive(int n)
{
    if(n==1)
        return false;
        // 1 is neither prime nor composite

    for(int i=2;i<n;i++)
        if(n%i==0)
            return false;

    return true;
}

/*
Below is an optimized implementation of a iterative function to check if an input number is prime 

Time complexity:  theta( sq. root(n) ) 

Space complexity: theta(1)   
Auxiliary space:  theta(1)    
*/

bool prime_number_check_optimized(int n)
{
    if(n==1)
        return false;
        // 1 is neither prime nor composite

    for(int i=2;(i*i)<=n;i++)
        if(n%i==0)
            return false;

    return true;
}

/*
Below is a further optimized implementation of a iterative function to check if an input number is prime 

Time complexity:  theta( sq. root(n) ) 

Space complexity: theta(1)   
Auxiliary space:  theta(1)    
*/

bool prime_number_check_further_optimized(int n)
{
    if(n==1)
        return false;
        // 1 is neither prime nor composite

    if(n==2 || n==3)
        return true;

    if(n%2==0 || n%3==0)
        return false;

    for(int i=5;i*i<=n;i=i+6)
    {
        if( n%i==0 || n%(i+2)==0 )
            return false;
    }
    /*
    We're iterating i by 6 to skip 2 even numbers and one multiple of 3 between i and i+6. We only check the 
    divisibility of n by the 2 odd numbers in between the range.

    Example:
    i=5
    i+6=11

    i0=5   // can be used to check if n is composite
    i1=6   // even number (multiple of 2), skip
    i2=7   // can be used to check if n is composite
    i3=8   // even number (multiple of 2), skip
    i4=9   // multiple of 3, skip
    i5=10  // even number (multiple of 2), skip
    i6=11  // can be used to check if n is composite

    Similarly, 
    i=11
    i+6=17

    i0=11   // can be used to check if n is composite
    i1=12   // even number (multiple of 2), skip
    i2=13   // can be used to check if n is composite
    i3=14   // even number (multiple of 2), skip
    i4=15   // multiple of 3, skip
    i5=16   // even number (multiple of 2), skip
    i6=17   // can be used to check if n is composite
    */

    return true;
}

int main()
{
    int n=0;

    cout<<"Enter a natural number: ";
    cin>>n;

    cout<<"Is "<<n<<" prime? ";
    if(prime_number_check_further_optimized(n))
        cout<<"YES!";
    
    else
        cout<<"NO!";
    
    return 0;
}