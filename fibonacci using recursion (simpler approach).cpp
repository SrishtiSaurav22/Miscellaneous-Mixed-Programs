#include<bits/stdc++.h>

using namespace std;

int fibonacci(int n)
{
    if(n==1 || n==0)
        return n;

    else
        return (fibonacci(n-1)+fibonacci(n-2));
}

int main()
{
    int n;
    cout<<"Enter n=";
    cin>>n;

    if(n==1)
    cout<<n<<"st number in the Fibonacci Series: "<<fibonacci(n);

    else if(n==2)
    cout<<n<<"nd number in the Fibonacci Series: "<<fibonacci(n);

    else if(n==3)
    cout<<n<<"rd number in the Fibonacci Series: "<<fibonacci(n);

    else
    cout<<n<<"th number in the Fibonacci Series: "<<fibonacci(n);

    return 0;
}
