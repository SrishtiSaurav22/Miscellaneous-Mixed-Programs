#include<bits/stdc++.h>
// #include"factorial-of-a-number.cpp"
/*
I can't simply include the above code file because I'm getting the following error:

    redefinition of 'int main()'
*/

using namespace std;

/*
The below function will potentially cause an integer overflow when the product of the multiplication operation being performed very quickly 
exceedes the max value that "int" can store.

For a typical 32 bit signed integer:
Max value=2,147,483,647

In C/C++, signed integer overflow is undefined behaviour, so the result may become negative or garbage.
=> Program may still run but give incorrect results

So:
12! = 479001600   (fits)
13! = 6227020800  (exceeds int limit)

Now, we could use another data type like "long long", but it also has its limitations:

20! fits in long long
21! overflows
*/

/*
Below is an iterative function to calculate the factorial of a whole number 

Time complexity:  theta(n) 

Space complexity: theta(1)      (due to fixed number of total variables (input n, extra res), independent of input size)
Auxiliary space:  theta(1)      (due to fixed number of extra variables (res), independent of input size)
*/

int factorial_i(int n)
{
    int res=1;

    for(int i=2; i<=n; i++)
    {
        res=res*i;
    }

    return res;
}

/*
Below is an iterative function to calculate the number of trailing zeroes in the factorial of a whole number 

Time complexity:  theta(n) + theta(log n) => theta(n) 

Space complexity: theta(1)      (fixed number of total variables)
Auxiliary space:  theta(1)      (fixed number of extra variables)
*/

int calc_trailing_zeroes_in_fact(int n)
{
    int N=factorial_i(n), num=0;

    while(N%10==0)
    {
        ++num;
        N=N/10;
    }

    return num;
}

/*
Below is an optimized version of the iterative function to calculate the number of trailing zeroes in the factorial of a whole number 

Time complexity:  theta(n)  

Space complexity: theta(1)      (fixed number of total variables)
Auxiliary space:  theta(1)      (fixed number of extra variables)
*/

int calc_trailing_zeroes_in_fact_optimized(int n)
{
    if(n<5)
        return 0;

    int count=0;

    for(int i=5;i<=n;i+=5)
    {
        int N=i;
        while(N%5==0)
        {
            ++count;
            N/=5;
        }
    }

    return count;
}

/*
Below is an even further optimized version of the iterative function to calculate the number of trailing zeroes in the factorial of a 
whole number 

Time complexity:  theta(log n)

Space complexity: theta(1)      (fixed number of total variables)
Auxiliary space:  theta(1)      (fixed number of extra variables)
*/

int calc_trailing_zeroes_in_fact_optimized_further(int n)
{
    int res=0;

    for(int i=5;i<=n;i*=5)
        res=res+(n/i);

    return res;
}

int main()
{
    int n;

    cout<<"Enter a whole number: ";
    cin>>n;

    cout<<"\nThe number of trailing zeroes in the factorial of "<<n<<" is "<<calc_trailing_zeroes_in_fact_optimized(n);

    return 0;
}