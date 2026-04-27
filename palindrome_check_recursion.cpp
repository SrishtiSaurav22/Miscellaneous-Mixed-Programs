#include<bits/stdc++.h>
#include<string.h>

using namespace std;

bool palindrome_check(string s, int start, int stop)
{
    if(start>=stop)
        return true;

    if(s[start]!=s[stop])
        return false;

    return palindrome_check(s,start+1,stop-1);
}

int main()
{
    string s1="abba", s2="abcba";

    /*
     You have store the positions in start & stop,
     so you need to enter 0 and string_name.length()-1
    */

    if(palindrome_check(s1,0,s1.length()-1))
        cout<<s1<<" is a palindrome!"<<endl;

    if(palindrome_check(s2,0,s2.length()-1))
        cout<<s2<<" is a palindrome!"<<endl;

    cout<<endl;
    return 0;
}
