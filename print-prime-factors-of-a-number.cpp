#include<bits/stdc++.h>

using namespace std;

/*
Below is a further optimized implementation of a iterative function to check if an input number is prime 

Time complexity:  theta( sq. root(n) ) 

Space complexity: theta(1)   
Auxiliary space:  theta(1)    
*/

bool prime_number_check_further_optimized(int n)
{
    if(n==1)
        return false;
        // 1 is neither prime nor composite

    if(n==2 || n==3)
        return true;

    if(n%2==0 || n%3==0)
        return false;

    for(int i=5;i*i<=n;i=i+6)
    {
        if( n%i==0 || n%(i+2)==0 )
            return false;
    }
    
    return true;
}

/*
Below is a naive implementation of a iterative function to print all the prime factors of an input number

Time complexity:   

Space complexity: theta(1)   
Auxiliary space:  theta(1)
*/

void print_prime_factors_naive(int N)
{
    if(N==1)
    {
        cout<<"1 does not have any prime factors; in fact it itself isn't prime or composite!\n";
        return;
    }
    
    cout<<"Prime factors of "<<N<<" are:\n";
    
    int not_prime=0, n=N;

    start:

    while(n!=0 && n%2==0)
    {
        ++not_prime;
        cout<<"2 ";
        n=n/2;
    }

    while(n!=0 && n%3==0)
    {
        ++not_prime;
        cout<<"3 ";
        n=n/3;
    }

    while(n!=0 && n%5==0)
    {
        ++not_prime;
        cout<<"5 ";
        n=n/5;
    }

    while(n!=0 && n%7==0)
    {
        ++not_prime;
        cout<<"7 ";
        n=n/7;
    }

    while(n!=0 && n%11==0)
    {
        ++not_prime;
        cout<<"11 ";
        n=n/11;
    }
    
    while(n!=0 && n%13==0)
    {
        ++not_prime;
        cout<<"13 ";
        n=n/13;
    }

    int i=17, alt_incre=0;
    while(i<=n && n!=0 && n!=1)
    {
        i_check:

        if(i%5==0)  goto i_increment;
        if(i%7==0)  goto i_increment;
        if(i%11==0) goto i_increment;
        if(i%13==0) goto i_increment;

        if(i>=199)
            if( prime_number_check_further_optimized(i)==false )
            {
                alt_incre=(alt_incre==0)?1:0;
                goto i_increment;
            } 

        while(n%i==0)
        {
            ++not_prime;
            cout<<i<<" ";
            n=n/i;
            goto start;
        }

       i_increment:

       if(alt_incre==0)
       {
            i=i+2;
            alt_incre=(alt_incre==0)?1:0;
       }

       else
       {
            i=i+4;
            alt_incre=(alt_incre==0)?1:0; 
       } 
    }

    if(not_prime==0)
    {
        cout<<"\nLooks like "<<N<<" is a prime number so it's only prime factor is itself!\n";
        cout<<N<<" ";
    }     
}

/*
Below is a optimized implementation of a iterative function to print all the prime factors of an input number

Time complexity:   

Space complexity: theta(1)   
Auxiliary space:  theta(1)

NOTE:
A very common misconception about the 6k ± 1 method is that we think that "numbers of the form 6k±1 are not always prime, 
so won’t composite numbers end up getting printed?"

No — composite numbers will never be printed a number i is only printed if n is divisible by i. BUT, an interesting fact
about prime factorization is that if a composite number divides n, then its prime factors must already divide n first.
And those (the prime factors) are removed first so a composite will never get printed.

It is not necessary to check the whether i is prime or not because when we use the 6k±1 form for i, we are NOT assuming 
that all i will be prime. We are only checking n's divisibility by i. Composite values of i will simply fail divisibility 
test, and thus, not get printed.
*/

void print_prime_factors_optimized(int N)
{
    if(N==1)
    {
        cout<<"1 does not have any prime factors; in fact it itself isn't prime or composite!\n";
        return;
    }
    
    cout<<"\nPrime factors of "<<N<<":\n";

    int n=N;

    while(n%2==0)
    {
        cout<<"2 ";
        n=n/2;
    }

    while(n%3==0)
    {
        cout<<"3 ";
        n=n/3;
    }

    for(int i=5;i*i<=n;i=i+6)
    {
        while(n%i==0)
        {
            cout<<i<<" ";
            n=n/i;
        }

        while(n%(i+2)==0)
        {
            cout<<(i+2)<<" ";
            n=n/(i+2);
        }
    }

    if(n>3)
        cout<<n<<" ";
}

int main()
{
    int N=0;
    
    cout<<"Enter a number: ";
    cin>>N;

    print_prime_factors_optimized(N);

    cout<<endl;
    return 0;
}