/*
 Here the functions can be members of the stack.
 Or they can call the stack by value (for access) or by reference or pointer (for modification).
*/

#include<bits/stdc++.h>

using namespace std;

struct STUFF
{
    int i;
    string s;

    STUFF(int i, string s)
{
    this->i=i;
    this->s.assign(s);
}
};

void assigning(STUFF *stuff /* *stuff */, int i, string s) //remove the & and see what happens
{
    stuff->i=i; /* stuff->i=i */
    stuff->s.assign(s); /* stuff->s.assign(s) */
}

int main()
{
    STUFF stuff(-1,"C'EST MOINS DE ZERO!");
    cout<<"\n"<<stuff.i<<"\t"<<stuff.s;

    assigning(*stuff,0,"N/A");
    cout<<"\n"<<stuff.i<<"\t"<<stuff.s;

    cout<<"\n\nChanging these two:\n";
    stuff.i++;
    stuff.s.assign("Bienvenue");
    cout<<"\n"<<stuff.i<<"\t"<<stuff.s;

    cout<<"\n";
    return 0;
}
