#include<bits/stdc++.h>
#include<string.h>
#include<math.h>

using namespace std;

int subsets_of_array(vector<int> input, vector<int> *output)
{
    if(input.empty())
    {
        output[0].push_back(0);
        return 1;
    }

    vector<int> small_input;
    vector<int>::iterator itr;
    int i;

    for(itr=input.begin()+1;itr!=input.end();itr++)
        small_input.push_back(*itr);

    int small_input_count=subsets_of_array(small_input,output);

    for(i=0;i<small_input_count;i++)
        output[i+small_input_count]=output[i];

    for(i=0;i<small_input_count;i++)
        output[i+small_input_count].push_back(*(input.begin()));

    return 2*small_input_count;
}

int ksum_subsets_of_array(vector<int> input, vector<int> *output, vector<vector<int>> &outputk, int k)
{
    int i,j;
    vector<int>::iterator itr;

    int sum;
    int ksum_subsets_count=0;
    int total_subsets_count=subsets_of_array(input,output);

    for(i=0; i<total_subsets_count; i++)
    {
        sum=0;
        for(itr=output[i].begin();itr!=output[i].end();itr++)
            sum=sum+*itr;

        if(sum==k)
        {
            outputk.push_back(output[i]);
            ++ksum_subsets_count;
        }
    }

    return ksum_subsets_count;
}

/*
 When a vector vec has only one element 1, then
 vec.begin()=1 and vec.end()=0
 How?
*/

int main()
{
    int k=3;
    vector<int> input;

    input.push_back(1);
    input.push_back(2);
    input.push_back(3);

    int no_of_rows=pow(2,input.size());

    vector<int> *output=new vector<int>[no_of_rows];
    vector<vector<int>> outputk;
    /*
     since the max no. of k sum subsets will be equal
     to the total no. of subsets
    */

    int total_subsets=subsets_of_array(input, output);
    int ksum_subsets=ksum_subsets_of_array(input, output, outputk, k);

    int i;

    cout<<"Total subsets:\n\n";
    for(i=0;i<total_subsets;i++)
    {
        for(auto itr=output[i].begin();itr!=output[i].end();itr++)
            cout<<*itr<<"\t";

        cout<<endl;
    }

    cout<<"\n\nK-sum subsets:\n\n";
    // if using auto keyword, the variable needs to be initialized along with declaration.
    for(auto itr=outputk.begin();itr!=outputk.end();itr++)
    {
        // iterator is always a pointer so to use '->' when accessing its object members
        for(auto jtr=itr->begin();jtr!=itr->end();jtr++)
            cout<<*jtr<<"\t";

        cout<<endl;
    }

    /*
     Why does the output have 2 zeroes before all the vector values?
     This is regardless of whether you use 'auto' or 'vector<int>::iterator'..........
    */

    cout<<endl;
    return 0;
}


