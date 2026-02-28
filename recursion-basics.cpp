#include<bits/stdc++.h>

using namespace std;

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
    print_n_to_1(n-1);
}

int natural_num_sum(int n)
{
    if(n==0)
        return 0;
    
    return n + natural_num_sum(n-1);
}

int natural_num_sum_tail_recursion(int n, int sum=0)
{
    if(n==0)
        return sum;

    return natural_num_sum_tail_recursion(n-1, sum + n);
}

string palindrome_check_iterative(string &str) 
// passing the string by ref to avoid multiple copy creation
{
    int size=str.size();

    int i,j;

    for(i=0,j=size-1;i<=(size/2);i++,j--)
    {
        // here the base cases' order is important
        if(i>=j)
            return "Yes.";

        if(str[i]!=str[j])
            return "No.";
    }

    return "Error";
}

string palindrome_check_recursive(string &str, int i, int j)
// passing the string by ref to avoid multiple copy creation during every recursive call
{
    // here the base cases' order is important
    if(i>=j)
        return "Yes.";
    
    if(str[i]!=str[j])
        return "No.";

    return palindrome_check_recursive(str,i+1,j-1);
}

int main()
{
    int n=8;

    cout<<natural_num_sum_tail_recursion(n);
    
    string str="abba";
    int size=str.size();

    cout<<"\nIs "<<str<<" a palindrome? "<<palindrome_check_recursive(str,0,size-1)<<endl;

    return 0;
}