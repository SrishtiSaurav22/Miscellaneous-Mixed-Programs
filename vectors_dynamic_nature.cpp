/*
 This code is to check how dynamic vectors really are. :D
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> vec{0,1,2,3,4,5,6,7,8,9};

    /*
    vector<int>::iterator itr;
    int flag=0;

    check_size:
    if(flag==0)
        cout<<"Initial size of the vector: "<<vec.size()<<endl;

    else
        cout<<"New size of the vector: "<<vec.size()<<endl;

    if(flag==3)
        goto stop_and_print;

    for(itr=vec.begin();itr!=vec.end();itr++)
    {
        if(*itr%2==0)
        {
            vec.erase(itr);
            ++flag;
            goto check_size;
        }
    }

    stop_and_print:
    cout<<"\nNow printing the modified vector:\n";
    for(itr=vec.begin();itr!=vec.end();itr++)
        cout<<*itr<<"\t";
    */

    cout<<"Beginning element: "<<*(vec.begin())<<endl;
    cout<<"Ending element or end of vector: "<<*(vec.begin())<<endl;
    cout<<"After end of vector: "<<*(++vec.end())<<endl;
    cout<<"Ending element: "<<*(--vec.end());

    cout<<endl;
    return 0;
}
