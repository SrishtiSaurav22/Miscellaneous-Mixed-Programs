#include<bits/stdc++.h>

using namespace std;

/*
Below is the most naive implementation of a iterative function to calculate the GCD or HCF of two numbers

Time complexity:  theta( min(a,b) )

Space complexity: theta(1)   
Auxiliary space:  theta(1)    
*/

int hcf_i_most_naive(int a, int b)
{
    int res=min(a,b);

    /*
    This is considering the fact that HCF of 2 numbers can be at most equal to the smaller of the two numbers.

    Example:
    a=100
    b=200

    HCF=100

    */ 

    while(res>0)
    {
        if(a%res==0 && b%res==0)
            break;

        --res;
    }

    return res;
}

/*
Below is a naive implementation of a recursive function to calculate the GCD or HCF of two numbers

Time complexity:  theta( log( min(a,b) ) ) 

Space complexity: theta( log( min(a,b) ) )   
Auxiliary space:  theta( log( min(a,b) ) )    
*/

int hcf_r_naive(int a, int b)
{
    if(a<b)
    {
        int c=a;
        a=b;
        b=c;
    }
    
    if(a%b==0)
        return b;

    else
        return hcf_r_naive(b,a%b);
}

/*
Below is an optimized implementation of a recursive function to calculate the GCD or HCF of two numbers

Time complexity:  theta( log( min(a,b) ) ) 

Space complexity: theta( log( min(a,b) ) )   
Auxiliary space:  theta( log( min(a,b) ) )    
*/

int hcf_r_optimized(int a, int b)
{
    if(b==0)
        return a;

    else 
        return hcf_r_optimized(b,a%b);
}

/*
Below is a naive implementation of a iterative function to calculate the GCD or HCF of two numbers

Time complexity:  theta( log( min(a,b) ) ) 

Space complexity: theta(1)   
Auxiliary space:  theta(1)    
*/

int hcf_i_naive(int a, int b)
{
    if(a<b)
    {
        int c=a;
        a=b;
        b=c;
    }

    hcf_check:

    int c=a%b;

    if(c==0)
        return b;

    else
    {
        a=b;
        b=c;
        goto hcf_check;
    }
}

/*
Below is an optimized implementation of a iterative function to calculate the GCD or HCF of two numbers

Time complexity:  theta( max(a,b) ) 

Space complexity: theta(1)   
Auxiliary space:  theta(1)    
*/

int hcf_i_optimized(int a, int b)
{
    while(a!=b)
    {
        if(a>b)
            a=a-b;

        else
            b=b-a;
    }

    return a;
}

int main()
{
    int a=0,b=0;

    cout<<"Enter two natural numbers:\na=";
    cin>>a;

    cout<<"b=";
    cin>>b;

    cout<<"Via the most naive iterative solution, the HCF of "<<a<<" and "<<b<<" is "<<hcf_i_most_naive(a,b);
    cout<<"\nVia the naive recursive solution, the HCF of "<<a<<" and "<<b<<" is "<<hcf_r_naive(a,b);
    cout<<"\nVia the naive iterative solution, the HCF of "<<a<<" and "<<b<<" is "<<hcf_i_naive(a,b);
    cout<<"\nVia the optimized recursive solution, the HCF of "<<a<<" and "<<b<<" is "<<hcf_r_optimized(a,b);
    cout<<"\nVia the optimized iterative solution, the HCF of "<<a<<" and "<<b<<" is "<<hcf_i_optimized(a,b);
    
    return 0;
}