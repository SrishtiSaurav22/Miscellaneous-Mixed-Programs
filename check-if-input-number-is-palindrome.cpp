#include<bits/stdc++.h>

using namespace std;

/*
Below is a function to 

Time complexity:  theta(log(n))  (log-base: 10)
OR
Time complexity:  theta(d)       (where d is the number of digits in the input n)
 
Space complexity: theta(1)       (fixed number of total variables, input: n, extra: num, rev, d)
Auxiliary space:  theta(1)       (fixed number of extra variables: num, rev, d)
*/

bool palindrome_check(int n)
{
    if((n/10) == 0) // input is a single digit number
        return true; // single digit numbers are always palindromes

    int num=n, rev=0; 
    // num will undergo computations instead of the original input n which we need for comparison with rev later

    while(num>0)
    {
        int d=num%10; // take out the last digit from n
        rev=(rev*10)+d; // add the last digit to the reversed number rev
        num=num/10; // remove the last digit from n
    }

    if(rev==n)
        return true;

    return false;
}

int main()
{
    int n=0;

    input:
    cout<<"\n\nPlease enter a whole number: ";
    cin>>n;

    if(n<0) // ask the user to re-enter a whole number
        goto input;

    cout<<"\nAh, "<<n<<" is ";

    if(palindrome_check(n)==true)
        cout<<"PALINDROME\n\n";

    else
        cout<<"NOT A PALINDROME\n\n";

    return 0;
}