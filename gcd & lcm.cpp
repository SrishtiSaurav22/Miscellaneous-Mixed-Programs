#include<bits/stdc++.h>
#include<math.h>

using namespace std;

//we find gcd using minimum of two numbers ( min(r,s)= (1/2)*(r+s - |r-s|) )
//we find lcm using maximum of two numbers ( max(r,s)= (1/2)*(r+s + |r+s|) )

//here, though, I have used Euclidean Algorithm

int gcd_recursion(int a, int b) //this is an "overkill" too many unnecessary iterations that may cause stack overflow
{
    if(a==0)
        return b;

    else if (b==0)
        return a;

    else if(a==b)
        return a; // or b, they are the same

    else if(a>b)
         return gcd_recursion(a-b, b);

    else
        return gcd_recursion(b-a, a);
}

int gcd_iterative(int a, int b) //much simpler with fewer iterations
{
    while(a!=b)
    {
        if(a>b) a=a-b;
        else b=b-a;
    }
    return a;
}

bool prime_check(int n)
{
    int i,c=0;
    for(i=2;i<=n;i++)
        if(n%i==0)
        c++;

    if(c==1) return true;

    else return false;
}

int lcm_brute(int a, int b)
{
    int i=2, p=1;

    while( !( !(a>1) && !(b>1) ) )
    {
        if( prime_check(i)==true )
        {
            while(a%i==0 && b%i==0)
            {
                 a=a/i;
                 b=b/i;
                 p=p*i;
            }

            while(a%i==0)
            {
              a=a/i;
              p=p*i;
            }

            while(b%i==0)
            {
              b=b/i;
              p=p*i;
            }
        }
        i++;
    }
    return p;
}

int lcm_recursion(int a, int b) //I DON'T UNDERSTAND THIS AT ALL........HOW IS IT WORKIING (IT'S FROM THE INTERNET)
{
    static int temp=1;

    if(temp%a==0 && temp%b==0)
        return temp;

    else
    {
        temp++;
        temp=lcm_recursion(a,b);
        return temp;
    }
}

int lcm_wrt_gcd(int a, int b)
{
    return (a*b)/gcd_iterative(a,b);
}

int main()
{

    int a,b;
    cout<<"Enter a=";
    cin>>a;
    cout<<"\nEnter b=";
    cin>>b;

    cout<<"\n\nGCD (using recursion): "<<gcd_recursion(a,b)<<"\nGCD (using iteration): "<<gcd_iterative(a,b);
    cout<<"\nLCM (using brute force): "<<lcm_brute(a,b)<<"\nLCM (using recursion):"<<lcm_recursion(a,b);
    cout<<"\nLCM (w.r.t GCD): "<<lcm_wrt_gcd(a,b);
    return 0;
}
