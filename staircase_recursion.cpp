#include<bits/stdc++.h>

using namespace std;

int ways_count(int n, int s) // w, s refer to ways and steps resp.
{
    if(s>=n)
        return 0;

    return ways_count(n-s,1)+ways_count(n-s,2)+ways_count(n-s,3)+1;
    // +1 is for counting every way considered, otherwise you'll just get zero as the answer
}

int total_ways_count(int n)
{
    return ways_count(n,1)+ways_count(n,2)+ways_count(n,3);
}

int main()
{
    int n=4;

    cout<<total_ways_count(n);

    cout<<endl;
    return 0;
}
