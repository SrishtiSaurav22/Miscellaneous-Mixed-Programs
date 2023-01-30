#ifndef STRING_SUB_SEQUENCES_H_INCLUDED
#define STRING_SUB_SEQUENCES_H_INCLUDED

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

int subseq(std::string input, std::string output[])
{
    if(input.empty())
    {
        output[0]="";
        return 1;
    }

    std::string small_string=input.substr(1);
    int small_string_output=subseq(small_string,output);

    int i;
    for(i=0;i<small_string_output;i++)
        output[i+small_string_output]=input[0]+output[i];

    return 2*small_string_output;
}

#endif // STRING_SUB_SEQUENCES_H_INCLUDED
