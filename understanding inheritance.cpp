#include<bits/stdc++.h>

using namespace std;

class class1
{
    protected:

    int c1;

    public:

    class1()
    {}

    class1(int c1)
    {
        this->c1=c1;
    }

    void print()
    {
        cout<<"c1: "<<c1;
    }
};

class class2:protected class1
{
    int c2;

    public:

    class2()
    {}

    class2(int c2)
    {
        this->c2=c2;
    }

    void print()
    {
        cout<<"c1: "<<c1;
        cout<<"c2: "<<c2;
    }
};

int main()
{
    class1 C1(1);
    class2 C2(2);

    /*
     Why do I have to refer to the base class's customer
     in the derived class constructor definition, in 'shop code.cpp',
     but not here?
    */

    C1.print();
    cout<<endl;
    C2.print();

    cout<<endl;
    return 0;
}

/*
     Writing this I get the error:
     'class vehicle' has no member named 'print'

     So initializing a base class object with its derived class object
     will not call the derived class functions
    */
