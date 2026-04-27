#include<bits/stdc++.h>

using namespace std;

class rand_class
{
    int i;
    string s;

    public:

    rand_class()
    {
        i=0;
        s="n\a";
    }

    rand_class(int i ,string s)
    {
        this->i=i;
        this->s=s;
    }

    rand_class(rand_class &rc)
    // a copy contructor cannot be pass by value
    {
        i=rc.i;
        s=rc.s;
    }

    void print_rc()
    {
        cout<<"i= "<<i<<endl;
        cout<<"s= "<<s<<endl<<endl;
    }
};

int main()
{
    rand_class rc1;
    rand_class rc2(1,"abc");
    rand_class rc3(2,"xyz");
    rand_class rc4(rc3);

    cout<<"rc1:\n";
    rc1.print_rc();
    cout<<"rc2:\n";
    rc2.print_rc();
    cout<<"rc3:\n";
    rc3.print_rc();
    cout<<"rc4:\n";
    rc4.print_rc();

    cout<<endl;
    return 0;
}

