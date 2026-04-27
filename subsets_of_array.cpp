#include<bits/stdc++.h>
#include<string.h>
#include<math.h>

using namespace std;

int subsets_of_array(vector<int> input, vector<int> *output)
{
    if(input.empty())
    {
        output[0].push_back(0); //zero denoting empty place
        return 1;
    }

    int i;
    vector<int>::iterator itr;

    vector<int> small_input;

    for(itr=input.begin()+1;itr!=input.end();itr++)
        small_input.push_back(*itr);

    int small_input_count=subsets_of_array(small_input,output);

    for(i=0;i<small_input_count;i++)
        output[i+small_input_count]=output[i];

    for(i=0;i<small_input_count;i++)
        output[i+small_input_count].push_back(*(input.begin()));
        // remember to dereference the pointer pointing
        // to the desired value

    return 2*small_input_count;
}

int main()
{
    vector<int> input;

    input.push_back(1);
    input.push_back(2);
    input.push_back(3);

    int no_of_rows=pow(2,input.size());

    vector<int> *output=new vector<int>[no_of_rows];

    cout<<"Count of subsets of an array: "<<subsets_of_array(input,output)<<endl;

    int i;
    vector<int>::iterator itr;

    cout<<"\nOutputs of the array include:\n";
    for(i=0;i<no_of_rows;i++)
    {
        cout<<"\n("<<i+1<<")\n";
        for(itr=output[i].begin();itr!=output[i].end();itr++)
            cout<<*itr<<"\t";


        cout<<endl;
    }

    cout<<endl;
    return 0;
}
