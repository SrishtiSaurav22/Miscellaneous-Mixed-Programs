#include<bits/stdc++.h>

using namespace std;

class point
{
    int x;
    int y;

    public:
        point(int x, int y)
        {
            this->x=x;
            this->y=y;
        }

        point &setX(int x)
        {
            this->x=x;
            return *this;
        }

        point &setY(int y)
        {
            this->y=y;
            return *this;
        }

        void display()
        {
            cout<<" "<<x<<" "<<y;
        }
};

int main()
{
    point p(0,0);
    p.setX(10).setY(20).display();
}
