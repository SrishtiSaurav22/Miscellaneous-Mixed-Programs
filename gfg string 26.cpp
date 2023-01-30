#include<bits/stdc++.h>

using namespace std;

void alphabets(char c1, char c2)
{
    string alpha="abcdefghijklmnopqrstuvwxyz";
    string::iterator it;

    int beg, end, c=0;

    for(it=alpha.begin(); it<=alpha.end() ; it++)
    {
        if(*it==c1) beg=c;

        c++;
    }
    end=c2-c1+1;

    cout<<alpha.substr(beg, end+1);
}

int main()
{
    char c1, c2;
    cout<<"Enter the starting and ending characters:\n";
    cin>>c1>>c2;

    alphabets(c1,c2);
}
