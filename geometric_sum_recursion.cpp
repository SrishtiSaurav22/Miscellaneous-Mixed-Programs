#include<bits/stdc++.h>

using namespace std;

int power(int n, int p)
{
    if(p==1)
        return n;

    return n*power(n,p-1);
}

// Here, we are assuming a simpler form the geometric sum
// with just one number taking up different powers

int geo_sum(int a, int n,int k) // (n^0)+(n^1)+(n^2)+.....+(n^k-1)+(n^k)
{
    if(k==0)
        return a;

    return a*power(n,k)+geo_sum(a,n,k-1);
}

int main()
{
    cout<<geo_sum(2,3,4);

    cout<<endl;
    return 0;
}
