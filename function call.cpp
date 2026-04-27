#include<bits/stdc++.h>

using namespace std;

//you don't need to preserve n as in the function call only a copy of the result will be returned
//the actual n won't be changed
//don't create unnecessary variables

int firstDigit(int n)
{
    while((n/10)!=0)
        n=n/10;

return n;
}

int main()
{
    int n;
    cout<<"Enter n=";
    cin>>n;

    cout<<"\n"<<firstDigit(n);
    cout<<"\nn="<<n;

    return 0;
}
