#include<bits/stdc++.h>

using namespace std;

int multiplication(int num, int no_of_times)
{
    if(no_of_times==1)
        return num;

    return num+multiplication(num,no_of_times-1);
}

int count_zeroes(int num)
{
    int c=0;

    while(num!=0)
    {
        if(num%10==0)
            c++;
        num=num/10;
    }

    return c;
}

int geometric_sum(int first_term, int no_of_terms, int geometric_ratio)
{
    static int c=0;

    if(c==no_of_terms)
        return first_term*sum;

    return geometric_ratio*
}

bool palindrome_check(int n)
{

}

int main()
{
    cout<<"Multiplication:\n"<<multiplication(7,6)<<endl;
    cout<<"No. of zeroes in 3002007 are: "<<count_zeroes(3002007)<<endl;

    return 0;
}
