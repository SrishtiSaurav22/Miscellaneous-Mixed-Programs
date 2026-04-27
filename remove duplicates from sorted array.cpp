#include<bits/stdc++.h>

using namespace std;

int new_size(int a[], int n)
{
    int i, res=1; //res is 1 as the first element will be a part of the new array anyways

    for(i=0;<n;i++)
    {
        for(if(a[i]!=a[res-1]))
        a[res]=a[i];
        res++;
    }
    return res; //returns the size of the new array

    //we ignore the elements after res
}
