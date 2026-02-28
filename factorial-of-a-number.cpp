#include<bits/stdc++.h>

using namespace std;

/*
Below is an iterative function to calculate the factorial of a whole number 

Time complexity:  theta(n) 

Space complexity: theta(1)      (due to fixed number of total variables (input n, extra res), independent of input size)
Auxiliary space:  theta(1)      (due to fixed number of extra variables (res), independent of input size)
*/

int factorial_i(int n)
{
    int res=1;

    for(int i=2; i<=n; i++)
    {
        res=res*i;
    }

    return res;
}

/*
Below is a recursive function to calculate the factorial of a whole number 

Time complexity:  theta(n) 

Space complexity: theta(n)      (due to the function keeping n pending function calls on the call stack)
Auxiliary space:  theta(n)      (due to the function keeping n pending function calls on the call stack)
*/

int factorial_r(int n)
{
    if(n==0)
        return 1;

    return n*factorial_r(n-1);
}

int main()
{
    int n;

    cout<<"Enter a whole number: ";
    cin>>n;

    cout<<"\nFactorial of "<<n<<", using the iterative solution, is "<<factorial_i(n);
    cout<<"\n\nFactorial of "<<n<<", using the recursive solution, is "<<factorial_r(n);

    return 0;
}

