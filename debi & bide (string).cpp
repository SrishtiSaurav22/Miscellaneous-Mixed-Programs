#include<bits/stdc++.h>

using namespace std;

int power(int A, int a)
{
    int i,p=1;
     for(i=0;i<a;i++)
        p=p*A;

     return p;
}

string debi(string st)
{
    int temp, s=0, i, nn, c, bi=0;

    for(i=0;i<st.length();i++)
    {
        temp=st[i]-'0';
        s=(s*10)+temp;
    }

    nn=s;
    c=0;
    while(nn!=0)
    {
        bi=bi+(nn%2)*power(10,c);
        nn=nn/2;
        c++;
    }

    return std::to_string(bi);
}

string bide(string st)
{
    int temp, s=0, i, nn, c, de=0;

    for(i=0;i<st.length();i++)
    {
        temp=st[i]-'0';
        s=(s*10)+temp;
    }

    nn=s;
    c=0;
    while(nn!=0)
    {
        de=de+(nn%10)*power(2,c);
        nn=nn/10;
        c++;
    }

    return std::to_string(de);
}

int main()
{
    string sd, sb;

    cout<<"Enter a string containing decimal numbers: ";
    cin>>sd;

    cout<<"Binary form of "<<sd<<" : "<<debi(sd);

    cout<<"\n\nEnter a string containing binary numbers: ";
    cin>>sb;

    cout<<"Decimal form of "<<sb<<" : "<<bide(sb);
    cout<<"\n";

    return 0;
}
