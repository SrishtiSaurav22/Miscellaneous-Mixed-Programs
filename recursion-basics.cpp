#include<bits/stdc++.h>

using namespace std;

/*
Below is a function to print numbers from 1 to n

Time complexity:   theta(n)

Space complexity:  theta(n)
Auxiliary space:   theta(n)
*/

void print_1_to_n(int n)
{
    if(n==0)
        return;

    print_1_to_n(n-1);
    cout<<n<<" ";
}

/*
Below is a function to print numbers from n to 1

Time complexity:   theta(n)

Space complexity:  theta(n)
Auxiliary space:   theta(n)
*/

void print_n_to_1(int n)
{
    if(n==0)
        return;

    cout<<n<<" ";
    print_n_to_1(n-1);
}

/*
Below is a function to get the sum of n natural numbers

Time complexity:   theta(n)

Space complexity:  theta(n)
Auxiliary space:   theta(n)
*/

int natural_num_sum(int n)
{
    if(n==0)
        return 0;
    
    return n + natural_num_sum(n-1);
}

/*
Below is a function to get the sum of n natural numbers using tail recursion

Time complexity:    theta(n)

Space complexity:  theta(n) (can be theta(1) is TCO works, but it's not guaranteed so we take theta(n) as the answer)
Auxiliary space:   theta(n) (can be theta(1) is TCO works, but it's not guaranteed so we take theta(n) as the answer)
*/

int natural_num_sum_tail_recursion(int n, int sum=0)
{
    if(n==0)
        return sum;

    return natural_num_sum_tail_recursion(n-1, sum + n);
}

/*
Below is a iterative function to check if a given input string is a palindrome or not

Time complexity:   theta(size_of_string)

Space complexity:  theta(1)
Auxiliary space:   theta(1)
*/

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

/*
Below is a recursive function to check if a given input string is a palindrome or not

Time complexity:   theta(size_of_string)

Space complexity:  theta(size_of_string)
Auxiliary space:   theta(size_of_string)
*/

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

/*
Below is a iterative function to get the sum of the digits of an input number

Time complexity:   theta(log n)

Space complexity:  theta(1)
Auxiliary space:   theta(1)
*/

int sum_of_digits_iterative(int n)
{
    int N=n, sum=0;

    while(N>0)
    {
        sum=sum+(N%10);
        N=N/10;
    }

    return sum;
}

/*
Below is a recursive function to get the sum of the digits of an input number

Time complexity:   theta(log n)

Space complexity:  theta(log n)
Auxiliary space:   theta(log n)

*/

int sum_of_digits_recursive(int n, int sum=0)
{
    if(n==0)
        return sum;

    return sum_of_digits_recursive(n/10, sum+(n%10));
}

int max(int a, int b, int c)
{
    if(a>=b && a>=c)
        return a;
    
    if(b>=a && b>=c)
        return b;
    
    if(c>=a && c>=b)
        return c;

    return -1;
}

int rope_cutting(int n, int a, int b, int c)
{
    if(n==0)
        return 0;

    if(n<0)
        return -1;

    int cut1=rope_cutting(n-a,a,b,c);
    int cut2=rope_cutting(n-b,a,b,c);
    int cut3=rope_cutting(n-c,a,b,c);
    /*
    Here, cut1 means:

    => “If I make a cut of length a right now, how many additional pieces can I make from the remaining rope?”
    => It is NOT the total pieces.
    => It is the number of pieces from the remaining rope.
    => cut1 does NOT include the current cut which is why, later in the code, we do  (max_val + 1)
    => If cut1 = -1 it means that cutting "a" first leads to an impossible path. So that branch is discarded later.
    => cut1 represents the answer to the subproblem created by choosing cut "a".
    
    The function is basically saying:
    "Try all three first moves. See which leads to the best outcome."
    */

    int max_val=max(cut1,cut2,cut3);

    return (max_val==-1)?-1:(max_val+1);
    /*
    Why (max+1)?

    Example: If cut1 = 3
    That means that if I cut "a" first, then the remaining rope can give 3 pieces.
    But one cut has already been made at this level.
    
    So total pieces = 1 (current cut) + 3 (recursive result) = 4
    */
}

int main()
{
    int n=8;

    cout<<natural_num_sum_tail_recursion(n);
    
    string str="abba";
    int size=str.size();

    cout<<"\nIs "<<str<<" a palindrome? "<<palindrome_check_recursive(str,0,size-1)<<endl;

    int N=123;

    cout<<"Sum of the digits of "<<N<<" is "<<sum_of_digits_recursive(N)<<endl;

    int num=23, a=12, b=9, c=11;
    cout<<"Rope cutting problem solution: "<<rope_cutting(num,a,b,c)<<endl;

    return 0;
}
