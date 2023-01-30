#include<bits/stdc++.h>

using namespace std;

class test
{
    public:
        test(int n)  {    cout<<"Object containing "<<n<<" created!";    }
        ~test()  {   cout<<"Object containing "<<" destroyed!";  }
};

int main()
{
    test t1(5);
    {
        test t2(10);
    }
    return 0;
}
