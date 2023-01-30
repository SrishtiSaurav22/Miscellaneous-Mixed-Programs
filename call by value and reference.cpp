#include<bits/stdc++.h>

using namespace std;

void incremenet1(int n)
{
    n++;
}

void incremenet2(int& n)
{
    n++;
}

int decrement1(int n)
{
    n--;
    return n;
}

// bad practice
int& decrement2(int n) //  there can be int* too instead of int&
{
    n--;
    return n;
}

int main()
{
    int n=10;

    cout<<"Before increment: "<<n<<endl;

    incremenet1(n);
    cout<<"After increment 1: "<<n<<endl;

    incremenet2(n);
    cout<<"After increment 2: "<<n<<endl;

    n=decrement1(n);
    cout<<"After decrement 1: "<<n<<endl;

    //n=decrement2(n);
    int &ref_n=decrement2(n);
    cout<<"After decrement 2: "<<ref_n<<endl;

    cout<<endl;
    return 0;
}
