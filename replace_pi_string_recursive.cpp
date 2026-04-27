#include<bits/stdc++.h>
#include<string.h>

using namespace std;

// This function is not working
// How do I fix it?

/*
void replace_pi(string &s, int i)
{
    // you can check if (i+1)==s.length()
    // but then the length of the string
    // would be calculated at every recursive
    // call, that's not efficient.


    if(s[i+1]=='\0')
        return;

    if(s[i]=='p' && s[i+1]=='i')
    {
       s=s.replace(i,2,"3.14");
       replace_pi(s,i+1);
    }
}
*/

void replace_pi(string &s, int i)
{
    if(s[i+1]=='\0')
        return;

    else if(s[i]=='p' && s[i+1]=='i')
    {
        // parts of the new string
        string left=s.substr(0,i);
        string mid="3.14";
        string right="";

        if(s[i+2]!='\0')
            right=s.substr(i+2);

        s=left+mid+right;
    }

    replace_pi(s,i+1);
}


int main()
{
    string s="xypiztbpimno";

    cout<<"Before: "<<s;
    replace_pi(s,0);
    cout<<"\nAfter: "<<s;

    cout<<endl;
    return 0;
}
