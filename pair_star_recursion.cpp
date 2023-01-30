#include<bits/stdc++.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

string pair_star(string str, int i)
{
    if(i==str.length())
        return str;

    if(str[i]==str[i+1])
    {
        string left=str.substr(0,i+1); // here i+1 denotes the number of letters in str
        string right=str.substr(i+1); // here i+1 denotes a position in str

        str=left+"*"+right;
    }

    return pair_star(str,i+1);
    // i+1 because we have * there which will not match with any letter in the string
}

int main()
{
    string str="aaa";

    cout<<pair_star(str,0)<<endl;

    cout<<endl;
    return 0;
}
