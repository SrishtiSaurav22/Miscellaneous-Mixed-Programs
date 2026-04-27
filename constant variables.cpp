#include<bits/stdc++.h>

using namespace std;

int main()
{
    // you have initialize a const variable along with the declaration
    const int i=10;
    // int const i=10; also valid
    // i++; is not allowed

    int m=20;
    // int &n=m;
    const int &n=m;

    // Here, we can see that the storage is not constant the path is.
    cout<<"Before increment:\nm: "<<m<<"\tn: "<<n<<endl;
    m++; // we can't do n++;
    cout<<"After increment:\nm: "<<m<<"\tn: "<<n<<endl;

    // constant path constant storage
    const int a=5;
    const int &b=a;

    cout<<endl;
    return 0;
}
