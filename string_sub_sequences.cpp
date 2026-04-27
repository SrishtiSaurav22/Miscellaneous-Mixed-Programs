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

using namespace std;

int subseq(string input, string output[])
{
    if(input.empty())
    {
        output[0]="";
        return 1;
    }

    string small_string=input.substr(1);
    int small_string_output=subseq(small_string,output);

    int i;
    for(i=0;i<small_string_output;i++)
        output[i+small_string_output]=input[0]+output[i];

    return 2*small_string_output;
}

int main()
{
    string str="pqrs";
    int n=str.length();
    int size_of_output_str=pow(2,n);

    string *output=new string[size_of_output_str];
    // you need to use square braces when creating a string pointer
    // we can use normal braces with integer or character

    cout<<"No. of subsequences of <<"<<str<<">> are: "<<subseq(str,output);

    cout<<"\nSub-sequences of <<"<<str<<">> are:\n";
    int i;
    for(i=0;i<size_of_output_str;i++)
        cout<<"("<<i+1<<") "<<output[i]<<"\n";

    cout<<endl;
    return 0;
}
