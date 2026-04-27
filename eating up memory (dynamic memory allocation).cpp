#include<bits/stdc++.h>

using namespace std;

int eating_up_memory_static()
{
    while(true)
    {
        int i=10;
    }
}

int eating_up_memory_dynamic()
{
    while(true)
    {
        int *i=new int;
    }
}

int main()
{
    /*
     Here, when you call eating_up_memory_dynamic()
     you can open the task manager and see how the
     amount of memory being taken increases.
    */

    //eating_up_memory_static();
    eating_up_memory_dynamic();

    return 0;
}
