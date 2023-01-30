//can this code be simplified?

#include<bits/stdc++.h>

using namespace std;

int dc(int n) //digit check
{
    if(n>=48 && n<=57) return 1;
    else return 0;
}

int findSum(string str) //find the sum of the numbers, not the digits
{
    int ss=0, sm=0, i, t;

    str="."+str+".";
    //in case a digit is present at the first and last location where i will not stop

    for( i=1 ; i<=str.length()-1 ; i++)
    {
        t=str[i]-'0'; // to do this: '6' -> 6
        //t is an integer

        //for single digit numbers
        if( dc(str[i-1])==0 && dc(str[i])==1 && dc(str[i+1])==0 )
        ss=ss+t;

        //for multi digit numbers
        else
        {
            if( dc(str[i])==1 && dc(str[i+1])==1 )
            sm=(sm*10) + t;

            else if( dc(str[i])==1 ) //the multi-digit number ends st this str[i]
            {
                sm=(sm*10) + t;
                ss=ss+sm;
                sm=0;
            }
        }
    }
    return ss;
}

int main()
{
    string s;

    cout<<"Enter a string containing numbers along with other characters in it: ";
    cin>>s;

    cout<<"\nSum of the numbers (not digits) in the string: "<<findSum(s);

    return 0;
}
