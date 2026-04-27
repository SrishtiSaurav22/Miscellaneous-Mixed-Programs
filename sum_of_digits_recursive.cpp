#include<bits/stdc++.h>

using namespace std;

int sum_digits_recursive(int n)
{
    if(n==0)
        return 0;

    return (n%10)+sum_digits_recursive(n/10);
}

int main()
{
    int n=123;

    cout<<"Sum of the digits of "<<n<<" is: "<<sum_digits_recursive(n)<<endl;

    cout<<endl;
    return 0;
}
