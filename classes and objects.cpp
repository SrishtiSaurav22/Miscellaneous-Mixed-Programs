#include<bits/stdc++.h>

using namespace std;

/*
class point
{
    int x;
    int y;

    public:

    // we need a copy constructor
    // but we don't need to define it

    point(int x, int y)
    {
        this->x=x;
        this->y=y;
    }

    void print_point()
    {
        cout<<"x coordinate: "<<x<<endl;
        cout<<"y coordinate: "<<y<<endl;
    }
};

void swap_points(point &p1, point &p2)
{
    point temp(p1);

    p1=p2;
    p2=temp;
}

class line
{
    point p1;
    point p2;

};
*/

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
    /*
    point p1(1,2), p2(8,9);

    cout<<"Before swapping:\n";
    cout<<"p1:\n";
    p1.print_point();
    cout<<endl;
    cout<<"p2:\n";
    p2.print_point();
    cout<<endl;

    swap_points(p1,p2);

    cout<<"After swapping:\n";
    cout<<"p1:\n";
    p1.print_point();
    cout<<endl;
    cout<<"p2:\n";
    p2.print_point();
    cout<<endl;
    */

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
