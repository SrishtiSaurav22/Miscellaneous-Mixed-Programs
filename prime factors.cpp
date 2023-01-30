#include<bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
    int c=0;

    for(int i=2;i<=n;i++)
    if(n%i==0)
    c++;

    if(c==1) return true;

    else return false;
}

void printPrimeFactorization(int n)
{
    int p;

    for(int i=2;i<=n;i++)
    if(isPrime(i)==true)
    {
        p=i;
        while(n%p==0)
        {
         cout<<i<<" ";
         p=p*i;
        }
    }
}
