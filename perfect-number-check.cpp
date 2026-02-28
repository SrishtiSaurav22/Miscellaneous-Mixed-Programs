#include<bits/stdc++.h>

using namespace std;

/*
Below is an iterative function to check whether the given input natural number is a perfect number

Time complexity:  theta(n) 

Space complexity: theta(1)   
Auxiliary space:  theta(1)
*/

bool perfect_number_check(int n)
{
    int sum=0;

    for(int i=1; i<=(n/2); i++)
    {
        if(n%i==0)
            sum=sum+i;
    }

    if(sum==n)
        return true;
    
    else
        return false;
}

int main()
{
    int n;

    cout<<"Enter a natural number: ";
    cin>>n;

    if(perfect_number_check(n)==true)
        cout<<"\n"<<n<<" is a perfect number!\n";

    else
        cout<<"\n"<<n<<" is NOT a perfect number!\n";

    return 0;
}