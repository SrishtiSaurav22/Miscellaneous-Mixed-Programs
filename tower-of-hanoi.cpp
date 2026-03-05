#include<bits/stdc++.h>

using namespace std;

/*
Below are two functions with differently named parameters to generate solve the Tower of Hanoi problem

Time complexity:   theta(2^n) 

Space complexity:  theta(n)
Auxiliary space:   theta(n)
*/

void tower_of_hanoi(int n, char A, char B, char C)
{
    /*
    Rules:

    1. Only 1 disk moves at a time
    2. No larger disk above smaller
    3. Only the top disk of a tower can be moved
    */
    
    if(n==1)
    {
        cout<<n<<" is moved from "<<A<<" to "<<C<<endl;
        return;
    }

    tower_of_hanoi(n-1,A,C,B);
    cout<<n<<" is moved from "<<A<<" to "<<C<<endl;
    tower_of_hanoi(n-1,B,A,C);
}

void tower_of_hanoi_edited(int n, char source, char helper, char destination)
{
    if(n==1)
    {
        cout<<n<<" is moved from "<<source<<" to "<<destination<<endl;
        return;
    }

    tower_of_hanoi(n-1, source, destination, helper);
    cout<<n<<" is moved from "<<source<<" to "<<destination<<endl;
    tower_of_hanoi(n-1, helper, source, destination);
}

int main()
{
    int n=3;
    char A='A', B='B', C='C';

    tower_of_hanoi(n,A,B,C);
    
    return 0;
}