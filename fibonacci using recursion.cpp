//I am only getting 1 as an answer (Regardless of whether the function variables are static or not).

#include<bits/stdc++.h>

using namespace std;

int fibonacci(int n)
{
    if(n==1 || n==2)
    return 1;

    else
    {
      static int a0=0, a1=1, s=0, c=0; //Do recursive functions require static variables?

      s=a0+a1;
      a0=a1;
      a1=s;
      c++;


      if(c==(n-1))
      return s;

      else
      s=fibonacci(c);
    }
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
