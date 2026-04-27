#include<bits/stdc++.h>

using namespace std;

void increment(int& n) // notice the int and & together signifying the 'reference type variable'
{
    /*
     Here, the parameter type is a reference variable
     so it will become a reference variable to i,
     rather than becoming just a copy of it.
    */

    n--;
}

int main()
{
    int i=10;
    int &j=i;

    /*
     int &j;
     j=i;

     This will throw the error saying declaration of reference variable requires an initializer.
    */

    cout<<"i="<<i<<"\tj="<<j<<endl;

    int k=9;
    j=k;

    cout<<"i="<<i<<"\tj="<<j<<endl;

    increment(i);

    cout<<"i="<<i<<"\tj="<<j;

    cout<<endl;
    return 0;
}
