#include<bits/stdc++.h>

using namespace std;

/*
functions to implement using recursion:

fibonacci
factorial
numbers from 1 to n (with and without tail recursive elimination)
numbers from n to 1 (with and without tail recursive elimination)
*/

int fibonacci(int n) //returns nth fibonacci number
{
    if(n==0 || n==1)
        return 0;

    else if(n==2)
        return 1;

    return fibonacci(n-1)+fibonacci(n-2);
}

int factorial(int n) //returns value of n!
{
    if(n==0 || n==1)
        return 1;

    return n*factorial(n-1);
}

void print_1_to_n(int n)
{
    if(n==0)
        return;

    print_1_to_n(n-1);
    cout<<n<<" ";
}

void print_n_to_1(int n)
{
    if(n==0)
        return;

    cout<<n<<" ";
    print_n_to_1(--n);
}

int sum_n_natural_num(int n)
{
    if(n==1)
        return 1;

    return n+sum_n_natural_num(n-1);
}

bool palindrome_check(string &s /* passed by reference for optimisation */, int begi, int endi)
{
    if(s[begi]!=s[endi])
        return false;

    if(begi==endi /* for odd length string */ || begi>endi /* for even length string */ )
        return true;

    ++begi; --endi;
    return palindrome_check(s, begi, endi);
}

int sum_of_digits(int n)
//it is better to do this iteratively due to no overhead (execution time less than switching time) of function calls
{
    if(n==0)
        return 0;

    return n%10+sum_of_digits(n/10);
}

int power(int n, int x)
{
    if(x==1)
        return n;

    return n*power(n,x-1);
}

int nCr(int n, int r)
{
    if(r==1)
    return n;

    return factorial(n) / ( factorial(n-r) * factorial(r) );
}

void print_array(int a[], int n)
{
    if(n==0) //why not -1 ?
        return;

    print_array(a,n-1);
    cout<<a[n-1]<<" "; //and a[n] ?
}

int main()
{
    int n, x, r, a[]={1,2,3,4,5,6,7,8,9};
    string s;

    cout<<"Displaying an array:\n";
    print_array(a,9);

    cout<<"\n\nEnter n=";
    cin>>n;

    cout<<"\nnth Fibonacci number: "<<fibonacci(n);
    cout<<"\n\nFactorial of n: "<<factorial(n);

    cout<<"\n\nPrinting numbers from 1 to n:\n";
    print_1_to_n(n);

    cout<<"\n\nPrinting numbers from n to 1\n";
    print_n_to_1(n);

    cout<<"\n\nSum of n natural numbers: "<<sum_n_natural_num(n);

    cout<<"\n\nPalindrome check time!\nEnter a string: ";
    cin>>s;

    if(palindrome_check(s,0,s.length()-1)==true)
        cout<<"\nYes! This string is a palindrome!";

    else
        cout<<"No!. This string is not a Palindrome!";

    cout<<"\n\nEnter a number (with multiple digits): ";
    cin>>n;

    cout<<"Sum of digits of "<<n<<": "<<sum_of_digits(n);

    cout<<"\n\nEnter n=";
    cin>>n;
    cout<<"Enter x=";
    cin>>x;
    cout<<n<<" raised to the power of "<<x<<" : "<<power(n,x);

    cout<<"\n\nCalculating combinations:\nEnter n=";
    cin>>n;
    cout<<"Enter r=";
    cin>>r;

    cout<<"nCr : "<<nCr(n,r);

    cout<<"\n";
    return 0;
}
