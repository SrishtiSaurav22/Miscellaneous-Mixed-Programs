// figure out how to use a string class string here
// for all these functions

#include<bits/stdc++.h>
#include<string.h>
#include<cstring>

using namespace std;

// it can be void as an array is anyhow passed by reference
void replace_char(char* ch)
{
    if(*ch=='\0')
        return;

    if(*ch=='u')
        *ch='*';

    replace_char(++ch);
}

// it can be void as an array is anyhow passed by reference
void remove_duplicates_char(char* ch)
{

}

string remove_duplicates_string(string str, int i, int j)
{
    // for the initial function call i=0, j=1
    string str1,str2;

    if(j==str.length())
        return str;

    if(str[i]==str[j])
    {
        str1=str.substr(0,i+1);
        str2=str.substr(j+1);
        str=str1+str2;
        return remove_duplicates_string(str,i,j);
    }

    else
        return remove_duplicates_string(str,++i,++j);
}

int main()
{

    char str1[100]="fuck this fucking hell!";
    char str2[100]="abbcccdddd";

    string str3="abbcccdddd";

    cout<<"Before replacement: "<<str1;
    replace_char(str1);
    cout<<"\nAfter replacement: "<<str1;

    cout<<"\nBefore the removal of duplicates: "<<str3;
    str3=remove_duplicates_string(str3,0,1);
    cout<<"\nAfter the removal of duplicates: "<<str3;

    cout<<endl;
    return 0;
}
