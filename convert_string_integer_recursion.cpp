// also handles negative numbers

#include<bits/stdc++.h>
#include<string.h>

using namespace std;

int convert_string_integer(string str, int i, int n, int neg)
{
    if(str[0]=='-')
    {
        neg=1;
        str=str.substr(1);
    }

    if(i==str.length() && neg==1)
        return n*(-1);

    if(i==str.length())
        return n;

    char ch=str[i];
    int ch_int=ch-48;
    n=(n*10)+ch_int;

    return convert_string_integer(str,i+1,n,neg);
}

int main()
{
    string s="-16";

    /*
     Converting character to integer:

     char ch='1';
     int ch_int=ch-48; // warning multiple character constant
    */

    cout<<convert_string_integer(s,0,0,0)+1<<endl;
    // the +1 is for checking if the string is really an integer

    cout<<endl;
    return 0;
}
