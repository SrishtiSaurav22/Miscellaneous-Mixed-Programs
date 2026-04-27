// no output....fix this

#include<bits/stdc++.h>

using namespace std;

int vec_to_num(vector<int> vec)
{
    int sum=0;

    for(auto itr=vec.begin();itr!=vec.end();itr++)
        sum=sum+*itr;

    return sum;
}

char int_to_char(int n)
{
    return n+96;
}

void gen_possible_letters(vector<int> input, set<char> &output, int pos, int len)
{
    if(input.empty())
        return;

    int n=input.size();

    vector<int> small_input;

    for(auto itr=input.begin()+pos;itr!=input.end();itr++)
    {

    }

    if(n>=1 && n<=2)
    {
        int num=vec_to_num(input);

        if(num>=1 && num<=26)
            output.insert(int_to_char(num));
    }

    gen_possible_letters(input,output,0,n-1);
    gen_possible_letters(input,output,1,n-1);
}

int main()
{
    vector<int> input;

    input.push_back(1);
    input.push_back(2);
    input.push_back(3);

    set<char> output;

    gen_possible_letters(input,output,0,input.size());

    for(auto itr=output.begin();itr!=output.end();itr++)
        cout<<*itr<<"\t";

    cout<<endl;
    return 0;
}
