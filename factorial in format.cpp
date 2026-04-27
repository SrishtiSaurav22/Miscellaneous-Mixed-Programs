#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,p=1,i;

    cout<<"Enter a number: ";
    cin>>n;

    cout<<"\nFactorial of "<<n<<" is:\n"<<n<<"! = ";
    for(i=n;i>=1;i--)
    {
        p=p*i;

        if(i==1)
            cout<<i<<" = "<<p;

        else
            cout<<i<<" * ";
    }

    // I could have used /b to remove the last star in the output but it is not working here

}
