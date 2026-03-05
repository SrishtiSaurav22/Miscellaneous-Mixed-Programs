#include<bits/stdc++.h>

using namespace std;

/*
Below is a function to generate subset strings of an input string

Time complexity:   theta(n.2^n) 

Space complexity:  theta(n^2)
Auxiliary space:   theta(n^2)
*/

void generate_subsets_recursion(string &origin, string curr="", int index=0) 
// if you assign a default value to a parameter, all the parameters to it right should also have default values assigned
// curr is being passed by value here

/*
We can keep curr passed by value.

=> It is simpler.
=> Cleaner.
=> Less error-prone.
=> Perfectly acceptable.

Subset generation is O(2^n) anyway — so copying small strings like curr isn’t your bottleneck.
*/
{
    if(index==origin.length())
    {
        cout<<curr<<", ";
        return;
    }

    generate_subsets_recursion(origin, curr + origin[index], index+1);
    generate_subsets_recursion(origin, curr, index+1);
}

/*
Below is a function to generate subset strings of an input string

Time complexity:   theta(n.2^n) 

Space complexity:  theta(n)
Auxiliary space:   theta(n)
*/

void generate_subsets_recursion_optimized(string &origin, string &curr, int index=0)
// curr is bein passed by reference here
{
    if(index==origin.length())
    {
        cout<<curr<<", ";
        return;
    }

    curr.push_back(origin[index]);
    generate_subsets_recursion_optimized(origin, curr, index+1);

    curr.pop_back();
    generate_subsets_recursion_optimized(origin, curr, index+1);

    /*
    Need to use push_back() and pop_back() because I cannot use the line:
    
    generate_subsets_recursion(origin, curr + origin[index], index+1);

    This is because I've passed curr by reference so it's a non-const reference (string &) that 
    can only bind to named variables (lvalues).
    An 'curr + origin[i]' is temporary and an rvalue so it cannot bind to a non-const reference
    */
}

int main()
{
    string origin="ABC", curr="";

    cout<<"Subsets of the "<<origin<<" are:\n";
    generate_subsets_recursion_optimized(origin,curr,0);
    cout<<endl;
    
    return 0;
}