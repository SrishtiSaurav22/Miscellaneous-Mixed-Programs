#include<bits/stdc++.h>

using namespace std;

/*
Below is a naive implementation of a iterative function to calculate the LCM of two numbers

Time complexity:  O(a*b - max(a,b)), omega(1) 

Space complexity: theta(1)   
Auxiliary space:  theta(1)    
*/

int lcm_naive(int a, int b)
{
    int res=max(a,b);

    while(true)
    {
        if(res%a==0 && res%b==0)
            return res;

        ++res;
    }

    return res;
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
Below is an optimized implementation of a iterative function to calculate the LCM of two numbers

Time complexity:  theta( log( min(a,b) ) ) 

Space complexity: theta(1)   
Auxiliary space:  theta(1)    
*/

int lcm_optimized(int a, int b)
{
    return  ( ( a / hcf_i_naive(a,b) ) * b );
    /*
    This is the divide-first-multiply-next approach to reduce the risk of overflow when a and b are very large, 
    and their product will be even larger. 
    
    So, instead of:
    (a*b) / hcf(a,b)

    Use:
    ( a/hcf(a,b) ) * b
    */ 
}

int main()
{
    int a=0, b=0;

    cout<<"Enter two whole numbers:\na=";
    cin>>a;

    cout<<"b=";
    cin>>b;

    cout<<"\nThe LCM of "<<a<<" and "<<b<<", using the naive approach comes out to be "<<lcm_naive(a,b);
    cout<<"\nThe LCM of "<<a<<" and "<<b<<", using the optimized approach comes out to be "<<lcm_optimized(a,b);
    
    return 0;
}