#include<bits/stdc++.h>
#include<math.h>

using namespace std;

void debi(int n)
{
    int nn=n, s=0, c=0;

    while(nn!=0)
    {
        s=s+((nn%2)*pow(10,c));
        nn=nn/2;
        c++;
    }
    cout<<"\n"<<s;
}

void bide(int n)
{
    int nn=n, s=0,c=0;

    while(nn!=0)
    {
        s=s+((nn%10)*pow(2,c));
        nn=nn/10;
        c++;
    }
    cout<<"\n"<<s;
}


int main()
{
    int base,n;

    cout<<"Enter the base of the number: ";
    enter:
    cin>>base;

    switch(base)
    {
    case 2:
        cout<<"Enter the number: ";
        cin>>n;

        bide(n);
        break;

    case 10:
        cout<<"Enter the number: ";
        cin>>n;

        debi(n);
        break;

    default:
        cout<<"Invalid base. Re-enter the base: ";
        goto enter;
    }

    return 0;
}
