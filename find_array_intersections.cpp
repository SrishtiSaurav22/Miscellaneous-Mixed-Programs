/*
 Here, you need to find the intersection elements of two given arrays.
 They can hold duplicates which will be matched based on their sequence of appearance.

 Time complexity: O(n*m)
 where n is the number of elements of vector1 and m is the number of elements of vector2.
*/

#include<bits/stdc++.h>

using namespace std;

void print_intersection_vector(vector<int> v1, vector<int> v2)
{
    vector<int>::iterator i,j;
    vector<int> vout;

    i=v1.begin();
    j=v2.begin();

    while(j!=v2.end())
    {
        if(*i==*j)
        {
            vout.push_back(*i);

            v1.erase(i);
            v2.erase(j);

            i=v1.begin();
            j=v2.begin();
        }

        else
        {
            ++i;

            if(i==v1.end())
            {
                i=v1.begin();
                ++j;
            }
        }
    }

    cout<<"Printing the vector of intersection elements:\n";
    for(i=vout.begin();i!=vout.end();i++)
        cout<<*i<<"\t";
}

int main()
{
    vector<int> v1{2,6,1,2};
    vector<int> v2{1,2,3,4,2};

    print_intersection_vector(v1,v2);

    cout<<endl;
    return 0;
}
