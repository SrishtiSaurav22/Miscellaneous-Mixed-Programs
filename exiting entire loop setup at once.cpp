#include<bits/stdc++.h>

void func()
{
    int i,j;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            std::cout<<i<<" "<<j<<"\t";

            if(i==1 && j==1)
            {
                std::cout<<"\nBreaking out of inner loop";
                return;
            }
        }
        std::cout<<"\n\nAre we outside?\n\n";
    }
}

int main()
{
    func();
    std::cout<<"\n\nNow we're really outside!";
    return 0;
}

/*
if you want to come out of multiple loops at once:
# you cannot use break as it will only come out of the loop in which it is present and none of the outer loops.
# we could use return in a function in order to terminate the whole function containing  the entire loop setup.
( return statement is only used with functions, not with blocks of code )
# or you can write some logic to exit all three loops at once.
