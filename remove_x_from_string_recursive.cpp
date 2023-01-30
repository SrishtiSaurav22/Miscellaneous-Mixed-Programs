#include<bits/stdc++.h>
#include<string.h>

using namespace std;

void remove_x(string &s, int pos)
{
    if(s[pos]=='\0')
        return;

    if(s[pos]=='x')
    {
        string left=s.substr(0,pos);
        string right=s.substr(pos+1);

        s=left+right;
        remove_x(s,pos);

        /*
         This is for multiple consecutive zeros.
         The pos value will not increase as the
         character which was supposed to be in 'pos+1' moves to 'pos'
         and we must check that new character.
        */
    }

    remove_x(s,pos+1);
}

int main()
{
    string s="abcxmxnxoxx123xpqr";

    cout<<"Before removal: "<<s<<endl;
    remove_x(s,0);
    cout<<"After removal: "<<s<<endl;;;;;
    // You can put as many semicolons as you want.
    // They're just empty instructions.

    cout<<endl;
    return 0;
}
