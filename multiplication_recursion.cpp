#include<bits/stdc++.h>

using namespace std;

int multiply(int a, int b)
{
    if(b==0)
        return 0;

    // multiplication is repeated addition
    return a+multiply(a,b-1);
}

int main()
{
    int a=5,b=6;

    cout<<"Product of "<<a<<" and "<<b<<" is "<<multiply(a,b);

    cout<<endl;
    return 0;
}
