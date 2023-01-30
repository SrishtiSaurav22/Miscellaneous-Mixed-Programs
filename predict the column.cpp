#include<bits/stdc++.h>

using namespace std;

int columnWithMaxZeroes(vector<vector<int>> arr, int N)
{
    int i,j,max0=0,maxj=0,d;

    for(j=0;j<N;j++)
    {
        d=0;
        for(i=0;i<N;i++)
            if(arr[i][j]==0)
                d++;

        if(d>max0)
        {
            max0=d;
            maxj=j;
        }
    }
    return maxj;
}

int main()
{
    vector<vector<int>> arr={ {1,1,1,1,1} , {0,0,0,0,0} , {0,1,0,1,0} , {0,0,1,0,0} , {0,0,0,0,0} };

    cout<<"Column with the maximum zeroes: "<<columnWithMaxZeroes(arr,5);

    return 0;
}
