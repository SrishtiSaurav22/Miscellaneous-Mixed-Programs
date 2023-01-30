#include<bits/stdc++.h>

using namespace std;

class A
{
    static int a;

    public:

    A()
    {
        a=0;
    }

    A(int a)
    {
        this->a=a;
    }

    static void set_a(int n)
    {
         a=n;
    }

    void print()
    {
        cout<<"a="<<a<<endl;
    }
};

int main()
{
    A A1(5);

    A1.print();

    A::set_a(6);

    A1.print();

    cout<<endl;
    return 0;
}
