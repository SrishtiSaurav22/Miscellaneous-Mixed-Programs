#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=0;

    //if(n++) would lead to "B" as the condition would be checked before incrementing n, and in the next branch, n=1 (after increment)
    //would be checked before decrementing it.

    if(++n) cout<<"A"; //here n is incremented then the expression would be evaluated so output is "A"
    //similarly, output is "A" for if(n=n+1)

    else if(n--) cout<<"\nB";


    else cout<<"\nC";


    cout<<"\n"<<n;
}
