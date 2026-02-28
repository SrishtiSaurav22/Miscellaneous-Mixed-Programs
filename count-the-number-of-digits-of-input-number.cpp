#include<bits/stdc++.h>

using namespace std;

/*
Below is a function to count the number of digits in an integer. 

Time complexity:  theta(log(n)) (due to n being divided by 10 until it is 0, so the log-base would be 10)
OR
Time complexity:  theta(d)      (where d is the number of digits in the input n)

Space complexity: theta(1)      (due to fixed number of total variables (input n, extra d), independent of input size)
Auxiliary space:  theta(1)      (due to fixed number of extra variables (d), independent of input size)
*/

int count_digits(int n)
{
    int d=0; // d as in digits

    if(n<0) // if n is a negative integer
        n=n*(-1);

    if(n==0)
        return 1;

    while (n>0)
    {
        d++;
        n=n/10;
    }

    return d;
}

int main ()
{
    int num=0;

    cout<<"Enter an integer: ";
    cin>>num;

    cout<<"\nNumber of digits in "<<num<<" are "<<count_digits(num)<<" !\n\n";

    return 0;
}