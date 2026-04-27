// Reference code for understanding inheritance among classes

#include<bits/stdc++.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

/*
 parent class pointer can point to child class objects.
 child class will inherit all the properties of the parent, including functions
 but without its own attributes.
*/

class A
{
    int a;

    public:

    A()
    {}

    A(int a)
    {
        this->a=a;
    }

    void enter_a(int a)
    {
        this->a=a;
    }

    int print_a()
    {
        return a;
    }

};

class B:public A
{
    int b;

    public:

    B()
    {}

    B(int b)
    {
        this->b=b;
    }

    void enter_b(int b)
    {
        this->b=b;
    }

    int print_b()
    {
        return b;
    }
};

int main()
{
    A a1(1);
    B b1(2);

    cout<<"a is "<<a1.print_a()<<"\n"<<"b is "<<b1.print_b()<<"\n";

    b1.enter_a(3);

    /*
     in the above line, you have changed the parameter a of object b1,
     not a1, so a1's a will have no change in it.
    */

    cout<<"a is "<<b1.print_a()<<"\n"<<"b is "<<b1.print_b()<<"\n";

    cout<<endl<<endl;
    return 0;
}

