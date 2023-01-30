#include<bits/stdc++.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

bool check_ab(string str, int i)
{
    if(str.length()==0)
        return false;

    // what is the base case?
    if(i==str.length())
        return true;

    if(str[i]=='a')
    {
        if(str[i+1]=='a' || (str[i+1]=='b' && str[i+2]=='b') || str[i+1]=='\0')
            return check_ab(str,i+1);

        else
            return false;
    }

    else if(str[i]=='b' && str[i+1]=='b')
    {
        if(str[i+2]=='a' || str[i+2]=='\0')
            return check_ab(str,i+2);

        else
            return false;
    }

    else
        return false;
}

int main()
{
    string str="abbaaab";

    cout<<check_ab(str,0)<<endl;

    cout<<endl;
    return 0;
}

