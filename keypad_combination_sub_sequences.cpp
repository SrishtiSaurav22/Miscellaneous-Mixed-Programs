/*
 Some clarification:

 Here, the name of the file is mentions
 subsequences, but we are using subsets.

 Subsequences will preserve the order of
 the elements, but not subsets.
*/

#include<bits/stdc++.h>
#include<string.h>
#include<math.h>
#include "string_sub_sequences.h"

using namespace std;

/*
 I'm removing duplicates from the number
 as in subsequences of a string, there are
 no duplicates.

 This is by copying the number's digits
 into a set and then converting that set
 into a string, using any method.
*/

// keypad combination string list
string alpha[10]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz",""};

string num_to_alpha(int num)
{
    int nnum=num, d, i;
    string str="";
    std::set<int> s;

    while(nnum)
    {
        d=nnum%10;
        s.insert(d);
        nnum=nnum/10;
    }

    std::set<int>::iterator itr;
    // take care of the scope resolution when using STL

    for(itr=s.begin();itr!=s.end();itr++)
        str=str+alpha[*itr-1];

    return str;
}

int count_num_to_alpha(int num)
{
    int nnum=num, d, c=0;

    while(nnum)
    {
        d=nnum%10;
        c=c+alpha[d-1].length();
        nnum=nnum/10;
    }

    return c;
}

int main()
{
    int i;

    int keypad_combi=234;

    string keypad_combi_str=num_to_alpha(keypad_combi);
    int size_of_output=pow(2,count_num_to_alpha(keypad_combi));

    string *output=new string[size_of_output];
    subseq(keypad_combi_str,output);

    for(i=0;i<size_of_output;i++)
        cout<<"("<<i+1<<") "<<output[i]<<"\n";

    cout<<endl;
    return 0;
}
