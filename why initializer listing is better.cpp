#include<bits/stdc++.h>

using namespace std;

class Test
{
    public:
        Test()
        {
            cout<<"Default Constructor\n";
        }

        Test(int n)
        {
            cout<<"Parameterized Constructor with T value as 10\n";
        }
};

class Main
{
    public:
        Main()
        {
            Test t=Test(10);
        }
};

int main()
{
    Main M;
    cout<<"\nWell...well....well....";
    return 0;
}
