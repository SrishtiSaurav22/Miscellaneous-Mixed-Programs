#include<bits/stdc++.h>

using namespace std;

int count_zeroes(int n)
{
    if(n==0)
        return 0;

    if(n%10==0)
        return 1+count_zeroes(n/10);

    else
        return 0+count_zeroes(n/10);
}

int main()
{
    int n=10204000;

    cout<<"Number of zeroes in "<<n<<" is "<<count_zeroes(n);

    cout<<endl;
    return 0;
}
