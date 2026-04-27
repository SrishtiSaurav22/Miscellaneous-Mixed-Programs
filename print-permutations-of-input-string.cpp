#include<bits/stdc++.h>

using namespace std;

/*
Below is 

Time complexity:  theta(1)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
void swap(char &a, char &b)
{
    char c=a;
    a=b;
    b=c;
}

/*
Below is 

Time complexity:  theta(n * n!)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
void print_permutations(string str, int i=0)
{
    if(i==str.length()-1)
    {
        cout<<str<<" ";
        return;
    }

    for(int j=i;j<str.length();j++)
    {
        swap(str[i], str[j]);
        print_permutations(str,i+1);
        swap(str[j], str[i]);
    }
}

int main()
{
    string str="ABCD";

    print_permutations(str);

    return 0;
}