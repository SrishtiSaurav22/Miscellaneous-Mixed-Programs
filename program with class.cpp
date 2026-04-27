#include<bits/stdc++.h>

using namespace std;

class factorial
{
    public:

    int n;

    factorial(int n)
    {
        this->n=n;
    }

    int calfac(int n)
    {
        if(n==0 || n==1)
            return 1;

        return n*calfac(n-1);
    }
};

int main()
{
    factorial f(5);

    cout<<"Factorial value of the object: "<<f.calfac(f.n);

    cout<<endl;
    return 0;
}
