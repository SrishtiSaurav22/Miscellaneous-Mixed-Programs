//this is incomplete

#include<bits/stdc++.h>

using namespace std;

int rope_cutting(int n, int a, int b, int c)
{
    if(n==0) return 0;

    if (n<0) return -1;

    int p,q,r;
    p=max( rope_cutting(n-a,a,b,c) , rope_cutting(n-b,a,b,c) );
    q=max( rope_cutting(n-b,a,b,c) , rope_cutting(n-c,a,b,c) );
    r=max( rope_cutting(n-a,a,b,c) , rope_cutting(n-c,a,b,c) );

    int res=max( max(p,q) , );

    if(res==-1) return -1;

    return res+1;
}

int main()
{
    return 0;
}
